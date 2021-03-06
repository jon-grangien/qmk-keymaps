#include QMK_KEYBOARD_H
// #include "keymap_nordic.h"

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
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  NPM_START,
  LSLAXH,
  GIT_ADD_ALL,
  GIT_PULL,
  GIT_COMMIT,
  GIT_STATUS,
  GIT_DIFF,
  GIT_PUSH
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define CONFIG MO(_CONFIG)
#define FN     MO(_FN)

#define ZERO_RAISE     LT(_RAISE, KC_0)

#define CTRL_TAB       LCTL(KC_TAB)
#define CTRL_S_TAB LCTL(LSFT(KC_TAB))
#define ALT_TAB        LALT(KC_TAB)
#define SHFT_ALT_TAB   LSFT(LALT(KC_TAB))
#define ALT_F4         LALT(KC_F4)
#define GUI_TAB        LGUI(KC_TAB)
#define HYPER_TAB      HYPR_T(KC_TAB)
#define L_AG_SWAP      MAGIC_SWAP_LALT_LGUI
#define L_AG_NORM      MAGIC_UNSWAP_LALT_LGUI
#define PERM_ALT_TAB   LALT(LCTL(KC_TAB))

#define WIN_WS_RIGHT LCTL(LWIN(KC_RIGHT))
#define WIN_WS_LEFT  LCTL(LWIN(KC_LEFT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------.         .-----------------------------------------.
 * | GUI  |   Q  |   W  |   F  |   P  |   B  |         |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+------|         |------+------+------+------+------+------|
 * |CrlEsc|   A  |   R  |   S  |   T  |   G  |         |   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|         |------+------+------+------+------+------|
 * |HypTab|   Z  |   X  |   C  |   D  |   V  |         |   K  |   H  |   ,  |   .  |   /  |R ctl |
 * |------+------+------+------+------+------|         |------+------+------+------+------+------|
 * |Config| GUI  | Alt  |SC Sft|Lower | Bksp |         |Space |Raise |SC Sft| Enter| RALT | Fn   |
 * `-----------------------------------------'         '-----------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12( \
  KC_LGUI,       KC_Q,    KC_W,    KC_F,    KC_P,  KC_B,    /**/   KC_J,   KC_L,  KC_U,    KC_Y,    KC_SCLN, KC_DEL, \
  CTL_T(KC_ESC), KC_A,    KC_R,    KC_S,    KC_T,  KC_G,    /**/   KC_M,   KC_N,  KC_E,    KC_I,    KC_O,    KC_QUOT, \
  HYPER_TAB,     KC_Z,    KC_X,    KC_C,    KC_D,  KC_V,    /**/   KC_K,   KC_H,  KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL , \
  CONFIG,        KC_LGUI, KC_LALT, KC_LSPO, LOWER, KC_BSPC, /**/   KC_SPC, RAISE, KC_RSPC, KC_ENT, KC_RALT, FN  \
),

/* Qwerty
 * ,-----------------------------------------.          .-----------------------------------------.
 * | GUI  |   Q  |   W  |   E  |   R  |   T  |          |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+------|          |------+------+------+------+------+------|
 * |CrlEsc|   A  |   S  |   D  |   F  |   G  |          |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|          |------+------+------+------+------+------|
 * |HypTab|   Z  |   X  |   C  |   V  |   B  |          |   N  |   M  |   ,  |   .  |   /  |R ctl |
 * |------+------+------+------+------+------|          |------+------+------+------+------+------|
 * |Config| GUI  | Alt  |SC Sft|Lower | Bksp |          |Space |Raise |SC Sft| Enter| RALT | Fn   |
 * `-----------------------------------------'          '-----------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
   KC_LGUI,       KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,    /**/   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_DEL, \
   CTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,  KC_G,    /**/   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
   HYPER_TAB,     KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,    /**/   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL , \
   CONFIG,        KC_LGUI, KC_LALT, KC_LSPO, LOWER, KC_BSPC, /**/   KC_SPC, RAISE, KC_RSPC, KC_ENT, KC_RALT, FN  \
),

