/***********************************************************
* Based on the information in <X11/keysymdef.h>
**/

#include <ctype.h>
#include <stdio.h>
#include "ucssymbols.h"



// From <X11/extensions/XKBfile.h>
#define	_XkbKSLower	(1<<0)
#define	_XkbKSUpper	(1<<1)
#define	XkbKSIsLower(k)		(_XkbKSCheckCase(k)&_XkbKSLower)
#define	XkbKSIsUpper(k)		(_XkbKSCheckCase(k)&_XkbKSUpper)
#define XkbKSIsKeypad(k)	(((k)>=XK_KP_Space)&&((k)<=XK_KP_Equal))
#define	XkbKSIsDeadKey(k)	\
		(((k)>=XK_dead_grave)&&((k)<=XK_dead_semivoiced_sound))

int
XKeysymToUCSValue(KeySym sym){
    int byte3 = (sym >> 8);
    if(sym > 0x1000000){
        // TODO: Verify that directly translateable to unicode iff sym > 0x1000000;
        return sym - 0x1000000;
    }

/*
* Latin 1
* (ISO/IEC 8859-1 = Unicode U+0020..U+00FF)
* Byte 3 = 0
*/
#ifdef XK_LATIN1
    else if(byte3 == 0){
        return sym;
    } 
#endif /* XK_LATIN1 */

/*
* Latin 2
* Byte 3 = 1
*/
#ifdef XK_LATIN2
    else if(byte3 == 1){
        switch(sym){
        case XK_Aogonek: return UCS_Aogonek;
        case XK_breve: return UCS_breve;
        case XK_Lstroke: return UCS_Lstroke;
        case XK_Lcaron: return UCS_Lcaron;
        case XK_Sacute: return UCS_Sacute;
        case XK_Scaron: return UCS_Scaron;
        case XK_Scedilla: return UCS_Scedilla;
        case XK_Tcaron: return UCS_Tcaron;
        case XK_Zacute: return UCS_Zacute;
        case XK_Zcaron: return UCS_Zcaron;
        case XK_Zabovedot: return UCS_Zabovedot;
        case XK_aogonek: return UCS_aogonek;
        case XK_ogonek: return UCS_ogonek;
        case XK_lstroke: return UCS_lstroke;
        case XK_lcaron: return UCS_lcaron;
        case XK_sacute: return UCS_sacute;
        case XK_caron: return UCS_caron;
        case XK_scaron: return UCS_scaron;
        case XK_scedilla: return UCS_scedilla;
        case XK_tcaron: return UCS_tcaron;
        case XK_zacute: return UCS_zacute;
        case XK_doubleacute: return UCS_doubleacute;
        case XK_zcaron: return UCS_zcaron;
        case XK_zabovedot: return UCS_zabovedot;
        case XK_Racute: return UCS_Racute;
        case XK_Abreve: return UCS_Abreve;
        case XK_Lacute: return UCS_Lacute;
        case XK_Cacute: return UCS_Cacute;
        case XK_Ccaron: return UCS_Ccaron;
        case XK_Eogonek: return UCS_Eogonek;
        case XK_Ecaron: return UCS_Ecaron;
        case XK_Dcaron: return UCS_Dcaron;
        case XK_Dstroke: return UCS_Dstroke;
        case XK_Nacute: return UCS_Nacute;
        case XK_Ncaron: return UCS_Ncaron;
        case XK_Odoubleacute: return UCS_Odoubleacute;
        case XK_Rcaron: return UCS_Rcaron;
        case XK_Uring: return UCS_Uring;
        case XK_Udoubleacute: return UCS_Udoubleacute;
        case XK_Tcedilla: return UCS_Tcedilla;
        case XK_racute: return UCS_racute;
        case XK_abreve: return UCS_abreve;
        case XK_lacute: return UCS_lacute;
        case XK_cacute: return UCS_cacute;
        case XK_ccaron: return UCS_ccaron;
        case XK_eogonek: return UCS_eogonek;
        case XK_ecaron: return UCS_ecaron;
        case XK_dcaron: return UCS_dcaron;
        case XK_dstroke: return UCS_dstroke;
        case XK_nacute: return UCS_nacute;
        case XK_ncaron: return UCS_ncaron;
        case XK_odoubleacute: return UCS_odoubleacute;
        case XK_rcaron: return UCS_rcaron;
        case XK_uring: return UCS_uring;
        case XK_udoubleacute: return UCS_udoubleacute;
        case XK_tcedilla: return UCS_tcedilla;
        case XK_abovedot: return UCS_abovedot;
        }
    }
#endif /* XK_LATIN2 */

/*
* Latin 3
* Byte 3 = 2
*/
#ifdef XK_LATIN3
    if(byte3 == 2){
        switch(sym){
        case XK_Hstroke: return UCS_Hstroke;
        case XK_Hcircumflex: return UCS_Hcircumflex;
        case XK_Iabovedot: return UCS_Iabovedot;
        case XK_Gbreve: return UCS_Gbreve;
        case XK_Jcircumflex: return UCS_Jcircumflex;
        case XK_hstroke: return UCS_hstroke;
        case XK_hcircumflex: return UCS_hcircumflex;
        case XK_idotless: return UCS_idotless;
        case XK_gbreve: return UCS_gbreve;
        case XK_jcircumflex: return UCS_jcircumflex;
        case XK_Cabovedot: return UCS_Cabovedot;
        case XK_Ccircumflex: return UCS_Ccircumflex;
        case XK_Gabovedot: return UCS_Gabovedot;
        case XK_Gcircumflex: return UCS_Gcircumflex;
        case XK_Ubreve: return UCS_Ubreve;
        case XK_Scircumflex: return UCS_Scircumflex;
        case XK_cabovedot: return UCS_cabovedot;
        case XK_ccircumflex: return UCS_ccircumflex;
        case XK_gabovedot: return UCS_gabovedot;
        case XK_gcircumflex: return UCS_gcircumflex;
        case XK_ubreve: return UCS_ubreve;
        case XK_scircumflex: return UCS_scircumflex;
        }
    }
#endif /* XK_LATIN3 */

/*
* Latin 4
* Byte 3 = 3
*/
#ifdef XK_LATIN4
    if(byte3 == 3){
        switch(sym){
        case XK_kra: return UCS_kra;
        case XK_Rcedilla: return UCS_Rcedilla;
        case XK_Itilde: return UCS_Itilde;
        case XK_Lcedilla: return UCS_Lcedilla;
        case XK_Emacron: return UCS_Emacron;
        case XK_Gcedilla: return UCS_Gcedilla;
        case XK_Tslash: return UCS_Tslash;
        case XK_rcedilla: return UCS_rcedilla;
        case XK_itilde: return UCS_itilde;
        case XK_lcedilla: return UCS_lcedilla;
        case XK_emacron: return UCS_emacron;
        case XK_gcedilla: return UCS_gcedilla;
        case XK_tslash: return UCS_tslash;
        case XK_ENG: return UCS_ENG;
        case XK_eng: return UCS_eng;
        case XK_Amacron: return UCS_Amacron;
        case XK_Iogonek: return UCS_Iogonek;
        case XK_Eabovedot: return UCS_Eabovedot;
        case XK_Imacron: return UCS_Imacron;
        case XK_Ncedilla: return UCS_Ncedilla;
        case XK_Omacron: return UCS_Omacron;
        case XK_Kcedilla: return UCS_Kcedilla;
        case XK_Uogonek: return UCS_Uogonek;
        case XK_Utilde: return UCS_Utilde;
        case XK_Umacron: return UCS_Umacron;
        case XK_amacron: return UCS_amacron;
        case XK_iogonek: return UCS_iogonek;
        case XK_eabovedot: return UCS_eabovedot;
        case XK_imacron: return UCS_imacron;
        case XK_ncedilla: return UCS_ncedilla;
        case XK_omacron: return UCS_omacron;
        case XK_kcedilla: return UCS_kcedilla;
        case XK_uogonek: return UCS_uogonek;
        case XK_utilde: return UCS_utilde;
        case XK_umacron: return UCS_umacron;
        }
    }
#endif /* XK_LATIN4 */

/*
 * Latin 8
 */
#ifdef XK_LATIN8
    switch(sym){
    case XK_Wcircumflex: return UCS_Wcircumflex;
    case XK_wcircumflex: return UCS_wcircumflex;
    case XK_Ycircumflex: return UCS_Ycircumflex;
    case XK_ycircumflex: return UCS_ycircumflex;
    case XK_Babovedot: return UCS_Babovedot;
    case XK_babovedot: return UCS_babovedot;
    case XK_Dabovedot: return UCS_Dabovedot;
    case XK_dabovedot: return UCS_dabovedot;
    case XK_Fabovedot: return UCS_Fabovedot;
    case XK_fabovedot: return UCS_fabovedot;
    case XK_Mabovedot: return UCS_Mabovedot;
    case XK_mabovedot: return UCS_mabovedot;
    case XK_Pabovedot: return UCS_Pabovedot;
    case XK_pabovedot: return UCS_pabovedot;
    case XK_Sabovedot: return UCS_Sabovedot;
    case XK_sabovedot: return UCS_sabovedot;
    case XK_Tabovedot: return UCS_Tabovedot;
    case XK_tabovedot: return UCS_tabovedot;
    case XK_Wgrave: return UCS_Wgrave;
    case XK_wgrave: return UCS_wgrave;
    case XK_Wacute: return UCS_Wacute;
    case XK_wacute: return UCS_wacute;
    case XK_Wdiaeresis: return UCS_Wdiaeresis;
    case XK_wdiaeresis: return UCS_wdiaeresis;
    case XK_Ygrave: return UCS_Ygrave;
    case XK_ygrave: return UCS_ygrave;
    }
#endif /* XK_LATIN8 */

/*
 * Latin 9
 * Byte 3 = 0x13
 */

#ifdef XK_LATIN9
    if(byte3 == 13){
        switch(sym){
        case XK_OE: return UCS_OE;
        case XK_oe: return UCS_oe;
        case XK_Ydiaeresis: return UCS_Ydiaeresis;
        }
    }
#endif /* XK_LATIN9 */

/*
 * Katakana
 * Byte 3 = 4
 */

#ifdef XK_KATAKANA
    if(byte3 == 4){
        switch(sym){
        case XK_overline: return UCS_overline;
        case XK_kana_fullstop: return UCS_kana_fullstop;
        case XK_kana_openingbracket: return UCS_kana_openingbracket;
        case XK_kana_closingbracket: return UCS_kana_closingbracket;
        case XK_kana_comma: return UCS_kana_comma;
        case XK_kana_conjunctive: return UCS_kana_conjunctive;
        case XK_kana_WO: return UCS_kana_WO;
        case XK_kana_a: return UCS_kana_a;
        case XK_kana_i: return UCS_kana_i;
        case XK_kana_u: return UCS_kana_u;
        case XK_kana_e: return UCS_kana_e;
        case XK_kana_o: return UCS_kana_o;
        case XK_kana_ya: return UCS_kana_ya;
        case XK_kana_yu: return UCS_kana_yu;
        case XK_kana_yo: return UCS_kana_yo;
        case XK_kana_tsu: return UCS_kana_tsu;
        case XK_prolongedsound: return UCS_prolongedsound;
        case XK_kana_A: return UCS_kana_A;
        case XK_kana_I: return UCS_kana_I;
        case XK_kana_U: return UCS_kana_U;
        case XK_kana_E: return UCS_kana_E;
        case XK_kana_O: return UCS_kana_O;
        case XK_kana_KA: return UCS_kana_KA;
        case XK_kana_KI: return UCS_kana_KI;
        case XK_kana_KU: return UCS_kana_KU;
        case XK_kana_KE: return UCS_kana_KE;
        case XK_kana_KO: return UCS_kana_KO;
        case XK_kana_SA: return UCS_kana_SA;
        case XK_kana_SHI: return UCS_kana_SHI;
        case XK_kana_SU: return UCS_kana_SU;
        case XK_kana_SE: return UCS_kana_SE;
        case XK_kana_SO: return UCS_kana_SO;
        case XK_kana_TA: return UCS_kana_TA;
        case XK_kana_CHI: return UCS_kana_CHI;
        case XK_kana_TSU: return UCS_kana_TSU;
        case XK_kana_TE: return UCS_kana_TE;
        case XK_kana_TO: return UCS_kana_TO;
        case XK_kana_NA: return UCS_kana_NA;
        case XK_kana_NI: return UCS_kana_NI;
        case XK_kana_NU: return UCS_kana_NU;
        case XK_kana_NE: return UCS_kana_NE;
        case XK_kana_NO: return UCS_kana_NO;
        case XK_kana_HA: return UCS_kana_HA;
        case XK_kana_HI: return UCS_kana_HI;
        case XK_kana_FU: return UCS_kana_FU;
        case XK_kana_HE: return UCS_kana_HE;
        case XK_kana_HO: return UCS_kana_HO;
        case XK_kana_MA: return UCS_kana_MA;
        case XK_kana_MI: return UCS_kana_MI;
        case XK_kana_MU: return UCS_kana_MU;
        case XK_kana_ME: return UCS_kana_ME;
        case XK_kana_MO: return UCS_kana_MO;
        case XK_kana_YA: return UCS_kana_YA;
        case XK_kana_YU: return UCS_kana_YU;
        case XK_kana_YO: return UCS_kana_YO;
        case XK_kana_RA: return UCS_kana_RA;
        case XK_kana_RI: return UCS_kana_RI;
        case XK_kana_RU: return UCS_kana_RU;
        case XK_kana_RE: return UCS_kana_RE;
        case XK_kana_RO: return UCS_kana_RO;
        case XK_kana_WA: return UCS_kana_WA;
        case XK_kana_N: return UCS_kana_N;
        case XK_voicedsound: return UCS_voicedsound;
        case XK_semivoicedsound: return UCS_semivoicedsound;
        }
    }
#endif /* XK_KATAKANA */

/*
 * Arabic
 * Byte 3 = 5
 */

#ifdef XK_ARABIC
    if(byte3 == 5){
        switch(sym){
        case XK_Arabic_semicolon: return UCS_Arabic_semicolon;
        case XK_Arabic_question_mark: return UCS_Arabic_question_mark;
        case XK_Arabic_hamza: return UCS_Arabic_hamza;
        case XK_Arabic_maddaonalef: return UCS_Arabic_maddaonalef;
        case XK_Arabic_hamzaonalef: return UCS_Arabic_hamzaonalef;
        case XK_Arabic_hamzaonwaw: return UCS_Arabic_hamzaonwaw;
        case XK_Arabic_hamzaunderalef: return UCS_Arabic_hamzaunderalef;
        case XK_Arabic_hamzaonyeh: return UCS_Arabic_hamzaonyeh;
        case XK_Arabic_alef: return UCS_Arabic_alef;
        case XK_Arabic_beh: return UCS_Arabic_beh;
        case XK_Arabic_tehmarbuta: return UCS_Arabic_tehmarbuta;
        case XK_Arabic_teh: return UCS_Arabic_teh;
        case XK_Arabic_theh: return UCS_Arabic_theh;
        case XK_Arabic_jeem: return UCS_Arabic_jeem;
        case XK_Arabic_hah: return UCS_Arabic_hah;
        case XK_Arabic_khah: return UCS_Arabic_khah;
        case XK_Arabic_dal: return UCS_Arabic_dal;
        case XK_Arabic_thal: return UCS_Arabic_thal;
        case XK_Arabic_ra: return UCS_Arabic_ra;
        case XK_Arabic_zain: return UCS_Arabic_zain;
        case XK_Arabic_seen: return UCS_Arabic_seen;
        case XK_Arabic_sheen: return UCS_Arabic_sheen;
        case XK_Arabic_sad: return UCS_Arabic_sad;
        case XK_Arabic_dad: return UCS_Arabic_dad;
        case XK_Arabic_tah: return UCS_Arabic_tah;
        case XK_Arabic_zah: return UCS_Arabic_zah;
        case XK_Arabic_ain: return UCS_Arabic_ain;
        case XK_Arabic_ghain: return UCS_Arabic_ghain;
        case XK_Arabic_tatweel: return UCS_Arabic_tatweel;
        case XK_Arabic_feh: return UCS_Arabic_feh;
        case XK_Arabic_qaf: return UCS_Arabic_qaf;
        case XK_Arabic_kaf: return UCS_Arabic_kaf;
        case XK_Arabic_lam: return UCS_Arabic_lam;
        case XK_Arabic_meem: return UCS_Arabic_meem;
        case XK_Arabic_noon: return UCS_Arabic_noon;
        case XK_Arabic_ha: return UCS_Arabic_ha;
        case XK_Arabic_waw: return UCS_Arabic_waw;
        case XK_Arabic_alefmaksura: return UCS_Arabic_alefmaksura;
        case XK_Arabic_yeh: return UCS_Arabic_yeh;
        case XK_Arabic_fathatan: return UCS_Arabic_fathatan;
        case XK_Arabic_dammatan: return UCS_Arabic_dammatan;
        case XK_Arabic_kasratan: return UCS_Arabic_kasratan;
        case XK_Arabic_fatha: return UCS_Arabic_fatha;
        case XK_Arabic_damma: return UCS_Arabic_damma;
        case XK_Arabic_kasra: return UCS_Arabic_kasra;
        case XK_Arabic_shadda: return UCS_Arabic_shadda;
        case XK_Arabic_sukun: return UCS_Arabic_sukun;
        }
    }
#endif /* XK_ARABIC */

/*
 * Cyrillic
 * Byte 3 = 6
 */
#ifdef XK_CYRILLIC
    if(byte3 == 6){
        switch(sym){
        case XK_Serbian_dje: return UCS_Serbian_dje;
        case XK_Macedonia_gje: return UCS_Macedonia_gje;
        case XK_Cyrillic_io: return UCS_Cyrillic_io;
        case XK_Ukrainian_ie: return UCS_Ukrainian_ie;
        case XK_Macedonia_dse: return UCS_Macedonia_dse;
        case XK_Ukrainian_i: return UCS_Ukrainian_i;
        case XK_Ukrainian_yi: return UCS_Ukrainian_yi;
        case XK_Cyrillic_je: return UCS_Cyrillic_je;
        case XK_Cyrillic_lje: return UCS_Cyrillic_lje;
        case XK_Cyrillic_nje: return UCS_Cyrillic_nje;
        case XK_Serbian_tshe: return UCS_Serbian_tshe;
        case XK_Macedonia_kje: return UCS_Macedonia_kje;
        case XK_Ukrainian_ghe_with_upturn: return UCS_Ukrainian_ghe_with_upturn;
        case XK_Byelorussian_shortu: return UCS_Byelorussian_shortu;
        case XK_Cyrillic_dzhe: return UCS_Cyrillic_dzhe;
        case XK_numerosign: return UCS_numerosign;
        case XK_Serbian_DJE: return UCS_Serbian_DJE;
        case XK_Macedonia_GJE: return UCS_Macedonia_GJE;
        case XK_Cyrillic_IO: return UCS_Cyrillic_IO;
        case XK_Ukrainian_IE: return UCS_Ukrainian_IE;
        case XK_Macedonia_DSE: return UCS_Macedonia_DSE;
        case XK_Ukrainian_I: return UCS_Ukrainian_I;
        case XK_Ukrainian_YI: return UCS_Ukrainian_YI;
        case XK_Cyrillic_JE: return UCS_Cyrillic_JE;
        case XK_Cyrillic_LJE: return UCS_Cyrillic_LJE;
        case XK_Cyrillic_NJE: return UCS_Cyrillic_NJE;
        case XK_Serbian_TSHE: return UCS_Serbian_TSHE;
        case XK_Macedonia_KJE: return UCS_Macedonia_KJE;
        case XK_Ukrainian_GHE_WITH_UPTURN: return UCS_Ukrainian_GHE_WITH_UPTURN;
        case XK_Byelorussian_SHORTU: return UCS_Byelorussian_SHORTU;
        case XK_Cyrillic_DZHE: return UCS_Cyrillic_DZHE;
        case XK_Cyrillic_yu: return UCS_Cyrillic_yu;
        case XK_Cyrillic_a: return UCS_Cyrillic_a;
        case XK_Cyrillic_be: return UCS_Cyrillic_be;
        case XK_Cyrillic_tse: return UCS_Cyrillic_tse;
        case XK_Cyrillic_de: return UCS_Cyrillic_de;
        case XK_Cyrillic_ie: return UCS_Cyrillic_ie;
        case XK_Cyrillic_ef: return UCS_Cyrillic_ef;
        case XK_Cyrillic_ghe: return UCS_Cyrillic_ghe;
        case XK_Cyrillic_ha: return UCS_Cyrillic_ha;
        case XK_Cyrillic_i: return UCS_Cyrillic_i;
        case XK_Cyrillic_shorti: return UCS_Cyrillic_shorti;
        case XK_Cyrillic_ka: return UCS_Cyrillic_ka;
        case XK_Cyrillic_el: return UCS_Cyrillic_el;
        case XK_Cyrillic_em: return UCS_Cyrillic_em;
        case XK_Cyrillic_en: return UCS_Cyrillic_en;
        case XK_Cyrillic_o: return UCS_Cyrillic_o;
        case XK_Cyrillic_pe: return UCS_Cyrillic_pe;
        case XK_Cyrillic_ya: return UCS_Cyrillic_ya;
        case XK_Cyrillic_er: return UCS_Cyrillic_er;
        case XK_Cyrillic_es: return UCS_Cyrillic_es;
        case XK_Cyrillic_te: return UCS_Cyrillic_te;
        case XK_Cyrillic_u: return UCS_Cyrillic_u;
        case XK_Cyrillic_zhe: return UCS_Cyrillic_zhe;
        case XK_Cyrillic_ve: return UCS_Cyrillic_ve;
        case XK_Cyrillic_softsign: return UCS_Cyrillic_softsign;
        case XK_Cyrillic_yeru: return UCS_Cyrillic_yeru;
        case XK_Cyrillic_ze: return UCS_Cyrillic_ze;
        case XK_Cyrillic_sha: return UCS_Cyrillic_sha;
        case XK_Cyrillic_e: return UCS_Cyrillic_e;
        case XK_Cyrillic_shcha: return UCS_Cyrillic_shcha;
        case XK_Cyrillic_che: return UCS_Cyrillic_che;
        case XK_Cyrillic_hardsign: return UCS_Cyrillic_hardsign;
        case XK_Cyrillic_YU: return UCS_Cyrillic_YU;
        case XK_Cyrillic_A: return UCS_Cyrillic_A;
        case XK_Cyrillic_BE: return UCS_Cyrillic_BE;
        case XK_Cyrillic_TSE: return UCS_Cyrillic_TSE;
        case XK_Cyrillic_DE: return UCS_Cyrillic_DE;
        case XK_Cyrillic_IE: return UCS_Cyrillic_IE;
        case XK_Cyrillic_EF: return UCS_Cyrillic_EF;
        case XK_Cyrillic_GHE: return UCS_Cyrillic_GHE;
        case XK_Cyrillic_HA: return UCS_Cyrillic_HA;
        case XK_Cyrillic_I: return UCS_Cyrillic_I;
        case XK_Cyrillic_SHORTI: return UCS_Cyrillic_SHORTI;
        case XK_Cyrillic_KA: return UCS_Cyrillic_KA;
        case XK_Cyrillic_EL: return UCS_Cyrillic_EL;
        case XK_Cyrillic_EM: return UCS_Cyrillic_EM;
        case XK_Cyrillic_EN: return UCS_Cyrillic_EN;
        case XK_Cyrillic_O: return UCS_Cyrillic_O;
        case XK_Cyrillic_PE: return UCS_Cyrillic_PE;
        case XK_Cyrillic_YA: return UCS_Cyrillic_YA;
        case XK_Cyrillic_ER: return UCS_Cyrillic_ER;
        case XK_Cyrillic_ES: return UCS_Cyrillic_ES;
        case XK_Cyrillic_TE: return UCS_Cyrillic_TE;
        case XK_Cyrillic_U: return UCS_Cyrillic_U;
        case XK_Cyrillic_ZHE: return UCS_Cyrillic_ZHE;
        case XK_Cyrillic_VE: return UCS_Cyrillic_VE;
        case XK_Cyrillic_SOFTSIGN: return UCS_Cyrillic_SOFTSIGN;
        case XK_Cyrillic_YERU: return UCS_Cyrillic_YERU;
        case XK_Cyrillic_ZE: return UCS_Cyrillic_ZE;
        case XK_Cyrillic_SHA: return UCS_Cyrillic_SHA;
        case XK_Cyrillic_E: return UCS_Cyrillic_E;
        case XK_Cyrillic_SHCHA: return UCS_Cyrillic_SHCHA;
        case XK_Cyrillic_CHE: return UCS_Cyrillic_CHE;
        case XK_Cyrillic_HARDSIGN: return UCS_Cyrillic_HARDSIGN;
        }
    }
#endif /* XK_CYRILLIC */

/*
 * Greek
 * (based on an early draft of, and not quite identical to, ISO/IEC 8859-7)
 * Byte 3 = 7
 */

#ifdef XK_GREEK
    if(byte3 == 7){
        switch(sym){
        case XK_Greek_ALPHAaccent: return UCS_Greek_ALPHAaccent;
        case XK_Greek_EPSILONaccent: return UCS_Greek_EPSILONaccent;
        case XK_Greek_ETAaccent: return UCS_Greek_ETAaccent;
        case XK_Greek_IOTAaccent: return UCS_Greek_IOTAaccent;
        case XK_Greek_IOTAdieresis: return UCS_Greek_IOTAdieresis;
        case XK_Greek_OMICRONaccent: return UCS_Greek_OMICRONaccent;
        case XK_Greek_UPSILONaccent: return UCS_Greek_UPSILONaccent;
        case XK_Greek_UPSILONdieresis: return UCS_Greek_UPSILONdieresis;
        case XK_Greek_OMEGAaccent: return UCS_Greek_OMEGAaccent;
        case XK_Greek_accentdieresis: return UCS_Greek_accentdieresis;
        case XK_Greek_horizbar: return UCS_Greek_horizbar;
        case XK_Greek_alphaaccent: return UCS_Greek_alphaaccent;
        case XK_Greek_epsilonaccent: return UCS_Greek_epsilonaccent;
        case XK_Greek_etaaccent: return UCS_Greek_etaaccent;
        case XK_Greek_iotaaccent: return UCS_Greek_iotaaccent;
        case XK_Greek_iotadieresis: return UCS_Greek_iotadieresis;
        case XK_Greek_iotaaccentdieresis: return UCS_Greek_iotaaccentdieresis;
        case XK_Greek_omicronaccent: return UCS_Greek_omicronaccent;
        case XK_Greek_upsilonaccent: return UCS_Greek_upsilonaccent;
        case XK_Greek_upsilondieresis: return UCS_Greek_upsilondieresis;
        case XK_Greek_upsilonaccentdieresis: return UCS_Greek_upsilonaccentdieresis;
        case XK_Greek_omegaaccent: return UCS_Greek_omegaaccent;
        case XK_Greek_ALPHA: return UCS_Greek_ALPHA;
        case XK_Greek_BETA: return UCS_Greek_BETA;
        case XK_Greek_GAMMA: return UCS_Greek_GAMMA;
        case XK_Greek_DELTA: return UCS_Greek_DELTA;
        case XK_Greek_EPSILON: return UCS_Greek_EPSILON;
        case XK_Greek_ZETA: return UCS_Greek_ZETA;
        case XK_Greek_ETA: return UCS_Greek_ETA;
        case XK_Greek_THETA: return UCS_Greek_THETA;
        case XK_Greek_IOTA: return UCS_Greek_IOTA;
        case XK_Greek_KAPPA: return UCS_Greek_KAPPA;
        // case XK_Greek_LAMDA: return UCS_Greek_LAMDA;
        case XK_Greek_LAMBDA: return UCS_Greek_LAMBDA;
        case XK_Greek_MU: return UCS_Greek_MU;
        case XK_Greek_NU: return UCS_Greek_NU;
        case XK_Greek_XI: return UCS_Greek_XI;
        case XK_Greek_OMICRON: return UCS_Greek_OMICRON;
        case XK_Greek_PI: return UCS_Greek_PI;
        case XK_Greek_RHO: return UCS_Greek_RHO;
        case XK_Greek_SIGMA: return UCS_Greek_SIGMA;
        case XK_Greek_TAU: return UCS_Greek_TAU;
        case XK_Greek_UPSILON: return UCS_Greek_UPSILON;
        case XK_Greek_PHI: return UCS_Greek_PHI;
        case XK_Greek_CHI: return UCS_Greek_CHI;
        case XK_Greek_PSI: return UCS_Greek_PSI;
        case XK_Greek_OMEGA: return UCS_Greek_OMEGA;
        case XK_Greek_alpha: return UCS_Greek_alpha;
        case XK_Greek_beta: return UCS_Greek_beta;
        case XK_Greek_gamma: return UCS_Greek_gamma;
        case XK_Greek_delta: return UCS_Greek_delta;
        case XK_Greek_epsilon: return UCS_Greek_epsilon;
        case XK_Greek_zeta: return UCS_Greek_zeta;
        case XK_Greek_eta: return UCS_Greek_eta;
        case XK_Greek_theta: return UCS_Greek_theta;
        case XK_Greek_iota: return UCS_Greek_iota;
        case XK_Greek_kappa: return UCS_Greek_kappa;
        // case XK_Greek_lamda: return UCS_Greek_lamda;
        case XK_Greek_lambda: return UCS_Greek_lambda;
        case XK_Greek_mu: return UCS_Greek_mu;
        case XK_Greek_nu: return UCS_Greek_nu;
        case XK_Greek_xi: return UCS_Greek_xi;
        case XK_Greek_omicron: return UCS_Greek_omicron;
        case XK_Greek_pi: return UCS_Greek_pi;
        case XK_Greek_rho: return UCS_Greek_rho;
        case XK_Greek_sigma: return UCS_Greek_sigma;
        case XK_Greek_finalsmallsigma: return UCS_Greek_finalsmallsigma;
        case XK_Greek_tau: return UCS_Greek_tau;
        case XK_Greek_upsilon: return UCS_Greek_upsilon;
        case XK_Greek_phi: return UCS_Greek_phi;
        case XK_Greek_chi: return UCS_Greek_chi;
        case XK_Greek_psi: return UCS_Greek_psi;
        case XK_Greek_omega: return UCS_Greek_omega;
        }
    }
#endif /* XK_GREEK */

/*
 * Technical
 * (from the DEC VT330/VT420 Technical Character Set, http://vt100.net/charsets/technical.html)
 * Byte 3 = 8
 */

#ifdef XK_TECHNICAL
    if(byte3 == 8){
        switch(sym){
        case XK_leftradical: return UCS_leftradical;
        case XK_topleftradical: return UCS_topleftradical;
        case XK_horizconnector: return UCS_horizconnector;
        case XK_topintegral: return UCS_topintegral;
        case XK_botintegral: return UCS_botintegral;
        case XK_vertconnector: return UCS_vertconnector;
        case XK_topleftsqbracket: return UCS_topleftsqbracket;
        case XK_botleftsqbracket: return UCS_botleftsqbracket;
        case XK_toprightsqbracket: return UCS_toprightsqbracket;
        case XK_botrightsqbracket: return UCS_botrightsqbracket;
        case XK_topleftparens: return UCS_topleftparens;
        case XK_botleftparens: return UCS_botleftparens;
        case XK_toprightparens: return UCS_toprightparens;
        case XK_botrightparens: return UCS_botrightparens;
        case XK_leftmiddlecurlybrace: return UCS_leftmiddlecurlybrace;
        case XK_rightmiddlecurlybrace: return UCS_rightmiddlecurlybrace;
        case XK_lessthanequal: return UCS_lessthanequal;
        case XK_notequal: return UCS_notequal;
        case XK_greaterthanequal: return UCS_greaterthanequal;
        case XK_integral: return UCS_integral;
        case XK_therefore: return UCS_therefore;
        case XK_variation: return UCS_variation;
        case XK_infinity: return UCS_infinity;
        case XK_nabla: return UCS_nabla;
        case XK_approximate: return UCS_approximate;
        case XK_similarequal: return UCS_similarequal;
        case XK_ifonlyif: return UCS_ifonlyif;
        case XK_implies: return UCS_implies;
        case XK_identical: return UCS_identical;
        case XK_radical: return UCS_radical;
        case XK_includedin: return UCS_includedin;
        case XK_includes: return UCS_includes;
        case XK_intersection: return UCS_intersection;
        case XK_union: return UCS_union;
        case XK_logicaland: return UCS_logicaland;
        case XK_logicalor: return UCS_logicalor;
        case XK_partialderivative: return UCS_partialderivative;
        case XK_function: return UCS_function;
        case XK_leftarrow: return UCS_leftarrow;
        case XK_uparrow: return UCS_uparrow;
        case XK_rightarrow: return UCS_rightarrow;
        case XK_downarrow: return UCS_downarrow;
        }
    }
#endif /* XK_TECHNICAL */

/*
 * Special
 * (from the DEC VT100 Special Graphics Character Set)
 * Byte 3 = 9
 */

#ifdef XK_SPECIAL
    if(byte3 == 9){
        switch(sym){
        case XK_soliddiamond: return UCS_soliddiamond;
        case XK_checkerboard: return UCS_checkerboard;
        case XK_ht: return UCS_ht;
        case XK_ff: return UCS_ff;
        case XK_cr: return UCS_cr;
        case XK_lf: return UCS_lf;
        case XK_nl: return UCS_nl;
        case XK_vt: return UCS_vt;
        case XK_lowrightcorner: return UCS_lowrightcorner;
        case XK_uprightcorner: return UCS_uprightcorner;
        case XK_upleftcorner: return UCS_upleftcorner;
        case XK_lowleftcorner: return UCS_lowleftcorner;
        case XK_crossinglines: return UCS_crossinglines;
        case XK_horizlinescan1: return UCS_horizlinescan1;
        case XK_horizlinescan3: return UCS_horizlinescan3;
        case XK_horizlinescan5: return UCS_horizlinescan5;
        case XK_horizlinescan7: return UCS_horizlinescan7;
        case XK_horizlinescan9: return UCS_horizlinescan9;
        case XK_leftt: return UCS_leftt;
        case XK_rightt: return UCS_rightt;
        case XK_bott: return UCS_bott;
        case XK_topt: return UCS_topt;
        case XK_vertbar: return UCS_vertbar;
        }
    }
#endif /* XK_SPECIAL */

/*
 * Publishing
 * (these are probably from a long forgotten DEC Publishing
 * font that once shipped with DECwrite)
 * Byte 3 = 0x0a
 */

#ifdef XK_PUBLISHING
    if(byte3 == 0x0a){
        switch(sym){
        case XK_emspace: return UCS_emspace;
        case XK_enspace: return UCS_enspace;
        case XK_em3space: return UCS_em3space;
        case XK_em4space: return UCS_em4space;
        case XK_digitspace: return UCS_digitspace;
        case XK_punctspace: return UCS_punctspace;
        case XK_thinspace: return UCS_thinspace;
        case XK_hairspace: return UCS_hairspace;
        case XK_emdash: return UCS_emdash;
        case XK_endash: return UCS_endash;
        case XK_signifblank: return UCS_signifblank;
        case XK_ellipsis: return UCS_ellipsis;
        case XK_doubbaselinedot: return UCS_doubbaselinedot;
        case XK_onethird: return UCS_onethird;
        case XK_twothirds: return UCS_twothirds;
        case XK_onefifth: return UCS_onefifth;
        case XK_twofifths: return UCS_twofifths;
        case XK_threefifths: return UCS_threefifths;
        case XK_fourfifths: return UCS_fourfifths;
        case XK_onesixth: return UCS_onesixth;
        case XK_fivesixths: return UCS_fivesixths;
        case XK_careof: return UCS_careof;
        case XK_figdash: return UCS_figdash;
        case XK_leftanglebracket: return UCS_leftanglebracket;
        case XK_decimalpoint: return UCS_decimalpoint;
        case XK_rightanglebracket: return UCS_rightanglebracket;
        case XK_oneeighth: return UCS_oneeighth;
        case XK_threeeighths: return UCS_threeeighths;
        case XK_fiveeighths: return UCS_fiveeighths;
        case XK_seveneighths: return UCS_seveneighths;
        case XK_trademark: return UCS_trademark;
        case XK_signaturemark: return UCS_signaturemark;
        case XK_leftopentriangle: return UCS_leftopentriangle;
        case XK_rightopentriangle: return UCS_rightopentriangle;
        case XK_emopencircle: return UCS_emopencircle;
        case XK_emopenrectangle: return UCS_emopenrectangle;
        case XK_leftsinglequotemark: return UCS_leftsinglequotemark;
        case XK_rightsinglequotemark: return UCS_rightsinglequotemark;
        case XK_leftdoublequotemark: return UCS_leftdoublequotemark;
        case XK_rightdoublequotemark: return UCS_rightdoublequotemark;
        case XK_prescription: return UCS_prescription;
        case XK_permille: return UCS_permille;
        case XK_minutes: return UCS_minutes;
        case XK_seconds: return UCS_seconds;
        case XK_latincross: return UCS_latincross;
        case XK_filledrectbullet: return UCS_filledrectbullet;
        case XK_filledlefttribullet: return UCS_filledlefttribullet;
        case XK_filledrighttribullet: return UCS_filledrighttribullet;
        case XK_emfilledcircle: return UCS_emfilledcircle;
        case XK_emfilledrect: return UCS_emfilledrect;
        case XK_enopencircbullet: return UCS_enopencircbullet;
        case XK_enopensquarebullet: return UCS_enopensquarebullet;
        case XK_openrectbullet: return UCS_openrectbullet;
        case XK_opentribulletup: return UCS_opentribulletup;
        case XK_opentribulletdown: return UCS_opentribulletdown;
        case XK_openstar: return UCS_openstar;
        case XK_enfilledcircbullet: return UCS_enfilledcircbullet;
        case XK_enfilledsqbullet: return UCS_enfilledsqbullet;
        case XK_filledtribulletup: return UCS_filledtribulletup;
        case XK_filledtribulletdown: return UCS_filledtribulletdown;
        case XK_leftpointer: return UCS_leftpointer;
        case XK_rightpointer: return UCS_rightpointer;
        case XK_club: return UCS_club;
        case XK_diamond: return UCS_diamond;
        case XK_heart: return UCS_heart;
        case XK_maltesecross: return UCS_maltesecross;
        case XK_dagger: return UCS_dagger;
        case XK_doubledagger: return UCS_doubledagger;
        case XK_checkmark: return UCS_checkmark;
        case XK_ballotcross: return UCS_ballotcross;
        case XK_musicalsharp: return UCS_musicalsharp;
        case XK_musicalflat: return UCS_musicalflat;
        case XK_malesymbol: return UCS_malesymbol;
        case XK_femalesymbol: return UCS_femalesymbol;
        case XK_telephone: return UCS_telephone;
        case XK_telephonerecorder: return UCS_telephonerecorder;
        case XK_phonographcopyright: return UCS_phonographcopyright;
        case XK_caret: return UCS_caret;
        case XK_singlelowquotemark: return UCS_singlelowquotemark;
        case XK_doublelowquotemark: return UCS_doublelowquotemark;
        }
    }
#endif /* XK_PUBLISHING */

/*
 * APL
 * Byte 3 = 0x0b
 */

#ifdef XK_APL
    if(byte3 == 0x0b){
        switch(sym){
        case XK_leftcaret: return UCS_leftcaret;
        case XK_rightcaret: return UCS_rightcaret;
        case XK_downcaret: return UCS_downcaret;
        case XK_upcaret: return UCS_upcaret;
        case XK_overbar: return UCS_overbar;
        case XK_downtack: return UCS_downtack;
        case XK_upshoe: return UCS_upshoe;
        case XK_downstile: return UCS_downstile;
        case XK_underbar: return UCS_underbar;
        case XK_jot: return UCS_jot;
        case XK_quad: return UCS_quad;
        case XK_uptack: return UCS_uptack;
        case XK_circle: return UCS_circle;
        case XK_upstile: return UCS_upstile;
        case XK_downshoe: return UCS_downshoe;
        case XK_rightshoe: return UCS_rightshoe;
        case XK_leftshoe: return UCS_leftshoe;
        case XK_lefttack: return UCS_lefttack;
        case XK_righttack: return UCS_righttack;
        }
    }
#endif /* XK_APL */

/*
 * Hebrew
 * Byte 3 = 0x0c
 */

#ifdef XK_HEBREW
    if(byte3 == 0x0c){
        switch(sym){
        case XK_hebrew_doublelowline: return UCS_hebrew_doublelowline;
        case XK_hebrew_aleph: return UCS_hebrew_aleph;
        case XK_hebrew_bet: return UCS_hebrew_bet;
        case XK_hebrew_gimel: return UCS_hebrew_gimel;
        case XK_hebrew_dalet: return UCS_hebrew_dalet;
        case XK_hebrew_he: return UCS_hebrew_he;
        case XK_hebrew_waw: return UCS_hebrew_waw;
        case XK_hebrew_zain: return UCS_hebrew_zain;
        case XK_hebrew_chet: return UCS_hebrew_chet;
        case XK_hebrew_tet: return UCS_hebrew_tet;
        case XK_hebrew_yod: return UCS_hebrew_yod;
        case XK_hebrew_finalkaph: return UCS_hebrew_finalkaph;
        case XK_hebrew_kaph: return UCS_hebrew_kaph;
        case XK_hebrew_lamed: return UCS_hebrew_lamed;
        case XK_hebrew_finalmem: return UCS_hebrew_finalmem;
        case XK_hebrew_mem: return UCS_hebrew_mem;
        case XK_hebrew_finalnun: return UCS_hebrew_finalnun;
        case XK_hebrew_nun: return UCS_hebrew_nun;
        case XK_hebrew_samech: return UCS_hebrew_samech;
        case XK_hebrew_ayin: return UCS_hebrew_ayin;
        case XK_hebrew_finalpe: return UCS_hebrew_finalpe;
        case XK_hebrew_pe: return UCS_hebrew_pe;
        case XK_hebrew_finalzade: return UCS_hebrew_finalzade;
        case XK_hebrew_zade: return UCS_hebrew_zade;
        case XK_hebrew_qoph: return UCS_hebrew_qoph;
        case XK_hebrew_resh: return UCS_hebrew_resh;
        case XK_hebrew_shin: return UCS_hebrew_shin;
        case XK_hebrew_taw: return UCS_hebrew_taw;
        }
    }
#endif /* XK_HEBREW */

/*
 * Thai
 * Byte 3 = 0x0d
 */

#ifdef XK_THAI
    if(byte3 == 0x0d){
        switch(sym){
        case XK_Thai_kokai: return UCS_Thai_kokai;
        case XK_Thai_khokhai: return UCS_Thai_khokhai;
        case XK_Thai_khokhuat: return UCS_Thai_khokhuat;
        case XK_Thai_khokhwai: return UCS_Thai_khokhwai;
        case XK_Thai_khokhon: return UCS_Thai_khokhon;
        case XK_Thai_khorakhang: return UCS_Thai_khorakhang;
        case XK_Thai_ngongu: return UCS_Thai_ngongu;
        case XK_Thai_chochan: return UCS_Thai_chochan;
        case XK_Thai_choching: return UCS_Thai_choching;
        case XK_Thai_chochang: return UCS_Thai_chochang;
        case XK_Thai_soso: return UCS_Thai_soso;
        case XK_Thai_chochoe: return UCS_Thai_chochoe;
        case XK_Thai_yoying: return UCS_Thai_yoying;
        case XK_Thai_dochada: return UCS_Thai_dochada;
        case XK_Thai_topatak: return UCS_Thai_topatak;
        case XK_Thai_thothan: return UCS_Thai_thothan;
        case XK_Thai_thonangmontho: return UCS_Thai_thonangmontho;
        case XK_Thai_thophuthao: return UCS_Thai_thophuthao;
        case XK_Thai_nonen: return UCS_Thai_nonen;
        case XK_Thai_dodek: return UCS_Thai_dodek;
        case XK_Thai_totao: return UCS_Thai_totao;
        case XK_Thai_thothung: return UCS_Thai_thothung;
        case XK_Thai_thothahan: return UCS_Thai_thothahan;
        case XK_Thai_thothong: return UCS_Thai_thothong;
        case XK_Thai_nonu: return UCS_Thai_nonu;
        case XK_Thai_bobaimai: return UCS_Thai_bobaimai;
        case XK_Thai_popla: return UCS_Thai_popla;
        case XK_Thai_phophung: return UCS_Thai_phophung;
        case XK_Thai_fofa: return UCS_Thai_fofa;
        case XK_Thai_phophan: return UCS_Thai_phophan;
        case XK_Thai_fofan: return UCS_Thai_fofan;
        case XK_Thai_phosamphao: return UCS_Thai_phosamphao;
        case XK_Thai_moma: return UCS_Thai_moma;
        case XK_Thai_yoyak: return UCS_Thai_yoyak;
        case XK_Thai_rorua: return UCS_Thai_rorua;
        case XK_Thai_ru: return UCS_Thai_ru;
        case XK_Thai_loling: return UCS_Thai_loling;
        case XK_Thai_lu: return UCS_Thai_lu;
        case XK_Thai_wowaen: return UCS_Thai_wowaen;
        case XK_Thai_sosala: return UCS_Thai_sosala;
        case XK_Thai_sorusi: return UCS_Thai_sorusi;
        case XK_Thai_sosua: return UCS_Thai_sosua;
        case XK_Thai_hohip: return UCS_Thai_hohip;
        case XK_Thai_lochula: return UCS_Thai_lochula;
        case XK_Thai_oang: return UCS_Thai_oang;
        case XK_Thai_honokhuk: return UCS_Thai_honokhuk;
        case XK_Thai_paiyannoi: return UCS_Thai_paiyannoi;
        case XK_Thai_saraa: return UCS_Thai_saraa;
        case XK_Thai_maihanakat: return UCS_Thai_maihanakat;
        case XK_Thai_saraaa: return UCS_Thai_saraaa;
        case XK_Thai_saraam: return UCS_Thai_saraam;
        case XK_Thai_sarai: return UCS_Thai_sarai;
        case XK_Thai_saraii: return UCS_Thai_saraii;
        case XK_Thai_saraue: return UCS_Thai_saraue;
        case XK_Thai_sarauee: return UCS_Thai_sarauee;
        case XK_Thai_sarau: return UCS_Thai_sarau;
        case XK_Thai_sarauu: return UCS_Thai_sarauu;
        case XK_Thai_phinthu: return UCS_Thai_phinthu;
        case XK_Thai_baht: return UCS_Thai_baht;
        case XK_Thai_sarae: return UCS_Thai_sarae;
        case XK_Thai_saraae: return UCS_Thai_saraae;
        case XK_Thai_sarao: return UCS_Thai_sarao;
        case XK_Thai_saraaimaimuan: return UCS_Thai_saraaimaimuan;
        case XK_Thai_saraaimaimalai: return UCS_Thai_saraaimaimalai;
        case XK_Thai_lakkhangyao: return UCS_Thai_lakkhangyao;
        case XK_Thai_maiyamok: return UCS_Thai_maiyamok;
        case XK_Thai_maitaikhu: return UCS_Thai_maitaikhu;
        case XK_Thai_maiek: return UCS_Thai_maiek;
        case XK_Thai_maitho: return UCS_Thai_maitho;
        case XK_Thai_maitri: return UCS_Thai_maitri;
        case XK_Thai_maichattawa: return UCS_Thai_maichattawa;
        case XK_Thai_thanthakhat: return UCS_Thai_thanthakhat;
        case XK_Thai_nikhahit: return UCS_Thai_nikhahit;
        case XK_Thai_leksun: return UCS_Thai_leksun;
        case XK_Thai_leknung: return UCS_Thai_leknung;
        case XK_Thai_leksong: return UCS_Thai_leksong;
        case XK_Thai_leksam: return UCS_Thai_leksam;
        case XK_Thai_leksi: return UCS_Thai_leksi;
        case XK_Thai_lekha: return UCS_Thai_lekha;
        case XK_Thai_lekhok: return UCS_Thai_lekhok;
        case XK_Thai_lekchet: return UCS_Thai_lekchet;
        case XK_Thai_lekpaet: return UCS_Thai_lekpaet;
        case XK_Thai_lekkao: return UCS_Thai_lekkao;
        }
    }
#endif /* XK_THAI */
    return 0;

}



