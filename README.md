
# XKBPrint with plaintext diagrams

A fork of [XKBPrint](https://gitlab.freedesktop.org/xorg/app/xkbprint).

Difference to the standard xkbprint:
- Ascii- or unicode-based plaintext diagrams as output.
- When using plaintext diagrams, display up to four symbols per key-top
- When using plaintext diagrams, display unicode-compatible symbols as their respective symbols


### Plaintext diagrams

By using the `-ascii` or `-unicode` arguments, the output becomes a plaintext diagram of the keyboard geometry using `-|+` or uncode box characters, respectively. Due to the inherent problem with geometry sizes in millimeters and fixed-width terminals with rectangular unit characters, it might be necessary to fiddle with the `-width <width>` and `-cwhr <character_width_height_ratio>` arguments for the perfect result.

While the PostScript-output toggles keycodes off with `-nokc`, the equivalent argument with plaintext-output is the `-legend <type>` argument, which allows certain kinds of labels to be displayed along the outline of keys. Legal values for `<type>` are:
- `none`: No legend
- `code`: Key code (eg. `66`)
- `name`: Key name (eg. `<AE01>`)
- `type`: Key type (eg. `ONE_LEVEL`)
- `typeabbr`: Likely unique abbreviated key type (eg. `ONE_LEVEL` => `O7L`)
- `symbol`: Symbol of a certain level and group specified with `-legend-symlevel <level>` and `-legend-symgroup <group>`

Default length-limit for a legend is 4 characters, but this is adjustable with `-legend-length <length>`.

It is recommended to use the `-color` argument, with which key outlines will displayed with ANSI-style dim color, and labels with ANSI-style bright color. 

### Four symbols per key-top

`-nks <num_levels>`, where `<num_levels>` is the number of levels to display, starting at the level set by `-ll <base_level>`.

Example of `-nkl <num_levels>` for `1`, `2`, `3`, `4`, on the `AE01` key
```
┌AE01──┐ ┌AE01──┐ ┌AE01──┐ ┌AE01──┐        
│  1   │ │  !   │ │!  ¹  │ │!  ¡  │        
│      │ │  1   │ │1     │ │1  ¹  │        
└──────┘ └──────┘ └──────┘ └──────┘
```

If space is limited, the number of keys displayed will be reduced. The left side is generally prioritized before the right, and the lower side before the upper.

### Unicode-compatatible symbols

While using the `-unicode` argument, all key-top symbols will be converted to unicode, if possible. Certain symbols are not accounted for, and thus will be displayed with their names as specified in the XkbSymbols component.

While the plain-text diagrams supports full-width characters like `茶` by sacrificing whitespace, quarter or no-space characters like `dead_hook` and `dead_horn` are not accounted for.

All of X's KeySym values can be manually set to certain labels by changing the methods `UCSOverrideKeySym` and `UCSOverrideKeySymAscii` in the `uscsymbols.c` file, for `-unicode` and `-ascii` modes respectively. This can be done to add more symbols or less, depending on need. For instance, despite `⭲` being a normal character, certain editors can't display this as a monospace character, and it might need replacement if certain examples in a README-file are to look their best.

## Build

To build `xkbprint`, simply run `autogen.sh` followed by `make`.

Certain X-development packages might be required, but a couple of `apt install <package>` should fix this.

## Examples

To run `xkbprint`, you need to supply a keymap.
There are two easy ways to do this: from current display `./xkbprint :0 - -unicode -color`, or by piping in an xkm-file.

Eg. to diplay a french (`fr`) keyboard on the `pc(pc105)` geometry, simply run: 
```
setxkbmap -print -geometry "pc(pc105)" -symbols "pc+fr+inet(evdev)" | xkbcomp - - | ./xkbprint - - -unicode -color -width 214
``` 

To see the current keymap as supplied by setxkbmap, use `setxkbmap -print`

```
xkb_keymap {
	xkb_keycodes  { include "evdev+aliases(qwerty)"	};
	xkb_types     { include "complete"	};
	xkb_compat    { include "complete"	};
	xkb_symbols   { include "pc+ch+inet(evdev)"	};
	xkb_geometry  { include "pc(pc104)"	};
};
```




### `pc(pc105)`-geometry w/ `fr`-symbols (AZERTY)


```                                                       
                                                                                                                                                                           ┌─────────────────────────────────┐           
          ┌ESC──┐          ┌FK01──┐ ┌FK02─┐ ┌FK03──┐ ┌FK04──┐     ┌FK05──┐ ┌FK06─┐  ┌FK07─┐ ┌FK08──┐      ┌FK09─┐ ┌FK10──┐ ┌FK11─┐  ┌FK12─┐    ┌PRSC──┐ ┌SCLK─┐  ┌PAUS─┐   │Num        Caps       Scroll     │           
          │Escap│          │F1 F1 │ │F2 F2│ │F3 F3 │ │F4 F4 │     │F5 F5 │ │F6 F6│  │F7 F7│ │F8 F8 │      │F9 F9│ │F10F10│ │F11F1│  │F12F1│    │Sys_Re│ │Scrol│  │Break│   │Lock       Lock       Lock       │           
          │  e  │          │F1 F1 │ │F2 F2│ │F3 F3 │ │F4 F4 │     │F5 F5 │ │F6 F6│  │F7 F7│ │F8 F8 │      │F9 F9│ │F10F10│ │F11F1│  │F12F1│    │Print │ │l loc│  │Pause│   │ ●           ●           ●       │           
          └─────┘          └──────┘ └─────┘ └──────┘ └──────┘     └──────┘ └─────┘  └─────┘ └──────┘      └─────┘ └──────┘ └─────┘  └─────┘    └──────┘ └─────┘  └─────┘   └─────────────────────────────────┘           
                                                                                                                                                                                                                         
                                                                                                                                                                                                                         
                                                                                                                                                                                                                         
                                                                                                                                                                                                                         
          ┌TLDE─┐ ┌AE01──┐ ┌AE02──┐ ┌AE03─┐ ┌AE04──┐ ┌AE05──┐ ┌AE06─┐ ┌AE07──┐ ┌AE08─┐  ┌AE09─┐ ┌AE10──┐ ┌AE11─┐  ┌AE12─┐ ┌BKSP───────────┐    ┌INS───┐ ┌HOME─┐  ┌PGUP─┐    ┌NMLK──┐ ┌KPDV─┐  ┌KPMU─┐ ┌KPSU──┐           
          │~  ¬ │ │1  ¡  │ │2  ⅛  │ │3  £ │ │4   $ │ │5  ⅜  │ │6  ⅝ │ │7  ⅞  │ │8  ™ │  │9  ± │ │0  °  │ │°  ¿ │  │+  ˛ │ │      ⌫        │    │Insert│ │Home │  │PgUp │    │NumLoc│ │/  / │  │*  * │ │-   - │           
          │²  ¬ │ │&  ¹  │ │é   ~ │ │"  # │ │'   { │ │(   [ │ │-  | │ │è   ` │ │_  \ │  │ç  ^ │ │à   @ │ │)  ] │  │=  } │ │      ⌫        │    │      │ │     │  │     │    │  k   │ │/  / │  │*  * │ │-   - │           
          └─────┘ └──────┘ └──────┘ └─────┘ └──────┘ └──────┘ └─────┘ └──────┘ └─────┘  └─────┘ └──────┘ └─────┘  └─────┘ └───────────────┘    └──────┘ └─────┘  └─────┘    └──────┘ └─────┘  └─────┘ └──────┘           
          ┌TAB───────┐ ┌AD01─┐  ┌AD02─┐ ┌AD03──┐ ┌AD04─┐  ┌AD05─┐ ┌AD06──┐ ┌AD07─┐  ┌AD08─┐ ┌AD09──┐ ┌AD10─┐ ┌AD11──┐ ┌AD12──┐ ┌RTRN──────┐    ┌DELE──┐ ┌END──┐  ┌PGDN─┐    ┌KP7───┐ ┌KP8──┐  ┌KP9──┐ ┌KPAD──┐           
          │Left Tab  │ │A  Æ │  │Z  < │ │E  ¢  │ │R  ® │  │T  Ŧ │ │Y  ¥  │ │U  ↑ │  │I  ı │ │O  Ø  │ │P  Þ │ │¨  °  │ │£  ¯  │ │          │    │Delete│ │ End │  │PgDn │    │  7   │ │  8  │  │  9  │ │+   + │           
          │   Tab    │ │a  æ │  │z  « │ │e  Eur│ │r  ¶ │  │t  ŧ │ │y  ←  │ │u  ↓ │  │i  → │ │o  ø  │ │p  þ │ │^  ¨  │ │$  ¤  │ │   ↵      │    │      │ │     │  │     │    │Home  │ │ ⯅   │  │Pg Up│ │      │           
          └──────────┘ └─────┘  └─────┘ └──────┘ └─────┘  └─────┘ └──────┘ └─────┘  └─────┘ └──────┘ └─────┘ └──────┘ └──────┘ └─┐        │    └──────┘ └─────┘  └─────┘    └──────┘ └─────┘  └─────┘ │      │           
          ┌CAPS────────┐ ┌AC01──┐ ┌AC02─┐  ┌AC03─┐ ┌AC04──┐ ┌AC05─┐  ┌AC06─┐ ┌AC07──┐ ┌AC08─┐  ┌AC09─┐ ┌AC10─┐  ┌AC11─┐  ┌BKSL─┐ │        │                                 ┌KP4───┐ ┌KP5──┐  ┌KP6──┐ │      │           
          │ CapsLock   │ │Q  Ω  │ │S  § │  │D  Ð │ │F  ª  │ │G  Ŋ │  │H  Ħ │ │J  dea│ │K  & │  │L  Ł │ │M  º │  │%  ˇ │  │µ  ˘ │ │        │                                 │  4   │ │  5  │  │  6  │ │      │           
          │            │ │q   @ │ │s  ß │  │d  ð │ │f  đ  │ │g  ŋ │  │h  ħ │ │j  dea│ │k  ĸ │  │l  ł │ │m  µ │  │ù  ^ │  │*  ` │ │        │                                 │ ⯇    │ │Begin│  │ ⯈   │ │+   + │           
          └────────────┘ └──────┘ └─────┘  └─────┘ └──────┘ └─────┘  └─────┘ └──────┘ └─────┘  └─────┘ └─────┘  └─────┘  └─────┘ └────────┘                                 └──────┘ └─────┘  └─────┘ └──────┘           
          ┌LFSH────┐  ┌LSGT─┐ ┌AB01──┐ ┌AB02─┐  ┌AB03─┐ ┌AB04──┐ ┌AB05─┐  ┌AB06─┐ ┌AB07──┐ ┌AB08─┐  ┌AB09─┐ ┌AB10──┐ ┌RTSH────────────────┐             ┌UP───┐             ┌KP1───┐ ┌KP2──┐  ┌KP3──┐ ┌KPEN──┐           
          │ Shift  │  │>  ¦ │ │W  Ł  │ │X  > │  │C  © │ │V  ‘  │ │B  ’ │  │N  N │ │?  ˝  │ │.  × │  │/  ÷ │ │§  ˙  │ │       Shift        │             │ ↑   │             │  1   │ │  2  │  │  3  │ │      │           
          │        │  │<  | │ │w  ł  │ │x  » │  │c  ¢ │ │v  “  │ │b  ” │  │n  n │ │,  ´  │ │;  ─ │  │:  · │ │!  dea│ │                    │             │     │             │ End  │ │ ⯆   │  │Pg Dn│ │Enter │           
          └────────┘  └─────┘ └──────┘ └─────┘  └─────┘ └──────┘ └─────┘  └─────┘ └──────┘ └─────┘  └─────┘ └──────┘ └────────────────────┘             └─────┘             └──────┘ └─────┘  └─────┘ │      │           
          ┌LCTL─────┐  ┌LWIN───┐  ┌LALT───┐ ┌SPCE─────────────────────────────────────────────┐ ┌RALT────┐ ┌RWIN────┐ ┌MENU────┐ ┌RCTL────┐    ┌LEFT──┐ ┌DOWN─┐  ┌RGHT─┐    ┌KP0───────────┐  ┌KPDL─┐ │      │           
          │  Ctrl   │  │SuperL │  │ MetaL │ │                       ⎵                         │ │Alt Gr  │ │SuperR  │ │ Menu   │ │ Ctrl   │    │ ←    │ │ ↓   │  │ →   │    │      0       │  │KP_De│ │      │           
          │         │  │       │  │  Alt  │ │                                                 │ │        │ │        │ │        │ │        │    │      │ │     │  │     │    │   Insert     │  │Delet│ │      │           
          └─────────┘  └───────┘  └───────┘ └─────────────────────────────────────────────────┘ └────────┘ └────────┘ └────────┘ └────────┘    └──────┘ └─────┘  └─────┘    └──────────────┘  └─────┘ └──────┘           
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   

```


