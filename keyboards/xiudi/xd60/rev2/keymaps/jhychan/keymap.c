#include QMK_KEYBOARD_H

// Layer enumerations
enum {
  _BL = 0, // Windows Base layer
  _GL    , // Guest mode layer (standard 60% ANSI)
  _JL    , // Ju-mode layer
  _FN    , // Universal Function layer
  _CL    , // Universal Control layer
  _MP      // Mouse/Pointer Layer
};

// Keycode macros
#define _____ KC_NO
#define __v__ KC_TRNS
#define _RSKU RSFT_T(KC_UP)
#define _RAKD RALT_T(KC_DOWN)
#define _FNKL LT(_FN,KC_LEFT)
#define _CTKR RCTL_T(KC_RIGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // Windows Base Layer
  [_BL] = LAYOUT_all(
    KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_NUBS,  TT(_CL),
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,            KC_BSPC,
    KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  _____,              KC_ENT,
    KC_LSFT,  _____,    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  _____,    KC_RSFT,  _____,
    KC_NUHS,  MO(_FN),  KC_RALT,                                KC_SPC,                                 KC_RGUI,  MO(_FN),  _____,    KC_RALT,  TG(_JL)
  ),

  // Guest mode layer
  [_GL] = LAYOUT_all(
    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    KC_BSPC,  KC_BSPC,
    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,              KC_NUBS,
    KC_CAPS,  __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    _____,              __v__,
    __v__,    _____,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    _____,    __v__,    _____,
    KC_LCTL,  KC_LGUI,  KC_LALT,                                __v__,                                  KC_RALT,  KC_RGUI,  _____,    KC_APP,   __v__
  ),

  // Ju-mode layer
  [_JL] = LAYOUT_all(
    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    KC_NUBS,  KC_DEL,
    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,              KC_BSPC,
    KC_CAPS,  __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    _____,              __v__,
    __v__,    _____,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    __v__,    _____,    _RSKU,    _____,
    KC_LCTL,  KC_LGUI,  KC_LALT,                                __v__,                                  __v__,    _FNKL,    _____,    _RAKD,    _CTKR
  ),

  // Universal Function layer
  [_FN] = LAYOUT_all(
    KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   __v__,    __v__,
    __v__,    _____,    _____,    KC_UP,    _____,    _____,    _____,    _____,    KC_UP,    _____,    KC_PSCR,  _____,    _____,              KC_DEL,
    __v__,    _____,    KC_LEFT,  KC_DOWN,  KC_RIGHT, _____,    _____,    KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_HOME,  KC_PGUP,  _____,              __v__,
    __v__,    _____,    _____,    KC_APP,   _____,    _____,    _____,    _____,    _____,    _____,    KC_END,   KC_PGDN,  _____,    __v__,    _____,
    __v__,    __v__,    __v__,                                  _____,                                  __v__,    __v__,    _____,    __v__,    __v__
  ),

  // Universal Control layer
  [_CL] = LAYOUT_all(
    KC_WAKE,  KC_SLEP,  KC_PWR,   _____,    _____,    _____,    _____,    _____,    _____,    _____,    _____,    _____,    _____,    _____,    TG(_CL),
    _____,    _____,    KC_F14,   KC_VOLU,  KC_F15,   _____,    _____,    _____,    BL_UP,    KC_MSTP,  KC_MPLY,  KC_MPRV,  KC_MNXT,            _____,
    _____,    _____,    _____,    KC_VOLD,  KC_MUTE,  _____,    _____,    _____,    BL_DOWN,  _____,    KC_MRWD,  KC_MFFD,  _____,              _____,
    KC_CAPS,  _____,    _____,    RGB_HUD,  RGB_SAD,  RGB_VAD,  RGB_TOG,  RGB_VAI,  RGB_SAI,  RGB_HUI,  _____,    _____,    _____,    KC_CAPS,  _____,
    TG(_MP),  _____,    _____,                                  RGB_MOD,                                _____,    _____,    _____,    _____,    _____
  ),

  // Mouse/Pointer Layer
  [_MP] = LAYOUT_all(
    _____,    KC_ACL0,  KC_ACL1,  KC_ACL2,  _____,    _____,    _____,    _____,    _____,    _____,    _____,    _____,    _____,    _____,    _____,
    _____,    _____,    KC_BTN2,  KC_WH_U,  KC_BTN1,  _____,    _____,    KC_BTN1,  KC_MS_U,  KC_BTN2,  _____,    _____,    _____,              _____,
    _____,    _____,    KC_WH_L,  KC_WH_D,  KC_WH_R,  _____,    _____,    KC_MS_L,  KC_MS_D,  KC_MS_R,  _____,    _____,    _____,              _____,
    _____,    _____,    _____,    _____,    _____,    _____,    _____,    _____,    _____,    _____,    _____,    _____,    _____,    _____,    _____,
    __v__,    _____,    _____,                                  _____,                                  _____,    _____,    _____,    _____,
  )

};
