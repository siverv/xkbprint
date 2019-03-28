#ifndef _UCSSYMBOLS_H_
#define _UCSSYMBOLS_H_ 1

/***********************************************************
* Based on the information in <X11/keysymdef.h>
**/

#define	XK_TECHNICAL
#define	XK_PUBLISHING
#define XK_MISCELLANY
#define XK_XKB_KEYS
#define XK_LATIN1
#define XK_LATIN2
#define XK_LATIN3
#define XK_LATIN4
#define XK_LATIN8
#define XK_LATIN9
#define XK_CAUCASUS
#define XK_GREEK
#define XK_KATAKANA
#define XK_ARABIC
#define XK_CYRILLIC
#define XK_HEBREW
#define XK_THAI
#define XK_KOREAN
#define XK_ARMENIAN
#define XK_GEORGIAN
#define XK_VIETNAMESE
#define XK_CURRENCY
#define XK_MATHEMATICAL
#define XK_BRAILLE
#define XK_SINHALA


#include <X11/Xlib.h>
#include <X11/keysymdef.h>

int XKeysymToUCSValue(KeySym sym);
KeySym CheckSymbolAlias(KeySym sym);
int UCSValueToString(char * string, unsigned int value);
unsigned int UCSStringToValue(char * string);
int UCSOverrideKeySym(char * output, int limit, KeySym);
int UCSOverrideKeySymAscii(char * output, int limit, KeySym);

/*
 * Latin 2
 * Byte 3 = 1
 */

#ifdef XK_LATIN2
#define UCS_Aogonek                       0x0104  /* 0x01a1 LATIN CAPITAL LETTER A WITH OGONEK */
#define UCS_breve                         0x02D8  /* 0x01a2 BREVE */
#define UCS_Lstroke                       0x0141  /* 0x01a3 LATIN CAPITAL LETTER L WITH STROKE */
#define UCS_Lcaron                        0x013D  /* 0x01a5 LATIN CAPITAL LETTER L WITH CARON */
#define UCS_Sacute                        0x015A  /* 0x01a6 LATIN CAPITAL LETTER S WITH ACUTE */
#define UCS_Scaron                        0x0160  /* 0x01a9 LATIN CAPITAL LETTER S WITH CARON */
#define UCS_Scedilla                      0x015E  /* 0x01aa LATIN CAPITAL LETTER S WITH CEDILLA */
#define UCS_Tcaron                        0x0164  /* 0x01ab LATIN CAPITAL LETTER T WITH CARON */
#define UCS_Zacute                        0x0179  /* 0x01ac LATIN CAPITAL LETTER Z WITH ACUTE */
#define UCS_Zcaron                        0x017D  /* 0x01ae LATIN CAPITAL LETTER Z WITH CARON */
#define UCS_Zabovedot                     0x017B  /* 0x01af LATIN CAPITAL LETTER Z WITH DOT ABOVE */
#define UCS_aogonek                       0x0105  /* 0x01b1 LATIN SMALL LETTER A WITH OGONEK */
#define UCS_ogonek                        0x02DB  /* 0x01b2 OGONEK */
#define UCS_lstroke                       0x0142  /* 0x01b3 LATIN SMALL LETTER L WITH STROKE */
#define UCS_lcaron                        0x013E  /* 0x01b5 LATIN SMALL LETTER L WITH CARON */
#define UCS_sacute                        0x015B  /* 0x01b6 LATIN SMALL LETTER S WITH ACUTE */
#define UCS_caron                         0x02C7  /* 0x01b7 CARON */
#define UCS_scaron                        0x0161  /* 0x01b9 LATIN SMALL LETTER S WITH CARON */
#define UCS_scedilla                      0x015F  /* 0x01ba LATIN SMALL LETTER S WITH CEDILLA */
#define UCS_tcaron                        0x0165  /* 0x01bb LATIN SMALL LETTER T WITH CARON */
#define UCS_zacute                        0x017A  /* 0x01bc LATIN SMALL LETTER Z WITH ACUTE */
#define UCS_doubleacute                   0x02DD  /* 0x01bd DOUBLE ACUTE ACCENT */
#define UCS_zcaron                        0x017E  /* 0x01be LATIN SMALL LETTER Z WITH CARON */
#define UCS_zabovedot                     0x017C  /* 0x01bf LATIN SMALL LETTER Z WITH DOT ABOVE */
#define UCS_Racute                        0x0154  /* 0x01c0 LATIN CAPITAL LETTER R WITH ACUTE */
#define UCS_Abreve                        0x0102  /* 0x01c3 LATIN CAPITAL LETTER A WITH BREVE */
#define UCS_Lacute                        0x0139  /* 0x01c5 LATIN CAPITAL LETTER L WITH ACUTE */
#define UCS_Cacute                        0x0106  /* 0x01c6 LATIN CAPITAL LETTER C WITH ACUTE */
#define UCS_Ccaron                        0x010C  /* 0x01c8 LATIN CAPITAL LETTER C WITH CARON */
#define UCS_Eogonek                       0x0118  /* 0x01ca LATIN CAPITAL LETTER E WITH OGONEK */
#define UCS_Ecaron                        0x011A  /* 0x01cc LATIN CAPITAL LETTER E WITH CARON */
#define UCS_Dcaron                        0x010E  /* 0x01cf LATIN CAPITAL LETTER D WITH CARON */
#define UCS_Dstroke                       0x0110  /* 0x01d0 LATIN CAPITAL LETTER D WITH STROKE */
#define UCS_Nacute                        0x0143  /* 0x01d1 LATIN CAPITAL LETTER N WITH ACUTE */
#define UCS_Ncaron                        0x0147  /* 0x01d2 LATIN CAPITAL LETTER N WITH CARON */
#define UCS_Odoubleacute                  0x0150  /* 0x01d5 LATIN CAPITAL LETTER O WITH DOUBLE ACUTE */
#define UCS_Rcaron                        0x0158  /* 0x01d8 LATIN CAPITAL LETTER R WITH CARON */
#define UCS_Uring                         0x016E  /* 0x01d9 LATIN CAPITAL LETTER U WITH RING ABOVE */
#define UCS_Udoubleacute                  0x0170  /* 0x01db LATIN CAPITAL LETTER U WITH DOUBLE ACUTE */
#define UCS_Tcedilla                      0x0162  /* 0x01de LATIN CAPITAL LETTER T WITH CEDILLA */
#define UCS_racute                        0x0155  /* 0x01e0 LATIN SMALL LETTER R WITH ACUTE */
#define UCS_abreve                        0x0103  /* 0x01e3 LATIN SMALL LETTER A WITH BREVE */
#define UCS_lacute                        0x013A  /* 0x01e5 LATIN SMALL LETTER L WITH ACUTE */
#define UCS_cacute                        0x0107  /* 0x01e6 LATIN SMALL LETTER C WITH ACUTE */
#define UCS_ccaron                        0x010D  /* 0x01e8 LATIN SMALL LETTER C WITH CARON */
#define UCS_eogonek                       0x0119  /* 0x01ea LATIN SMALL LETTER E WITH OGONEK */
#define UCS_ecaron                        0x011B  /* 0x01ec LATIN SMALL LETTER E WITH CARON */
#define UCS_dcaron                        0x010F  /* 0x01ef LATIN SMALL LETTER D WITH CARON */
#define UCS_dstroke                       0x0111  /* 0x01f0 LATIN SMALL LETTER D WITH STROKE */
#define UCS_nacute                        0x0144  /* 0x01f1 LATIN SMALL LETTER N WITH ACUTE */
#define UCS_ncaron                        0x0148  /* 0x01f2 LATIN SMALL LETTER N WITH CARON */
#define UCS_odoubleacute                  0x0151  /* 0x01f5 LATIN SMALL LETTER O WITH DOUBLE ACUTE */
#define UCS_rcaron                        0x0159  /* 0x01f8 LATIN SMALL LETTER R WITH CARON */
#define UCS_uring                         0x016F  /* 0x01f9 LATIN SMALL LETTER U WITH RING ABOVE */
#define UCS_udoubleacute                  0x0171  /* 0x01fb LATIN SMALL LETTER U WITH DOUBLE ACUTE */
#define UCS_tcedilla                      0x0163  /* 0x01fe LATIN SMALL LETTER T WITH CEDILLA */
#define UCS_abovedot                      0x02D9  /* 0x01ff DOT ABOVE */
#endif /* XK_LATIN2 */

/*
 * Latin 3
 * Byte 3 = 2
 */

#ifdef XK_LATIN3
#define UCS_Hstroke                       0x0126  /* 0x02a1 LATIN CAPITAL LETTER H WITH STROKE */
#define UCS_Hcircumflex                   0x0124  /* 0x02a6 LATIN CAPITAL LETTER H WITH CIRCUMFLEX */
#define UCS_Iabovedot                     0x0130  /* 0x02a9 LATIN CAPITAL LETTER I WITH DOT ABOVE */
#define UCS_Gbreve                        0x011E  /* 0x02ab LATIN CAPITAL LETTER G WITH BREVE */
#define UCS_Jcircumflex                   0x0134  /* 0x02ac LATIN CAPITAL LETTER J WITH CIRCUMFLEX */
#define UCS_hstroke                       0x0127  /* 0x02b1 LATIN SMALL LETTER H WITH STROKE */
#define UCS_hcircumflex                   0x0125  /* 0x02b6 LATIN SMALL LETTER H WITH CIRCUMFLEX */
#define UCS_idotless                      0x0131  /* 0x02b9 LATIN SMALL LETTER DOTLESS I */
#define UCS_gbreve                        0x011F  /* 0x02bb LATIN SMALL LETTER G WITH BREVE */
#define UCS_jcircumflex                   0x0135  /* 0x02bc LATIN SMALL LETTER J WITH CIRCUMFLEX */
#define UCS_Cabovedot                     0x010A  /* 0x02c5 LATIN CAPITAL LETTER C WITH DOT ABOVE */
#define UCS_Ccircumflex                   0x0108  /* 0x02c6 LATIN CAPITAL LETTER C WITH CIRCUMFLEX */
#define UCS_Gabovedot                     0x0120  /* 0x02d5 LATIN CAPITAL LETTER G WITH DOT ABOVE */
#define UCS_Gcircumflex                   0x011C  /* 0x02d8 LATIN CAPITAL LETTER G WITH CIRCUMFLEX */
#define UCS_Ubreve                        0x016C  /* 0x02dd LATIN CAPITAL LETTER U WITH BREVE */
#define UCS_Scircumflex                   0x015C  /* 0x02de LATIN CAPITAL LETTER S WITH CIRCUMFLEX */
#define UCS_cabovedot                     0x010B  /* 0x02e5 LATIN SMALL LETTER C WITH DOT ABOVE */
#define UCS_ccircumflex                   0x0109  /* 0x02e6 LATIN SMALL LETTER C WITH CIRCUMFLEX */
#define UCS_gabovedot                     0x0121  /* 0x02f5 LATIN SMALL LETTER G WITH DOT ABOVE */
#define UCS_gcircumflex                   0x011D  /* 0x02f8 LATIN SMALL LETTER G WITH CIRCUMFLEX */
#define UCS_ubreve                        0x016D  /* 0x02fd LATIN SMALL LETTER U WITH BREVE */
#define UCS_scircumflex                   0x015D  /* 0x02fe LATIN SMALL LETTER S WITH CIRCUMFLEX */
#endif /* XK_LATIN3 */


