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

#include "krissen.h"

#ifdef ENCODER_ENABLE

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

void matrix_scan_user(void) {
	if (is_alt_tab_active) {
		if (timer_elapsed(alt_tab_timer) > 1250) {
			unregister_code(KC_LCTL);
			is_alt_tab_active = false;
		}
	}
}

uint8_t selected_layer = 0;

bool encoder_update_user(uint8_t index, bool clockwise) {
	if (index == 0) {// Left encoder
		switch (get_highest_layer(layer_state)) {
			case _COLEMAK:
				// Tabbing through windows
				if (clockwise) {
					if (!is_alt_tab_active) {
						is_alt_tab_active = true;
						register_code(KC_LCTL);
					}
					alt_tab_timer = timer_read();
					tap_code16(KC_F4);
					return true;
				} else {
					if (!is_alt_tab_active) {
						is_alt_tab_active = true;
						register_code(KC_LCTL);
					}
					alt_tab_timer = timer_read();
					tap_code16(S(KC_F4));
					return true;
				}
			break;
			case _SHORTCUT:
				// Volume Control
				if (clockwise) {
					tap_code(KC_VOLU);
					return true;
				} else {
					tap_code(KC_VOLD);
					return true;
				}
			break;
			case _NUMNAV:
				// Move whole words. Hold shift to select while moving.
				if (clockwise) {
					tap_code16(A(KC_RGHT));
					return true;
				} else {
					tap_code16(A(KC_LEFT));
					return true;
				}
			break;

			default:
				// History scrubbing. For Adobe products, hold shift while moving
				// backward to go forward instead.
				if (clockwise) {
					tap_code16(G(KC_Y));
					return true;
				} else {
					tap_code16(G(KC_Z));
					return true;
				}
			break;
		}
		return true;
	} else if (index == 1) {// Right encoder
	switch (get_highest_layer(layer_state)) {
		case _NUMNAV:
			// Ändra lager med encoder
			// https://www.reddit.com/r/olkb/comments/cmyodl/comment/ew9dg5m/?utm_source=share&utm_medium=web2x&context=3
			if (!clockwise && selected_layer  < 10) {
				selected_layer ++;
				} else if (clockwise && selected_layer  > 0){
				selected_layer --;
			}
			layer_clear();
			layer_on(selected_layer);
			return true;
		break;
		default:
			if (clockwise) {
				tap_code16(KC_LEFT);
				return true;
				} else {
				tap_code16(KC_RIGHT);
				return true;
			}
		break;
	}
	}
	return false;
}
#endif
