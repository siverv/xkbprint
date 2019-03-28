/************************************************************
 Copyright (c) 1995 by Silicon Graphics Computer Systems, Inc.

 Permission to use, copy, modify, and distribute this
 software and its documentation for any purpose and without
 fee is hereby granted, provided that the above copyright
 notice appear in all copies and that both that copyright
 notice and this permission notice appear in supporting
 documentation, and that the name of Silicon Graphics not be
 used in advertising or publicity pertaining to distribution
 of the software without specific prior written permission.
 Silicon Graphics makes no representation about the suitability
 of this software for any purpose. It is provided "as is"
 without any express or implied warranty.

 SILICON GRAPHICS DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS
 SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL SILICON
 GRAPHICS BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL
 DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
 OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION  WITH
 THE USE OR PERFORMANCE OF THIS SOFTWARE.

 ********************************************************/



#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <ctype.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/XKBlib.h>
#include <X11/extensions/XKBgeom.h>
#include <X11/extensions/XKM.h>
#include <X11/extensions/XKBfile.h>
#include <X11/keysym.h>
#include <X11/Xutil.h>

#if defined(sgi)
#include <malloc.h>
#endif


#include <stdlib.h>

#include "ucssymbols.h"
#include "utils.h"
#include "xkbprint.h"
#include "wcwidth.c"

typedef struct {
    char box_mask;
    int color;
    char value[5];
} Cell;

typedef struct {
    Cell * cells;
    int width;
    int height;
} Grid;


typedef struct {
    Display *           dpy;
    Grid                grid;
    XkbDescPtr          xkb;
    XkbGeometryPtr      geom;
    char * * shapeNames;
    char * * shapePaths;
    int                 totalKB;
    int                 kbPerPage;
    int                 black;
    int                 white;
    int                 color;
    int                 font;
    int                 fontSize;
    int                 nPages;
    int                 x1, y1;
    int                 x2, y2;
    XKBPrintArgs *      args;
    int                 keyLabelType;
    int                 keyLegendType;
    int                 keyLegendLength;
    int                 keyLegendLevel;
    int                 keyLegendGroup;
    int                 baseLabelLevel;
    int                 baseLabelGroup;
    int                 labelLevels;
    int                 labelGroups;
} UCSState;


typedef struct {
    XkbKeyPtr key;
    XkbShapePtr shape;
    KeySym * symbols;
    int keyCode; 
    int keyTypeIndex;
    float x;
    float y;
    int outlineColor;
    int legendColor;
    int labelColor;
    int outline_ndx;
    XkbOutlinePtr outline;
    char * legend;
    char labels[4][30];
    int num_labels;
} UCSKeyDefinition;

// static const char * box_chars = "+++++|++++-++++++++++++++++++++";
static const char * box_chars_unicode[] = {
    " ","╵","╶","└","╷","│","┌","├","╴","┘","─","┴","┐","┤","┬","┼"," ","╵","╶","╰","╷","│","╭","├","╴","╯","─","┴","╮","┤","┬"
};
static const char * box_chars_ascii[] = {
    " ","|","-","+","|","|","+","|","-","+","-","+","+","+","+","+"," ","|","-","+","|","|","+","|","-","+","-","+","+","+","+"
};

static char * * box_chars = box_chars_ascii; 
static Bool wantAscii = False;
static Bool wantColor = True;

#define BOX_MASK_TOP     1
#define BOX_MASK_RIGHT   2
#define BOX_MASK_BOTTOM  4
#define BOX_MASK_LEFT    8
#define BOX_MASK_ROUNDED 16

static float keyboard_scale = 1;
static float char_width_height = 1;
#define X_mm2ch(x) ((((((x) * 72) / 254) * 11) / 10) * keyboard_scale)
#define Y_mm2ch(y) ((((((y) * 72) / 254) * 11) / 10) * keyboard_scale * char_width_height)

#define max(a,b) ((a) < (b) ? b : a)
#define min(a,b) ((a) > (b) ? b : a)

#define GRID_CELL(grid, x, y) (grid).cells[(y) * (grid).width + x]

#define IS_ABOVE(x0,y0,x1,y1) ((x0) == (x1) && (y0) == (y1)-1)
#define IS_BELOW(x0,y0,x1,y1) ((x0) == (x1) && (y0) == (y1)+1)
#define IS_LEFT(x0,y0,x1,y1)  ((x0) == (x1)-1 && (y0) == (y1))
#define IS_RIGHT(x0,y0,x1,y1) ((x0) == (x1)+1 && (y0) == (y1))