/*
 * Latin 4
 * Byte 3 = 3
 */

#ifdef XK_LATIN4
#define UCS_kra                           0x0138  /* 0x03a2 LATIN SMALL LETTER KRA */
#define UCS_Rcedilla                      0x0156  /* 0x03a3 LATIN CAPITAL LETTER R WITH CEDILLA */
#define UCS_Itilde                        0x0128  /* 0x03a5 LATIN CAPITAL LETTER I WITH TILDE */
#define UCS_Lcedilla                      0x013B  /* 0x03a6 LATIN CAPITAL LETTER L WITH CEDILLA */
#define UCS_Emacron                       0x0112  /* 0x03aa LATIN CAPITAL LETTER E WITH MACRON */
#define UCS_Gcedilla                      0x0122  /* 0x03ab LATIN CAPITAL LETTER G WITH CEDILLA */
#define UCS_Tslash                        0x0166  /* 0x03ac LATIN CAPITAL LETTER T WITH STROKE */
#define UCS_rcedilla                      0x0157  /* 0x03b3 LATIN SMALL LETTER R WITH CEDILLA */
#define UCS_itilde                        0x0129  /* 0x03b5 LATIN SMALL LETTER I WITH TILDE */
#define UCS_lcedilla                      0x013C  /* 0x03b6 LATIN SMALL LETTER L WITH CEDILLA */
#define UCS_emacron                       0x0113  /* 0x03ba LATIN SMALL LETTER E WITH MACRON */
#define UCS_gcedilla                      0x0123  /* 0x03bb LATIN SMALL LETTER G WITH CEDILLA */
#define UCS_tslash                        0x0167  /* 0x03bc LATIN SMALL LETTER T WITH STROKE */
#define UCS_ENG                           0x014A  /* 0x03bd LATIN CAPITAL LETTER ENG */
#define UCS_eng                           0x014B  /* 0x03bf LATIN SMALL LETTER ENG */
#define UCS_Amacron                       0x0100  /* 0x03c0 LATIN CAPITAL LETTER A WITH MACRON */
#define UCS_Iogonek                       0x012E  /* 0x03c7 LATIN CAPITAL LETTER I WITH OGONEK */
#define UCS_Eabovedot                     0x0116  /* 0x03cc LATIN CAPITAL LETTER E WITH DOT ABOVE */
#define UCS_Imacron                       0x012A  /* 0x03cf LATIN CAPITAL LETTER I WITH MACRON */
#define UCS_Ncedilla                      0x0145  /* 0x03d1 LATIN CAPITAL LETTER N WITH CEDILLA */
#define UCS_Omacron                       0x014C  /* 0x03d2 LATIN CAPITAL LETTER O WITH MACRON */
#define UCS_Kcedilla                      0x0136  /* 0x03d3 LATIN CAPITAL LETTER K WITH CEDILLA */
#define UCS_Uogonek                       0x0172  /* 0x03d9 LATIN CAPITAL LETTER U WITH OGONEK */
#define UCS_Utilde                        0x0168  /* 0x03dd LATIN CAPITAL LETTER U WITH TILDE */
#define UCS_Umacron                       0x016A  /* 0x03de LATIN CAPITAL LETTER U WITH MACRON */
#define UCS_amacron                       0x0101  /* 0x03e0 LATIN SMALL LETTER A WITH MACRON */
#define UCS_iogonek                       0x012F  /* 0x03e7 LATIN SMALL LETTER I WITH OGONEK */
#define UCS_eabovedot                     0x0117  /* 0x03ec LATIN SMALL LETTER E WITH DOT ABOVE */
#define UCS_imacron                       0x012B  /* 0x03ef LATIN SMALL LETTER I WITH MACRON */
#define UCS_ncedilla                      0x0146  /* 0x03f1 LATIN SMALL LETTER N WITH CEDILLA */
#define UCS_omacron                       0x014D  /* 0x03f2 LATIN SMALL LETTER O WITH MACRON */
#define UCS_kcedilla                      0x0137  /* 0x03f3 LATIN SMALL LETTER K WITH CEDILLA */
#define UCS_uogonek                       0x0173  /* 0x03f9 LATIN SMALL LETTER U WITH OGONEK */
#define UCS_utilde                        0x0169  /* 0x03fd LATIN SMALL LETTER U WITH TILDE */
#define UCS_umacron                       0x016B  /* 0x03fe LATIN SMALL LETTER U WITH MACRON */
#endif /* XK_LATIN4 */

/*
 * Latin 8
 */
#ifdef XK_LATIN8
#define UCS_Wcircumflex                0x0174  /* 0x1000174 LATIN CAPITAL LETTER W WITH CIRCUMFLEX */
#define UCS_wcircumflex                0x0175  /* 0x1000175 LATIN SMALL LETTER W WITH CIRCUMFLEX */
#define UCS_Ycircumflex                0x0176  /* 0x1000176 LATIN CAPITAL LETTER Y WITH CIRCUMFLEX */
#define UCS_ycircumflex                0x0177  /* 0x1000177 LATIN SMALL LETTER Y WITH CIRCUMFLEX */
#define UCS_Babovedot                  0x1E02  /* 0x1001e02 LATIN CAPITAL LETTER B WITH DOT ABOVE */
#define UCS_babovedot                  0x1E03  /* 0x1001e03 LATIN SMALL LETTER B WITH DOT ABOVE */
#define UCS_Dabovedot                  0x1E0A  /* 0x1001e0a LATIN CAPITAL LETTER D WITH DOT ABOVE */
#define UCS_dabovedot                  0x1E0B  /* 0x1001e0b LATIN SMALL LETTER D WITH DOT ABOVE */
#define UCS_Fabovedot                  0x1E1E  /* 0x1001e1e LATIN CAPITAL LETTER F WITH DOT ABOVE */
#define UCS_fabovedot                  0x1E1F  /* 0x1001e1f LATIN SMALL LETTER F WITH DOT ABOVE */
#define UCS_Mabovedot                  0x1E40  /* 0x1001e40 LATIN CAPITAL LETTER M WITH DOT ABOVE */
#define UCS_mabovedot                  0x1E41  /* 0x1001e41 LATIN SMALL LETTER M WITH DOT ABOVE */
#define UCS_Pabovedot                  0x1E56  /* 0x1001e56 LATIN CAPITAL LETTER P WITH DOT ABOVE */
#define UCS_pabovedot                  0x1E57  /* 0x1001e57 LATIN SMALL LETTER P WITH DOT ABOVE */
#define UCS_Sabovedot                  0x1E60  /* 0x1001e60 LATIN CAPITAL LETTER S WITH DOT ABOVE */
#define UCS_sabovedot                  0x1E61  /* 0x1001e61 LATIN SMALL LETTER S WITH DOT ABOVE */
#define UCS_Tabovedot                  0x1E6A  /* 0x1001e6a LATIN CAPITAL LETTER T WITH DOT ABOVE */
#define UCS_tabovedot                  0x1E6B  /* 0x1001e6b LATIN SMALL LETTER T WITH DOT ABOVE */
#define UCS_Wgrave                     0x1E80  /* 0x1001e80 LATIN CAPITAL LETTER W WITH GRAVE */
#define UCS_wgrave                     0x1E81  /* 0x1001e81 LATIN SMALL LETTER W WITH GRAVE */
#define UCS_Wacute                     0x1E82  /* 0x1001e82 LATIN CAPITAL LETTER W WITH ACUTE */
#define UCS_wacute                     0x1E83  /* 0x1001e83 LATIN SMALL LETTER W WITH ACUTE */
#define UCS_Wdiaeresis                 0x1E84  /* 0x1001e84 LATIN CAPITAL LETTER W WITH DIAERESIS */
#define UCS_wdiaeresis                 0x1E85  /* 0x1001e85 LATIN SMALL LETTER W WITH DIAERESIS */
#define UCS_Ygrave                     0x1EF2  /* 0x1001ef2 LATIN CAPITAL LETTER Y WITH GRAVE */
#define UCS_ygrave                     0x1EF3  /* 0x1001ef3 LATIN SMALL LETTER Y WITH GRAVE */
#endif /* XK_LATIN8 */

/*
 * Latin 9
 * Byte 3 = 0x13
 */

#ifdef XK_LATIN9
#define UCS_OE                            0x0152  /* 0x13bc LATIN CAPITAL LIGATURE OE */
#define UCS_oe                            0x0153  /* 0x13bd LATIN SMALL LIGATURE OE */
#define UCS_Ydiaeresis                    0x0178  /* 0x13be LATIN CAPITAL LETTER Y WITH DIAERESIS */
#endif /* XK_LATIN9 */

/*
 * Katakana
 * Byte 3 = 4
 */