### `pc(pc86)`-geometry w/ `us(mac)`-symbols (QWERTY)


```
┌───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐  
│                                                                                                                                                                                   │  
│                                                                                                                                   ┌───────Num───────Caps──────Scroll──────────────┤  
│                                                                                                                                   │    ●  Lock   ●  Lock   ●  Lock                │  
│                                                                                                                                   └───────────────────────────────────────────────┤  
│                                                                                                                                                                                   │  
│   ┌─┬ESC───┬──┬FK01──┬──┬FK02──┬──┬FK03──┬──┬FK04──┬──┬FK05──┬──┬FK06──┬──┬FK07──┬──┬FK08──┬──┬FK09──┬──┬FK10──┬──┬FK11──┬──┬FK12──┬──┬NMLK──┬──┬PRSC──┬──┬SCLK──┬──┬PAUS──┬┐     │  
│   │ │Escape│  │F1 F1 │  │F2 F2 │  │F3 F3 │  │F4 F4 │  │F5 F5 │  │F6 F6 │  │F7 F7 │  │F8 F8 │  │F9 F9 │  │F10F10│  │F11F11│  │F12F12│  │NumLoc│  │Sys_Re│  │Scroll│  │Break ││     │  
│   │ │      │  │F1 F1 │  │F2 F2 │  │F3 F3 │  │F4 F4 │  │F5 F5 │  │F6 F6 │  │F7 F7 │  │F8 F8 │  │F9 F9 │  │F10F10│  │F11F11│  │F12F12│  │  k   │  │Print │  │ lock │  │Pause ││     │  
│   │ └──────┘  └──────┘  └──────┘  └──────┘  └──────┘  └──────┘  └──────┘  └──────┘  └──────┘  └──────┘  └──────┘  └──────┘  └──────┘  └──────┘  └──────┘  └──────┘  └──────┘│     │  
│   │  ┌AE01───────┐ ┌AE02───┐   ┌AE03───┐   ┌AE04───┐   ┌AE05───┐   ┌AE06──┐    ┌AE07──┐    ┌AE08──┐    ┌AE09──┐    ┌AE10──┐    ┌AE11──┐   ┌AE12───┐    ┌BKSP─────┐   ┌HOME─┐│     │  
│   │  │!      ⁄   │ │@   Eur│   │#   ‹  │   │$   ›  │   │%   ﬁ  │   │^  ﬂ  │    │&  ‡  │    │*  °  │    │(  ·  │    │)  ‚  │    │_  —  │   │+   ±  │    │   ⌫     │   │Home ││     │  
│   │  │           │ │    ™  │   │    £  │   │    ¢  │   │    ∞  │   │   §  │    │   ¶  │    │   •  │    │   ª  │    │   º  │    │   –  │   │    ≠  │    │         │   │     ││     │  
│   │  │           │ │2      │   │3      │   │4      │   │5      │   │6     │    │7     │    │8     │    │9     │    │0     │    │-     │   │=      │    │   ⌫     │   │     ││     │  
│   │  │1       ¡  │ └───────┘   └───────┘   └───────┘   └───────┘   └──────┘    └──────┘    └──────┘    └──────┘    └──────┘    └──────┘   └───────┘    └─────────┘   └─────┘│     │  
│   │ ┌TAB──┬───┬AD01──┐   ┌AD02───┐    ┌AD03──┐   ┌AD04───┐   ┌AD05───┐   ┌AD06───┐   ┌AD07───┐   ┌AD08───┐   ┌AD09──┐    ┌AD10───┐   ┌AD11──┐    ┌AD12───┐  ┌AD13─┐  ┌PGUP─┐│     │  
│   │ │Left │   │Q  OE │   │W   „  │    │E  ´  │   │R   ‰  │   │T   ˇ  │   │Y   ¼  │   │U   ¨  │   │I   ˆ  │   │O  Ø  │    │P   ∏  │   │{  ”  │    │}   ’  │  │     │  │PgUp ││     │  
│   │ │ Tab │   │   oe │   │    ∑  │    │   ´  │   │    ®  │   │    †  │   │    ¥  │   │    ¨  │   │       │   │   ø  │    │    π  │   │   “  │    │    ‘  │  │     │  │     ││     │  
│   │ │ Tab │   │q     │   │w      │    │e     │   │r      │   │t      │   │y      │   │u      │   │i    ^ │   │o     │    │p      │   │[     │    │]      │  │     │  │     ││     │  
│   │ └─────┘   └──────┘   └───────┘    └──────┘   └───────┘   └───────┘   └───────┘   └───────┘   └───────┘   └──────┘    └───────┘   └──────┘    └───────┘  └─────┘  └─────┘│     │  
│   │                                                                                                                                                                         │     │  
│   │  ┌CAPS──┐    ┌AC01──┐    ┌AC02──┐    ┌AC03──┐   ┌AC04───┐    ┌AC05──┐   ┌AC06───┐    ┌AC07──┐   ┌AC08───┐   ┌AC09───┐   ┌AC10───┐   ┌AC11───┐   ┌RTRN────────┐   ┌PGDN─┐│     │  
│   │  │CapsLo│    │A  Å  │    │S  dea│    │D  ð  │   │F   dea│    │G  ˝  │   │H   dea│    │J  ½  │   │K     │   │L   Þ  │   │:   þ  │   │"   Æ  │   │            │   │PgDn ││     │  
│   │  │ ck   │    │   å  │    │   ß  │    │   ∂  │   │    ƒ  │    │   ©  │   │    ˙  │    │   ∆  │   │    °  │   │    ¬  │   │    …  │   │    æ  │   │    ↵       │   │     ││     │  
│   │  │      │    │a     │    │s     │    │d     │   │f      │    │g     │   │h      │    │j     │   │k      │   │l      │   │;      │   │'      │   │            │   │     ││     │  
│   │  └──────┘    └──────┘    └──────┘    └──────┘   └───────┘    └──────┘   └───────┘    └──────┘   └───────┘   └───────┘   └───────┘   └───────┘   └────────────┘   └─────┘│     │  
│   │  ┌LFSH────────┐   ┌AB01───┐   ┌AB02───┐   ┌AB03───┐   ┌AB04───┐   ┌AB05───┐   ┌AB06───┐   ┌AB07───┐   ┌AB08──┐    ┌AB09──┐    ┌AB10──┐    ┌RTSH──────┐  ┌UP───┐  ┌END──┐│     │  
│   │  │            │   │Z   ¸  │   │X   ˛  │   │C   Ç  │   │V   ◊  │   │B   ı  │   │N   ˜  │   │M   ¾  │   │<  ¯  │    │>  ˘  │    │?  ¿  │    │          │  │     │  │     ││     │  
│   │  │   Shift    │   │       │   │       │   │       │   │       │   │       │   │       │   │       │   │      │    │      │    │      │    │  Shift   │  │ ↑   │  │ End ││     │  
│   │  │            │   │    Ω  │   │    ≈  │   │    ç  │   │    √  │   │    ∫  │   │       │   │    µ  │   │   ≤  │    │   ≥  │    │   ÷  │    │          │  │     │  │     ││     │  
│   │  │            │   │z      │   │x      │   │c      │   │v      │   │b      │   │n    ~ │   │m      │   │,     │    │.     │    │/     │    │          │  │     │  │     ││     │  
│   │  └────────────┘   └───────┘   └───────┘   └───────┘   └───────┘   └───────┘   └───────┘   └───────┘   └──────┘    └──────┘    └──────┘    └──────────┘  └─────┘  └─────┘│     │  
│   │  ┌LCTL──┐    ┌FN────┐    ┌LALT──┐    ┌AE00──┐   ┌LSGT───┐    ┌SPCE──────────────────────────────────────┐   ┌RALT───┐   ┌INS────┐   ┌DELE───┐  ┌LEFT─┐  ┌DOWN─┐  ┌RGHT─┐│     │  
│   │  │      │    │      │    │MetaL │    │      │   │±   ±  │    │                                          │   │Alt Gr │   │Insert │   │Delete │  │     │  │     │  │     ││     │  
│   │  │Ctrl  │    │      │    │      │    │      │   │    §  │    │                   ⎵                      │   │       │   │       │   │       │  │ ←   │  │ ↓   │  │ →   ││     │  
│   │  │      │    │      │    │ Alt  │    │      │   │§      │    │                                          │   │       │   │       │   │       │  │     │  │     │  │     ││     │  
│   │  └──────┘    └──────┘    └──────┘    └──────┘   └───────┘    └──────────────────────────────────────────┘   └───────┘   └───────┘   └───────┘  └─────┘  └─────┘  └─────┘│     │  
│   │                                                                                                                                                                         │     │  
│   └─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘     │  
│                                                                                                                                                                                   │  
│                                                                                                                                                                                   │  
└───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘  
                                                                                                                                                                                       
```