#define STYLE_RESET_ALL 0

#define STYLE_BRIGHT 1
#define STYLE_DIM 2
#define STYLE_UNDERLINED 4
#define STYLE_BLINK 5
#define STYLE_INVERTED 7

#define STYLE_RESET_BRIGHT 21
#define STYLE_RESET_DIM 22
#define STYLE_RESET_UNDERLINED 24
#define STYLE_RESET_BLANK 25
#define STYLE_RESET_INVERTED 27

#define STYLE_FOREGROUND_DEFAULT 39 
#define STYLE_FOREGROUND_BLACK 30
#define STYLE_FOREGROUND_RED 31 	
#define STYLE_FOREGROUND_GREEN 32 	
#define STYLE_FOREGROUND_YELLOW 33 	
#define STYLE_FOREGROUND_BLUE 34 	
#define STYLE_FOREGROUND_MAGENTA 35 	
#define STYLE_FOREGROUND_CYAN 36 	
#define STYLE_FOREGROUND_DARK_GRAY 90 	
#define STYLE_FOREGROUND_LIGHT_GRAY 37 	
#define STYLE_FOREGROUND_LIGHT_RED 91 	
#define STYLE_FOREGROUND_LIGHT_GREEN 92 	
#define STYLE_FOREGROUND_LIGHT_YELLOW 93 	
#define STYLE_FOREGROUND_LIGHT_BLUE 94 	
#define STYLE_FOREGROUND_LIGHT_MAGENTA 95 	
#define STYLE_FOREGROUND_LIGHT_CYAN 96 	
#define STYLE_FOREGROUND_WHITE 97 

static char * INDICATOR_SYMBOL = "●";
static char * INDICATOR_SYMBOL_ASCII = "*";

static int
UCSGetDoodadOutlineColor(UCSState * state)
{
    return STYLE_FOREGROUND_DEFAULT;
}
static int
UCSGetDoodadTextColor(UCSState * state)
{
    return STYLE_DIM;
}
static int
UCSGetDoodadLogoColor(UCSState * state)
{
    return STYLE_DIM;
}
static int
UCSGetDoodadIndicatorColor(UCSState * state)
{
    return STYLE_FOREGROUND_GREEN;
}
static int
UCSGetKeyOutlineColor(UCSState * state, XkbKeyPtr key, UCSKeyDefinition keyDef)
{
    return STYLE_DIM;
}
static int
UCSGetKeyLegendColor(UCSState * state, XkbKeyPtr key, UCSKeyDefinition keyDef)
{
    return 0;
}
static int
UCSGetKeyLabelColor(UCSState * state, XkbKeyPtr key, UCSKeyDefinition keyDef)
{
    return STYLE_BRIGHT;
}


static int
UCSKeySymToString(char * output, int limit, KeySym sym){
    char * tmp;
    int value;
    if(wantAscii){
        value = UCSOverrideKeySymAscii(output, limit, sym);
    } else {
        value = UCSOverrideKeySym(output, limit, sym);
    }
    if(value != 0){
        return value;
    }
    else if ((sym < 128 || !wantAscii) && limit > 4 && 0 != (value = XKeysymToUCSValue(sym))){
        return UCSValueToString(output, value);
    }
    else {
        tmp = XKeysymToString(sym);
        if (tmp != NULL) {
            return snprintf(output, limit, "%s", tmp);
        }
        else {
            return snprintf(output, limit, "(%ld)", sym);
        }
    }
}

static void
UCSGridEcho(FILE *out, Grid grid){
    for(int y = 0; y < grid.height; y++){
        char currentColor = -1;
        int charDeficit = 0;
        for(int x = 0; x < grid.width; x++){
            Cell cell = GRID_CELL(grid, x, y);
            char * value = cell.value;
            char mask = cell.box_mask;
            char color = cell.color;
            if(wantColor && color && color != currentColor){
                currentColor = color;
                fprintf(out, "\e[0m\e[%im", color);
            }
            if(value[0] != 0){
                if(value[1] != 0){
                    int unicode = UCSStringToValue(value);
                    int width = mk_wcwidth(unicode);
                    if(width > 1){
                        charDeficit += width-1;
                    }
                }
                fprintf(out, "%s", value);
            } else if(mask == 0){
                if(charDeficit == 0) {
                    fprintf(out, " ");
                } else {
                    charDeficit--;
                }
            } else {
                fprintf(out, "%s", box_chars[mask & 31]);
            }
        }
        fprintf(out, "\e[0m\n");
    }
}