#ifdef XK_KATAKANA
#define UCS_overline                      0x203E  /* 0x047e OVERLINE */
#define UCS_kana_fullstop                 0x3002  /* 0x04a1 IDEOGRAPHIC FULL STOP */
#define UCS_kana_openingbracket           0x300C  /* 0x04a2 LEFT CORNER BRACKET */
#define UCS_kana_closingbracket           0x300D  /* 0x04a3 RIGHT CORNER BRACKET */
#define UCS_kana_comma                    0x3001  /* 0x04a4 IDEOGRAPHIC COMMA */
#define UCS_kana_conjunctive              0x30FB  /* 0x04a5 KATAKANA MIDDLE DOT */
#define UCS_kana_WO                       0x30F2  /* 0x04a6 KATAKANA LETTER WO */
#define UCS_kana_a                        0x30A1  /* 0x04a7 KATAKANA LETTER SMALL A */
#define UCS_kana_i                        0x30A3  /* 0x04a8 KATAKANA LETTER SMALL I */
#define UCS_kana_u                        0x30A5  /* 0x04a9 KATAKANA LETTER SMALL U */
#define UCS_kana_e                        0x30A7  /* 0x04aa KATAKANA LETTER SMALL E */
#define UCS_kana_o                        0x30A9  /* 0x04ab KATAKANA LETTER SMALL O */
#define UCS_kana_ya                       0x30E3  /* 0x04ac KATAKANA LETTER SMALL YA */
#define UCS_kana_yu                       0x30E5  /* 0x04ad KATAKANA LETTER SMALL YU */
#define UCS_kana_yo                       0x30E7  /* 0x04ae KATAKANA LETTER SMALL YO */
#define UCS_kana_tsu                      0x30C3  /* 0x04af KATAKANA LETTER SMALL TU */
#define UCS_prolongedsound                0x30FC  /* 0x04b0 KATAKANA-HIRAGANA PROLONGED SOUND MARK */
#define UCS_kana_A                        0x30A2  /* 0x04b1 KATAKANA LETTER A */
#define UCS_kana_I                        0x30A4  /* 0x04b2 KATAKANA LETTER I */
#define UCS_kana_U                        0x30A6  /* 0x04b3 KATAKANA LETTER U */
#define UCS_kana_E                        0x30A8  /* 0x04b4 KATAKANA LETTER E */
#define UCS_kana_O                        0x30AA  /* 0x04b5 KATAKANA LETTER O */
#define UCS_kana_KA                       0x30AB  /* 0x04b6 KATAKANA LETTER KA */
#define UCS_kana_KI                       0x30AD  /* 0x04b7 KATAKANA LETTER KI */
#define UCS_kana_KU                       0x30AF  /* 0x04b8 KATAKANA LETTER KU */
#define UCS_kana_KE                       0x30B1  /* 0x04b9 KATAKANA LETTER KE */
#define UCS_kana_KO                       0x30B3  /* 0x04ba KATAKANA LETTER KO */
#define UCS_kana_SA                       0x30B5  /* 0x04bb KATAKANA LETTER SA */
#define UCS_kana_SHI                      0x30B7  /* 0x04bc KATAKANA LETTER SI */
#define UCS_kana_SU                       0x30B9  /* 0x04bd KATAKANA LETTER SU */
#define UCS_kana_SE                       0x30BB  /* 0x04be KATAKANA LETTER SE */
#define UCS_kana_SO                       0x30BD  /* 0x04bf KATAKANA LETTER SO */
#define UCS_kana_TA                       0x30BF  /* 0x04c0 KATAKANA LETTER TA */
#define UCS_kana_CHI                      0x30C1  /* 0x04c1 KATAKANA LETTER TI */
#define UCS_kana_TSU                      0x30C4  /* 0x04c2 KATAKANA LETTER TU */
#define UCS_kana_TE                       0x30C6  /* 0x04c3 KATAKANA LETTER TE */
#define UCS_kana_TO                       0x30C8  /* 0x04c4 KATAKANA LETTER TO */
#define UCS_kana_NA                       0x30CA  /* 0x04c5 KATAKANA LETTER NA */
#define UCS_kana_NI                       0x30CB  /* 0x04c6 KATAKANA LETTER NI */
#define UCS_kana_NU                       0x30CC  /* 0x04c7 KATAKANA LETTER NU */
#define UCS_kana_NE                       0x30CD  /* 0x04c8 KATAKANA LETTER NE */
#define UCS_kana_NO                       0x30CE  /* 0x04c9 KATAKANA LETTER NO */
#define UCS_kana_HA                       0x30CF  /* 0x04ca KATAKANA LETTER HA */
#define UCS_kana_HI                       0x30D2  /* 0x04cb KATAKANA LETTER HI */
#define UCS_kana_FU                       0x30D5  /* 0x04cc KATAKANA LETTER HU */
#define UCS_kana_HE                       0x30D8  /* 0x04cd KATAKANA LETTER HE */
#define UCS_kana_HO                       0x30DB  /* 0x04ce KATAKANA LETTER HO */
#define UCS_kana_MA                       0x30DE  /* 0x04cf KATAKANA LETTER MA */
#define UCS_kana_MI                       0x30DF  /* 0x04d0 KATAKANA LETTER MI */
#define UCS_kana_MU                       0x30E0  /* 0x04d1 KATAKANA LETTER MU */
#define UCS_kana_ME                       0x30E1  /* 0x04d2 KATAKANA LETTER ME */
#define UCS_kana_MO                       0x30E2  /* 0x04d3 KATAKANA LETTER MO */
#define UCS_kana_YA                       0x30E4  /* 0x04d4 KATAKANA LETTER YA */
#define UCS_kana_YU                       0x30E6  /* 0x04d5 KATAKANA LETTER YU */
#define UCS_kana_YO                       0x30E8  /* 0x04d6 KATAKANA LETTER YO */
#define UCS_kana_RA                       0x30E9  /* 0x04d7 KATAKANA LETTER RA */
#define UCS_kana_RI                       0x30EA  /* 0x04d8 KATAKANA LETTER RI */
#define UCS_kana_RU                       0x30EB  /* 0x04d9 KATAKANA LETTER RU */
#define UCS_kana_RE                       0x30EC  /* 0x04da KATAKANA LETTER RE */
#define UCS_kana_RO                       0x30ED  /* 0x04db KATAKANA LETTER RO */
#define UCS_kana_WA                       0x30EF  /* 0x04dc KATAKANA LETTER WA */
#define UCS_kana_N                        0x30F3  /* 0x04dd KATAKANA LETTER N */
#define UCS_voicedsound                   0x309B  /* 0x04de KATAKANA-HIRAGANA VOICED SOUND MARK */
#define UCS_semivoicedsound               0x309C  /* 0x04df KATAKANA-HIRAGANA SEMI-VOICED SOUND MARK */
#endif /* XK_KATAKANA */

/*
 * Arabic
 * Byte 3 = 5
 */

#ifdef XK_ARABIC
#define UCS_Arabic_semicolon              0x061B  /* 0x05bb ARABIC SEMICOLON */
#define UCS_Arabic_question_mark          0x061F  /* 0x05bf ARABIC QUESTION MARK */
#define UCS_Arabic_hamza                  0x0621  /* 0x05c1 ARABIC LETTER HAMZA */
#define UCS_Arabic_maddaonalef            0x0622  /* 0x05c2 ARABIC LETTER ALEF WITH MADDA ABOVE */
#define UCS_Arabic_hamzaonalef            0x0623  /* 0x05c3 ARABIC LETTER ALEF WITH HAMZA ABOVE */
#define UCS_Arabic_hamzaonwaw             0x0624  /* 0x05c4 ARABIC LETTER WAW WITH HAMZA ABOVE */
#define UCS_Arabic_hamzaunderalef         0x0625  /* 0x05c5 ARABIC LETTER ALEF WITH HAMZA BELOW */
#define UCS_Arabic_hamzaonyeh             0x0626  /* 0x05c6 ARABIC LETTER YEH WITH HAMZA ABOVE */
#define UCS_Arabic_alef                   0x0627  /* 0x05c7 ARABIC LETTER ALEF */
#define UCS_Arabic_beh                    0x0628  /* 0x05c8 ARABIC LETTER BEH */
#define UCS_Arabic_tehmarbuta             0x0629  /* 0x05c9 ARABIC LETTER TEH MARBUTA */
#define UCS_Arabic_teh                    0x062A  /* 0x05ca ARABIC LETTER TEH */
#define UCS_Arabic_theh                   0x062B  /* 0x05cb ARABIC LETTER THEH */
#define UCS_Arabic_jeem                   0x062C  /* 0x05cc ARABIC LETTER JEEM */
#define UCS_Arabic_hah                    0x062D  /* 0x05cd ARABIC LETTER HAH */
#define UCS_Arabic_khah                   0x062E  /* 0x05ce ARABIC LETTER KHAH */
#define UCS_Arabic_dal                    0x062F  /* 0x05cf ARABIC LETTER DAL */
#define UCS_Arabic_thal                   0x0630  /* 0x05d0 ARABIC LETTER THAL */
#define UCS_Arabic_ra                     0x0631  /* 0x05d1 ARABIC LETTER REH */
#define UCS_Arabic_zain                   0x0632  /* 0x05d2 ARABIC LETTER ZAIN */
#define UCS_Arabic_seen                   0x0633  /* 0x05d3 ARABIC LETTER SEEN */
#define UCS_Arabic_sheen                  0x0634  /* 0x05d4 ARABIC LETTER SHEEN */
#define UCS_Arabic_sad                    0x0635  /* 0x05d5 ARABIC LETTER SAD */
#define UCS_Arabic_dad                    0x0636  /* 0x05d6 ARABIC LETTER DAD */
#define UCS_Arabic_tah                    0x0637  /* 0x05d7 ARABIC LETTER TAH */
#define UCS_Arabic_zah                    0x0638  /* 0x05d8 ARABIC LETTER ZAH */
#define UCS_Arabic_ain                    0x0639  /* 0x05d9 ARABIC LETTER AIN */
#define UCS_Arabic_ghain                  0x063A  /* 0x05da ARABIC LETTER GHAIN */
#define UCS_Arabic_tatweel                0x0640  /* 0x05e0 ARABIC TATWEEL */
#define UCS_Arabic_feh                    0x0641  /* 0x05e1 ARABIC LETTER FEH */
#define UCS_Arabic_qaf                    0x0642  /* 0x05e2 ARABIC LETTER QAF */
#define UCS_Arabic_kaf                    0x0643  /* 0x05e3 ARABIC LETTER KAF */
#define UCS_Arabic_lam                    0x0644  /* 0x05e4 ARABIC LETTER LAM */
#define UCS_Arabic_meem                   0x0645  /* 0x05e5 ARABIC LETTER MEEM */
#define UCS_Arabic_noon                   0x0646  /* 0x05e6 ARABIC LETTER NOON */
#define UCS_Arabic_ha                     0x0647  /* 0x05e7 ARABIC LETTER HEH */
#define UCS_Arabic_waw                    0x0648  /* 0x05e8 ARABIC LETTER WAW */
#define UCS_Arabic_alefmaksura            0x0649  /* 0x05e9 ARABIC LETTER ALEF MAKSURA */
#define UCS_Arabic_yeh                    0x064A  /* 0x05ea ARABIC LETTER YEH */
#define UCS_Arabic_fathatan               0x064B  /* 0x05eb ARABIC FATHATAN */
#define UCS_Arabic_dammatan               0x064C  /* 0x05ec ARABIC DAMMATAN */
#define UCS_Arabic_kasratan               0x064D  /* 0x05ed ARABIC KASRATAN */
#define UCS_Arabic_fatha                  0x064E  /* 0x05ee ARABIC FATHA */
#define UCS_Arabic_damma                  0x064F  /* 0x05ef ARABIC DAMMA */
#define UCS_Arabic_kasra                  0x0650  /* 0x05f0 ARABIC KASRA */
#define UCS_Arabic_shadda                 0x0651  /* 0x05f1 ARABIC SHADDA */
#define UCS_Arabic_sukun                  0x0652  /* 0x05f2 ARABIC SUKUN */
#endif /* XK_ARABIC */