/* Lower
 * ,-----------------------------------------.          .-----------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |          |   =  |   7  |  8   |  9   |  \   |      |
 * |------+------+------+------+------+------|          |------+------+------+------+------+------|
 * |      |   ^  |   &  |   *  |   ~  |   `  |          |   +  |   4  |  5   |  6   |   |  |      |
 * |------+------+------+------+------+------|          |------+------+------+------+------+------|
 * |      |      |      |      |  _   |      |          |   -  |   1  |  2   |  3   |      |      |
 * |------+------+------+------+------+------|          |------+------+------+------+------+------|
 * |      |      |      |      |      |      |          |Enter |  Rse |  0   |  .   |      |PRTSCR|
 * `-----------------------------------------'          '-----------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,   KC_PERC,  /**/ KC_EQUAL, KC_7,  KC_8, KC_9,   KC_BSLS, _______, \
  _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_TILDE, KC_GRAVE, /**/ KC_PLUS,  KC_4,  KC_5, KC_6,   KC_PIPE, _______, \
  _______, _______, _______, _______, KC_UNDS,  _______,  /**/ KC_MINS,  KC_1,  KC_2, KC_3,   _______, _______, \
  _______, _______, _______, _______, _______,  _______,  /**/ KC_ENT,   RAISE, KC_0, KC_DOT, _______, KC_PSCR \
),

/* Raise
 * ,-----------------------------------------.          .-----------------------------------------.
 * |      |   [  |  (   |  )   |  ]   |      |          |      |ALT_TB|S_A_TB|A_C_TB|GUITAB|      |
 * |------+------+------+------+------+------|          |------+------+------+------+------+------|
 * |      |      |  ä   |  å   |  ö   |      |          |      |  <   |  v   |  ^   |   >  |      |
 * |------+------+------+------+------+------|          |------+------+------+------+------+------|
 * |      |      |      |      |      |      |          |      |CS_TAB|C_TAB |W_WS_L|W_WS_R|      |
 * |------+------+------+------+------+------|          |------+------+------+------+------+------|
 * |      |      |      |      |      |      |          |      |      |      |      |      |      |
 * `-----------------------------------------'          '-----------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  _______, KC_LBRC, KC_LPRN,    KC_RPRN, KC_RBRC,       _______, /**/  _______, ALT_TAB,    SHFT_ALT_TAB, PERM_ALT_TAB, GUI_TAB,      _______, \
  _______, _______, RALT(KC_Q), RALT(KC_W), RALT(KC_P), _______, /**/  _______, KC_LEFT,    KC_DOWN,      KC_UP,        KC_RIGHT,     _______, \
  _______, _______, _______,    _______,    _______,    _______, /**/  _______, CTRL_S_TAB, CTRL_TAB,     WIN_WS_LEFT,  WIN_WS_RIGHT, _______, \
  _______, _______, _______,    _______,    _______,    _______, /**/  _______, _______,     _______,     _______,      _______,      _______ \
), 

/* Adjust (Lower + Raise)
 * ,-----------------------------------------.          .-----------------------------------------.
 * |      |      |      |      |      |      |          |      |      |      |      |      |      |
 * |------+------+------+------+------+------|          |------+------+------+------+------+------|
 * |      |      |      |npm s |  ls  |      |          |      | HOME | PGDN | PGUP |  END |      |
 * |------+------+------+------+------+------|          |------+------+------+------+------+------|
 * |g push|g pull|g add |g comt|g sts |g diff|          |      |      |      |      |      |      |
 * |------+------+------+------+------+------|          |------+------+------+------+------+------|
 * |      |      |      |      |      |      |          |      |      |      |      |      |      |
 * `-----------------------------------------'          '-----------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  _______,  _______, _______,     _______,    _______,    _______,  /**/ _______, _______, _______, _______, _______, _______, \
  _______,  _______, _______,     NPM_START,  LSLAXH,     _______,  /**/ _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, \
  GIT_PUSH, GIT_PULL,GIT_ADD_ALL, GIT_COMMIT, GIT_STATUS, GIT_DIFF, /**/ _______, _______, _______, _______, _______, _______, \
  _______,  _______, _______,     _______,    _______,    _______,  /**/ _______, _______, _______, _______, _______, _______ \
  ),

