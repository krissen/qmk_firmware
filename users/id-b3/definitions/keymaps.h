#pragma once

#include QMK_KEYBOARD_H
#include "keycodes.h"
#include "layers.h"

#define ________COLEMKL1________    KC_Q, KC_W, KC_F, KC_P, KC_G
#define ________COLEMKL2________    HR_A, HR_R, HR_S, HR_T, KC_D
#define ________COLEMKL3________    KC_Z, KC_X, KC_C, KC_V, KC_B

#define ________COLEMKR1________    KC_J, KC_L, KC_U, KC_Y, KC_SCLN
#define ________COLEMKR2________    KC_H, HR_N, HR_E, HR_I, HR_O
#define ________COLEMKR3________    KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH

#define ____THL1____    MT(MOD_LSFT, KC_SPC), LT(_SYMNUM, KC_ENT), KC_ESC
#define ____THR1____    KC_DEL, LT(_SHORTCUT, KC_TAB), KC_BSPC

#define ________SYMNUML1________    A(KC_F4), KC_DQT, KC_AT, KC_LPRN, KC_RPRN
#define ________SYMNUML2________    KC_NUHS, KC_EQL, KC_MINS, KC_EXLM, KC_PERC
#define ________SYMNUML3________    KC_NO, KC_NO, KC_NO, KC_LBRC, KC_RBRC

#define ________SYMNUMR1________    KC_NO, KC_7, KC_8, KC_9, KC_NO 
#define ________SYMNUMR2________    KC_NO, KC_4, KC_5, KC_6, KC_0 
#define ________SYMNUMR3________    KC_NO, KC_1, KC_2, KC_3, KC_NO 

#define ____THBK____    _______, _______, _______

#define ________SHRTCTL1________    CADEL, C(KC_W), C(KC_F), SNAPL, SNAPR
#define ________SHRTCTL2________    TRML,   _______,   SNAP,CLSTAB, _______
#define ________SHRTCTL3________    TSKMN, _______, _______, FPASTE, _______

#define ________SHRTCTR1________    KC_MYCM, _______, KC_UP, _______, _______
#define ________SHRTCTR2________    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______
#define ________SHRTCTR3________    _______, _______, _______, _______, G(KC_DOT)
