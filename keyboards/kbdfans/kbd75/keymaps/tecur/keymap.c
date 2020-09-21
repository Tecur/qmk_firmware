#include QMK_KEYBOARD_H
#include "keymap_german.h"

//Macro enum
enum custom_keycodes {
  TS_MUTE = SAFE_RANGE,
  TS_DEAF
  //add more here...
};

//Layer names
#define BASE 0 // default layer
#define FNT 1 // symbol layer

//Color names
#define HSV_STATIC 121, 133, 118    //Static Color
#define HSV_CAPS 0, 255, 255    //Caps Indicator Color
#define HSV_LAYER 30, 218, 218   //Second Layer Color

//Variables
bool is_caps_active = false;
bool is_layer_active = false;
//Variables to remeber last Color for Caps
uint8_t last_color_hue = 121;
uint8_t last_color_sat = 133;
uint8_t last_color_val = 118;

//Variables to remeber last Color for Layer
uint8_t layer_last_color_hue = 121;
uint8_t layer_last_color_sat = 133;
uint8_t layer_last_color_val = 118;

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
    _______,  KC_WHOM,  KC_MYCM,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  TS_MUTE,  TS_DEAF,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,    _______,
    _______,  RGB_TOG,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  KC_VOLU,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,  KC_VOLD,
    _______,  _______,  _______,  _______,  BL_DEC,   BL_TOGG,  BL_INC,   BL_STEP,  _______,  _______,  _______,  _______,  _______,            _______,  KC_MUTE,
    _______,  _______,  _______,                      _______,  _______,  _______,                      _______,  _______,  _______,  KC_MPRV,  KC_MPLY,  KC_MNXT
  ),
};

void matrix_init_user(void) {  // Runs boot tasks for keyboard
    rgblight_enable();
    rgblight_sethsv(HSV_STATIC);
    rgblight_mode(0);   //No animation
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
      case KC_CAPS:                                 // Caps Lock
        if (record->event.pressed) {
          // when Caps Lock is pressed
          is_caps_active = !is_caps_active;
          if (is_caps_active) {                   //Update Caps Lock Color
              last_color_hue = rgblight_get_hue();
              last_color_sat = rgblight_get_sat();
              last_color_val = rgblight_get_val();
              rgblight_sethsv(HSV_CAPS);
          } else {
              rgblight_sethsv(last_color_hue,last_color_sat,last_color_val);
          }
        } else {
          // when Caps Lock is released
        }
        break;
        /*
        case MO(FNT):                                 // Second Layer
          if (record->event.pressed) {
            // when Layer Key is pressed
            is_layer_active = true;
            layer_last_color_hue = rgblight_get_hue();
            layer_last_color_sat = rgblight_get_sat();
            layer_last_color_val = rgblight_get_val();
            rgblight_sethsv(HSV_LAYER);
          } else {
            // when Layer Key is released
            is_layer_active = false;
            rgblight_sethsv(layer_last_color_hue,layer_last_color_sat,layer_last_color_val);
          }
          break;
          */
      //add more here...
  }
  return true;  //for use later
};

/*
Planned:
    - Layer Indicator debug (funktionier nicht mit Caps), evtl. neue Methode
    - More Macros
		- Diffrent Light Scenes for Debug, Bootloader, etc.
		- Debug Log output???
*/