/*
 * Cyrillic
 * Byte 3 = 6
 */
#ifdef XK_CYRILLIC
#define UCS_Serbian_dje                   0x0452  /* 0x06a1 CYRILLIC SMALL LETTER DJE */
#define UCS_Macedonia_gje                 0x0453  /* 0x06a2 CYRILLIC SMALL LETTER GJE */
#define UCS_Cyrillic_io                   0x0451  /* 0x06a3 CYRILLIC SMALL LETTER IO */
#define UCS_Ukrainian_ie                  0x0454  /* 0x06a4 CYRILLIC SMALL LETTER UKRAINIAN IE */
#define UCS_Macedonia_dse                 0x0455  /* 0x06a5 CYRILLIC SMALL LETTER DZE */
#define UCS_Ukrainian_i                   0x0456  /* 0x06a6 CYRILLIC SMALL LETTER BYELORUSSIAN-UKRAINIAN I */
#define UCS_Ukrainian_yi                  0x0457  /* 0x06a7 CYRILLIC SMALL LETTER YI */
#define UCS_Cyrillic_je                   0x0458  /* 0x06a8 CYRILLIC SMALL LETTER JE */
#define UCS_Cyrillic_lje                  0x0459  /* 0x06a9 CYRILLIC SMALL LETTER LJE */
#define UCS_Cyrillic_nje                  0x045A  /* 0x06aa CYRILLIC SMALL LETTER NJE */
#define UCS_Serbian_tshe                  0x045B  /* 0x06ab CYRILLIC SMALL LETTER TSHE */
#define UCS_Macedonia_kje                 0x045C  /* 0x06ac CYRILLIC SMALL LETTER KJE */
#define UCS_Ukrainian_ghe_with_upturn     0x0491  /* 0x06ad CYRILLIC SMALL LETTER GHE WITH UPTURN */
#define UCS_Byelorussian_shortu           0x045E  /* 0x06ae CYRILLIC SMALL LETTER SHORT U */
#define UCS_Cyrillic_dzhe                 0x045F  /* 0x06af CYRILLIC SMALL LETTER DZHE */
#define UCS_numerosign                    0x2116  /* 0x06b0 NUMERO SIGN */
#define UCS_Serbian_DJE                   0x0402  /* 0x06b1 CYRILLIC CAPITAL LETTER DJE */
#define UCS_Macedonia_GJE                 0x0403  /* 0x06b2 CYRILLIC CAPITAL LETTER GJE */
#define UCS_Cyrillic_IO                   0x0401  /* 0x06b3 CYRILLIC CAPITAL LETTER IO */
#define UCS_Ukrainian_IE                  0x0404  /* 0x06b4 CYRILLIC CAPITAL LETTER UKRAINIAN IE */
#define UCS_Macedonia_DSE                 0x0405  /* 0x06b5 CYRILLIC CAPITAL LETTER DZE */
#define UCS_Ukrainian_I                   0x0406  /* 0x06b6 CYRILLIC CAPITAL LETTER BYELORUSSIAN-UKRAINIAN I */
#define UCS_Ukrainian_YI                  0x0407  /* 0x06b7 CYRILLIC CAPITAL LETTER YI */
#define UCS_Cyrillic_JE                   0x0408  /* 0x06b8 CYRILLIC CAPITAL LETTER JE */
#define UCS_Cyrillic_LJE                  0x0409  /* 0x06b9 CYRILLIC CAPITAL LETTER LJE */
#define UCS_Cyrillic_NJE                  0x040A  /* 0x06ba CYRILLIC CAPITAL LETTER NJE */
#define UCS_Serbian_TSHE                  0x040B  /* 0x06bb CYRILLIC CAPITAL LETTER TSHE */
#define UCS_Macedonia_KJE                 0x040C  /* 0x06bc CYRILLIC CAPITAL LETTER KJE */
#define UCS_Ukrainian_GHE_WITH_UPTURN     0x0490  /* 0x06bd CYRILLIC CAPITAL LETTER GHE WITH UPTURN */
#define UCS_Byelorussian_SHORTU           0x040E  /* 0x06be CYRILLIC CAPITAL LETTER SHORT U */
#define UCS_Cyrillic_DZHE                 0x040F  /* 0x06bf CYRILLIC CAPITAL LETTER DZHE */
#define UCS_Cyrillic_yu                   0x044E  /* 0x06c0 CYRILLIC SMALL LETTER YU */
#define UCS_Cyrillic_a                    0x0430  /* 0x06c1 CYRILLIC SMALL LETTER A */
#define UCS_Cyrillic_be                   0x0431  /* 0x06c2 CYRILLIC SMALL LETTER BE */
#define UCS_Cyrillic_tse                  0x0446  /* 0x06c3 CYRILLIC SMALL LETTER TSE */
#define UCS_Cyrillic_de                   0x0434  /* 0x06c4 CYRILLIC SMALL LETTER DE */
#define UCS_Cyrillic_ie                   0x0435  /* 0x06c5 CYRILLIC SMALL LETTER IE */
#define UCS_Cyrillic_ef                   0x0444  /* 0x06c6 CYRILLIC SMALL LETTER EF */
#define UCS_Cyrillic_ghe                  0x0433  /* 0x06c7 CYRILLIC SMALL LETTER GHE */
#define UCS_Cyrillic_ha                   0x0445  /* 0x06c8 CYRILLIC SMALL LETTER HA */
#define UCS_Cyrillic_i                    0x0438  /* 0x06c9 CYRILLIC SMALL LETTER I */
#define UCS_Cyrillic_shorti               0x0439  /* 0x06ca CYRILLIC SMALL LETTER SHORT I */
#define UCS_Cyrillic_ka                   0x043A  /* 0x06cb CYRILLIC SMALL LETTER KA */
#define UCS_Cyrillic_el                   0x043B  /* 0x06cc CYRILLIC SMALL LETTER EL */
#define UCS_Cyrillic_em                   0x043C  /* 0x06cd CYRILLIC SMALL LETTER EM */
#define UCS_Cyrillic_en                   0x043D  /* 0x06ce CYRILLIC SMALL LETTER EN */
#define UCS_Cyrillic_o                    0x043E  /* 0x06cf CYRILLIC SMALL LETTER O */
#define UCS_Cyrillic_pe                   0x043F  /* 0x06d0 CYRILLIC SMALL LETTER PE */
#define UCS_Cyrillic_ya                   0x044F  /* 0x06d1 CYRILLIC SMALL LETTER YA */
#define UCS_Cyrillic_er                   0x0440  /* 0x06d2 CYRILLIC SMALL LETTER ER */
#define UCS_Cyrillic_es                   0x0441  /* 0x06d3 CYRILLIC SMALL LETTER ES */
#define UCS_Cyrillic_te                   0x0442  /* 0x06d4 CYRILLIC SMALL LETTER TE */
#define UCS_Cyrillic_u                    0x0443  /* 0x06d5 CYRILLIC SMALL LETTER U */
#define UCS_Cyrillic_zhe                  0x0436  /* 0x06d6 CYRILLIC SMALL LETTER ZHE */
#define UCS_Cyrillic_ve                   0x0432  /* 0x06d7 CYRILLIC SMALL LETTER VE */
#define UCS_Cyrillic_softsign             0x044C  /* 0x06d8 CYRILLIC SMALL LETTER SOFT SIGN */
#define UCS_Cyrillic_yeru                 0x044B  /* 0x06d9 CYRILLIC SMALL LETTER YERU */
#define UCS_Cyrillic_ze                   0x0437  /* 0x06da CYRILLIC SMALL LETTER ZE */
#define UCS_Cyrillic_sha                  0x0448  /* 0x06db CYRILLIC SMALL LETTER SHA */
#define UCS_Cyrillic_e                    0x044D  /* 0x06dc CYRILLIC SMALL LETTER E */
#define UCS_Cyrillic_shcha                0x0449  /* 0x06dd CYRILLIC SMALL LETTER SHCHA */
#define UCS_Cyrillic_che                  0x0447  /* 0x06de CYRILLIC SMALL LETTER CHE */
#define UCS_Cyrillic_hardsign             0x044A  /* 0x06df CYRILLIC SMALL LETTER HARD SIGN */
#define UCS_Cyrillic_YU                   0x042E  /* 0x06e0 CYRILLIC CAPITAL LETTER YU */
#define UCS_Cyrillic_A                    0x0410  /* 0x06e1 CYRILLIC CAPITAL LETTER A */
#define UCS_Cyrillic_BE                   0x0411  /* 0x06e2 CYRILLIC CAPITAL LETTER BE */
#define UCS_Cyrillic_TSE                  0x0426  /* 0x06e3 CYRILLIC CAPITAL LETTER TSE */
#define UCS_Cyrillic_DE                   0x0414  /* 0x06e4 CYRILLIC CAPITAL LETTER DE */
#define UCS_Cyrillic_IE                   0x0415  /* 0x06e5 CYRILLIC CAPITAL LETTER IE */
#define UCS_Cyrillic_EF                   0x0424  /* 0x06e6 CYRILLIC CAPITAL LETTER EF */
#define UCS_Cyrillic_GHE                  0x0413  /* 0x06e7 CYRILLIC CAPITAL LETTER GHE */
#define UCS_Cyrillic_HA                   0x0425  /* 0x06e8 CYRILLIC CAPITAL LETTER HA */
#define UCS_Cyrillic_I                    0x0418  /* 0x06e9 CYRILLIC CAPITAL LETTER I */
#define UCS_Cyrillic_SHORTI               0x0419  /* 0x06ea CYRILLIC CAPITAL LETTER SHORT I */
#define UCS_Cyrillic_KA                   0x041A  /* 0x06eb CYRILLIC CAPITAL LETTER KA */
#define UCS_Cyrillic_EL                   0x041B  /* 0x06ec CYRILLIC CAPITAL LETTER EL */
#define UCS_Cyrillic_EM                   0x041C  /* 0x06ed CYRILLIC CAPITAL LETTER EM */
#define UCS_Cyrillic_EN                   0x041D  /* 0x06ee CYRILLIC CAPITAL LETTER EN */
#define UCS_Cyrillic_O                    0x041E  /* 0x06ef CYRILLIC CAPITAL LETTER O */
#define UCS_Cyrillic_PE                   0x041F  /* 0x06f0 CYRILLIC CAPITAL LETTER PE */
#define UCS_Cyrillic_YA                   0x042F  /* 0x06f1 CYRILLIC CAPITAL LETTER YA */
#define UCS_Cyrillic_ER                   0x0420  /* 0x06f2 CYRILLIC CAPITAL LETTER ER */
#define UCS_Cyrillic_ES                   0x0421  /* 0x06f3 CYRILLIC CAPITAL LETTER ES */
#define UCS_Cyrillic_TE                   0x0422  /* 0x06f4 CYRILLIC CAPITAL LETTER TE */
#define UCS_Cyrillic_U                    0x0423  /* 0x06f5 CYRILLIC CAPITAL LETTER U */
#define UCS_Cyrillic_ZHE                  0x0416  /* 0x06f6 CYRILLIC CAPITAL LETTER ZHE */
#define UCS_Cyrillic_VE                   0x0412  /* 0x06f7 CYRILLIC CAPITAL LETTER VE */
#define UCS_Cyrillic_SOFTSIGN             0x042C  /* 0x06f8 CYRILLIC CAPITAL LETTER SOFT SIGN */
#define UCS_Cyrillic_YERU                 0x042B  /* 0x06f9 CYRILLIC CAPITAL LETTER YERU */
#define UCS_Cyrillic_ZE                   0x0417  /* 0x06fa CYRILLIC CAPITAL LETTER ZE */
#define UCS_Cyrillic_SHA                  0x0428  /* 0x06fb CYRILLIC CAPITAL LETTER SHA */
#define UCS_Cyrillic_E                    0x042D  /* 0x06fc CYRILLIC CAPITAL LETTER E */
#define UCS_Cyrillic_SHCHA                0x0429  /* 0x06fd CYRILLIC CAPITAL LETTER SHCHA */
#define UCS_Cyrillic_CHE                  0x0427  /* 0x06fe CYRILLIC CAPITAL LETTER CHE */
#define UCS_Cyrillic_HARDSIGN             0x042A  /* 0x06ff CYRILLIC CAPITAL LETTER HARD SIGN */
#endif /* XK_CYRILLIC */