KeySym
CheckSymbolAlias(KeySym sym)
{
    #ifdef XK_XKB_KEYS
    if (XkbKSIsDeadKey(sym)) {
        switch (sym) {
        case XK_dead_grave:
            sym = XK_grave;
            break;
        case XK_dead_acute:
            sym = XK_acute;
            break;
        case XK_dead_circumflex:
            sym = XK_asciicircum;
            break;
        case XK_dead_tilde:
            sym = XK_asciitilde;
            break;
        case XK_dead_macron:
            sym = XK_macron;
            break;
        case XK_dead_breve:
            sym = XK_breve;
            break;
        case XK_dead_abovedot:
            sym = XK_abovedot;
            break;
        case XK_dead_diaeresis:
            sym = XK_diaeresis;
            break;
        case XK_dead_abovering:
            sym = XK_degree;
            break;
        case XK_dead_doubleacute:
            sym = XK_doubleacute;
            break;
        case XK_dead_caron:
            sym = XK_caron;
            break;
        case XK_dead_cedilla:
            sym = XK_cedilla;
            break;
        case XK_dead_ogonek:
            sym = XK_ogonek;
            break;
        case XK_dead_iota:
            sym = XK_Greek_iota;
            break;
        case XK_dead_voiced_sound:
            sym = XK_voicedsound;
            break;
        case XK_dead_semivoiced_sound:
            sym = XK_semivoicedsound;
            break;
        }
    }
    #endif /* XK_XKB_KEYS */
    return sym;
}


