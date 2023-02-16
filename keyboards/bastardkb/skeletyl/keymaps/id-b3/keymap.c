/* 
 * Copyright 2022 id-b3 <id-b3>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "id-b3.h"

#define LAYOUT_wrapper(...) LAYOUT_split_3x5_3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_wrapper(
        ________COLEMKL1________,       ________COLEMKR1________,
        ________COLEMKL2________,       ________COLEMKR2________,
        ________COLEMKL3________,       ________COLEMKR3________,
                    ____THL1____,       ____THR1____
    ),
    [_SYMNUM] = LAYOUT_wrapper(
        ________SYMNUML1________,       ________SYMNUMR1________,
        ________SYMNUML2________,       ________SYMNUMR2________,
        ________SYMNUML3________,       ________SYMNUMR3________,
                    ____THBK____,       ____THBK____
    ),
    [_SHORTCUT] = LAYOUT_wrapper(
        ________SHRTCTL1________,       ________SHRTCTR1________,
        ________SHRTCTL2________,       ________SHRTCTR2________,
        ________SHRTCTL3________,       ________SHRTCTR3________,
                    ____THBK____,       ____THBK____
    )
};