static void 
interpolatePathOntoGrid(Grid onto, int x0, int y0, int x1, int y1, int color)
{
    char mask;
    int xDiff = x1-x0;
    int yDiff = y1-y0;
    int max = max(abs(xDiff), abs(yDiff));
    float incX, incY;
    int xPrevious, yPrevious;
    int xCurrent = x0;
    int yCurrent = y0;
    int xNext = x0;
    int yNext = y0;
    if(max == 0){
        printf("MAX IS 0\n");
        return;
    }
    incX = xDiff / ((float) max);
    incY = yDiff / ((float) max);
    for(int i = 1; i <= max; i++){
        xPrevious = xCurrent;
        yPrevious = yCurrent;
        xCurrent = xNext;
        yCurrent = yNext;
        xNext = x0 + incX * i;
        yNext = y0 + incY * i;
        mask = \
            (IS_ABOVE(xPrevious,yPrevious,xCurrent,yCurrent) || IS_ABOVE(xNext,yNext,xCurrent,yCurrent) ? BOX_MASK_TOP : 0) \
        +   (IS_BELOW(xPrevious,yPrevious,xCurrent,yCurrent) || IS_BELOW(xNext,yNext,xCurrent,yCurrent) ? BOX_MASK_BOTTOM : 0)\
        +   (IS_LEFT(xPrevious,yPrevious,xCurrent,yCurrent) || IS_LEFT(xNext,yNext,xCurrent,yCurrent) ? BOX_MASK_LEFT : 0)\
        +   (IS_RIGHT(xPrevious,yPrevious,xCurrent,yCurrent) || IS_RIGHT(xNext,yNext,xCurrent,yCurrent) ? BOX_MASK_RIGHT : 0);
        GRID_CELL(onto, xCurrent, yCurrent).box_mask |= mask;
        GRID_CELL(onto, xCurrent, yCurrent).color = color;
    }
    xPrevious = xCurrent;
    yPrevious = yCurrent;
    xCurrent = xNext;
    yCurrent = yNext;
    mask = \
        (IS_ABOVE(xPrevious,yPrevious,xCurrent,yCurrent) ? BOX_MASK_TOP : 0) \
    +   (IS_BELOW(xPrevious,yPrevious,xCurrent,yCurrent) ? BOX_MASK_BOTTOM : 0)\
    +   (IS_LEFT(xPrevious,yPrevious,xCurrent,yCurrent) ? BOX_MASK_LEFT : 0)\
    +   (IS_RIGHT(xPrevious,yPrevious,xCurrent,yCurrent) ? BOX_MASK_RIGHT : 0);
    GRID_CELL(onto, xCurrent, yCurrent).box_mask |= mask;
    GRID_CELL(onto, xCurrent, yCurrent).color = color;
}

static int
UCSCharOntoCell(Cell * cell, char * ch, int color) {
    if(color){
        cell->color = color;
    }
    if((ch[0] & 128) == 0){
        if(ch[0] == '\n'){
            if(wantAscii){
                return 1;
            }
            cell->value[0] = "↵"[0];
            cell->value[1] = "↵"[1];
            cell->value[2] = "↵"[2];
        } else {
            cell->value[0] = ch[0];
            cell->value[1] = 0;
            cell->value[2] = 0;
        }
        cell->value[3] = 0;
        cell->value[4] = 0;
        return 1;
    } else if((ch[0] & 0b11100000) == 0b11000000) {
        if(wantAscii){
            cell->color = STYLE_DIM;
            cell->value[0] = '?';
            cell->value[1] = 0;
            return 1;
        }
        cell->value[0] = ch[0];
        cell->value[1] = ch[1];
        cell->value[2] = 0;
        cell->value[3] = 0;
        cell->value[4] = 0;
        return 2;
    } else if((ch[0] & 0b11110000) == 0b11100000) {
        if(wantAscii){
            cell->color = STYLE_DIM;
            cell->value[0] = '?';
            cell->value[1] = 0;
            return 1;
        }
        cell->value[0] = ch[0];
        cell->value[1] = ch[1];
        cell->value[2] = ch[2];
        cell->value[3] = 0;
        cell->value[4] = 0;
        return 3;

    } else if((ch[0] & 0b11111000) == 0b11110000) {
        if(wantAscii){
            cell->color = STYLE_DIM;
            cell->value[0] = '?';
            cell->value[1] = 0;
            return 1;
        }
        cell->value[0] = ch[0];
        cell->value[1] = ch[1];
        cell->value[2] = ch[2];
        cell->value[3] = ch[3];
        cell->value[4] = 0;
        return 4;
    }
    return 1;
}