int
UCSValueToString(char * string, unsigned int value) {
    if(value < 128){
        string[0] = value;
        string[1] = 0;
        return 1;
    } else if(value < (1 << 11)){
        string[0] = 0b11000000 + (value >> 6);
        string[1] = 128 + (value & 63);
        string[2] = 0;
        return 2;
    } else if(value < (1 << 16)) {
        string[0] = 0b11100000 + (value >> 12);
        string[1] = 128 + ((value >> 6) & 63);
        string[2] = 128 + (value & 63);
        string[3] = 0;
        return 3;
    } else {
        string[0] = 0b11110000 + (value >> 18);
        string[1] = 128 + ((value >> 12) & 63);
        string[2] = 128 + ((value >> 6) & 63);
        string[3] = 128 + (value & 63);
        string[4] = 0;
        return 4;
    }
}
unsigned int
UCSStringToValue(char * string) {
    unsigned int value = 0;
    if(string[0] == 0){
    } else if(string[1] == 0){
        value = string[0];
    } else if(string[2] == 0){
        value = string[0] & 0b00111111;
        value = (value << 6) | (string[1] & 63);
    } else if(string[3] == 0){
        value = string[0] & 0b00011111;
        value = (value << 6) | (string[1] & 63);
        value = (value << 6) | (string[2] & 63);
    } else if(string[4] == 0){
        value = string[0] & 0b00001111;
        value = (value << 6) | (string[1] & 63);
        value = (value << 6) | (string[2] & 63);
        value = (value << 6) | (string[3] & 63);
    }
    return value;
}