/* Fn (F-keys etc)
 * ,-----------------------------------------.          .-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |          |      |      |      |      |      |      |
 * |------+------+------+------+------+------|          |------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  |  F10 |          |      |      |      |      |      |      |
 * |------+------+------+------+------+------|          |------+------+------+------+------+------|
 * |      | F11  |  F12 |      |ALT F4|      |          |      |      |      |      |      |      |
 * |------+------+------+------+------+------|          |------+------+------+------+------+------|
 * |      |      |      |      |      |      |          |      |      |      |      |      |      |
 * `-----------------------------------------'          '-----------------------------------------'
 */
[_FN] = LAYOUT_ortho_4x12( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   /**/ _______, _______, _______, _______, _______, _______, \
  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  /**/ _______, _______, _______, _______, _______, _______, \
  _______, KC_F11,  KC_F12,  _______, ALT_F4,  _______, /**/ _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______ \
),

/* CONFIG
 * ,-----------------------------------------.          .-----------------------------------------.
 * |Reset |Colemk|Qwerty|      |      |      |          |      |      |      |      |      |      |
 * |------+------+------+------+------+------|          |------+------+------+------+------+------|
 * |Aud on|Audoff|AGnorm|AGswap|      |      |          | Play | Prev | Vol- | Vol+ | Next |      |
 * |------+------+------+------+------+------|          |------+------+------+------+------+------|
 * | CAPS |      |      |      |      |      |          |      |      |      |      |      |      |
 * |------+------+------+------+------+------|          |------+------+------+------+------+------|
 * |      |      |      |      |      |      |          |      |      |      |      |      |      |
 * `-----------------------------------------'          '-----------------------------------------'
 */
[_CONFIG] =  LAYOUT_ortho_4x12( \
  RESET,       COLEMAK, QWERTY,    _______,   _______, _______, /**/ _______, _______, _______, _______, _______, _______, \
  AU_ON,       AU_OFF,  L_AG_NORM, L_AG_SWAP, _______, _______, /**/ KC_MPLY, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,\
  KC_CAPSLOCK, _______, _______,   _______,   _______, _______, /**/ _______, _______, _______, _______, _______, _______, \
  _______,     _______, _______,   _______,   _______, _______, /**/ _______, _______, _______, _______, _______, _______ \
)
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
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case NPM_START:
      if (record->event.pressed) {
        SEND_STRING("npm start");
      }
      return false;
      break;
    case LSLAXH:
      if (record->event.pressed) {
        SEND_STRING("ls -laXh");
      }
      return false;
      break;
    case GIT_ADD_ALL:
      if (record->event.pressed) {
        SEND_STRING("git add --all");
      }
      return false;
      break;
    case GIT_PULL:
      if (record->event.pressed) {
        SEND_STRING("git pull origin $(git rev-parse --abbrev-ref HEAD)");
      }
      return false;
      break;
    case GIT_COMMIT:
      if (record->event.pressed) {
        SEND_STRING("git commit -m \"\""SS_TAP(X_LEFT));
      }
      return false;
      break;
    case GIT_STATUS:
      if (record->event.pressed) {
        SEND_STRING("git status");
      }
      return false;
      break;
    case GIT_DIFF:
      if (record->event.pressed) {
        SEND_STRING("git diff");
      }
      return false;
      break;
    case GIT_PUSH:
      if (record->event.pressed) {
        SEND_STRING("git push origin $(git rev-parse --abbrev-ref HEAD)");
      }
      return false;
      break;
  }
  return true;
}