static int 
interpolateLegendOntoGrid(Grid onto, int x0, int y0, int x1, int y1, int color, char * legend)
{
    int xDiff = x1-x0;
    int yDiff = y1-y0;
    int max = max(abs(xDiff), abs(yDiff));
    int legendIndex = 0;
    float incX, incY;
    int xCurrent = x0;
    int yCurrent = y0;
    int xNext = x0;
    int yNext = y0;
    incX = xDiff / ((float) max);
    incY = yDiff / ((float) max);
    for(int i = 1; i <= max; i++){
        xCurrent = xNext;
        yCurrent = yNext;
        xNext = x0 + incX * i;
        yNext = y0 + incY * i;
        if(xCurrent == xNext && yCurrent == yNext){
            continue;
        } else if(legend[legendIndex] == 0){
            return legendIndex;
        } else if(legend[legendIndex] == '\n'){
            return legendIndex+1;
        } else if(i > 1){
            legendIndex += UCSCharOntoCell(&GRID_CELL(onto, xCurrent, yCurrent), legend+legendIndex, color);
        }
    }
    xCurrent = xNext;
    yCurrent = yNext;
    if(legend[legendIndex] == 0){
        return legendIndex;
    } else if(legend[legendIndex] == '\n'){
            return legendIndex+1;
    } else {
        legendIndex += UCSCharOntoCell(&GRID_CELL(onto, xCurrent, yCurrent), legend+legendIndex, color);
    }
    return legendIndex;
}


static void 
fitLabelOntoGrid(Grid onto, int x0, int y0, int x1, int y1, int color, char * label, int alignX, int alignY)
{
    int length = 0, lines = 0, index = 0;
    int minX = min(x0, x1);
    int maxX = max(x0, x1);
    int minY = min(y0, y1);
    int maxY = max(y0, y1);
    int xDiff = x1-x0;
    int yDiff = y1-y0;
    length = strlen(label);
    if(xDiff == 0){
        printf("NO SPACE!");
        return;
    }
    lines = length / xDiff + 1;
    if(alignY < 0){
    } else if(alignY == 0){
        minY = minY + yDiff / 2 - lines / 2;
    } else {
        minY = maxY - lines + 1;
    }
    for(int y = max(y0, minY); y <= maxY; y++){
        int left = length - index;
        if(left <= xDiff){
            if(alignX < 0){
                maxX = min(x1, minX + left);
            } else if(alignX == 0){
                minX = max(x0, minX + xDiff / 2 - left / 2);
                maxX = minX + left;
            } else {
                minX = max(x0, maxX - left);
            }
        }
        for(int x = minX; x <= maxX; x++){
            index += UCSCharOntoCell(&GRID_CELL(onto, x, y), label+index, color);
            if(label[index] == '\n'){
                index++;
                break;
            }
        }
        if(index >= length){
            return;
        }
    }
}


static int
UCSGetShapeOutlineIndexForUse(XkbShapePtr shape) {
    if(shape->primary != 0){
        return -1;
    } else if(shape->num_outlines > 1){
        return 1;
    } else {
        return 0;
    }
}


static void
UCSShapeApplyPathOntoGrid(UCSState *state, XkbShapePtr shape, int x, int y, int color)
{
    int p, o;
    XkbOutlinePtr ol;
    XkbPointPtr pt;
    o = UCSGetShapeOutlineIndexForUse(shape);
    ol = o < 0 ? shape->primary : shape->outlines+o;
    pt = ol->points;
    if(ol->num_points == 1 || ol->num_points == 2){
        int x0,y0,x1,y1;
        if (ol->num_points == 1) {
            x0 = X_mm2ch(x);
            y0 = Y_mm2ch(y);
            x1 = X_mm2ch(x + pt->x);
            y1 = Y_mm2ch(y + pt->y);
        }
        else {
            x0 = X_mm2ch(x + pt[0].x);
            y0 = Y_mm2ch(y + pt[0].y);
            x1 = X_mm2ch(x + pt[1].x);
            y1 = Y_mm2ch(y + pt[1].y);
        }
        interpolatePathOntoGrid(state->grid, x0, y0, x1, y0, color);
        interpolatePathOntoGrid(state->grid, x1, y0, x1, y1, color);
        interpolatePathOntoGrid(state->grid, x1, y1, x0, y1, color);
        interpolatePathOntoGrid(state->grid, x0, y1, x0, y0, color);
    }
    else {
        int x0 = X_mm2ch(x + pt[0].x);
        int y0 = Y_mm2ch(y + pt[0].y);
        int xL = x0;
        int yL = y0;
        int x1, y1;
        pt++;
        for (p = 1; p < ol->num_points; p++, pt++) {
            x1 = X_mm2ch(x + pt->x);
            y1 = Y_mm2ch(y + pt->y);
            interpolatePathOntoGrid(state->grid, x0, y0, x1, y1, color);
            x0 = x1;
            y0 = y1;
        }
        interpolatePathOntoGrid(state->grid, x0, y0, xL, yL, color);
    }
}

