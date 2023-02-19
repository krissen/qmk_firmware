/*
 * oled_stuff.h¨
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
#include "oled_driver.h"

/* Did this fix right side OLED being broken?
 * https://www.reddit.com/r/olkb/comments/q6s02g/comment/hge4r71/?utm_source=share&utm_medium=web2x&context=3 */
bool process_record_user_oled(uint16_t keycode, keyrecord_t *record);

//void oled_dice(int num);

static const char PROGMEM shift_key[] = {210,211,32,0};
static const char PROGMEM win_key[] = {147,148,32,0};
static const char PROGMEM alt_key[] = {146,32,0};
static const char PROGMEM ctrl_key[] = {127,32,0};

static const char PROGMEM logo[] = {
  0x20,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x20,0x20,0x20,0xb8,0xb9,0xba,0xbb,0xbc,0xbd,0xbe,0x20,
  0x20,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0x20,0x20,0x20,0xd8,0xd9,0xda,0xdb,0xdc,0xdd,0xde,0x20,
  0x20,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0
  };

#ifdef OLED_DISPLAY_128X64
#    define OLED_RENDER_KEYLOGGER "History: "

#    define OLED_RENDER_LAYOUT_NAME    "Layout: "
#    define OLED_RENDER_LAYOUT_COLEMAK "Colemak"
#    define OLED_RENDER_LAYOUT_NUMNAV "Num Nav"
#    define OLED_RENDER_LAYOUT_SYMBOLS "Symbols"
#    define OLED_RENDER_LAYOUT_SHORTCUT "Shortcut"
#    define OLED_RENDER_LAYOUT_QWERTY  "Qwerty"

#    define OLED_RENDER_LOCK_NAME "Lock: "
#    define OLED_RENDER_LOCK_NUML "NUML"
#    define OLED_RENDER_LOCK_CAPS "CAPS"
#    define OLED_RENDER_LOCK_SCLK "SCLK"

#    define OLED_RENDER_MODS_NAME "Mods: "

#endif
