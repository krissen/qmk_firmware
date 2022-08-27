#pragma once
#include "id-b3.h"

#define CADEL LALT(LCTL(KC_DELETE))
#define TRML LALT(LCTL(KC_T))
#define TSKMN LCTL(LSFT(KC_ESCAPE))
#define CLSTAB LCTL(LSFT(KC_T))
#define SNAP LGUI(LSFT(KC_S))
#define SNAPL LGUI(LSFT(KC_LEFT))
#define SNAPR LGUI(LSFT(KC_RGHT))

#define __________COLEMAK_L1__________      KC_Q,    KC_W,    KC_F,    KC_P,    KC_G
#define __________COLEMAK_L2__________      KC_A,    KC_R,    KC_S,    KC_T,    KC_D
#define __________COLEMAK_L3__________      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define __________COLEMAK_R1__________      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define __________COLEMAK_R2__________      KC_H,    KC_N,    KC_E,    KC_I,    KC_O
#define __________COLEMAK_R3__________      KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define _____THUMBS_LF1_____      MT(MOD_LSFT, KC_SPC), KC_ENT, KC_UP
#define _____THUMBS_LF2_____      OSM(MOD_LSFT), KC_DOWN

#define _____THUMBS_RG1_____      KC_LEFT, KC_TAB, KC_BSPC
#define _____THUMBS_RG2_____      OSL(_NAVIGATION), C(KC_BSPC)

#define __________SHORTCT_L1__________      CADEL,_______,C(KC_W),C(KC_F),SNAPL,SNAPR
#define __________SHORTCT_L2__________      TRML, _______, _______, SNAP, CLSTAB, _______
#define __________SHORTCT_L3__________      TSKMN, _______, _______, _______, LALT(LCTL(KC_V)),_______
#define __________SHRT_TH_L1__________      G(KC_TAB), G(C(KC_LEFT)), G(C(KC_RIGHT)), RGB_TOG, RGB_M_P
#define __________SHRT_TH_L2__________      _______,_______

#define __________SHORTCT_R1__________      KC_MYCM, _______, _______, _______, _______,   RESET
#define __________SHORTCT_R2__________      _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______
#define __________SHORTCT_R3__________      _______, _______, _______, _______, G(KC_DOT), _______
#define __________SHRT_TH_R1__________      RGB_HUD, RGB_HUI, RGB_MOD, RGB_RMOD, KC_MUTE
#define __________SHRT_TH_R2__________      RGB_VAD, RGB_VAI

#define __________SYMNUM_LF1__________      A(KC_F4),_______, _______, S(KC_2), KC_LPRN, KC_RPRN
#define __________SYMNUM_LF2__________      _______,  KC_NUHS, KC_EQL, KC_MINS, TD(TD_EXLM), TD(TD_PCAS)
#define __________SYMNUM_LF3__________      RESET, _______, _______, _______, KC_LBRC, KC_RBRC

#define __________SYMNUM_RT1__________      TD(TD_ASDI),KC_7,KC_8,KC_9,_______,_______
#define __________SYMNUM_RT2__________      TD(TD_PLMN),KC_4,KC_5,KC_6,KC_0,_______
#define __________SYMNUM_RT3__________      _______,KC_1,KC_2,KC_3,KC_DOT,_______

#define __________GAMING_LF1__________      KC_I,    KC_Q,    KC_W,    KC_E,    KC_R
#define __________GAMING_LF2__________      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F
#define __________GAMING_LF3__________      CTL_T(KC_C),KC_Z,    KC_X,    KC_C,    KC_V
#define __________GAME_TMB_L__________      KC_SPC,  KC_LALT,  KC_ENT
#define __________GAME_TM_L2__________      KC_TAB, KC_0

#define __________GAMING_RT1__________      KC_T,    TD(TD_7),    TD(TD_8),    TD(TD_9),    KC_O
#define __________GAMING_RT2__________      KC_G,    TD(TD_4),    TD(TD_5),    TD(TD_6),    TD(TD_0)
#define __________GAMING_RT3__________      KC_B,    TD(TD_1),    TD(TD_2),    TD(TD_3),  KC_DOT
#define __________GAME_TMB_R__________      KC_F5,  KC_F8,  KC_F18
#define __________GAME_TM_R2__________      KC_F10,  KC_F12

#define __________QWERTY_L1___________      KC_Q, KC_W, KC_E, KC_R, KC_T
#define __________QWERTY_L2___________      KC_A, KC_S, KC_D, KC_F, KC_G
#define __________QWERTY_L3___________      CTL_T(KC_Z), KC_X, KC_C, KC_V, KC_B

#define __________QWERTY_R1___________      KC_Y, KC_U, KC_I, KC_O, KC_P
#define __________QWERTY_R2___________      KC_H, KC_J, KC_K, KC_L, KC_SCLN
#define __________QWERTY_R3___________      KC_N, KC_M, KC_COMM, KC_DOT, CTL_T(KC_SLASH)
