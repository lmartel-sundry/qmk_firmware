/*  -*-  eval: (turn-on-orgtbl); -*-
 * Copyright 2019 Leo
 * Copyright 2017 Wunder
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Layer shorthand
#define _QW 0
#define _FN 1

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
  |--------+-------+------+------+-------+-------+-------+-------+-------+-------+------+--------+--------+--------+-------|
  | ESC    | 1     | 2    | 3    | 4     | 5     | 6     | 7     | 8     | 9     | 0    | -      | =      | \      | `     |
  |--------+-------+------+------+-------+-------+-------+-------+-------+-------+------+--------+--------+--------+-------|
  | TAB    | Q     | W    | E    | R     | T     | Y     | U     | I     | O     | P    | [      | ]      | BACKSP | DEL   |
  |--------+-------+------+------+-------+-------+-------+-------+-------+-------+------+--------+--------+--------+-------|
  | CAP LK | A     | S    | D    | F     | G     | H     | J     | K     | L     | ;    | '      | ENTER  | ENTER  | PG UP |
  |--------+-------+------+------+-------+-------+-------+-------+-------+-------+------+--------+--------+--------+-------|
  | LSHIFT | Z     | X    | C    | V     | B     | N     | M     | ,     | .     | /    | RSHIFT | RSHIFT | UP     | PG DN |
  |--------+-------+------+------+-------+-------+-------+-------+-------+-------+------+--------+--------+--------+-------|
  | HYPR   | LCTRL | LALT | LGUI | LOWER | SPACE | SPACE | SPACE | RAISE | RCTRL | HOME | END    | LEFT   | DOWN   | RIGHT |
  |--------+-------+------+------+-------+-------+-------+-------+-------+-------+------+--------+--------+--------+-------|
 */

  [_QW] = LAYOUT_ortho_5x15
  ( /* QWERTY */
   KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL, KC_BSLS, KC_GRV,
   KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, KC_DEL,
   KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_ENT,  KC_PGUP,
   KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT, KC_UP,   KC_PGDN,
   KC_HYPR,  KC_LCTL, KC_LALT, KC_LGUI, MO(_FN), KC_SPC,  KC_SPC,  KC_SPC,  MO(_FN), KC_RCTL, KC_HOME, KC_END,  KC_LEFT, KC_DOWN, KC_RIGHT
    ),

/* FUNCTION
  |---------+---------+------+------+-------+-------+-------+-------+---+---+---+---+---|
  | RGB TOG | RGB TOG |      |      |       |       |       |       |   |   |   |   |   |
  |---------+---------+------+------+-------+-------+-------+-------+---+---+---+---+---|
  | RGB HD  | RGB HI  |      |      |       |       |       |       |   |   |   |   |   |
  |---------+---------+------+------+-------+-------+-------+-------+---+---+---+---+---|
  | RGB SD  | RGB SI  |      |      |       |       |       |       |   |   |   |   |   |
  |---------+---------+------+------+-------+-------+-------+-------+---+---+---+---+---|
  | RGB VD  | RGB VI  |      |      |       |       |       |       |   |   |   |   |   |
  |---------+---------+------+------+-------+-------+-------+-------+---+---+---+---+---|
  | RGB RMD | RGB MD  | LALT | LGUI | LOWER | SPACE | RESET | SPACE |   |   |   |   |   |
  |---------+---------+------+------+-------+-------+-------+-------+---+---+---+---+---|
 */

  [_FN] = LAYOUT_ortho_5x15
  ( /* FUNCTION */
   RGB_TOG, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
   RGB_HUD, RGB_HUI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
   RGB_SAD, RGB_SAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
   RGB_VAD, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
   RGB_RMOD,RGB_MOD, _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
