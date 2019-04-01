#include QMK_KEYBOARD_H
#include "keymap_nordic.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _LOWER 3
#define _RAISE 4
#define _FN 6
#define _CONFIG 7
#define _WSNAV 7

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define CONFIG MO(_CONFIG)
#define FN     MO(_FN)
#define WSNAV  MO(_WSNAV)

#define CTRL_TAB       LCTL(KC_TAB)
#define CTRL_S_TAB LCTL(LSFT(KC_TAB))
#define ALT_TAB        LALT(KC_TAB)
#define SHFT_ALT_TAB   LSFT(LALT(KC_TAB))
#define ALT_F4         LALT(KC_F4)
#define SHIFT_BCKSPC   LSFT_T(KC_BSPC)
#define SHIFT_SPC      SFT_T(KC_SPC)
#define TAB_SHIFT      SFT_T(KC_TAB)
#define RAISESPACE     LT(_RAISE, KC_SPC)
#define L_AG_SWAP      MAGIC_SWAP_LALT_LGUI
#define L_AG_NORM      MAGIC_UNSWAP_LALT_LGUI

#define WS_MOD_1       LGUI(KC_1)
#define WS_MOD_2       LGUI(KC_2)
#define WS_MOD_3       LGUI(KC_3)
#define WS_MOD_4       LGUI(KC_4)
#define WS_MOD_5       LGUI(KC_5)
#define WS_MOD_6       LGUI(KC_6)
#define WS_MOD_7       LGUI(KC_7)
#define WS_MOD_8       LGUI(KC_8)
#define WS_MOD_9       LGUI(KC_9)
#define WS_MOD_0       LGUI(KC_0)

#define WIN_WS_RIGHT LCTL(LWIN(KC_RIGHT))
#define WIN_WS_LEFT  LCTL(LWIN(KC_LEFT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------.         .-----------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |         |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------         -------+------+------+------+------+------|
 * |CrlEsc|   A  |   R  |   S  |   T  |   D  |         |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|         |------+------+------+------+------+------|
 * |TabSft|   Z  |   X  |   C  |   V  |   B  |         |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+         +------+------+------+------+------+------|
 * |Config| Alt  | GUI  | Shft |Lower | Bksp |         |Space |Raise | Shft | Ctrl | RALT | Fn   |
 * `-----------------------------------------'         '-----------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12( \
  KC_TAB,         KC_Q,    KC_W,    KC_F,      KC_P,    KC_G,    /**/   KC_J,       KC_L,    KC_U,      KC_Y,     KC_SCLN,  KC_BSPC, \
  CTL_T(KC_ESC),  KC_A,    KC_R,    KC_S,      KC_T,    KC_D,    /**/   KC_H,       KC_N,    KC_E,      KC_I,     KC_O,     KC_QUOT, \
  TAB_SHIFT,      KC_Z,    KC_X,    KC_C,      KC_V,    KC_B,    /**/   KC_K,       KC_M,    KC_COMM,   KC_DOT,   KC_SLSH,  KC_ENT , \
  CONFIG,         KC_LALT, KC_LGUI, KC_LSHIFT, LOWER,   KC_BSPC, /**/   KC_SPC,     RAISE,   KC_RSHIFT, KC_RCTRL, KC_RALT,  FN  \
),

/* Qwerty
 * ,-----------------------------------------.          .-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |          |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------          -------+------+------+------+------+------|
 * |CrlEsc|   A  |   S  |   D  |   F  |   G  |          |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|          |------+------+------+------+------+------|
 * |TabSft|   Z  |   X  |   C  |   V  |   B  |          |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+          +------+------+------+------+------+------|
 * |Config| Alt  | GUI  | Shft |Lower | Bksp |          |Space |Raise | Shft | Ctrl | RALT | Fn   |
 * `-----------------------------------------'          '-----------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
   KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,    /**/   KC_Y,       KC_U,       KC_I,      KC_O,     KC_P,        KC_BSPC, \
   CTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,      KC_G,    /**/   KC_H,       KC_J,       KC_K,      KC_L,     KC_SCLN,     KC_QUOT, \
   TAB_SHIFT,      KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,    /**/   KC_N,       KC_M,       KC_COMM,   KC_DOT,   KC_SLSH,     KC_ENT , \
   CONFIG,         KC_LALT, KC_LGUI, KC_LSHIFT, LOWER,   KC_BSPC, /**/   KC_SPC,     RAISE,      KC_RSHIFT, KC_RCTRL, KC_RALT,     FN  \
),

/* Lower
 * ,-----------------------------------------.          .--------------------------------------------.
 * |  ~/` |   !  |   @  |   #  |   $  |   %  |          |   ^  |   7  |  8   |  9   |  \   | Del     |
 * |------+------+------+------+------+-------          -------+------+------+------+------+---------|
 * |      |   {  |   (  |   )  |   }  |  +   |          |   &  |   4  |  5   |  6   |   +  |ALT_TAB  |
 * |------+------+------+------+------+------|          |------+------+------+------+------+---------|
 * |      |      |   [  |   ]  |  _   |  |   |          |   *  |   1  |  2   |  3   |   -  |S_ALT_TAB|
 * |------+------+------+------+------+------+          +------+------+------+------+------+---------|
 * |      |      |      |      |      |WSNAV |          |Enter |   0  |  .   |      |      |PRTSCR   |
 * `-----------------------------------------'          '--------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_GRAVE, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, /**/ KC_CIRC, KC_7, KC_8,   KC_9,    KC_BSLS, KC_DEL, \
  _______,  KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, KC_PLUS, /**/ KC_ASTR, KC_4, KC_5,   KC_6,    KC_PLUS, ALT_TAB,  \
  _______,  _______, KC_LBRC, KC_RBRC, KC_UNDS, KC_PIPE, /**/ KC_AMPR, KC_1, KC_2,   KC_3,    KC_MINS, SHFT_ALT_TAB, \
  _______,  _______, _______, _______, _______, WSNAV,   /**/ KC_ENT,  KC_0, KC_DOT, _______, _______, KC_PSCR \
),