static void
UCSShapeApplyLegendOntoGrid(UCSState *state, UCSKeyDefinition keyDef)
{
    int i = 0;
    int x = keyDef.x;
    int y = keyDef.y;
    int color = keyDef.legendColor;
    int num_points = keyDef.outline->num_points;
    XkbPointPtr pt = keyDef.outline->points;
    int length = strlen(keyDef.legend);
    if(num_points == 1 || num_points == 2){
        int x0,y0,x1,y1;
        if (num_points == 1) {
            x0 = X_mm2ch(x);
            y0 = Y_mm2ch(y);
            x1 = X_mm2ch(x + pt->x);
            y1 = Y_mm2ch(y + pt->y);
        }
        else {
            x0 = X_mm2ch(x + pt[0].x);
            y0 = Y_mm2ch(y + pt[0].y);
            x1 = X_mm2ch(x + pt[1].x);
            y1 = Y_mm2ch(y + pt[1].y);
        }
        i += interpolateLegendOntoGrid(state->grid, x0, y0, x1, y0, color, keyDef.legend+i);
        if(i >= length) return;
        i += interpolateLegendOntoGrid(state->grid, x1, y0, x1, y1, color, keyDef.legend+i);
        if(i >= length) return;
        i += interpolateLegendOntoGrid(state->grid, x1, y1, x0, y1, color, keyDef.legend+i);
        if(i >= length) return;
        i += interpolateLegendOntoGrid(state->grid, x0, y1, x0, y0, color, keyDef.legend+i);
    }
    else {
        int x0 = X_mm2ch(x + pt[0].x);
        int y0 = Y_mm2ch(y + pt[0].y);
        int x1, y1;
        XkbPointPtr oPt = pt;
        pt++;
        for (int p = 1; p < num_points; p++, pt++) {
            x1 = X_mm2ch(x + pt->x);
            y1 = Y_mm2ch(y + pt->y);
            i += interpolateLegendOntoGrid(state->grid, x0, y0, x1, y1, color, keyDef.legend+i);
            if(i >= length || i > 4) return;
            x0 = x1;
            y0 = y1;
        }
        x0 = X_mm2ch(x + oPt[0].x);
        y0 = Y_mm2ch(y + oPt[0].y);
        x1 = X_mm2ch(x + oPt[1].x);
        y1 = Y_mm2ch(y + oPt[1].y);
        interpolateLegendOntoGrid(state->grid, x0, y0, x1, y1, color, keyDef.legend+i);
    }
}


