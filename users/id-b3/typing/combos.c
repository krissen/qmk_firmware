#include QMK_KEYBOARD_H

#include "combos.h"

// Basics

const uint16_t PROGMEM escape[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM apostrophe[] = {HR_E, HR_I, COMBO_END};
const uint16_t PROGMEM underscore[] = {HR_S, HR_T, COMBO_END};
const uint16_t PROGMEM backslash[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM delete[] = {HR_A, HR_R, COMBO_END};

// Layers
const uint16_t PROGMEM shortcut[] = {KC_DOT, KC_SLSH, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(escape, KC_ESC),
    COMBO(apostrophe, KC_QUOT),
    COMBO(underscore, KC_UNDS),
    COMBO(backslash, KC_NUBS),
    COMBO(delete, KC_DEL),
    COMBO(shortcut, OSL(_SHORTCUT))
};
