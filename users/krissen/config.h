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

/* Did this fix right side OLED being broken?
 * https://www.reddit.com/r/olkb/comments/q6s02g/comment/hge4r71/?utm_source=share&utm_medium=web2x&context=3 */
#define SPLIT_TRANSPORT_MIRROR

#pragma once

#ifdef OLED_ENABLE
#    define OLED_DISPLAY_128X64
#    define OLED_FONT_H "krissen_font.h"
#    define OLED_TIMEOUT 60000
#endif