static void
UCSShapeApplyLabelsOntoGrid(UCSState *state, UCSKeyDefinition keyDef)
{
    int x = keyDef.x;
    int y = keyDef.y;
    int x0,y0,x1,y1;
    int xh, yh;
    int color = keyDef.labelColor;
    XkbPointPtr pt = keyDef.outline->points;

    if(keyDef.outline->num_points == 1){
        x0 = X_mm2ch(x)+1;
        y0 = Y_mm2ch(y)+1;
        x1 = X_mm2ch(x + pt->x)-1;
        y1 = Y_mm2ch(y + pt->y)-1;
    }
    else if (keyDef.outline->num_points == 2){
        x0 = X_mm2ch(x + pt[0].x)+1;
        y0 = Y_mm2ch(y + pt[0].y)+1;
        x1 = X_mm2ch(x + pt[1].x)-1;
        y1 = Y_mm2ch(y + pt[1].y)-1;
    }
    else if (keyDef.outline->num_points > 2){
        // TODO: Proper handling of unusual geometry;
        x0 = X_mm2ch(x + pt[0].x)+1;
        x1 = X_mm2ch(x + pt[1].x)-1;
        y0 = Y_mm2ch(y + pt[0].y)+1;
        y1 = y0 + 2;
    } else {
        return;
    }
    xh = (x0+x1)/2;
    yh = (y0+y1)/2;
    if(keyDef.num_labels == 1) {
        fitLabelOntoGrid(state->grid, x0, y0, x1, y1, color, keyDef.labels[0], 0, 0);
    } else  if(keyDef.num_labels == 2) {
        fitLabelOntoGrid(state->grid, x0, y0, x1, yh, color, keyDef.labels[1], 0, -1);
        fitLabelOntoGrid(state->grid, x0, yh+1, x1, y1, color, keyDef.labels[0], 0, 1);
    } else if(keyDef.num_labels == 3){
        fitLabelOntoGrid(state->grid, x0, y0, xh, yh, color, keyDef.labels[1], -1, -1);
        fitLabelOntoGrid(state->grid, x0, yh+1, xh, y1, color, keyDef.labels[0], -1, 1);
        fitLabelOntoGrid(state->grid, xh+1, y0, x1, y1, color, keyDef.labels[2], 1, -1);
    } else if(keyDef.num_labels == 4){
        xh = max(xh, x0+1);
        yh = max(yh, y0+1);
        fitLabelOntoGrid(state->grid, x0, y0, xh, yh-1, color, keyDef.labels[1], -1, -1);
        fitLabelOntoGrid(state->grid, x0, yh, xh, y1, color, keyDef.labels[0], -1, 1);
        fitLabelOntoGrid(state->grid, xh+1, y0, x1, yh-1, color, keyDef.labels[3], 1, -1);
        fitLabelOntoGrid(state->grid, xh+1, yh, x1, y1, color, keyDef.labels[2], 1, 1);
    }
}
static int
UCSGetKeyLegend(char * legend, int legendLimit, UCSState *state, XkbKeyPtr key) {
    // TODO: keyLegendLength < 4 with unicode support.
    int limit = min(legendLimit, state->keyLegendLength+1);
    int keyCode;
    char * tmp;
    XkbKeyTypePtr keyType; 
    switch(state->keyLegendType){
        case KEY_LEGEND_KEYCODE: {
            keyCode = XkbFindKeycodeByName(state->xkb, key->name.name, False);
            return snprintf(legend, limit, "%d", keyCode);
        }
        case KEY_LEGEND_KEYNAME: {
            return snprintf(legend, limit, "%s", key->name.name);
        }
        case KEY_LEGEND_KEYTYPE_FULL: {
            keyCode = XkbFindKeycodeByName(state->xkb, key->name.name, False);
            keyType = XkbKeyKeyType(state->xkb, keyCode, XkbGroup1Index);
            return snprintf(legend, limit, "%s", XkbAtomGetString(state->dpy, keyType->name));
        }
        case KEY_LEGEND_KEYTYPE_ABBR: {
            int length;
            keyCode = XkbFindKeycodeByName(state->xkb, key->name.name, False);
            keyType = XkbKeyKeyType(state->xkb, keyCode, XkbGroup1Index);
            tmp = XkbAtomGetString(state->dpy, keyType->name);
            length = strlen(tmp);
            return snprintf(legend, limit, "%c%d%c", tmp[0], length-2, tmp[length-1]);
        }
        case KEY_LEGEND_SYMBOL: {
            int level = state->keyLegendLevel;
            int group = state->keyLegendGroup;
            KeySym * symbols;
            KeySym sym;
            keyCode = XkbFindKeycodeByName(state->xkb, key->name.name, False);
            if(group >= XkbKeyNumGroups(state->xkb, keyCode)){
                legend[0] = 0;
                return 0;
            }
            symbols = XkbKeySymsPtr(state->xkb, keyCode);
            if (level >= XkbKeyGroupWidth(state->xkb, keyCode, group)) {
                legend[0] = 0;
                return 0;
            }
            sym = symbols[group * XkbKeyGroupsWidth(state->xkb, keyCode) + (level)];
            return UCSKeySymToString(legend, limit, sym);
        }
        default:
        case KEY_LEGEND_NONE:
            legend[0] = 0;
            return 0;
    }
}


