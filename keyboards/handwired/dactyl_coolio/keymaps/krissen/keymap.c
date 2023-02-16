/*
 * keymap.c
 *
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

#include QMK_KEYBOARD_H
#include "krissen.h"

// Enumerate the tap dances
enum taps {
	TD_GUIDOL,
	TD_TICK
};

// define a type containing as many tapdance states as you need
typedef enum {
	SINGLE_TAP = 0,
	SINGLE_HOLD,
	DOUBLE_SINGLE_TAP
} td_state_t;

// create a global instance of the tapdance state type
static td_state_t td_state;

// function to determine the current tapdance state
int cur_dance (qk_tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void guidol_finished (qk_tap_dance_state_t *state, void *user_data);
void guidol_reset (qk_tap_dance_state_t *state, void *user_data);
void tick_finished (qk_tap_dance_state_t *state, void *user_data);
void tick_reset (qk_tap_dance_state_t *state, void *user_data);

// determine the tapdance state to return
int cur_dance (qk_tap_dance_state_t *state) {
	if (state->count == 1) {
		if (state->interrupted || !state->pressed) { return SINGLE_TAP; }
	else { return SINGLE_HOLD; }
	}
	if (state->count == 2) { return DOUBLE_SINGLE_TAP; }
else { return 3; } // any number higher than the maximum state value you return above
}

// handle the possible states for each tapdance keycode you define:
void guidol_finished (qk_tap_dance_state_t *state, void *user_data) {
	td_state = cur_dance(state);
	switch (td_state) {
		case SINGLE_TAP:
			register_mods(MOD_BIT(KC_RALT));
			register_code16(KC_4);
			break;
		case SINGLE_HOLD:
			register_mods(MOD_BIT(KC_LGUI)); // for a layer-tap key, use `layer_on(_MY_LAYER)` here
			break;
		case DOUBLE_SINGLE_TAP: // allow nesting of 2 parens `((` within tapping term
			register_mods(MOD_BIT(KC_LSFT));
			register_code16(KC_GRAVE);
	}
}
void guidol_reset (qk_tap_dance_state_t *state, void *user_data) {
	switch (td_state) {
		case SINGLE_TAP:
			unregister_code16(KC_4);
			unregister_mods(MOD_BIT(KC_RALT));
			break;
		case SINGLE_HOLD:
			unregister_mods(MOD_BIT(KC_LGUI)); // for a layer-tap key, use `layer_off(_MY_LAYER)` here
			break;
		case DOUBLE_SINGLE_TAP:
			unregister_mods(MOD_BIT(KC_LSFT));
			unregister_code16(KC_GRAVE);
			break;
	}
}


void tick_finished (qk_tap_dance_state_t *state, void *user_data) {
	td_state = cur_dance(state);
	switch (td_state) {
		case SINGLE_TAP:
			register_mods(MOD_BIT(KC_RSFT));
			register_code16(KC_EQUAL);
			register_code16(KC_SPACE);
			break;
		case SINGLE_HOLD:
			register_mods(MOD_BIT(KC_RGUI)); // for a layer-tap key, use `layer_on(_MY_LAYER)` here
			break;
		case DOUBLE_SINGLE_TAP: // allow nesting of 2 parens `((` within tapping term
			register_code16(KC_EQUAL);
			register_code16(KC_SPACE);
			break;
	}
}

void tick_reset (qk_tap_dance_state_t *state, void *user_data) {
	switch (td_state) {
		case SINGLE_TAP:
			unregister_code16(KC_EQUAL);
			unregister_code16(KC_SPACE);
			unregister_mods(MOD_BIT(KC_RSFT));
			break;
		case SINGLE_HOLD:
			unregister_mods(MOD_BIT(KC_RGUI)); // for a layer-tap key, use `layer_off(_MY_LAYER)` here
			break;
		case DOUBLE_SINGLE_TAP:
			unregister_code16(KC_EQUAL);
			unregister_code16(KC_SPACE);
			break;
	}
}

// TAP DANCING
qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_GUIDOL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, guidol_finished, guidol_reset),
	[TD_TICK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tick_finished, tick_reset),
};

// KEYMAPS
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*Base Layerer*/
	[_COLEMAK] = LAYOUT_wrapper(
		KC_ESC,        KC_Q,	  KC_W, KC_F, KC_P, KC_B,						KC_J, KC_L, KC_U   , KC_Y  , KC_SCLN         , KC_LBRC,
		TD(TD_GUIDOL), LCTL_T(KC_A), KC_R, KC_S, KC_T, KC_G,						KC_M, KC_N, KC_E   , KC_I  , RCTL_T(KC_O)    , RGUI_T(KC_QUOTE),
		LSFT(KC_RBRC), LALT_T(KC_Z), KC_X, KC_C, KC_D, KC_V,						KC_K, KC_H, KC_COMM, KC_DOT, RALT_T(KC_SLASH), LT(_SHORTCUT, KC_BSLS),
		KC_MEDIA_PLAY_PAUSE, KC_LEFT, LT(_SHORTCUT, KC_BSPC), MT(MOD_RSFT, KC_TAB), OSM(MOD_LSFT),	OSM(MOD_LSFT), MT(MOD_RSFT, KC_SPC), LT(_SHORTCUT, KC_DEL), KC_RIGHT, KC_MUTE,
		LT(_SYMBOLS, KC_ENT), OSL(_NUMNAV),								OSL(_NUMNAV), LT(_SYMBOLS, KC_ENT) 
	),
	[_SYMBOLS] = LAYOUT_wrapper(
		KC_F1,	  KC_F2,      KC_F3, 	KC_F4, 	       KC_F5,	   KC_F6,		KC_F7,      KC_F8,          KC_F9,         KC_F10,  	     KC_F11,	       KC_F12,
		KC_GRAVE, LALT(KC_8), LALT(KC_9), LALT(KC_RBRC), LALT(KC_7), LALT(LSFT(KC_7)),	RSFT(KC_7), RSFT(KC_MINUS), RSFT(KC_BSLS), RALT(RSFT(KC_8)), RALT(RSFT(KC_9)), RSFT(KC_2),
		KC_NUBS,  LSFT(KC_1), LALT(KC_2), LSFT(KC_3),    LSFT(KC_4), LSFT(KC_5),		RSFT(KC_6), RALT(KC_3),     RSFT(KC_8),    RSFT(KC_9),       RALT(KC_EQUAL),    TD(TD_TICK),
		_______, KC_UP, TO(_COLEMAK), _______, _______,       	    				_______, _______, TO(_COLEMAK), KC_DOWN, _______,
		_______, _______,                                  	    				_______, _______
	),
	[_NUMNAV] = LAYOUT_wrapper(
		KC_ESC,      KC_SLSH,	     KC_7, KC_8, KC_9, KC_KP_MINUS,		KC_VOLU, KC_HOME, KC_UP,   KC_PGUP,  RGUI(KC_X), ASG_V,
		KC_KP_EQUAL, KC_KP_ASTERISK, KC_4, KC_5, KC_6, KC_KP_PLUS,		KC_MUTE, KC_LEFT, KC_DOWN, KC_RIGHT, RGUI(KC_C), RSFT(KC_2),
		KC_KP_DOT,   KC_0, 	     KC_1, KC_2, KC_3, KC_KP_COMMA,		KC_VOLD, KC_END,  KC_PSCR, KC_PGDN,  RGUI(KC_V), RSFT(KC_EQUAL),
		_______, _______, TO(_COLEMAK), _______, _______,       	    	_______, _______, TO(_COLEMAK), _______, _______,
		_______, _______,                                  	    		_______,_______
	),
	[_SHORTCUT] = LAYOUT_wrapper(
		RESET,   _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, 		_______, _______, _______, _______, _______, RESET,
		_______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,		_______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,		_______, _______, _______, _______, _______, TO(_COLEMAK),
		_______, RGB_SAD, _______, RGB_TOG, RGB_M_B,			RGB_HUD, RGB_HUI, RGB_MOD, RGB_RMOD, _______,
		RGB_RMOD, RGB_MOD,						RGB_VAD, RGB_VAI 
	),
	/* [_QWERTY] = LAYOUT_wrapper( */
	/* 	_____________________QWERTY_L1______________________,       _____________________QWERTY_R1______________________, */
	/* 	_____________________QWERTY_L2______________________,       _____________________QWERTY_R2______________________, */
	/* 	_____________________QWERTY_L3______________________,	    _____________________QWERTY_R3______________________, */
	/* 	_____________________QWER_TH_L1_____________________,       _____________________QWER_TH_R1_____________________, */
	/* 	_____________________QWER_TH_L2_____________________,       _____________________QWER_TH_R2_____________________ */
	/* ), */

	/*[_BLANK] = LAYOUT(
      _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,	   _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
	  _______,                                                                                                  _______
    )
	*/

};
