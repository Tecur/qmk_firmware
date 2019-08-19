#include QMK_KEYBOARD_H
#include "keymap_german.h"

//Layer names
#define BASE 0 // default layer
#define FNT 1 // symbol layer

//Color names
#define HSV_STATIC 121, 133, 118    //Static Color
#define HSV_CAPS 121, 133, 118    //Caps Indicator Color
#define HSV_LAYER 121, 133, 118    //First Layer Color

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
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,    _______,
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

/*
Planned:
    - Macro for TS/Discord Mute
    - Macro for TS/Discord Deaf
    - More Macros
    - More Animations?
    - RGB Caps Lock Indicator
    - RGB Layer Indicator?
		- Diffrent Light Scenes for Debug, Bootloader, etc.
		- Debug Log output???
*/