static void
UCSApplyKeyOntoGrid(UCSState *state, XkbKeyPtr key, XkbShapePtr shape, float x, float y) 
{
    UCSKeyDefinition keyDef;
    static char buffer[30];
    KeySym sym;
    int l, g;
    bzero(&keyDef, sizeof(UCSKeyDefinition));

    keyDef.key = key;
    keyDef.shape = shape;
    keyDef.x = x;
    keyDef.y = y;
    keyDef.keyCode = XkbFindKeycodeByName(state->xkb, key->name.name, True);
    keyDef.outline_ndx = UCSGetShapeOutlineIndexForUse(shape);
    keyDef.outline = keyDef.outline_ndx < 0 ? shape->primary : shape->outlines+keyDef.outline_ndx;
    keyDef.symbols = XkbKeySymsPtr(state->xkb, keyDef.keyCode);
    keyDef.keyTypeIndex = XkbKeyKeyTypeIndex(state->xkb, keyDef.keyCode, XkbGroup1Index);

    for(g = 0; g < state->labelGroups; g++){
        for (l = 0; l < state->labelLevels; l++) {
            if(keyDef.num_labels >= 4){
                break;
            }
            if (state->baseLabelLevel + l >= XkbKeyGroupWidth(state->xkb, keyDef.keyCode, (state->baseLabelGroup + g))){
                continue;
            }
            sym = keyDef.symbols[(state->baseLabelGroup + g)*XkbKeyGroupsWidth(state->xkb, keyDef.keyCode) + state->baseLabelLevel + l];
            if (state->args->wantSymbols != NO_SYMBOLS)
                sym = CheckSymbolAlias(sym);
            if(sym != 0){
                UCSKeySymToString(buffer, 30, sym);
                snprintf(keyDef.labels[l], 30, "%s", buffer);
                keyDef.num_labels++;
            } else {
                break;
            }
        }
    }
    UCSGetKeyLegend(buffer, 30, state, key);
    keyDef.legend = buffer;

    keyDef.outlineColor = UCSGetKeyOutlineColor(state, key, keyDef);
    keyDef.legendColor = UCSGetKeyLegendColor(state, key, keyDef);
    keyDef.labelColor = UCSGetKeyLabelColor(state, key, keyDef);

    UCSShapeApplyPathOntoGrid(state, keyDef.shape, keyDef.x, keyDef.y, keyDef.outlineColor);
    UCSShapeApplyLegendOntoGrid(state, keyDef);
    UCSShapeApplyLabelsOntoGrid(state, keyDef);
}



static void
UCSDoodad(FILE *out, UCSState *state, XkbDoodadPtr doodad)
{
    int color;
    int left, top;
    switch (doodad->any.type) {
        case XkbLogoDoodad:
        case XkbOutlineDoodad:
        case XkbSolidDoodad: {
            XkbShapePtr shape;
            left = doodad->shape.left;
            top = doodad->shape.top;
            shape = &(state->xkb->geom->shapes[doodad->shape.shape_ndx]);
            color = UCSGetDoodadOutlineColor(state); 
            UCSShapeApplyPathOntoGrid(state, shape, left, top, color);
            if(doodad->any.type == XkbLogoDoodad){
                int x0 = X_mm2ch(doodad->logo.left + shape->bounds.x1);
                int y0 = Y_mm2ch(doodad->logo.top + shape->bounds.y1);
                int x1 = X_mm2ch(doodad->logo.left + shape->bounds.x2);
                int y1 = Y_mm2ch(doodad->logo.top + shape->bounds.y2);
                color = UCSGetDoodadLogoColor(state); 
                fitLabelOntoGrid(state->grid, x0, y0, x1, y1, color, doodad->logo.logo_name, 0, 0);
                // UCSWriteToGrid(state->grid, x0+1, y0+1, doodad->logo.logo_name, strlen(doodad->logo.logo_name), 1);
            }
            break;
        }
        case XkbTextDoodad: {
            if (strchr(doodad->text.text, '\n') == NULL) {
                break;
            }
            else {
                // int offset = (leading * 8 / 10);
                int x0 = X_mm2ch(doodad->text.left);
                int y0 = Y_mm2ch(doodad->text.top);
                int x1 = X_mm2ch(doodad->text.left + doodad->text.width);
                int y1 = Y_mm2ch(doodad->text.top + doodad->text.height);
                color = UCSGetDoodadTextColor(state); 
                fitLabelOntoGrid(state->grid, x0, y0, x1, y1, color, doodad->text.text, -1, -1);
            }
            break;
        }
        case XkbIndicatorDoodad: {
            int x0 = X_mm2ch(doodad->indicator.left);
            int y0 = Y_mm2ch(doodad->indicator.top);
            color = UCSGetDoodadIndicatorColor(state); 
            UCSCharOntoCell(&GRID_CELL(state->grid, x0, y0), wantAscii ? INDICATOR_SYMBOL_ASCII : INDICATOR_SYMBOL, color);
            break;
        }
    }
    return;
}



