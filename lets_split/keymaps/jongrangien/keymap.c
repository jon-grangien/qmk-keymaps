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
#define _ADJUST 7

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define FN     MO(_FN)

#define CTRL_TAB       LCTL(KC_TAB)
#define CTRL_SHIFT_TAB LCTL(LSFT(KC_TAB))
#define ALT_TAB        LALT(KC_TAB)
#define SHIFT_BCKSPC   LSFT_T(KC_BSPC)
#define SHIFT_SPC      SFT_T(KC_SPC)
#define TAB_SHIFT      SFT_T(KC_TAB)
#define RAISESPACE     LT(_RAISE, KC_SPC)

#define WIN_WS_RIGHT LCTL(LGUI_T(KC_RIGHT))
#define WIN_WS_LEFT  LCTL(LGUI_T(KC_LEFT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |CrlEsc|   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |TabSft|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |SftBsp|Space |Raise | Enter| C_TAB| RALT | Fn   |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12( \
  KC_TAB,         KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,         KC_J,    KC_L,    KC_U,    KC_Y,     KC_SCLN, KC_BSPC, \
  CTL_T(KC_ESC),  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,         KC_H,    KC_N,    KC_E,    KC_I,     KC_O,    KC_QUOT, \
  TAB_SHIFT,      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_K,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH, KC_ENT , \
  ADJUST,         KC_LCTL, KC_LALT, KC_LGUI, LOWER,   SHIFT_BCKSPC, KC_SPC,  RAISE,   KC_ENT,  CTRL_TAB, KC_RALT, FN  \
),

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |CrlEsc|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |TabSft|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |SftBsp|Space |Raise | Enter|C_TAB | RALT | Fn   |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
   KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,    KC_BSPC, \
   CTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN, KC_QUOT, \
   TAB_SHIFT,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH, KC_ENT , \
   ADJUST,        KC_LCTL, KC_LALT, KC_LGUI, LOWER,   SHIFT_BCKSPC, KC_SPC,  RAISE,   KC_ENT,  CTRL_TAB, KC_RALT, FN  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  ~/` |   !  |   @  |   #  |   $  |   %  |   ^  |   7  |  8   |  9   | PgUp | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   {  |   (  |   )  |   }  |  +   |   &  |   4  |  5   |  6   | PgDn |ALT_TB|      
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |   [  |   ]  |  _   |  |   |   *  |   1  |  2   |  3   | Home |PRTSCR|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  0   |  .   |      | End  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_GRAVE, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_7, KC_8,   KC_9,    KC_PGUP, KC_DEL, \
  _______,  KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, KC_PLUS, KC_ASTR, KC_4, KC_5,   KC_6,    KC_PGDN, ALT_TAB,  \
  _______,  _______, KC_LBRC, KC_RBRC, KC_UNDS, KC_PIPE, KC_AMPR, KC_1, KC_2,   KC_3,    KC_HOME, KC_PSCR,\
  _______,  _______, _______, _______, _______, _______, _______, KC_0, KC_DOT, _______, KC_END,  _______ \
),


        /* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |   _  |  -   |  +   |  =   |   *  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |  ä   |  å   |  ö   |      |      |  <   |  v   |   ^  |   >  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |W_WS_L|W_WS_R|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |   ^  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  _______, _______, _______,    _______,    _______,    _______, KC_UNDS, KC_MINS, KC_PLUS, KC_EQUAL,     KC_ASTR,      KC_BSLS, \
  _______, _______, RALT(KC_Q), RALT(KC_W), RALT(KC_P), _______, _______, KC_LEFT, KC_DOWN, KC_UP,        KC_RIGHT,     _______, \
  _______, _______, _______,    _______,    _______,    _______, _______, _______, _______, WIN_WS_LEFT,  WIN_WS_RIGHT, _______,   \
  _______, _______, _______,    _______,    _______,    _______, _______, _______, _______, _______,      _______,      _______ \
), 

/* Fn (F-keys etc)
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  |  F10 |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | F11  |  F12 |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_ortho_4x12( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, _______, _______, _______, _______, \
  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, _______, _______, _______, _______, _______, \
  _______, KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Reset |Colemk|Qwerty|      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Aud on|Audoff|AGnorm|AGswap|      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | CAPS        |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Next | Vol- | Vol+ | Play |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  RESET,   COLEMAK,     QWERTY,  _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, \
  AU_ON,   AU_OFF,      AG_NORM, AG_SWAP, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_CAPSLOCK, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_MNXT,     KC_VOLD, KC_VOLU, KC_MPLY, _______, _______, _______, _______, _______, _______, _______ \
),

};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

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

