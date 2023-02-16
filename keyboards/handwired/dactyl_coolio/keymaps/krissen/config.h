/*
This is the c configuration file for the keymap

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

//#define DICE_ROLLER_ENABLE
//#define TRACKBALL_ENABLE

#define ENCODER_DIRECTION_FLIP
#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_SLEEP
/* #    define RGBLIGHT_ANIMATIONS */ 		// deprecated
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 8
#    define RGBLIGHT_LIMIT_VAL 200
# 	define RGBLIGHT_EFFECT_BREATHING
# 	define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
# 	define RGBLIGHT_EFFECT_SNAKE
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    define RGBLIGHT_EFFECT_TWINKLE
#endif

#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 175			// Default: 200
#define TAPPING_TERM_PER_KEY

#undef RGBLED_NUM
#undef RGBLED_SPLIT
#define RGBLED_SPLIT { 15, 15 }
#define RGBLED_NUM 30

#ifdef MOUSEKEY_ENABLE
/* #define 	MOUSEKEY_DELAY 10		// Delay between pressing a movement key and cursor movement */
/* #define 	MOUSEKEY_INTERVAL 20		// Time between cursor movements in milliseconds */
/* #define 	MOUSEKEY_MOVE_DELTA 8		// Step size */
#undef 		MOUSEKEY_MAX_SPEED
#define 	MOUSEKEY_MAX_SPEED 6		// Maximum cursor speed at which acceleration stops, DEF: 10
#undef 		MOUSEKEY_TIME_TO_MAX
#define 	MOUSEKEY_TIME_TO_MAX 80		// Time until maximum cursor speed is reached, DEF: 30 */
/* #define 	MOUSEKEY_WHEEL_DELAY 10		// Delay between pressing a wheel key and wheel movement */
/* #define 	MOUSEKEY_WHEEL_INTERVAL 80	// Time between wheel movements */
/* #define 	MOUSEKEY_WHEEL_MAX_SPEED 8	// Maximum number of scroll steps per scroll action */
/* #define 	MOUSEKEY_WHEEL_TIME_TO_MAX 40	// Time until maximum scroll speed is reached */
#endif