static void
UCSSection(FILE *out, UCSState *state, XkbSectionPtr section)
{
    int r;
    float offset;
    float sectionLeft, sectionTop;
    XkbRowPtr row;
    XkbDescPtr xkb;
    

    xkb = state->xkb;
    sectionLeft = section->left;
    sectionTop = section->top;



    if (section->doodads) {
        XkbDrawablePtr first, draw;

        first = draw = XkbGetOrderedDrawables(NULL, section);
        while (draw) {
            if (draw->type == XkbDW_Section)
                UCSSection(out, state, draw->u.section);
            else
                UCSDoodad(out, state, draw->u.doodad);
            draw = draw->next;
        }
        XkbFreeOrderedDrawables(first);
    }
    for (r = 0, row = section->rows; r < section->num_rows; r++, row++) {
        int k;
        float rowLeft, rowTop;
        XkbKeyPtr key;
        XkbShapePtr shape;

        rowLeft = row->left;
        rowTop = row->top;

        offset = 0;
        for (k = 0, key = row->keys; k < row->num_keys; k++, key++) {
            float keyLeft, keyTop;
            shape = XkbKeyShape(xkb->geom, key);
            offset += row->vertical ? key->gap : key->gap;
            keyLeft = sectionLeft + rowLeft + (row->vertical ? 0 : offset);
            keyTop = sectionTop + rowTop + (row->vertical ? offset : 0);

            UCSApplyKeyOntoGrid(state, key, shape, keyLeft, keyTop); 
            offset += row->vertical ? shape->bounds.y2 : shape->bounds.x2;
        }
    }
    return;
}


Bool
GeometryAsUnicodeDiagram(FILE *out, XkbFileInfo *pResult, XKBPrintArgs *args)
{
    Cell * cells;
    Grid grid;
    XkbDrawablePtr first, draw;
    UCSState state;
    int i, w, h;


    if ((!pResult) || (!pResult->xkb) || (!pResult->xkb->geom))
        return False;
    state.xkb = pResult->xkb;
    state.dpy = pResult->xkb->dpy;
    state.geom = pResult->xkb->geom;
    state.color = state.black = state.white = -1;
    state.font = -1;
    state.nPages = 0;
    state.totalKB = 1;
    state.kbPerPage = 1;
    state.x1 = state.y1 = state.x2 = state.y2 = 0;
    state.args = args;
    state.keyLegendType = args->legendType;
    state.keyLegendLength = args->legendLength;
    state.keyLegendLevel = args->legendLevel;
    state.keyLegendGroup = args->legendGroup;
    state.baseLabelLevel = args->labelLevel;
    state.baseLabelGroup = args->baseLabelGroup;
    state.labelLevels = args->nLabelLevels;
    state.labelGroups = args->nLabelGroups;

    wantAscii = args->wantAscii;
    wantColor = args->wantColor;

    if(wantAscii){
        box_chars = box_chars_ascii;
    } else {
        box_chars = box_chars_unicode;
    }

    char_width_height = args->charRatio;
    keyboard_scale = args->keyboardCharWidth / X_mm2ch(state.geom->width_mm);

    if ((args->label == LABEL_SYMBOLS) && (pResult->xkb->ctrls)) {
        if (args->nTotalGroups == 0)
            state.totalKB =
                pResult->xkb->ctrls->num_groups / args->nLabelGroups;
        else
            state.totalKB = args->nTotalGroups;
        if (state.totalKB < 1)
            state.totalKB = 1;
        else if (state.totalKB > 1)
            state.kbPerPage = 2;
    }
    if (args->nKBPerPage != 0)
        state.kbPerPage = args->nKBPerPage;


    w = X_mm2ch(state.geom->width_mm) + 3;
    h = Y_mm2ch(state.geom->height_mm) + 3;

    cells = malloc(sizeof(Cell) * w * h);
    grid.cells = cells;
    grid.width = w;
    grid.height = h;
    state.grid = grid; 

    first = XkbGetOrderedDrawables(state.geom, NULL);

    for (draw = first; draw != NULL; draw = draw->next) {
        if ((draw->type != XkbDW_Section) &&
            ((draw->u.doodad->any.type == XkbOutlineDoodad) ||
             (draw->u.doodad->any.type == XkbSolidDoodad))) {
            char *name;

            name = XkbAtomGetString(state.dpy, draw->u.doodad->any.name);
            if ((name != NULL) && (uStrCaseEqual(name, "edges"))) {
                break;
            }
        }
    }
    for (i = 0; i < state.totalKB; i++) {
        for (draw = first; draw != NULL; draw = draw->next) {
            if (draw->type == XkbDW_Section) {
                UCSSection(out, &state, draw->u.section);
            }
            else {
                UCSDoodad(out, &state, draw->u.doodad);
            }
        }
        state.args->baseLabelGroup += state.args->nLabelGroups;
    }
    XkbFreeOrderedDrawables(first);

    UCSGridEcho(out, state.grid);
    free(cells);
    return True;
}