/*
 * Greek
 * (based on an early draft of, and not quite identical to, ISO/IEC 8859-7)
 * Byte 3 = 7
 */

#ifdef XK_GREEK
#define UCS_Greek_ALPHAaccent             0x0386  /* 0x07a1 GREEK CAPITAL LETTER ALPHA WITH TONOS */
#define UCS_Greek_EPSILONaccent           0x0388  /* 0x07a2 GREEK CAPITAL LETTER EPSILON WITH TONOS */
#define UCS_Greek_ETAaccent               0x0389  /* 0x07a3 GREEK CAPITAL LETTER ETA WITH TONOS */
#define UCS_Greek_IOTAaccent              0x038A  /* 0x07a4 GREEK CAPITAL LETTER IOTA WITH TONOS */
#define UCS_Greek_IOTAdieresis            0x03AA  /* 0x07a5 GREEK CAPITAL LETTER IOTA WITH DIALYTIKA */
#define UCS_Greek_OMICRONaccent           0x038C  /* 0x07a7 GREEK CAPITAL LETTER OMICRON WITH TONOS */
#define UCS_Greek_UPSILONaccent           0x038E  /* 0x07a8 GREEK CAPITAL LETTER UPSILON WITH TONOS */
#define UCS_Greek_UPSILONdieresis         0x03AB  /* 0x07a9 GREEK CAPITAL LETTER UPSILON WITH DIALYTIKA */
#define UCS_Greek_OMEGAaccent             0x038F  /* 0x07ab GREEK CAPITAL LETTER OMEGA WITH TONOS */
#define UCS_Greek_accentdieresis          0x0385  /* 0x07ae GREEK DIALYTIKA TONOS */
#define UCS_Greek_horizbar                0x2015  /* 0x07af HORIZONTAL BAR */
#define UCS_Greek_alphaaccent             0x03AC  /* 0x07b1 GREEK SMALL LETTER ALPHA WITH TONOS */
#define UCS_Greek_epsilonaccent           0x03AD  /* 0x07b2 GREEK SMALL LETTER EPSILON WITH TONOS */
#define UCS_Greek_etaaccent               0x03AE  /* 0x07b3 GREEK SMALL LETTER ETA WITH TONOS */
#define UCS_Greek_iotaaccent              0x03AF  /* 0x07b4 GREEK SMALL LETTER IOTA WITH TONOS */
#define UCS_Greek_iotadieresis            0x03CA  /* 0x07b5 GREEK SMALL LETTER IOTA WITH DIALYTIKA */
#define UCS_Greek_iotaaccentdieresis      0x0390  /* 0x07b6 GREEK SMALL LETTER IOTA WITH DIALYTIKA AND TONOS */
#define UCS_Greek_omicronaccent           0x03CC  /* 0x07b7 GREEK SMALL LETTER OMICRON WITH TONOS */
#define UCS_Greek_upsilonaccent           0x03CD  /* 0x07b8 GREEK SMALL LETTER UPSILON WITH TONOS */
#define UCS_Greek_upsilondieresis         0x03CB  /* 0x07b9 GREEK SMALL LETTER UPSILON WITH DIALYTIKA */
#define UCS_Greek_upsilonaccentdieresis   0x03B0  /* 0x07ba GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND TONOS */
#define UCS_Greek_omegaaccent             0x03CE  /* 0x07bb GREEK SMALL LETTER OMEGA WITH TONOS */
#define UCS_Greek_ALPHA                   0x0391  /* 0x07c1 GREEK CAPITAL LETTER ALPHA */
#define UCS_Greek_BETA                    0x0392  /* 0x07c2 GREEK CAPITAL LETTER BETA */
#define UCS_Greek_GAMMA                   0x0393  /* 0x07c3 GREEK CAPITAL LETTER GAMMA */
#define UCS_Greek_DELTA                   0x0394  /* 0x07c4 GREEK CAPITAL LETTER DELTA */
#define UCS_Greek_EPSILON                 0x0395  /* 0x07c5 GREEK CAPITAL LETTER EPSILON */
#define UCS_Greek_ZETA                    0x0396  /* 0x07c6 GREEK CAPITAL LETTER ZETA */
#define UCS_Greek_ETA                     0x0397  /* 0x07c7 GREEK CAPITAL LETTER ETA */
#define UCS_Greek_THETA                   0x0398  /* 0x07c8 GREEK CAPITAL LETTER THETA */
#define UCS_Greek_IOTA                    0x0399  /* 0x07c9 GREEK CAPITAL LETTER IOTA */
#define UCS_Greek_KAPPA                   0x039A  /* 0x07ca GREEK CAPITAL LETTER KAPPA */
#define UCS_Greek_LAMDA                   0x039B  /* 0x07cb GREEK CAPITAL LETTER LAMDA */
#define UCS_Greek_LAMBDA                  0x039B  /* 0x07cb GREEK CAPITAL LETTER LAMDA */
#define UCS_Greek_MU                      0x039C  /* 0x07cc GREEK CAPITAL LETTER MU */
#define UCS_Greek_NU                      0x039D  /* 0x07cd GREEK CAPITAL LETTER NU */
#define UCS_Greek_XI                      0x039E  /* 0x07ce GREEK CAPITAL LETTER XI */
#define UCS_Greek_OMICRON                 0x039F  /* 0x07cf GREEK CAPITAL LETTER OMICRON */
#define UCS_Greek_PI                      0x03A0  /* 0x07d0 GREEK CAPITAL LETTER PI */
#define UCS_Greek_RHO                     0x03A1  /* 0x07d1 GREEK CAPITAL LETTER RHO */
#define UCS_Greek_SIGMA                   0x03A3  /* 0x07d2 GREEK CAPITAL LETTER SIGMA */
#define UCS_Greek_TAU                     0x03A4  /* 0x07d4 GREEK CAPITAL LETTER TAU */
#define UCS_Greek_UPSILON                 0x03A5  /* 0x07d5 GREEK CAPITAL LETTER UPSILON */
#define UCS_Greek_PHI                     0x03A6  /* 0x07d6 GREEK CAPITAL LETTER PHI */
#define UCS_Greek_CHI                     0x03A7  /* 0x07d7 GREEK CAPITAL LETTER CHI */
#define UCS_Greek_PSI                     0x03A8  /* 0x07d8 GREEK CAPITAL LETTER PSI */
#define UCS_Greek_OMEGA                   0x03A9  /* 0x07d9 GREEK CAPITAL LETTER OMEGA */
#define UCS_Greek_alpha                   0x03B1  /* 0x07e1 GREEK SMALL LETTER ALPHA */
#define UCS_Greek_beta                    0x03B2  /* 0x07e2 GREEK SMALL LETTER BETA */
#define UCS_Greek_gamma                   0x03B3  /* 0x07e3 GREEK SMALL LETTER GAMMA */
#define UCS_Greek_delta                   0x03B4  /* 0x07e4 GREEK SMALL LETTER DELTA */
#define UCS_Greek_epsilon                 0x03B5  /* 0x07e5 GREEK SMALL LETTER EPSILON */
#define UCS_Greek_zeta                    0x03B6  /* 0x07e6 GREEK SMALL LETTER ZETA */
#define UCS_Greek_eta                     0x03B7  /* 0x07e7 GREEK SMALL LETTER ETA */
#define UCS_Greek_theta                   0x03B8  /* 0x07e8 GREEK SMALL LETTER THETA */
#define UCS_Greek_iota                    0x03B9  /* 0x07e9 GREEK SMALL LETTER IOTA */
#define UCS_Greek_kappa                   0x03BA  /* 0x07ea GREEK SMALL LETTER KAPPA */
#define UCS_Greek_lamda                   0x03BB  /* 0x07eb GREEK SMALL LETTER LAMDA */
#define UCS_Greek_lambda                  0x03BB  /* 0x07eb GREEK SMALL LETTER LAMDA */
#define UCS_Greek_mu                      0x03BC  /* 0x07ec GREEK SMALL LETTER MU */
#define UCS_Greek_nu                      0x03BD  /* 0x07ed GREEK SMALL LETTER NU */
#define UCS_Greek_xi                      0x03BE  /* 0x07ee GREEK SMALL LETTER XI */
#define UCS_Greek_omicron                 0x03BF  /* 0x07ef GREEK SMALL LETTER OMICRON */
#define UCS_Greek_pi                      0x03C0  /* 0x07f0 GREEK SMALL LETTER PI */
#define UCS_Greek_rho                     0x03C1  /* 0x07f1 GREEK SMALL LETTER RHO */
#define UCS_Greek_sigma                   0x03C3  /* 0x07f2 GREEK SMALL LETTER SIGMA */
#define UCS_Greek_finalsmallsigma         0x03C2  /* 0x07f3 GREEK SMALL LETTER FINAL SIGMA */
#define UCS_Greek_tau                     0x03C4  /* 0x07f4 GREEK SMALL LETTER TAU */
#define UCS_Greek_upsilon                 0x03C5  /* 0x07f5 GREEK SMALL LETTER UPSILON */
#define UCS_Greek_phi                     0x03C6  /* 0x07f6 GREEK SMALL LETTER PHI */
#define UCS_Greek_chi                     0x03C7  /* 0x07f7 GREEK SMALL LETTER CHI */
#define UCS_Greek_psi                     0x03C8  /* 0x07f8 GREEK SMALL LETTER PSI */
#define UCS_Greek_omega                   0x03C9  /* 0x07f9 GREEK SMALL LETTER OMEGA */
#endif /* XK_GREEK */