### `teck`-geometry w/ `us(dvorak)`-symbols (DVORAK)

Certain geometries will have more problems than others. For instance, the `teck` and `kinesis` geometries utilizes rotations, which are ignored when displaying the plaintext diagrams.

```
        ┌ESC──┐  ┌FK01─┐ ┌FK02─┐ ┌FK03─┐ ┌FK04─┐  ┌FK05─┐ ┌FK06─┐ ┌FK07─┐ ┌FK08─┐  ┌FK09─┐ ┌FK10─┐ ┌FK11─┐ ┌FK12─┐  ┌DELE─┐          
        │Escap│  │F1 F1│ │F2 F2│ │F3 F3│ │F4 F4│  │F5 F5│ │F6 F6│ │F7 F7│ │F8 F8│  │F9 F9│ │F10F1│ │F11F1│ │F12F1│  │Delet│          
        │  e  │  │F1 F1│ │F2 F2│ │F3 F3│ │F4 F4│  │F5 F5│ │F6 F6│ │F7 F7│ │F8 F8│  │F9 F9│ │F10F1│ │F11F1│ │F12F1│  │  e  │          
        └─────┘  └─────┘ └─────┘ └─────┘ └─────┘  └─────┘ └─────┘ └─────┘ └─────┘  └─────┘ └─────┘ └─────┘ └─────┘  └─────┘          
                                                      ┌CAPS─┐ ┌FN───┐ ┌NMLK─┐                                                        
                                                      │CapsL│ │     │ │NumLo│                                                        
     ┌TAB───┐┌TLDE──┐┌AE01──┐┌AE02─┐ ┌AE03─┐ ┌AE04─┐ ┌AE05k┐│ │     │ │ ck  │                                                        
     │Left T││~   ~ ││  !   ││  @  │ │  #  │ │  $  │ │└─%──┼┘ └─────┘ └─────┘                                                        
     │ Tab  ││`   ` ││  1   ││  2  │ │  3  │ │  4  │ │  5  │                                                                         
     └──────┘└──────┘└──────┘└─────┘ └─────┘ └─────┘ └─────┘ ╶RSUP──┐ ┌AE06─┐ ┌AE07─┐ ┌AE08─┐ ┌AE09─┐ ┌AE10─┐ ┌AE12─┐ ┌RBSP─┐        
     ┌AD11─┐ ┌AD12─┐ ┌AD01─┐┌AD02─┐ ┌AD03─┐ ┌AD04─┐ ┌AD05─┐ ╷       │ │^  ^ │ │  &  │ │  *  │ │(  ` │ │  )  │ │}  ~ │ │     │        
     │  ?  │ │  +  │ │"  ¨ ││<  ˇ │ │>  · │ │  P  │ │  Y  │ │       ╵ │6  ^ │ │  7  │ │  8  │ │9    │ │  0  │ │]    │ │     │        
     │  /  │ │  =  │ │'  ´ ││,  ¸ │ │.  ˙ │ │  p  │ │  y  │ └────────╴└─────┘ └─────┘ └─────┘ └─────┘ └─────┘ └─────┘ └─────┘        
     └─────┘ └─────┘ └─────┘└─────┘ └─────┘ └─────┘ └─────┘ ╶DELE────┐ ┌AD06─┐ ┌AD07─┐ ┌AD08─┐ ┌AD09─┐ ┌AD10─┐ ┌AC11─┐ ┌BKSL─┐       
     ┌LCTL─────────┐ ┌AC01─┐┌AC02─┐ ┌AC03─┐ ┌AC04─┐ ┌AC05─┐╷ Del     │ │  F  │ │  G  │ │  C  │ │  R  │ │  L  │ │  _  │ │  |  │       
     │    Ctrl     │ │  A  ││  O  │ │  E  │ │  U  │ │  I  ││ ete     ╵ │  f  │ │  g  │ │  c  │ │  r  │ │  l  │ │  -  │ │  \  │       
     │             │ │  a  ││  o  │ │  e  │ │  u  │ │  i  │└──────────╴└─────┘ └─────┘ └─────┘ └─────┘ └─────┘ └─────┘ └─────┘       
     └─────────────┘ └─────┘└─────┘ └─────┘ └─────┘ └─────┘╶AE11──────┐┌AC06─┐ ┌AC07─┐ ┌AC08─┐ ┌AC09─┐ ┌AC10─┐ ┌RCTL─────────┐       
   ┌LFSH─────────┐ ┌AB01─┐ ┌AB02─┐┌AB03──┐┌AB04──┐┌AB05─┐ ╷  {        ││  D  │ │  H  │ │  T  │ │  N  │ │  S  │ │    Ctrl     │       
   │    Shift    │ │:  ˝ │ │  Q  ││  J   ││  K   ││  X  │ │           ╵│  d  │ │  h  │ │  t  │ │  n  │ │  s  │ │             │       
   │             │ │;  ˛ │ │  q  ││  j   ││  k   ││  x  │ └BKSP────────┼─┬AB06─┼─┬AB07─┼─┬AB08─┼─┬AB09─┼┬AB10┴─┼┬RTSH────────┴┐      
   └─────────────┘ └─────┘ └─────┘└──────┘└──────┘└─────┘╷  ⌫          │ │  B  │ │  M  │ │  W  │ │  V  ││  Z   ││    Shift    │      
  ┌LALT─────────┐         ┌PGUP─┐         ┌SPCE─────────┐│             │ │  b  │ │  m  │ │  w  │ │  v  ││  z   ││             │      
  │    MetaL    │         │PgUp │         │     ⎵       │└──⌫──╴ ╶─────┘ └─────┘ └─────┘ └─────┘ ├UP───┴┼──────┘└─────────────┘      
  │     Alt     │ ┌HOME─┐ │     │ ┌END──┐ │             │╶RTRN─────────┐  ┌SPCE─────────┐        │      │        ┌RALT─────────┐     
  └─────────────┘ │Home │ └─────┘ │ End │ └─────────────┤              │  │     ⎵       │ ┌LEFT─┐│ ↑    │┌RGHT─┐ │    MetaR    │     
                  │     │ ┌PGDN─┐ │     │               │  ↵           ╵  │             │ │ ←   ││      ││ →   │ │     Alt     │     
                  └─────┘ │PgDn │ └─────┘               └──────╴ ╶──────╴ └─────────────┘ │     │├DOWN──┤│     │ └─────────────┘     
                          │     │                                                         └─────┘│ ↓    │└─────┘                     
                          └─────┘                                                                │      │                            
                                                                                                 └──────┘                            
                                                                                                            
```


### ASCII based plaintext diagram

Displaying the diagram with ascii-symbols exposes some of the problems with overcrowded keys. Due to space limitations, symbol names will be cut off, and due to a very simple division of key tops, certain names will be cut off more than strictly necessary.

```
+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+   
|                                                                                                                                                                                                      |   
|                                                                                                                                                                                                      |   
|                                                                                                                                                                                                      |   
|  +-+9------------+-+67----*-+-+68-----+-+69------+-+70---*-+-+71------+-+72-----+-+73------+-+74-----+-+75------+-+76------++95------+-+96-----+-+110-----+-+115----+-+118-----+-+119----------+-+   |   
|  | |   Escape    | |F1   F1 | |F2  F2 | |F3   F3 | |F4  F4 | |F5   F5 | |F6  F6 | |F7   F7 | |F8  F8 | |F9   F9 | |F10 F10 ||F11 F11 | |F12 F12| | Home   | |  End  | |Insert  | |   Delete    | |   |   
|  | |             | |F1   F1 | |F2  F2 | |F3   F3 | |F4  F4 | |F5   F5 | |F6  F6 | |F7   F7 | |F8  F8 | |F9   F9 | |F10 F10 ||F11 F11 | |F12 F12| |        | |       | |        | |             | |   |   
|  | +-------------+ +--------+ +-------+ +--------+ +-------+ +--------+ +-------+ +--------+ +-------+ +--------+ +--------++--------+ +-------+ +--------+ +-------+ +--------+ +-------------+ |   |   
|  | +49-------+  +10-------+ +11-------+  +12-------+  +13-------+  +14-------+  +15-------+  +16------+  +17-------+  +18-------+  +19-------+  +20-------+ +21-------+  +22--------------------+|   |   
|  | ||    para|  |!    ones| |"    twos|  |#    thre|  |$      $ |  |%    cent|  |&    five|  |/     \ |  |(      { |  |)      } |  |=    U226|  |?    ques| |`    nots|  |      Backspace       ||   |   
|  | |     brok|  |     excl| |         |  |     ster|  |     curr|  |     oneh|  |         |  |        |  |         |  |         |  |     degr|  |     plus| |         |  |                      ||   |   
|  | |     enba|  |     amdo| |         |  |     ling|  |     ency|  |     alf |  |     yen |  |        |  |         |  |         |  |      ee |  |     minu| |     acut|  |                      ||   |   
|  | |'      r |  |1     wn | |2      @ |  |3        |  |4        |  |5        |  |6        |  |7     | |  |8      [ |  |9      ] |  |0        |  |+      s | |\      e |  |      Backspace       ||   |   
|  | +---------+  +---------+ +---------+  +---------+  +---------+  +---------+  +---------+  +--------+  +---------+  +---------+  +---------+  +---------+ +---------+  +----------------------+|   |   
|  |                                                                                                                                                                                               |   |   
|  | +23-------------+  +24------+   +25------+  +26-------+  +27-------+  +28-------+  +29------+  +30-------+  +31-------+  +32-------+  +33-------+  +34-------+ +35-------+  +36--------------+|   |   
|  | |   Left Tab    |  |Q   U220|   |W   U222|  |E    U221|  |R    U229|  |T    U229|  |Y   Gree|  |U    U229|  |I    U229|  |O    Gree|  |P    Gree|  |  Aring  | |^      ^ |  |                ||   |   
|  | |               |  |    part|   |    Gree|  |     Gree|  |     Gree|  |     Gree|  |    Gree|  |     Gree|  |     Gree|  |     Gree|  |     Gree|  |         | |         |  |     Enter      ||   |   
|  | |               |  |    diff|   |    k_et|  |     k_ep|  |     k_rh|  |     k_ta|  |    k_th|  |     k_up|  |     k_io|  |     k_om|  |     k_pi|  |         | |         |  |                ||   |   
|  | |      Tab      |  |q   eren|   |w     a |  |e    silo|  |r      o |  |t      u |  |y   eta |  |u    silo|  |i     ta |  |o    ega |  |p        |  |  aring  | |~      ~ |  |                ||   |   
|  | +---------------+  +--------+   +--------+  +---------+  +---------+  +---------+  +--------+  +---------+  +---------+  +---------+  +---------+  +---------+ +---------+  +--+             ||   |   
|  | +66----------------+ +38-------+  +39-------+  +40-------+  +41------+  +42-------+  +43-------+  +44-------+  +45-------+  +46------+  +47-------+  +48-------+  +0--------+  |             ||   |   
|  | |                  | |A    U213|  |S    Gree|  |D    Gree|  |F   Gree|  |G    Gree|  |H    Hstr|  |    J    |  |K      K |  |L   Gree|  |Oslas  ^ |  |AE   Arin|  |*    doub|  |             ||   |   
|  | |     Alt Gr       | |     Gree|  |     Gree|  |     Gree|  |    Gree|  |     Gree|  |     hstr|  |         |  |     Gree|  |    Gree|  |         |  |         |  |         |  |             ||   |   
|  | |                  | |     k_al|  |     k_si|  |     k_de|  |    k_ph|  |     k_ga|  |     oke |  |         |  |     k_ka|  |    k_la|  |oslascare|  |     arin|  |         |  |             ||   |   
|  | |*                 | |a    pha |  |s    gma |  |d    lta |  |f     i |  |g    mma++--+h        |  |    j    |  |k    ppa |  |l   mda |  |h      t |  |ae     g |  |'      @ |  |             ||   |   
|  | +------------------+ +---------+  +---------+  +---------+  +--------+  +--------++  ++--------+  +---------+  +---------+  +--------+  +---------+  +---------+  +---------+  +-------------+|   |   
|  | +50-----------+  +94------+  +52-------+  +53-------+  +54-------+  +55-------+  |56--+----+ +57-------+  +58-------+  +59-------+  +60-------+  +61-------+ +62----------------------------+ |   |   
|  | |             |  |>   U226|  |Z    Gree|  |X    Gree|  |C      C |  |V    left|  |B    Gree| |N      N |  |M      M |  |;    mult|  |:    peri|  |_      ~ | |                              | |   |   
|  | |    Shift    |  |        |  |     Gree|  |     Gree|  |     Gree|  |     left|  |     Gree| |     Gree|  |     Gree|  |     divi|  |     elli|  |         | |            Shift             | |   |   
|  | |             |  |    U226|  |     k_ps|  |     k_xi|  |     k_ch|  |     doub|  |     k_be| |     k_nu|  |     k_mu|  |     sion|  |     psis|  |         | |                              | |   |   
|  | |             |  |<     4 |  |z      i |  |x        |  |c      i |  |v    lequ|  |b     ta | |n        |  |m        |  |,        |  |.        |  |-      ~ | |                              | |   |   
|  | +-------------+  +--------+  +---------+  +---------+  +---------+  +---------+  +---------+ +---------+  +---------+  +---------+  +---------+  +---------+ +------------------------------+ |   |   
|  | +0------*-+ +37------------+ +134------+  +64-------+  +65----------------------------------------------------------+  +108------+  +107------+  +105------+ +112-----+ +111-----+  +117-----+|   |   
|  | |         | |              | |         |  |  MetaL  |  |Space                                                 Space |  |         |  | Sys_Req |  |         | | PgUp   | |  Up    |  | PgDn   ||   |   
|  | |         | |    Ctrl      | | SuperR  |  |         |  |                                                            |  | Alt Gr  |  |         |  |  Ctrl   | |        | |        |  |        ||   |   
|  | |         | |              | |         |  |         |  |                                                            |  |         |  |         |  |         | |113-----+ |116-----+  |114-----+|   |   
|  | |         | |              | |         |  |   Alt   |  |Space                                                 Space |  |         |  |  Print  |  |         | | Left   | | Down   |  | Right  ||   |   
|  | +---------+ +--------------+ +---------+  +---------+  +------------------------------------------------------------+  +---------+  +---------+  +---------+ |        | |        |  |        ||   |   
|  +------------------------------------------------------+ +------------------------------+-----------------------------++-------------------------------------+ +--------+ +--------+  +--------+|   |   
|                                                         | |                       +------+------                       ||                                     +----------------------------------+   |   
|                                                         | |                       |           |                        ||                                                                            |   
|                                                         | |                                   |                        ||                                                                            |   
|                                                         | |                                  |                         ||                                                                            |   
|                                                         +-+----------------------------------+-------------------------++                                                                            |   
|                                                                                                                                                                                                      |   
|                                                                                                                                                                                                      |   
|                                                                                                                                                                                                      |   
|                                                                                                                                                                                                      |   
+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+ 
```

## Future?

- Better support for dead characters
- Better division of space for key tops, based on symbol lengths.
- Support for groups.
- Color from geometry
- Optional color based on key (eg. every `FOUR_LEVEL_SEMIALPHABETIC` key is green)
- Modifier simulation (eg. `-mod shift+meta` displays symbols based on key type modifier configuration)
- Easier extension and/or overriding of non-standard symbols and X KeySyms.
- Four symbols in PostScript
- Unicode in PostScript
- Output in SVG

## Original Readme:

>> 
>> xkbprint generates a printable or encapsulated PostScript description
>> of an XKB keyboard description.
>> 
>> All questions regarding this software should be directed at the
>> Xorg mailing list:
>> 
>>   https://lists.x.org/mailman/listinfo/xorg
>> 
>> The master development code repository can be found at:
>> 
>>   https://gitlab.freedesktop.org/xorg/app/xkbprint
>> 
>> Please submit bug reports and requests to merge patches there.
>> 
>> For patch submission instructions, see:
>> 
>>   https://www.x.org/wiki/Development/Documentation/SubmittingPatches