int
UCSOverrideKeySym(char * output, int limit, KeySym sym)
{
    if(sym == XK_Shift_L) {
        return snprintf(output, limit, "Shift ⇧");
    }
    else if(sym == XK_Shift_R){
        return snprintf(output, limit, "Shift ⇧");
    }
    else if(sym == XK_Shift_Lock){
        return snprintf(output, limit, "Shift Lock");
    }
    else if(sym == XK_ISO_Lock){
        return snprintf(output, limit, "Lock");
    }
    else if(sym == XK_BackSpace){
        return snprintf(output, limit, "⌫");
    }
    else if(sym == XK_Return){
        return snprintf(output, limit, "↵");
    }
    else if(sym == XK_Up){
        return snprintf(output, limit, "↑");
    }
    else if(sym == XK_Down){
        return snprintf(output, limit, "↓");
    }
    else if(sym == XK_Left){
        return snprintf(output, limit, "←");
    }
    else if(sym == XK_Right){
        return snprintf(output, limit, "→");
    }
    else if(sym == XK_Tab){
        return snprintf(output, limit, "⭲");
    }
    else if(sym == XK_ISO_Left_Tab){
        return snprintf(output, limit, "⭰");
    }
    else if(sym == XK_Caps_Lock){
        return snprintf(output, limit, "CapsLock");
    }
    else if(sym == XK_Num_Lock){
        return snprintf(output, limit, "NumLock");
    }
    else if(sym == XK_ISO_Level3_Shift){
        return snprintf(output, limit, "Alt Gr");
    }
    else if(sym == XK_ISO_Level3_Lock){
        return snprintf(output, limit, "L3Lock");
    }
    else if(sym == XK_ISO_Next_Group){
        return snprintf(output, limit, "Next Group");
    }
    else if(sym == XK_ISO_Group_Shift){
        return snprintf(output, limit, "Group Shift");
    }
    else if(sym == XK_ISO_Next_Group_Lock){
        return snprintf(output, limit, "NxtGrpLk");
    }
    else if(sym == XK_space){
        return snprintf(output, limit, "⎵");
    }
    else if(sym == XK_nobreakspace){
        return snprintf(output, limit, "⍽");
    }
    else if(sym == XK_Insert){
        return snprintf(output, limit, "Insert");
    }
    else if(sym == XK_ISO_Continuous_Underline){
        return snprintf(output, limit, "ISO_Continuous_Underline");
    }
    else if(sym == XK_ISO_Discontinuous_Underline){
        return snprintf(output, limit, "ISO_Discontinuous_Underline");
    }
    else if(sym == XK_ISO_Emphasize){
        return snprintf(output, limit, "ISO_Emphasize");
    }
    else if(sym == XK_Multi_key){
        return snprintf(output, limit, "Multi Key");
    }
    else if(sym == XK_ISO_Center_Object){
        return snprintf(output, limit, "Center Object");
    }
    else if(sym == XK_Delete){
        return snprintf(output, limit, "Delete");
    }
    else if(sym == XK_Clear){
        return snprintf(output, limit, "Clear");
    }
    else if(sym == XK_Scroll_Lock){
        return snprintf(output, limit, "Scroll lock");
    }
    else if(sym == XK_Help){
        return snprintf(output, limit, "Help");
    }
    else if(sym == XK_Print){
        return snprintf(output, limit, "Print");
    }
    else if(sym == XK_ISO_Enter){
        return snprintf(output, limit, "ISO_Enter");
    }
    else if(sym == XK_Alt_L){
        return snprintf(output, limit, "Alt");
    }
    else if(sym == XK_Alt_R){
        return snprintf(output, limit, "Alt");
    }
    else if(sym == XK_Control_L){
        return snprintf(output, limit, "Ctrl");
    }
    else if(sym == XK_Control_R){
        return snprintf(output, limit, "Ctrl");
    }
    else if(sym == XK_Meta_L){
        return snprintf(output, limit, "MetaL");
    }
    else if(sym == XK_Meta_R){
        return snprintf(output, limit, "MetaR");
    }
    else if(sym == XK_Super_L){
        return snprintf(output, limit, "SuperL");
    }
    else if(sym == XK_Super_R){
        return snprintf(output, limit, "SuperR");
    }
    else if(sym == XK_Pause){
        return snprintf(output, limit, "Pause");
    }
    else if(sym == XK_Break){
        return snprintf(output, limit, "Break");
    }
    else if(sym == XK_Escape){
        return snprintf(output, limit, "Escape");
    }
    else if(sym == XK_Undo){
        return snprintf(output, limit, "Undo");
    }
    else if(sym == XK_ISO_Fast_Cursor_Up){
        return snprintf(output, limit, "ISO_Fast_Cursor_Up");
    }
    else if(sym == XK_ISO_Fast_Cursor_Down){
        return snprintf(output, limit, "ISO_Fast_Cursor_Down");
    }
    else if(sym == XK_ISO_Fast_Cursor_Left){
        return snprintf(output, limit, "ISO_Fast_Cursor_Left");
    }
    else if(sym == XK_ISO_Fast_Cursor_Right){
        return snprintf(output, limit, "ISO_Fast_Cursor_Right");
    }
    else if(sym == XK_Home){
        return snprintf(output, limit, "Home");
    }
    else if(sym == XK_End){
        return snprintf(output, limit, "End");
    }
    else if(sym == XK_Page_Up){
        return snprintf(output, limit, "PgUp");
    }
    else if(sym == XK_Page_Down){
        return snprintf(output, limit, "PgDn");
    }
    else if(sym == XK_ISO_Move_Line_Up){
        return snprintf(output, limit, "ISO_Move_Line_Up");
    }
    else if(sym == XK_ISO_Move_Line_Down){
        return snprintf(output, limit, "ISO_Move_Line_Down");
    }
    else if(sym == XK_ISO_Partial_Line_Up){
        return snprintf(output, limit, "ISO_Partial_Line_Up");
    }
    else if(sym == XK_ISO_Partial_Line_Down){
        return snprintf(output, limit, "ISO_Partial_Line_Down");
    }
    else if(sym == XK_ISO_Partial_Space_Left){
        return snprintf(output, limit, "ISO_Partial_Space_Left");
    }
    else if(sym == XK_ISO_Partial_Space_Right){
        return snprintf(output, limit, "ISO_Partial_Space_Right");
    }
    else if(sym == XK_ISO_Set_Margin_Left){
        return snprintf(output, limit, "ISO_Set_Margin_Left");
    }
    else if(sym == XK_ISO_Set_Margin_Right){
        return snprintf(output, limit, "ISO_Set_Margin_Right");
    }
    else if(sym == XK_ISO_Release_Margin_Left){
        return snprintf(output, limit, "ISO_Release_Margin_Left");
    }
    else if(sym == XK_ISO_Release_Margin_Right){
        return snprintf(output, limit, "ISO_Release_Margin_Right");
    }
    else if(sym == XK_ISO_Release_Both_Margins){
        return snprintf(output, limit, "ISO_Release_Both_Margins");
    }
    else if(sym == XK_ISO_Prev_Group){
        return snprintf(output, limit, "ISO_Prev_Group");
    }
    else if(sym == XK_ISO_Prev_Group_Lock){
        return snprintf(output, limit, "ISO_Prev_Group_Lock");
    }
    else if(sym == XK_KP_Space){
        return snprintf(output, limit, "space");
    }
    else if(sym == XK_KP_Tab){
        return snprintf(output, limit, "Tab");
    }
    else if(sym == XK_KP_Enter){
        return snprintf(output, limit, "Enter");
    }
    else if(sym == XK_KP_F1){
        return snprintf(output, limit, "F1");
    }
    else if(sym == XK_KP_F2){
        return snprintf(output, limit, "F2");
    }
    else if(sym == XK_KP_F3){
        return snprintf(output, limit, "F3");
    }
    else if(sym == XK_KP_F4){
        return snprintf(output, limit, "F4");
    }
    else if(sym == XK_KP_Home){
        return snprintf(output, limit, "Home");
    }
    else if(sym == XK_KP_Up){
        return snprintf(output, limit, "⯅");
    }
    else if(sym == XK_KP_Down){
        return snprintf(output, limit, "⯆");
    }
    else if(sym == XK_KP_Left){
        return snprintf(output, limit, "⯇");
    }
    else if(sym == XK_KP_Right){
        return snprintf(output, limit, "⯈");
    }
    else if(sym == XK_KP_Prior){
        return snprintf(output, limit, "Pg Up");
    }
    else if(sym == XK_KP_Next){
        return snprintf(output, limit, "Pg Dn");
    }
    else if(sym == XK_KP_Page_Up){
        return snprintf(output, limit, "Page_Up");
    }
    else if(sym == XK_KP_Page_Down){
        return snprintf(output, limit, "Page_Down");
    }
    else if(sym == XK_KP_End){
        return snprintf(output, limit, "End");
    }
    else if(sym == XK_KP_Begin){
        return snprintf(output, limit, "Begin");
    }
    else if(sym == XK_KP_Insert){
        return snprintf(output, limit, "Insert");
    }
    else if(sym == XK_KP_Delete){
        return snprintf(output, limit, "Delete");
    }
    else if(sym == XK_KP_Equal){
        return snprintf(output, limit, "=");
    }
    else if(sym == XK_KP_Multiply){
        return snprintf(output, limit, "*");
    }
    else if(sym == XK_KP_Add){
        return snprintf(output, limit, "+");
    }
    else if(sym == XK_KP_Subtract){
        return snprintf(output, limit, "-");
    }
    else if(sym == XK_KP_Divide){
        return snprintf(output, limit, "/");
    }
    else if(sym == XK_KP_Separator){
        return snprintf(output, limit, ",");
    }
    else if(sym == XK_KP_0){
        return snprintf(output, limit, "0");
    }
    else if(sym == XK_KP_1){
        return snprintf(output, limit, "1");
    }
    else if(sym == XK_KP_2){
        return snprintf(output, limit, "2");
    }
    else if(sym == XK_KP_3){
        return snprintf(output, limit, "3");
    }
    else if(sym == XK_KP_4){
        return snprintf(output, limit, "4");
    }
    else if(sym == XK_KP_5){
        return snprintf(output, limit, "5");
    }
    else if(sym == XK_KP_6){
        return snprintf(output, limit, "6");
    }
    else if(sym == XK_KP_7){
        return snprintf(output, limit, "7");
    }
    else if(sym == XK_KP_8){
        return snprintf(output, limit, "8");
    }
    else if(sym == XK_KP_9){
        return snprintf(output, limit, "9");
    }
    return 0;
}


