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

#include QMK_KEYBOARD_H
#include "id-b3.h"

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_EXLM] = ACTION_TAP_DANCE_DOUBLE(KC_EXLM, KC_QUES),
  [TD_PCAS] = ACTION_TAP_DANCE_DOUBLE(KC_PERC, KC_ASTR),
  [TD_PLMN] = ACTION_TAP_DANCE_DOUBLE(KC_PPLS, KC_PMNS),
  [TD_ASDI] = ACTION_TAP_DANCE_DOUBLE(KC_PAST, KC_PSLS),
  [TD_TABC] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, S(KC_TAB)),
  [TD_0] = ACTION_TAP_DANCE_DOUBLE(KC_0, C(KC_0)),
  [TD_1] = ACTION_TAP_DANCE_DOUBLE(KC_1, C(KC_1)),
  [TD_2] = ACTION_TAP_DANCE_DOUBLE(KC_2, C(KC_2)),
  [TD_3] = ACTION_TAP_DANCE_DOUBLE(KC_3, C(KC_3)),
  [TD_4] = ACTION_TAP_DANCE_DOUBLE(KC_4, C(KC_4)),
  [TD_5] = ACTION_TAP_DANCE_DOUBLE(KC_5, C(KC_5)),
  [TD_6] = ACTION_TAP_DANCE_DOUBLE(KC_6, C(KC_6)),
  [TD_7] = ACTION_TAP_DANCE_DOUBLE(KC_7, C(KC_7)),
  [TD_8] = ACTION_TAP_DANCE_DOUBLE(KC_8, C(KC_8)),
  [TD_9] = ACTION_TAP_DANCE_DOUBLE(KC_9, C(KC_9))
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*Base Layerer*/
    [_COLEMAK] = LAYOUT_wrapper(
        KC_NO, __________COLEMAK_L1__________,          __________COLEMAK_R1__________, KC_NO,
        KC_NO, __________COLEMAK_L2__________,          __________COLEMAK_R2__________, KC_NO,
        KC_NO, __________COLEMAK_L3__________,          __________COLEMAK_R3__________, KC_NO,
           KC_NO, KC_NO, _____THUMBS_LF1_____,          _____THUMBS_RG1_____, KC_NO, KC_NO,
                                 KC_NO, KC_NO,          KC_NO, KC_NO
    )

};
