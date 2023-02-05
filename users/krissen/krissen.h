/*
Copyright 2021 id-b3
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "quantum.h"
#include "process_records.h"
#ifdef OLED_ENABLE
#    include "oled_stuff.h"
#endif
/* #ifdef TRACKBALL_ENABLE */
/* 	#include "pimoroni_trackball.h" */
/* #endif */
//#define DICE_ROLLER_ENABLE

/*

    Character Frequency: SPC e t a o i n s r h l d c u m f g p y w ENT b , . v k - " _ ' x ) ( ; 0  j 1 q = 2 : z / * ! ? $ 3 5 > { } 4 9 [ ] 8 6 7 \ + | & < % @ # ^ ` ~

    Punctuation Frequency: , . - " _ ' ) ( ; = : / * ! ? $ > { } [ ] \ + | & < % @ # ^ ` ~

*/

/* Define layer names */
enum userspace_layers {
	_COLEMAK = 0,
	_QWERTY,
	_SHORTCUT,
	_SYMNUM,
	_NAVIGATION,
};

#define CADEL LALT(LCTL(KC_DELETE))
#define TRML LALT(LCTL(KC_T))
#define TSKMN LCTL(LSFT(KC_ESCAPE))

#define _____________________QWERTY_L1______________________ KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T
#define _____________________QWERTY_L2______________________ KC_DEL, LALT_T(KC_A), KC_S, KC_D, KC_F, KC_G
#define _____________________QWERTY_L3______________________ KC_LALT,LCTL_T(KC_Z), KC_X, KC_C, KC_V, KC_B
#define _____________________QWER_TH_L1_____________________ TO(_COLEMAK), KC_LEFT, MT(MOD_LSFT, KC_SPC), LT(_SYMNUM, KC_ENT), KC_UP
#define _____________________QWER_TH_L2_____________________ OSM(MOD_LSFT), KC_DOWN

#define _____________________QWERTY_R1______________________ KC_Y, KC_U, KC_I,    KC_O,	  KC_P,             KC_LBRC
#define _____________________QWERTY_R2______________________ KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,          RGUI_T(KC_QUOTE)
#define _____________________QWERTY_R3______________________ KC_N, KC_M, KC_COMM, KC_DOT, RCTL_T(KC_SLASH), OSL(_SHORTCUT)
#define _____________________QWER_TH_R1_____________________ KC_LEFT, TD(TD_TABC), KC_BSPC, KC_RIGHT, TO(_SYMNUM)
#define _____________________QWER_TH_R2_____________________ OSL(_NAVIGATION), C(KC_BSPC)

#define _____________________COLEMAK_L1_____________________ KC_ESC,        KC_Q,  KC_W, KC_F, KC_P, KC_B
#define _____________________COLEMAK_L2_____________________ TD(TD_GUIDOL),LCTL_T(KC_A), KC_R, KC_S, KC_T, KC_G
#define _____________________COLEMAK_L3_____________________ LT(_NAVIGATION, LSFT(KC_RBRC)), LALT_T(KC_Z), KC_X, KC_C, KC_D, KC_V
#define _____________________COLE_TH_L1_____________________ TO(_NAVIGATION), KC_LEFT, MT(MOD_LSFT, KC_TAB), LT(_SYMNUM, KC_ENT), KC_BSPC
#define _____________________COLE_TH_L2_____________________ OSM(MOD_LSFT), KC_DOWN

#define _____________________COLEMAK_R1_____________________ KC_J, KC_L, KC_U   , KC_Y  , KC_SCLN         , KC_LBRC
#define _____________________COLEMAK_R2_____________________ KC_M, KC_N, KC_E   , KC_I  , RCTL_T(KC_O)    , RGUI_T(KC_QUOTE)
#define _____________________COLEMAK_R3_____________________ KC_K, KC_H, KC_COMM, KC_DOT, RALT_T(KC_SLASH), OSL(_SHORTCUT)
#define _____________________COLE_TH_R1_____________________ KC_BSPC, MT(MOD_RSFT, KC_SPC), KC_DEL, KC_RIGHT, TO(_QWERTY)
#define _____________________COLE_TH_R2_____________________ OSL(_NAVIGATION), KC_UP

#define _____________________SHORTCT_L1_____________________ RESET,_______,C(KC_W),C(KC_F),_______,_______
#define _____________________SHORTCT_L2_____________________ TRML, _______, _______, _______, _______, _______
#define _____________________SHORTCT_L3_____________________ TSKMN, _______, _______, _______, LALT(LCTL(KC_V)),_______
#define _____________________SHRT_TH_L1_____________________ G(KC_TAB), G(C(KC_LEFT)), G(C(KC_RIGHT)), RGB_TOG, RGB_M_P
#define _____________________SHRT_TH_L2_____________________ _______,_______

#define _____________________SHORTCT_R1_____________________ KC_MYCM, _______, _______, _______, _______,   RESET
#define _____________________SHORTCT_R2_____________________ _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______
#define _____________________SHORTCT_R3_____________________ _______, _______, _______, _______, G(KC_DOT), TO(_COLEMAK)
#define _____________________SHRT_TH_R1_____________________ RGB_HUD, RGB_HUI, RGB_MOD, RGB_RMOD, KC_MUTE
#define _____________________SHRT_TH_R2_____________________ RGB_VAD, RGB_VAI

#define _____________________SYMNUM_LF1_____________________ A(KC_F4),_______, _______, S(KC_2), KC_LPRN, KC_RPRN
#define _____________________SYMNUM_LF2_____________________ _______,  KC_NUHS, KC_EQL, KC_MINS, TD(TD_EXLM), TD(TD_PCAS)
#define _____________________SYMNUM_LF3_____________________ RESET, _______, _______, _______, KC_LBRC, KC_RBRC

#define _____________________SYMNUM_RT1_____________________ TD(TD_ASDI),KC_7,KC_8,KC_9,_______,_______
#define _____________________SYMNUM_RT2_____________________ TD(TD_PLMN),KC_4,KC_5,KC_6,KC_0,_______
#define _____________________SYMNUM_RT3_____________________ _______,    KC_1,KC_2,KC_3,KC_DOT,_______

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
