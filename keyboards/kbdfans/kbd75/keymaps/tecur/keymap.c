#include QMK_KEYBOARD_H
#include "keymap_german.h"

//Macro enum
enum custom_keycodes {
  TS_MUTE = SAFE_RANGE,
  TS_DEAF,
  //add more here...
};

//Layer names
#define BASE 0 // default layer
#define FNT 1 // symbol layer

//Color names
#define HSV_BASE 121, 133, 118    //Static Color
#define HSV_CAPS 0, 255, 255    //Caps Indicator Color
#define HSV_FNT 30, 218, 218   //Second Layer Color

//Variables
bool is_caps_active = false;
uint8_t active_layer = BASE;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,   KC_HOME,   KC_INS,
    DE_CIRC,  DE_1,     DE_2,     DE_3,     DE_4,     DE_5,     DE_6,     DE_7,     DE_8,     DE_9,     DE_0,     DE_SS,    DE_ACUT,  _______,  KC_BSPC,  KC_PGUP,
    KC_TAB,   DE_Q,     DE_W,     DE_E,     DE_R,     DE_T,     DE_Z,     DE_U,     DE_I,     DE_O,     DE_P,     DE_UE,    DE_PLUS,            DE_HASH,  KC_PGDN,
    KC_CAPS,  DE_A,     DE_S,     DE_D,     DE_F,     DE_G,     DE_H,     DE_J,     DE_K,     DE_L,     DE_OE,    DE_AE,                        KC_ENT,   KC_END,
    KC_LSFT,  DE_LESS,  DE_Y,     DE_X,     DE_C,     DE_V,     DE_B,     DE_N,     DE_M,     DE_COMM,  DE_DOT,   DE_MINS,  KC_RSFT,            KC_UP,    KC_DEL,
    KC_LCTL,  KC_LGUI,  KC_LALT,                      KC_SPC,   KC_SPC,   KC_SPC,                       KC_RALT,  MO(FNT),  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

  [FNT] = LAYOUT(
    _______,  TS_MUTE,  TS_DEAF,  KC_WHOM,  KC_MYCM,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  KC_KP_1,  KC_KP_2,  KC_KP_3,  KC_KP_4,  KC_KP_5,  KC_KP_6,  KC_KP_7,  KC_KP_8,  KC_KP_9,  KC_KP_0,  KC_PSLS,  _______,  _______,  RESET,    _______,
    _______,  RGB_TOG,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PPLS,            KC_PAST,  KC_VOLU,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      KC_PENT,  KC_VOLD,
    _______,  _______,  _______,  _______,  BL_DEC,   BL_TOGG,  BL_INC,   BL_STEP,  _______,  KC_PCMM,  KC_PDOT,  KC_PMNS,  _______,            _______,  KC_MUTE,
    _______,  _______,  _______,                      _______,  _______,  _______,                      _______,  _______,  _______,  KC_MPRV,  KC_MPLY,  KC_MNXT
  ),
};

void matrix_init_user(void) {  // Runs boot tasks for keyboard
    rgblight_enable();
    rgblight_sethsv(HSV_BASE);
    rgblight_mode(0);   //No animation
};

void update_rgblight(void) {
  if (is_caps_active == false) {
    switch(active_layer) {
      case BASE:
        rgblight_sethsv(HSV_BASE);
        break;

      case FNT:
      rgblight_sethsv(HSV_FNT);
        break;
    }
  }
}

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
      case KC_CAPS:                                 // Caps Lock
        if (record->event.pressed) {
          // when Caps Lock is pressed
          is_caps_active = !is_caps_active;
          if (is_caps_active) {                   //Update Caps Lock Color
              rgblight_sethsv(HSV_CAPS);
          } else {
              update_rgblight();
          }
        } else {
          // when Caps Lock is released
        }
        break;

        case MO(FNT):                                 // Second Layer
          if (record->event.pressed) {
            // when Layer Key is pressed
            active_layer = FNT;
          } else {
            // when Layer Key is released
            active_layer = BASE;
          }
          update_rgblight();
          break;

      //add more here...
  }
  return true;  //for use later
};

/*
Planned:
    - More Macros
		- Diffrent Light Scenes for Debug, Bootloader, etc.
*/
