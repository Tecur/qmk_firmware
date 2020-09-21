#include QMK_KEYBOARD_H
#include "keymap_german.h"

enum layer_names {
    _BASE,
    _FN
};

//Macro enum
enum custom_keycodes {
  TS_MUTE = SAFE_RANGE,
  TS_DEAF,
  //add more here...
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_all( /* Base */
    KC_ESC,  DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_SS,   DE_ACUT, KC_BSPC, _______,
    KC_TAB,  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    DE_UE,   DE_PLUS,          DE_HASH,
    KC_CAPS, DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    DE_H,    DE_J,    DE_K,    DE_L,    DE_OE,   DE_AE,                     KC_ENT,
    KC_LSFT, DE_LESS, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS, KC_RSFT,          MO(_FN),
    KC_LCTL, KC_LGUI, KC_LALT,          KC_SPC,           KC_SPC,           KC_SPC,                    KC_RALT, KC_RGUI, KC_APP,  KC_RCTL
  ),
  [_FN] = LAYOUT_all( /* FN */
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  _______,
    DE_CIRC, KC_MYCM, KC_UP,   _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT,          _______,
    KC_WHOM, KC_LEFT, KC_DOWN, KC_RIGHT,_______, KC_VOLD, KC_VOLU, _______, _______, _______, _______, _______,                   _______,
    KC_PGUP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_PSCR, _______,
    KC_PGDN, TS_MUTE, TS_DEAF,          _______,          _______,          _______,                   _______, _______, _______, _______
  )
};

//Macro events
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TS_MUTE:                                   // TS/Discord MUTE
      if (record->event.pressed) {
        // when keycode TS_MUTE is pressed
        SEND_STRING(SS_LCTRL(SS_LALT(SS_LSFT(SS_TAP(X_END)))));
      } else {
        // when keycode TS_MUTE is released
      }
      break;
    case TS_DEAF:                                 // TS/Discord DEAF
      if (record->event.pressed) {
        // when keycode TS_DEAF is pressed
        SEND_STRING(SS_LCTRL(SS_LALT(SS_LSFT(SS_TAP(X_HOME)))));
      } else {
        // when keycode TS_DEAF is released
      }
      break;
      //add more here...
  }
  return true;  //for use later
};