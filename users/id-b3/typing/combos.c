#include QMK_KEYBOARD_H

#include "combos.h"
#include "../definitions/keycodes.h"

// Basics

const uint16_t PROGMEM escape[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM apostrophe[] = {HR_I, HR_O, COMBO_END};
const uint16_t PROGMEM underscore[] = {HR_T, KC_D, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(escape, KC_ESC),
    COMBO(apostrophe, KC_QUOT),
    COMBO(underscore, KC_UNDS)
};