int
UCSOverrideKeySymAscii(char * output, int limit, KeySym sym)
{
    if(sym == XK_Shift_L) {
        return snprintf(output, limit, "Shift");
    }
    else if(sym == XK_Shift_R){
        return snprintf(output, limit, "Shift");
    }
    else if(sym == XK_Shift_Lock){
        return snprintf(output, limit, "Shift Lock");
    }
    else if(sym == XK_ISO_Lock){
        return snprintf(output, limit, "Lock");
    }
    else if(sym == XK_BackSpace){
        return snprintf(output, limit, "Backspace");
    }
    else if(sym == XK_Return){
        return snprintf(output, limit, "Enter");
    }
    else if(sym == XK_Up){
        return snprintf(output, limit, "Up");
    }
    else if(sym == XK_Down){
        return snprintf(output, limit, "Down");
    }
    else if(sym == XK_Left){
        return snprintf(output, limit, "Left");
    }
    else if(sym == XK_Right){
        return snprintf(output, limit, "Right");
    }
    else if(sym == XK_Tab){
        return snprintf(output, limit, "Tab");
    }
    else if(sym == XK_ISO_Left_Tab){
        return snprintf(output, limit, "Left Tab");
    }
    else if(sym == XK_Caps_Lock){
        return snprintf(output, limit, "CapsLock");
    }
    else if(sym == XK_Num_Lock){
        return snprintf(output, limit, "NumLock");
    }
    else if(sym == XK_ISO_Level3_Shift){
        return snprintf(output, limit, "Alt Gr");
    }
    else if(sym == XK_ISO_Level3_Lock){
        return snprintf(output, limit, "L3Lock");
    }
    else if(sym == XK_ISO_Next_Group){
        return snprintf(output, limit, "Next Group");
    }
    else if(sym == XK_ISO_Group_Shift){
        return snprintf(output, limit, "Group Shift");
    }
    else if(sym == XK_ISO_Next_Group_Lock){
        return snprintf(output, limit, "NxtGrpLk");
    }
    else if(sym == XK_space){
        return snprintf(output, limit, "Space");
    }
    else if(sym == XK_nobreakspace){
        return snprintf(output, limit, "&nbsp;");
    }
    else if(sym == XK_Insert){
        return snprintf(output, limit, "Insert");
    }
    else if(sym == XK_ISO_Continuous_Underline){
        return snprintf(output, limit, "ISO_Continuous_Underline");
    }
    else if(sym == XK_ISO_Discontinuous_Underline){
        return snprintf(output, limit, "ISO_Discontinuous_Underline");
    }
    else if(sym == XK_ISO_Emphasize){
        return snprintf(output, limit, "ISO_Emphasize");
    }
    else if(sym == XK_Multi_key){
        return snprintf(output, limit, "Multi Key");
    }
    else if(sym == XK_ISO_Center_Object){
        return snprintf(output, limit, "Center Object");
    }
    else if(sym == XK_Delete){
        return snprintf(output, limit, "Delete");
    }
    else if(sym == XK_Clear){
        return snprintf(output, limit, "Clear");
    }
    else if(sym == XK_Scroll_Lock){
        return snprintf(output, limit, "Scroll lock");
    }
    else if(sym == XK_Help){
        return snprintf(output, limit, "Help");
    }
    else if(sym == XK_Print){
        return snprintf(output, limit, "Print");
    }
    else if(sym == XK_ISO_Enter){
        return snprintf(output, limit, "ISO_Enter");
    }
    else if(sym == XK_Alt_L){
        return snprintf(output, limit, "Alt");
    }
    else if(sym == XK_Alt_R){
        return snprintf(output, limit, "Alt");
    }
    else if(sym == XK_Control_L){
        return snprintf(output, limit, "Ctrl");
    }
    else if(sym == XK_Control_R){
        return snprintf(output, limit, "Ctrl");
    }
    else if(sym == XK_Meta_L){
        return snprintf(output, limit, "MetaL");
    }
    else if(sym == XK_Meta_R){
        return snprintf(output, limit, "MetaR");
    }
    else if(sym == XK_Super_L){
        return snprintf(output, limit, "SuperL");
    }
    else if(sym == XK_Super_R){
        return snprintf(output, limit, "SuperR");
    }
    else if(sym == XK_Pause){
        return snprintf(output, limit, "Pause");
    }
    else if(sym == XK_Break){
        return snprintf(output, limit, "Break");
    }
    else if(sym == XK_Escape){
        return snprintf(output, limit, "Escape");
    }
    else if(sym == XK_Undo){
        return snprintf(output, limit, "Undo");
    }
    else if(sym == XK_ISO_Fast_Cursor_Up){
        return snprintf(output, limit, "ISO_Fast_Cursor_Up");
    }
    else if(sym == XK_ISO_Fast_Cursor_Down){
        return snprintf(output, limit, "ISO_Fast_Cursor_Down");
    }
    else if(sym == XK_ISO_Fast_Cursor_Left){
        return snprintf(output, limit, "ISO_Fast_Cursor_Left");
    }
    else if(sym == XK_ISO_Fast_Cursor_Right){
        return snprintf(output, limit, "ISO_Fast_Cursor_Right");
    }
    else if(sym == XK_Home){
        return snprintf(output, limit, "Home");
    }
    else if(sym == XK_End){
        return snprintf(output, limit, "End");
    }
    else if(sym == XK_Page_Up){
        return snprintf(output, limit, "PgUp");
    }
    else if(sym == XK_Page_Down){
        return snprintf(output, limit, "PgDn");
    }
    else if(sym == XK_ISO_Move_Line_Up){
        return snprintf(output, limit, "ISO_Move_Line_Up");
    }
    else if(sym == XK_ISO_Move_Line_Down){
        return snprintf(output, limit, "ISO_Move_Line_Down");
    }
    else if(sym == XK_ISO_Partial_Line_Up){
        return snprintf(output, limit, "ISO_Partial_Line_Up");
    }
    else if(sym == XK_ISO_Partial_Line_Down){
        return snprintf(output, limit, "ISO_Partial_Line_Down");
    }
    else if(sym == XK_ISO_Partial_Space_Left){
        return snprintf(output, limit, "ISO_Partial_Space_Left");
    }
    else if(sym == XK_ISO_Partial_Space_Right){
        return snprintf(output, limit, "ISO_Partial_Space_Right");
    }
    else if(sym == XK_ISO_Set_Margin_Left){
        return snprintf(output, limit, "ISO_Set_Margin_Left");
    }
    else if(sym == XK_ISO_Set_Margin_Right){
        return snprintf(output, limit, "ISO_Set_Margin_Right");
    }
    else if(sym == XK_ISO_Release_Margin_Left){
        return snprintf(output, limit, "ISO_Release_Margin_Left");
    }
    else if(sym == XK_ISO_Release_Margin_Right){
        return snprintf(output, limit, "ISO_Release_Margin_Right");
    }
    else if(sym == XK_ISO_Release_Both_Margins){
        return snprintf(output, limit, "ISO_Release_Both_Margins");
    }
    else if(sym == XK_ISO_Prev_Group){
        return snprintf(output, limit, "ISO_Prev_Group");
    }
    else if(sym == XK_ISO_Prev_Group_Lock){
        return snprintf(output, limit, "ISO_Prev_Group_Lock");
    }
    else if(sym == XK_KP_Space){
        return snprintf(output, limit, "space");
    }
    else if(sym == XK_KP_Tab){
        return snprintf(output, limit, "Tab");
    }
    else if(sym == XK_KP_Enter){
        return snprintf(output, limit, "Enter");
    }
    else if(sym == XK_KP_F1){
        return snprintf(output, limit, "F1");
    }
    else if(sym == XK_KP_F2){
        return snprintf(output, limit, "F2");
    }
    else if(sym == XK_KP_F3){
        return snprintf(output, limit, "F3");
    }
    else if(sym == XK_KP_F4){
        return snprintf(output, limit, "F4");
    }
    else if(sym == XK_KP_Home){
        return snprintf(output, limit, "Home");
    }
    else if(sym == XK_KP_Up){
        return snprintf(output, limit, "Up");
    }
    else if(sym == XK_KP_Down){
        return snprintf(output, limit, "Down");
    }
    else if(sym == XK_KP_Left){
        return snprintf(output, limit, "Left");
    }
    else if(sym == XK_KP_Right){
        return snprintf(output, limit, "Right");
    }
    else if(sym == XK_KP_Prior){
        return snprintf(output, limit, "Pg Up");
    }
    else if(sym == XK_KP_Next){
        return snprintf(output, limit, "Pg Dn");
    }
    else if(sym == XK_KP_Page_Up){
        return snprintf(output, limit, "Page_Up");
    }
    else if(sym == XK_KP_Page_Down){
        return snprintf(output, limit, "Page_Down");
    }
    else if(sym == XK_KP_End){
        return snprintf(output, limit, "End");
    }
    else if(sym == XK_KP_Begin){
        return snprintf(output, limit, "Begin");
    }
    else if(sym == XK_KP_Insert){
        return snprintf(output, limit, "Insert");
    }
    else if(sym == XK_KP_Delete){
        return snprintf(output, limit, "Delete");
    }
    else if(sym == XK_KP_Equal){
        return snprintf(output, limit, "=");
    }
    else if(sym == XK_KP_Multiply){
        return snprintf(output, limit, "*");
    }
    else if(sym == XK_KP_Add){
        return snprintf(output, limit, "+");
    }
    else if(sym == XK_KP_Subtract){
        return snprintf(output, limit, "-");
    }
    else if(sym == XK_KP_Divide){
        return snprintf(output, limit, "/");
    }
    else if(sym == XK_KP_Separator){
        return snprintf(output, limit, ",");
    }
    else if(sym == XK_KP_0){
        return snprintf(output, limit, "0");
    }
    else if(sym == XK_KP_1){
        return snprintf(output, limit, "1");
    }
    else if(sym == XK_KP_2){
        return snprintf(output, limit, "2");
    }
    else if(sym == XK_KP_3){
        return snprintf(output, limit, "3");
    }
    else if(sym == XK_KP_4){
        return snprintf(output, limit, "4");
    }
    else if(sym == XK_KP_5){
        return snprintf(output, limit, "5");
    }
    else if(sym == XK_KP_6){
        return snprintf(output, limit, "6");
    }
    else if(sym == XK_KP_7){
        return snprintf(output, limit, "7");
    }
    else if(sym == XK_KP_8){
        return snprintf(output, limit, "8");
    }
    else if(sym == XK_KP_9){
        return snprintf(output, limit, "9");
    }
    return 0;
}
