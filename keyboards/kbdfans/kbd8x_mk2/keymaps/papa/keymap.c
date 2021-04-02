#include QMK_KEYBOARD_H
#include "keymap_german.h"

//Layer names
#define BASE 0 // default layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_tkl_iso(
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_PSCR, KC_SLCK, KC_PAUS, \
        DE_CIRC, DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_SS,   DE_ACUT, KC_BSPC,          KC_INS,  KC_HOME, KC_PGUP, \
        KC_TAB,  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    DE_UE,   DE_PLUS,                   KC_DEL,  KC_END,  KC_PGDN, \
        KC_CAPS, DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    DE_H,    DE_J,    DE_K,    DE_L,    DE_OE,   DE_AE,   DE_HASH, KC_ENT,                                      \
        KC_LSFT, DE_LESS, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS,          KC_RSFT,                   KC_UP,            \
        KC_LCTL, KC_LGUI, KC_LALT,                           KC_SPC,                              KC_RALT, KC_RGUI, KC_APP,  KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
};