/*
 * Technical
 * (from the DEC VT330/VT420 Technical Character Set, http://vt100.net/charsets/technical.html)
 * Byte 3 = 8
 */

#ifdef XK_TECHNICAL
#define UCS_leftradical                   0x23B7  /* 0x08a1 RADICAL SYMBOL BOTTOM */
#define UCS_topleftradical                0x250C  /* 0x08a2 BOX DRAWINGS LIGHT DOWN AND RIGHT */
#define UCS_horizconnector                0x2500  /* 0x08a3 BOX DRAWINGS LIGHT HORIZONTAL */
#define UCS_topintegral                   0x2320  /* 0x08a4 TOP HALF INTEGRAL */
#define UCS_botintegral                   0x2321  /* 0x08a5 BOTTOM HALF INTEGRAL */
#define UCS_vertconnector                 0x2502  /* 0x08a6 BOX DRAWINGS LIGHT VERTICAL */
#define UCS_topleftsqbracket              0x23A1  /* 0x08a7 LEFT SQUARE BRACKET UPPER CORNER */
#define UCS_botleftsqbracket              0x23A3  /* 0x08a8 LEFT SQUARE BRACKET LOWER CORNER */
#define UCS_toprightsqbracket             0x23A4  /* 0x08a9 RIGHT SQUARE BRACKET UPPER CORNER */
#define UCS_botrightsqbracket             0x23A6  /* 0x08aa RIGHT SQUARE BRACKET LOWER CORNER */
#define UCS_topleftparens                 0x239B  /* 0x08ab LEFT PARENTHESIS UPPER HOOK */
#define UCS_botleftparens                 0x239D  /* 0x08ac LEFT PARENTHESIS LOWER HOOK */
#define UCS_toprightparens                0x239E  /* 0x08ad RIGHT PARENTHESIS UPPER HOOK */
#define UCS_botrightparens                0x23A0  /* 0x08ae RIGHT PARENTHESIS LOWER HOOK */
#define UCS_leftmiddlecurlybrace          0x23A8  /* 0x08af LEFT CURLY BRACKET MIDDLE PIECE */
#define UCS_rightmiddlecurlybrace         0x23AC  /* 0x08b0 RIGHT CURLY BRACKET MIDDLE PIECE */
#define UCS_lessthanequal                 0x2264  /* 0x08bc LESS-THAN OR EQUAL TO */
#define UCS_notequal                      0x2260  /* 0x08bd NOT EQUAL TO */
#define UCS_greaterthanequal              0x2265  /* 0x08be GREATER-THAN OR EQUAL TO */
#define UCS_integral                      0x222B  /* 0x08bf INTEGRAL */
#define UCS_therefore                     0x2234  /* 0x08c0 THEREFORE */
#define UCS_variation                     0x221D  /* 0x08c1 PROPORTIONAL TO */
#define UCS_infinity                      0x221E  /* 0x08c2 INFINITY */
#define UCS_nabla                         0x2207  /* 0x08c5 NABLA */
#define UCS_approximate                   0x223C  /* 0x08c8 TILDE OPERATOR */
#define UCS_similarequal                  0x2243  /* 0x08c9 ASYMPTOTICALLY EQUAL TO */
#define UCS_ifonlyif                      0x21D4  /* 0x08cd LEFT RIGHT DOUBLE ARROW */
#define UCS_implies                       0x21D2  /* 0x08ce RIGHTWARDS DOUBLE ARROW */
#define UCS_identical                     0x2261  /* 0x08cf IDENTICAL TO */
#define UCS_radical                       0x221A  /* 0x08d6 SQUARE ROOT */
#define UCS_includedin                    0x2282  /* 0x08da SUBSET OF */
#define UCS_includes                      0x2283  /* 0x08db SUPERSET OF */
#define UCS_intersection                  0x2229  /* 0x08dc INTERSECTION */
#define UCS_union                         0x222A  /* 0x08dd UNION */
#define UCS_logicaland                    0x2227  /* 0x08de LOGICAL AND */
#define UCS_logicalor                     0x2228  /* 0x08df LOGICAL OR */
#define UCS_partialderivative             0x2202  /* 0x08ef PARTIAL DIFFERENTIAL */
#define UCS_function                      0x0192  /* 0x08f6 LATIN SMALL LETTER F WITH HOOK */
#define UCS_leftarrow                     0x2190  /* 0x08fb LEFTWARDS ARROW */
#define UCS_uparrow                       0x2191  /* 0x08fc UPWARDS ARROW */
#define UCS_rightarrow                    0x2192  /* 0x08fd RIGHTWARDS ARROW */
#define UCS_downarrow                     0x2193  /* 0x08fe DOWNWARDS ARROW */
#endif /* XK_TECHNICAL */

/*
 * Special
 * (from the DEC VT100 Special Graphics Character Set)
 * Byte 3 = 9
 */

#ifdef XK_SPECIAL
#define UCS_soliddiamond                  0x25C6  /* 0x09e0 BLACK DIAMOND */
#define UCS_checkerboard                  0x2592  /* 0x09e1 MEDIUM SHADE */
#define UCS_ht                            0x2409  /* 0x09e2 SYMBOL FOR HORIZONTAL TABULATION */
#define UCS_ff                            0x240C  /* 0x09e3 SYMBOL FOR FORM FEED */
#define UCS_cr                            0x240D  /* 0x09e4 SYMBOL FOR CARRIAGE RETURN */
#define UCS_lf                            0x240A  /* 0x09e5 SYMBOL FOR LINE FEED */
#define UCS_nl                            0x2424  /* 0x09e8 SYMBOL FOR NEWLINE */
#define UCS_vt                            0x240B  /* 0x09e9 SYMBOL FOR VERTICAL TABULATION */
#define UCS_lowrightcorner                0x2518  /* 0x09ea BOX DRAWINGS LIGHT UP AND LEFT */
#define UCS_uprightcorner                 0x2510  /* 0x09eb BOX DRAWINGS LIGHT DOWN AND LEFT */
#define UCS_upleftcorner                  0x250C  /* 0x09ec BOX DRAWINGS LIGHT DOWN AND RIGHT */
#define UCS_lowleftcorner                 0x2514  /* 0x09ed BOX DRAWINGS LIGHT UP AND RIGHT */
#define UCS_crossinglines                 0x253C  /* 0x09ee BOX DRAWINGS LIGHT VERTICAL AND HORIZONTAL */
#define UCS_horizlinescan1                0x23BA  /* 0x09ef HORIZONTAL SCAN LINE-1 */
#define UCS_horizlinescan3                0x23BB  /* 0x09f0 HORIZONTAL SCAN LINE-3 */
#define UCS_horizlinescan5                0x2500  /* 0x09f1 BOX DRAWINGS LIGHT HORIZONTAL */
#define UCS_horizlinescan7                0x23BC  /* 0x09f2 HORIZONTAL SCAN LINE-7 */
#define UCS_horizlinescan9                0x23BD  /* 0x09f3 HORIZONTAL SCAN LINE-9 */
#define UCS_leftt                         0x251C  /* 0x09f4 BOX DRAWINGS LIGHT VERTICAL AND RIGHT */
#define UCS_rightt                        0x2524  /* 0x09f5 BOX DRAWINGS LIGHT VERTICAL AND LEFT */
#define UCS_bott                          0x2534  /* 0x09f6 BOX DRAWINGS LIGHT UP AND HORIZONTAL */
#define UCS_topt                          0x252C  /* 0x09f7 BOX DRAWINGS LIGHT DOWN AND HORIZONTAL */
#define UCS_vertbar                       0x2502  /* 0x09f8 BOX DRAWINGS LIGHT VERTICAL */
#endif /* XK_SPECIAL */

/*
 * Publishing
 * (these are probably from a long forgotten DEC Publishing
 * font that once shipped with DECwrite)
 * Byte 3 = 0x0a
 */

