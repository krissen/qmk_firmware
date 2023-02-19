/*
Copyright 2023 krissen
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
#ifdef OLED_ENABLE
#	include "oled_stuff.h"
#endif


/* Define layer names */
enum userspace_layers {
	_COLEMAK = 0,
	_SYMBOLS,
	_NUMNAV,
	_SHORTCUT,
	/* _QWERTY, */
};

// Shorthand keycodes ("macros")
#define ASG_V RALT(RSFT(RGUI(KC_V)))

// Define layouts for wrapper
/* #define _____________________QWERTY_L1______________________ KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T */
/* #define _____________________QWERTY_L2______________________ KC_DEL, LALT_T(KC_A), KC_S, KC_D, KC_F, KC_G */
/* #define _____________________QWERTY_L3______________________ KC_LALT,LCTL_T(KC_Z), KC_X, KC_C, KC_V, KC_B */
/* #define _____________________QWER_TH_L1_____________________ TO(_COLEMAK), KC_LEFT, MT(MOD_LSFT, KC_SPC), LT(_NUMNAV, KC_ENT), KC_UP */
/* #define _____________________QWER_TH_L2_____________________ OSM(MOD_LSFT), KC_DOWN */

/* #define _____________________QWERTY_R1______________________ KC_Y, KC_U, KC_I,    KC_O,	  KC_P,             KC_LBRC */
/* #define _____________________QWERTY_R2______________________ KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,          RGUI_T(KC_QUOTE) */
/* #define _____________________QWERTY_R3______________________ KC_N, KC_M, KC_COMM, KC_DOT, RCTL_T(KC_SLASH), OSL(_SHORTCUT) */
/* #define _____________________QWER_TH_R1_____________________ KC_LEFT, KC_TAB, KC_BSPC, KC_RIGHT, TO(_NUMNAV) */
/* #define _____________________QWER_TH_R2_____________________ OSL(_NUMNAV), C(KC_BSPC) */

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
