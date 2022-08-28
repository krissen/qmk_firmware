#include QMK_KEYBOARD_H

#include "combos.h"

// Basics

const uint16_t PROGMEM escape[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM apostrophe[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM underscore[] = {KC_T, KC_D, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(escape, KC_ESC),
    COMBO(apostrophe, KC_QUOT),
    COMBO(underscore, KC_UNDS)
};
