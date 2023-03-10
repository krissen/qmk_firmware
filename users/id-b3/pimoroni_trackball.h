#pragma once

#include "quantum.h"
#include "pointing_device.h"

#ifndef TRACKBALL_ADDRESS
#    define TRACKBALL_ADDRESS 0x0A
#endif
#define TRACKBALL_WRITE ((TRACKBALL_ADDRESS << 1) | I2C_WRITE)
#define TRACKBALL_READ  ((TRACKBALL_ADDRESS << 1) | I2C_READ)

void trackball_set_rgbw(uint8_t red, uint8_t green, uint8_t blue, uint8_t white);
void trackball_check_click(bool pressed, report_mouse_t *mouse);

int16_t trackball_get_precision(void);
void    trackball_set_precision(int16_t precision);
bool    trackball_is_scrolling(void);
void    trackball_set_scrolling(bool scroll);
bool    trackball_is_carret(void);
void    trackball_set_carret(bool scroll);

void trackball_set_left(bool pressed);
void trackball_set_right(bool pressed);
void trackball_set_middle(bool pressed);