#ifdef XK_PUBLISHING
#define UCS_emspace                       0x2003  /* 0x0aa1 EM SPACE */
#define UCS_enspace                       0x2002  /* 0x0aa2 EN SPACE */
#define UCS_em3space                      0x2004  /* 0x0aa3 THREE-PER-EM SPACE */
#define UCS_em4space                      0x2005  /* 0x0aa4 FOUR-PER-EM SPACE */
#define UCS_digitspace                    0x2007  /* 0x0aa5 FIGURE SPACE */
#define UCS_punctspace                    0x2008  /* 0x0aa6 PUNCTUATION SPACE */
#define UCS_thinspace                     0x2009  /* 0x0aa7 THIN SPACE */
#define UCS_hairspace                     0x200A  /* 0x0aa8 HAIR SPACE */
#define UCS_emdash                        0x2014  /* 0x0aa9 EM DASH */
#define UCS_endash                        0x2013  /* 0x0aaa EN DASH */
#define UCS_signifblank                   0x2423  /* 0x0aac OPEN BOX */
#define UCS_ellipsis                      0x2026  /* 0x0aae HORIZONTAL ELLIPSIS */
#define UCS_doubbaselinedot               0x2025  /* 0x0aaf TWO DOT LEADER */
#define UCS_onethird                      0x2153  /* 0x0ab0 VULGAR FRACTION ONE THIRD */
#define UCS_twothirds                     0x2154  /* 0x0ab1 VULGAR FRACTION TWO THIRDS */
#define UCS_onefifth                      0x2155  /* 0x0ab2 VULGAR FRACTION ONE FIFTH */
#define UCS_twofifths                     0x2156  /* 0x0ab3 VULGAR FRACTION TWO FIFTHS */
#define UCS_threefifths                   0x2157  /* 0x0ab4 VULGAR FRACTION THREE FIFTHS */
#define UCS_fourfifths                    0x2158  /* 0x0ab5 VULGAR FRACTION FOUR FIFTHS */
#define UCS_onesixth                      0x2159  /* 0x0ab6 VULGAR FRACTION ONE SIXTH */
#define UCS_fivesixths                    0x215A  /* 0x0ab7 VULGAR FRACTION FIVE SIXTHS */
#define UCS_careof                        0x2105  /* 0x0ab8 CARE OF */
#define UCS_figdash                       0x2012  /* 0x0abb FIGURE DASH */
#define UCS_leftanglebracket              0x27E8  /* 0x0abc MATHEMATICAL LEFT ANGLE BRACKET */
#define UCS_decimalpoint                  0x002E  /* 0x0abd FULL STOP */
#define UCS_rightanglebracket             0x27E9  /* 0x0abe MATHEMATICAL RIGHT ANGLE BRACKET */
#define UCS_oneeighth                     0x215B  /* 0x0ac3 VULGAR FRACTION ONE EIGHTH */
#define UCS_threeeighths                  0x215C  /* 0x0ac4 VULGAR FRACTION THREE EIGHTHS */
#define UCS_fiveeighths                   0x215D  /* 0x0ac5 VULGAR FRACTION FIVE EIGHTHS */
#define UCS_seveneighths                  0x215E  /* 0x0ac6 VULGAR FRACTION SEVEN EIGHTHS */
#define UCS_trademark                     0x2122  /* 0x0ac9 TRADE MARK SIGN */
#define UCS_signaturemark                 0x2613  /* 0x0aca SALTIRE */
#define UCS_leftopentriangle              0x25C1  /* 0x0acc WHITE LEFT-POINTING TRIANGLE */
#define UCS_rightopentriangle             0x25B7  /* 0x0acd WHITE RIGHT-POINTING TRIANGLE */
#define UCS_emopencircle                  0x25CB  /* 0x0ace WHITE CIRCLE */
#define UCS_emopenrectangle               0x25AF  /* 0x0acf WHITE VERTICAL RECTANGLE */
#define UCS_leftsinglequotemark           0x2018  /* 0x0ad0 LEFT SINGLE QUOTATION MARK */
#define UCS_rightsinglequotemark          0x2019  /* 0x0ad1 RIGHT SINGLE QUOTATION MARK */
#define UCS_leftdoublequotemark           0x201C  /* 0x0ad2 LEFT DOUBLE QUOTATION MARK */
#define UCS_rightdoublequotemark          0x201D  /* 0x0ad3 RIGHT DOUBLE QUOTATION MARK */
#define UCS_prescription                  0x211E  /* 0x0ad4 PRESCRIPTION TAKE */
#define UCS_permille                      0x2030  /* 0x0ad5 PER MILLE SIGN */
#define UCS_minutes                       0x2032  /* 0x0ad6 PRIME */
#define UCS_seconds                       0x2033  /* 0x0ad7 DOUBLE PRIME */
#define UCS_latincross                    0x271D  /* 0x0ad9 LATIN CROSS */
#define UCS_filledrectbullet              0x25AC  /* 0x0adb BLACK RECTANGLE */
#define UCS_filledlefttribullet           0x25C0  /* 0x0adc BLACK LEFT-POINTING TRIANGLE */
#define UCS_filledrighttribullet          0x25B6  /* 0x0add BLACK RIGHT-POINTING TRIANGLE */
#define UCS_emfilledcircle                0x25CF  /* 0x0ade BLACK CIRCLE */
#define UCS_emfilledrect                  0x25AE  /* 0x0adf BLACK VERTICAL RECTANGLE */
#define UCS_enopencircbullet              0x25E6  /* 0x0ae0 WHITE BULLET */
#define UCS_enopensquarebullet            0x25AB  /* 0x0ae1 WHITE SMALL SQUARE */
#define UCS_openrectbullet                0x25AD  /* 0x0ae2 WHITE RECTANGLE */
#define UCS_opentribulletup               0x25B3  /* 0x0ae3 WHITE UP-POINTING TRIANGLE */
#define UCS_opentribulletdown             0x25BD  /* 0x0ae4 WHITE DOWN-POINTING TRIANGLE */
#define UCS_openstar                      0x2606  /* 0x0ae5 WHITE STAR */
#define UCS_enfilledcircbullet            0x2022  /* 0x0ae6 BULLET */
#define UCS_enfilledsqbullet              0x25AA  /* 0x0ae7 BLACK SMALL SQUARE */
#define UCS_filledtribulletup             0x25B2  /* 0x0ae8 BLACK UP-POINTING TRIANGLE */
#define UCS_filledtribulletdown           0x25BC  /* 0x0ae9 BLACK DOWN-POINTING TRIANGLE */
#define UCS_leftpointer                   0x261C  /* 0x0aea WHITE LEFT POINTING INDEX */
#define UCS_rightpointer                  0x261E  /* 0x0aeb WHITE RIGHT POINTING INDEX */
#define UCS_club                          0x2663  /* 0x0aec BLACK CLUB SUIT */
#define UCS_diamond                       0x2666  /* 0x0aed BLACK DIAMOND SUIT */
#define UCS_heart                         0x2665  /* 0x0aee BLACK HEART SUIT */
#define UCS_maltesecross                  0x2720  /* 0x0af0 MALTESE CROSS */
#define UCS_dagger                        0x2020  /* 0x0af1 DAGGER */
#define UCS_doubledagger                  0x2021  /* 0x0af2 DOUBLE DAGGER */
#define UCS_checkmark                     0x2713  /* 0x0af3 CHECK MARK */
#define UCS_ballotcross                   0x2717  /* 0x0af4 BALLOT X */
#define UCS_musicalsharp                  0x266F  /* 0x0af5 MUSIC SHARP SIGN */
#define UCS_musicalflat                   0x266D  /* 0x0af6 MUSIC FLAT SIGN */
#define UCS_malesymbol                    0x2642  /* 0x0af7 MALE SIGN */
#define UCS_femalesymbol                  0x2640  /* 0x0af8 FEMALE SIGN */
#define UCS_telephone                     0x260E  /* 0x0af9 BLACK TELEPHONE */
#define UCS_telephonerecorder             0x2315  /* 0x0afa TELEPHONE RECORDER */
#define UCS_phonographcopyright           0x2117  /* 0x0afb SOUND RECORDING COPYRIGHT */
#define UCS_caret                         0x2038  /* 0x0afc CARET */
#define UCS_singlelowquotemark            0x201A  /* 0x0afd SINGLE LOW-9 QUOTATION MARK */
#define UCS_doublelowquotemark            0x201E  /* 0x0afe DOUBLE LOW-9 QUOTATION MARK */
#endif /* XK_PUBLISHING */

/*
 * APL
 * Byte 3 = 0x0b
 */

#ifdef XK_APL
#define UCS_leftcaret                     0x003C  /* 0x0ba3 LESS-THAN SIGN */
#define UCS_rightcaret                    0x003E  /* 0x0ba6 GREATER-THAN SIGN */
#define UCS_downcaret                     0x2228  /* 0x0ba8 LOGICAL OR */
#define UCS_upcaret                       0x2227  /* 0x0ba9 LOGICAL AND */
#define UCS_overbar                       0x00AF  /* 0x0bc0 MACRON */
#define UCS_downtack                      0x22A4  /* 0x0bc2 DOWN TACK */
#define UCS_upshoe                        0x2229  /* 0x0bc3 INTERSECTION */
#define UCS_downstile                     0x230A  /* 0x0bc4 LEFT FLOOR */
#define UCS_underbar                      0x005F  /* 0x0bc6 LOW LINE */
#define UCS_jot                           0x2218  /* 0x0bca RING OPERATOR */
#define UCS_quad                          0x2395  /* 0x0bcc APL FUNCTIONAL SYMBOL QUAD */
#define UCS_uptack                        0x22A5  /* 0x0bce UP TACK */
#define UCS_circle                        0x25CB  /* 0x0bcf WHITE CIRCLE */
#define UCS_upstile                       0x2308  /* 0x0bd3 LEFT CEILING */
#define UCS_downshoe                      0x222A  /* 0x0bd6 UNION */
#define UCS_rightshoe                     0x2283  /* 0x0bd8 SUPERSET OF */
#define UCS_leftshoe                      0x2282  /* 0x0bda SUBSET OF */
#define UCS_lefttack                      0x22A3  /* 0x0bdc LEFT TACK */
#define UCS_righttack                     0x22A2  /* 0x0bfc RIGHT TACK */
#endif /* XK_APL */

/*
 * Hebrew
 * Byte 3 = 0x0c
 */

#ifdef XK_HEBREW
#define UCS_hebrew_doublelowline          0x2017  /* 0x0cdf DOUBLE LOW LINE */
#define UCS_hebrew_aleph                  0x05D0  /* 0x0ce0 HEBREW LETTER ALEF */
#define UCS_hebrew_bet                    0x05D1  /* 0x0ce1 HEBREW LETTER BET */
#define UCS_hebrew_gimel                  0x05D2  /* 0x0ce2 HEBREW LETTER GIMEL */
#define UCS_hebrew_dalet                  0x05D3  /* 0x0ce3 HEBREW LETTER DALET */
#define UCS_hebrew_he                     0x05D4  /* 0x0ce4 HEBREW LETTER HE */
#define UCS_hebrew_waw                    0x05D5  /* 0x0ce5 HEBREW LETTER VAV */
#define UCS_hebrew_zain                   0x05D6  /* 0x0ce6 HEBREW LETTER ZAYIN */
#define UCS_hebrew_chet                   0x05D7  /* 0x0ce7 HEBREW LETTER HET */
#define UCS_hebrew_tet                    0x05D8  /* 0x0ce8 HEBREW LETTER TET */
#define UCS_hebrew_yod                    0x05D9  /* 0x0ce9 HEBREW LETTER YOD */
#define UCS_hebrew_finalkaph              0x05DA  /* 0x0cea HEBREW LETTER FINAL KAF */
#define UCS_hebrew_kaph                   0x05DB  /* 0x0ceb HEBREW LETTER KAF */
#define UCS_hebrew_lamed                  0x05DC  /* 0x0cec HEBREW LETTER LAMED */
#define UCS_hebrew_finalmem               0x05DD  /* 0x0ced HEBREW LETTER FINAL MEM */
#define UCS_hebrew_mem                    0x05DE  /* 0x0cee HEBREW LETTER MEM */
#define UCS_hebrew_finalnun               0x05DF  /* 0x0cef HEBREW LETTER FINAL NUN */
#define UCS_hebrew_nun                    0x05E0  /* 0x0cf0 HEBREW LETTER NUN */
#define UCS_hebrew_samech                 0x05E1  /* 0x0cf1 HEBREW LETTER SAMEKH */
#define UCS_hebrew_ayin                   0x05E2  /* 0x0cf2 HEBREW LETTER AYIN */
#define UCS_hebrew_finalpe                0x05E3  /* 0x0cf3 HEBREW LETTER FINAL PE */
#define UCS_hebrew_pe                     0x05E4  /* 0x0cf4 HEBREW LETTER PE */
#define UCS_hebrew_finalzade              0x05E5  /* 0x0cf5 HEBREW LETTER FINAL TSADI */
#define UCS_hebrew_zade                   0x05E6  /* 0x0cf6 HEBREW LETTER TSADI */
#define UCS_hebrew_qoph                   0x05E7  /* 0x0cf7 HEBREW LETTER QOF */
#define UCS_hebrew_resh                   0x05E8  /* 0x0cf8 HEBREW LETTER RESH */
#define UCS_hebrew_shin                   0x05E9  /* 0x0cf9 HEBREW LETTER SHIN */
#define UCS_hebrew_taw                    0x05EA  /* 0x0cfa HEBREW LETTER TAV */
#endif /* XK_HEBREW */

