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

#include "keyrecords/wrappers.h"

#ifdef OLED_ENABLE
#    include "oled/oled_stuff.h"
#endif

#ifdef TAP_DANCE_ENABLE
#    include "keyrecords/tap_dances.h"
#endif

/*

    Character Frequency: SPC e t a o i n s r h l d c u m f g p y w ENT b , . v k - " _ ' x ) ( ; 0  j 1 q = 2 : z / * ! ? $ 3 5 > { } 4 9 [ ] 8 6 7 \ + | & < % @ # ^ ` ~

    Punctuation Frequency: , . - " _ ' ) ( ; = : / * ! ? $ > { } [ ] \ + | & < % @ # ^ ` ~

*/

/* Define layer names */
enum userspace_layers {
	_COLEMAK = 0,
    _QWERTY,
	_GAMING,
    _SHORTCUT,
    _SYMNUM,
	_NAVIGATION,
};


#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