/* Raise
 * ,-----------------------------------------.          .-----------------------------------------.
 * |      |win+1 |win+2 |win+3 |win+4 |win+5 |          |      |      |  =   |  -   |      |      |
 * |------+------+------+------+------+-------          |------+------+------+------+------+------|
 * |      |      |  ä   |  å   |  ö   |      |          |      |  <   |  v   |  ^   |   >  |      |
 * |------+------+------+------+------+------|          |------+------+------+------+------+------|
 * |      |      |      |      |      |      |          |CS_TAB|C_TAB |W_WS_L|W_WS_R|      |      |
 * |------+------+------+------+------+------+          +------+------+------+------+------+------|
 * |      |      |      |      |      |      |          |      |      |      |      |      |      |
 * `-----------------------------------------'          '-----------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  _______, LWIN(KC_1), LWIN(KC_2), LWIN(KC_3),  LWIN(KC_4),  LWIN(KC_5), /**/ _______,    _______,  KC_EQUAL,    KC_MINS,      _______,  _______, \
  _______, _______,    RALT(KC_Q), RALT(KC_W),  RALT(KC_P),  _______,    /**/ _______,    KC_LEFT,  KC_DOWN,     KC_UP,        KC_RIGHT, _______, \
  _______, _______,    _______,    _______,     _______,     _______,    /**/ CTRL_S_TAB, CTRL_TAB, WIN_WS_LEFT, WIN_WS_RIGHT, _______,  _______,   \
  _______, _______,    _______,    _______,     _______,     _______,    /**/ _______,    _______,  _______,     _______,      _______,  _______ \
), 

/* Workspace nav
 * ,-----------------------------------------.          .-----------------------------------------.
 * |      |      |      |      |      |      |          |      |mod 7 |mod 8 |mod 9 |      |      |
 * |------+------+------+------+------+-------          -------+------+------+------+------+------|
 * |      |      |      |      |      |      |          |      |mod 4 |mod 5 |mod 6 |      |      |
 * |------+------+------+------+------+------|          |------+------+------+------+------+------|
 * |      |      |      |      |      |      |          |      |mod 1 |mod 2 |mod 3 |      |      |
 * |------+------+------+------+------+------+          +------+------+------+------+------+------|
 * |      |      |      |      |      |      |          |      |mod 0 |      |      |      |      |
 * `-----------------------------------------'          '-----------------------------------------'
 */
[_WSNAV] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, /**/ _______, WS_MOD_7, WS_MOD_8, WS_MOD_9, _______, _______, \
  _______, _______, _______, _______, _______, _______, /**/ _______, WS_MOD_4, WS_MOD_5, WS_MOD_6, _______, _______, \
  _______, _______, _______, _______, _______, _______, /**/ _______, WS_MOD_1, WS_MOD_2, WS_MOD_3, _______, _______, \
  _______, _______, _______, _______, _______, _______, /**/ _______, WS_MOD_0, _______,  _______, _______, _______ \
),

/* Fn (F-keys etc)
 * ,-----------------------------------------.          .-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |          |      |      |      |      |      |      |
 * |------+------+------+------+------+-------          -------+------+------+------+------+------|
 * |AltF4 |  F6  |  F7  |  F8  |  F9  |  F10 |          |      |      |      |      |      |      |
 * |------+------+------+------+------+------|          |------+------+------+------+------+------|
 * |      | F11  |  F12 |      |      |      |          |      |      |      |      |      |      |
 * |------+------+------+------+------+------+          +------+------+------+------+------+------|
 * |      |      |      |      |      |      |          |      |      |      |      |      |      |
 * `-----------------------------------------'          '-----------------------------------------'
 */
[_FN] = LAYOUT_ortho_4x12( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   /**/ _______, _______, _______, _______, _______, _______, \
  ALT_F4,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  /**/ _______, _______, _______, _______, _______, _______, \
  _______, KC_F11,  KC_F12,  _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______ \
),

/* CONFIG
 * ,-----------------------------------------.          .-----------------------------------------.
 * |Reset |Colemk|Qwerty|      |      |      |          |      |      |      |      |      |      |
 * |------+------+------+------+------+-------          -------+------+------+------+------+------|
 * |Aud on|Audoff|AGnorm|AGswap|      |      |          |      | HOME | PGDN | PGUP |  END |      |
 * |------+------+------+------+------+------|          |------+------+------+------+------+------|
 * |      | CAPS |      |      |      |      |          |      | Prev | Vol- | Vol+ | Next | Play |
 * |------+------+------+------+------+------+          +------+------+------+------+------+------|
 * |      |      |      |      |      |      |          |      |      |      |      |      |      |
 * `-----------------------------------------'          '-----------------------------------------'
 */
[_CONFIG] =  LAYOUT_ortho_4x12( \
  RESET,   COLEMAK,     QWERTY,    _______,   _______, _______, /**/ _______, _______, _______, _______, _______, _______, \
  AU_ON,   AU_OFF,      L_AG_NORM, L_AG_SWAP, _______, _______, /**/ _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, \
  _______, KC_CAPSLOCK, _______,   _______,   _______, _______, /**/ _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, \
  _______, _______,     _______,   _______,   _______,_______,  /**/ _______, _______, _______, _______, _______, _______ \
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
  }
  return true;
}