/*
 * Thai
 * Byte 3 = 0x0d
 */

#ifdef XK_THAI
#define UCS_Thai_kokai                    0x0E01  /* 0x0da1 THAI CHARACTER KO KAI */
#define UCS_Thai_khokhai                  0x0E02  /* 0x0da2 THAI CHARACTER KHO KHAI */
#define UCS_Thai_khokhuat                 0x0E03  /* 0x0da3 THAI CHARACTER KHO KHUAT */
#define UCS_Thai_khokhwai                 0x0E04  /* 0x0da4 THAI CHARACTER KHO KHWAI */
#define UCS_Thai_khokhon                  0x0E05  /* 0x0da5 THAI CHARACTER KHO KHON */
#define UCS_Thai_khorakhang               0x0E06  /* 0x0da6 THAI CHARACTER KHO RAKHANG */
#define UCS_Thai_ngongu                   0x0E07  /* 0x0da7 THAI CHARACTER NGO NGU */
#define UCS_Thai_chochan                  0x0E08  /* 0x0da8 THAI CHARACTER CHO CHAN */
#define UCS_Thai_choching                 0x0E09  /* 0x0da9 THAI CHARACTER CHO CHING */
#define UCS_Thai_chochang                 0x0E0A  /* 0x0daa THAI CHARACTER CHO CHANG */
#define UCS_Thai_soso                     0x0E0B  /* 0x0dab THAI CHARACTER SO SO */
#define UCS_Thai_chochoe                  0x0E0C  /* 0x0dac THAI CHARACTER CHO CHOE */
#define UCS_Thai_yoying                   0x0E0D  /* 0x0dad THAI CHARACTER YO YING */
#define UCS_Thai_dochada                  0x0E0E  /* 0x0dae THAI CHARACTER DO CHADA */
#define UCS_Thai_topatak                  0x0E0F  /* 0x0daf THAI CHARACTER TO PATAK */
#define UCS_Thai_thothan                  0x0E10  /* 0x0db0 THAI CHARACTER THO THAN */
#define UCS_Thai_thonangmontho            0x0E11  /* 0x0db1 THAI CHARACTER THO NANGMONTHO */
#define UCS_Thai_thophuthao               0x0E12  /* 0x0db2 THAI CHARACTER THO PHUTHAO */
#define UCS_Thai_nonen                    0x0E13  /* 0x0db3 THAI CHARACTER NO NEN */
#define UCS_Thai_dodek                    0x0E14  /* 0x0db4 THAI CHARACTER DO DEK */
#define UCS_Thai_totao                    0x0E15  /* 0x0db5 THAI CHARACTER TO TAO */
#define UCS_Thai_thothung                 0x0E16  /* 0x0db6 THAI CHARACTER THO THUNG */
#define UCS_Thai_thothahan                0x0E17  /* 0x0db7 THAI CHARACTER THO THAHAN */
#define UCS_Thai_thothong                 0x0E18  /* 0x0db8 THAI CHARACTER THO THONG */
#define UCS_Thai_nonu                     0x0E19  /* 0x0db9 THAI CHARACTER NO NU */
#define UCS_Thai_bobaimai                 0x0E1A  /* 0x0dba THAI CHARACTER BO BAIMAI */
#define UCS_Thai_popla                    0x0E1B  /* 0x0dbb THAI CHARACTER PO PLA */
#define UCS_Thai_phophung                 0x0E1C  /* 0x0dbc THAI CHARACTER PHO PHUNG */
#define UCS_Thai_fofa                     0x0E1D  /* 0x0dbd THAI CHARACTER FO FA */
#define UCS_Thai_phophan                  0x0E1E  /* 0x0dbe THAI CHARACTER PHO PHAN */
#define UCS_Thai_fofan                    0x0E1F  /* 0x0dbf THAI CHARACTER FO FAN */
#define UCS_Thai_phosamphao               0x0E20  /* 0x0dc0 THAI CHARACTER PHO SAMPHAO */
#define UCS_Thai_moma                     0x0E21  /* 0x0dc1 THAI CHARACTER MO MA */
#define UCS_Thai_yoyak                    0x0E22  /* 0x0dc2 THAI CHARACTER YO YAK */
#define UCS_Thai_rorua                    0x0E23  /* 0x0dc3 THAI CHARACTER RO RUA */
#define UCS_Thai_ru                       0x0E24  /* 0x0dc4 THAI CHARACTER RU */
#define UCS_Thai_loling                   0x0E25  /* 0x0dc5 THAI CHARACTER LO LING */
#define UCS_Thai_lu                       0x0E26  /* 0x0dc6 THAI CHARACTER LU */
#define UCS_Thai_wowaen                   0x0E27  /* 0x0dc7 THAI CHARACTER WO WAEN */
#define UCS_Thai_sosala                   0x0E28  /* 0x0dc8 THAI CHARACTER SO SALA */
#define UCS_Thai_sorusi                   0x0E29  /* 0x0dc9 THAI CHARACTER SO RUSI */
#define UCS_Thai_sosua                    0x0E2A  /* 0x0dca THAI CHARACTER SO SUA */
#define UCS_Thai_hohip                    0x0E2B  /* 0x0dcb THAI CHARACTER HO HIP */
#define UCS_Thai_lochula                  0x0E2C  /* 0x0dcc THAI CHARACTER LO CHULA */
#define UCS_Thai_oang                     0x0E2D  /* 0x0dcd THAI CHARACTER O ANG */
#define UCS_Thai_honokhuk                 0x0E2E  /* 0x0dce THAI CHARACTER HO NOKHUK */
#define UCS_Thai_paiyannoi                0x0E2F  /* 0x0dcf THAI CHARACTER PAIYANNOI */
#define UCS_Thai_saraa                    0x0E30  /* 0x0dd0 THAI CHARACTER SARA A */
#define UCS_Thai_maihanakat               0x0E31  /* 0x0dd1 THAI CHARACTER MAI HAN-AKAT */
#define UCS_Thai_saraaa                   0x0E32  /* 0x0dd2 THAI CHARACTER SARA AA */
#define UCS_Thai_saraam                   0x0E33  /* 0x0dd3 THAI CHARACTER SARA AM */
#define UCS_Thai_sarai                    0x0E34  /* 0x0dd4 THAI CHARACTER SARA I */
#define UCS_Thai_saraii                   0x0E35  /* 0x0dd5 THAI CHARACTER SARA II */
#define UCS_Thai_saraue                   0x0E36  /* 0x0dd6 THAI CHARACTER SARA UE */
#define UCS_Thai_sarauee                  0x0E37  /* 0x0dd7 THAI CHARACTER SARA UEE */
#define UCS_Thai_sarau                    0x0E38  /* 0x0dd8 THAI CHARACTER SARA U */
#define UCS_Thai_sarauu                   0x0E39  /* 0x0dd9 THAI CHARACTER SARA UU */
#define UCS_Thai_phinthu                  0x0E3A  /* 0x0dda THAI CHARACTER PHINTHU */
#define UCS_Thai_baht                     0x0E3F  /* 0x0ddf THAI CURRENCY SYMBOL BAHT */
#define UCS_Thai_sarae                    0x0E40  /* 0x0de0 THAI CHARACTER SARA E */
#define UCS_Thai_saraae                   0x0E41  /* 0x0de1 THAI CHARACTER SARA AE */
#define UCS_Thai_sarao                    0x0E42  /* 0x0de2 THAI CHARACTER SARA O */
#define UCS_Thai_saraaimaimuan            0x0E43  /* 0x0de3 THAI CHARACTER SARA AI MAIMUAN */
#define UCS_Thai_saraaimaimalai           0x0E44  /* 0x0de4 THAI CHARACTER SARA AI MAIMALAI */
#define UCS_Thai_lakkhangyao              0x0E45  /* 0x0de5 THAI CHARACTER LAKKHANGYAO */
#define UCS_Thai_maiyamok                 0x0E46  /* 0x0de6 THAI CHARACTER MAIYAMOK */
#define UCS_Thai_maitaikhu                0x0E47  /* 0x0de7 THAI CHARACTER MAITAIKHU */
#define UCS_Thai_maiek                    0x0E48  /* 0x0de8 THAI CHARACTER MAI EK */
#define UCS_Thai_maitho                   0x0E49  /* 0x0de9 THAI CHARACTER MAI THO */
#define UCS_Thai_maitri                   0x0E4A  /* 0x0dea THAI CHARACTER MAI TRI */
#define UCS_Thai_maichattawa              0x0E4B  /* 0x0deb THAI CHARACTER MAI CHATTAWA */
#define UCS_Thai_thanthakhat              0x0E4C  /* 0x0dec THAI CHARACTER THANTHAKHAT */
#define UCS_Thai_nikhahit                 0x0E4D  /* 0x0ded THAI CHARACTER NIKHAHIT */
#define UCS_Thai_leksun                   0x0E50  /* 0x0df0 THAI DIGIT ZERO */
#define UCS_Thai_leknung                  0x0E51  /* 0x0df1 THAI DIGIT ONE */
#define UCS_Thai_leksong                  0x0E52  /* 0x0df2 THAI DIGIT TWO */
#define UCS_Thai_leksam                   0x0E53  /* 0x0df3 THAI DIGIT THREE */
#define UCS_Thai_leksi                    0x0E54  /* 0x0df4 THAI DIGIT FOUR */
#define UCS_Thai_lekha                    0x0E55  /* 0x0df5 THAI DIGIT FIVE */
#define UCS_Thai_lekhok                   0x0E56  /* 0x0df6 THAI DIGIT SIX */
#define UCS_Thai_lekchet                  0x0E57  /* 0x0df7 THAI DIGIT SEVEN */
#define UCS_Thai_lekpaet                  0x0E58  /* 0x0df8 THAI DIGIT EIGHT */
#define UCS_Thai_lekkao                   0x0E59  /* 0x0df9 THAI DIGIT NINE */
#endif /* XK_THAI */

#endif                          /* _UCSSYMBOLS_H_ */