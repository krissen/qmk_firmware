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
#include <stdio.h>
#include <stdlib.h>

#ifdef OLED_ENABLE

#ifdef WPM_ENABLE
//#include "wpm_oled.c"
#include "wpm_cat.c"
char wpm_str[10];
#endif

extern uint8_t is_master;

void render_mod_status(uint8_t modifiers) {
	oled_write_P(PSTR(OLED_RENDER_MODS_NAME), false);

	if (modifiers & MOD_MASK_SHIFT){oled_write_P(shift_key, false);}
	if (modifiers & MOD_MASK_CTRL){oled_write_P(ctrl_key, false);}
	if (modifiers & MOD_MASK_ALT){oled_write_P(alt_key, false);}
	if (modifiers & MOD_MASK_GUI){oled_write_P(win_key, false);}
	oled_advance_page(true);
}

static void render_status(void) {
	// QMK Logo and version information
	oled_write_P(logo, false);
	oled_advance_page(true);
	oled_advance_page(true);

	// Host Keyboard Layer Status
	oled_write_P(PSTR(OLED_RENDER_LAYOUT_NAME), false);
	switch (get_highest_layer(layer_state)) {
		case _COLEMAK:
			oled_write_ln_P(PSTR(OLED_RENDER_LAYOUT_COLEMAK), false);
			break;
		case _SYMNUM:
			oled_write_ln_P(PSTR(OLED_RENDER_LAYOUT_SYMNUM), false);
			break;
		case _SHORTCUT:
			oled_write_ln_P(PSTR(OLED_RENDER_LAYOUT_SHORTCUT), false);
			break;
		case _NAVIGATION:
			oled_write_ln_P(PSTR(OLED_RENDER_LAYOUT_NAVIGATION), false);
			break;
		case _QWERTY:
			oled_write_ln_P(PSTR(OLED_RENDER_LAYOUT_QWERTY), false);
			break;
		default:
			// Or use the write_ln shortcut over adding '\n' to the end of your string
			oled_write_ln_P(PSTR("Undefined"), false);
	}

	// Host Keyboard LED Status
	led_t led_state = host_keyboard_led_state();
	oled_write_P(PSTR(OLED_RENDER_LOCK_NAME), false);
	oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
	oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
	oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
	oled_advance_page(true);
	render_mod_status(get_mods() | get_oneshot_mods());
}


bool oled_task_user(void) {
	if (is_keyboard_master()) {
	render_status();
		return false;
	} else {

		#ifdef WPM_ENABLE
		//render_wpm_graph();
		render_anim();
		oled_set_cursor(0,7);
		write_wpm();

		#endif
		//render_dice();
		oled_scroll_left();
		return false;
	}
}
#endif
