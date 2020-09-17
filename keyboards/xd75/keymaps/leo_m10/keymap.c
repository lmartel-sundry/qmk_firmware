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
  |----+-----+--------+------+------+----+-------+-------+-------+-------+----+------+------+--------+-------|
  | F1 | F2  | ESC    | 1    | 2    | 3  | 4     | 5     | 6     | 7     | 8  | 9    | 0    | BACKSP | DEL   |
  |----+-----+--------+------+------+----+-------+-------+-------+-------+----+------+------+--------+-------|
  | F3 | F4  | TAB    | Q    | W    | E  | R     | T     | Y     | U     | I  | O    | P    | '      | \     |
  |----+-----+--------+------+------+----+-------+-------+-------+-------+----+------+------+--------+-------|
  | F5 | F6  | CAP LK | A    | S    | D  | F     | G     | H     | J     | K  | L    | ;    | ENTER  | PG UP |
  |----+-----+--------+------+------+----+-------+-------+-------+-------+----+------+------+--------+-------|
  | F7 | F8  | LSHIFT | Z    | X    | C  | V     | B     | N     | M     | ,  | .    | /    | RSHIFT | PG DN |
  |----+-----+--------+------+------+----+-------+-------+-------+-------+----+------+------+--------+-------|
  | F9 | F10 | LCTRL  | LGUI | LALT | FN | SPACE | SPACE | SPACE | SPACE | FN | LEFT | DOWN | UP     | RIGHT |
  |----+-----+--------+------+------+----+-------+-------+-------+-------+----+------+------+--------+-------|
 */

  [_QW] = LAYOUT_ortho_5x15
  ( /* QWERTY */
   KC_F1, KC_F2, KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, KC_DEL,
   KC_F3, KC_F4, KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT, KC_BSLS,
   KC_F5, KC_F6, KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  KC_PGUP,
   KC_F7, KC_F8, KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_PGDN,
   KC_F9, KC_F10, KC_LCTL, KC_LGUI, KC_LALT, MO(_FN), KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  MO(_FN), KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
    ),

/* FUNCTION
  |---------+---------+-----+-----+-----+---+-------+---+---+------+------+------+------+------+------|
  | RGB TOG | RGB TOG | `   | F11 | F12 |   |       |   |   |      |      | -    | +    |      |      |
  |---------+---------+-----+-----+-----+---+-------+---+---+------+------+------+------+------+------|
  | RGB HD  | RGB HI  | Tab | Q   | W   | E | RESET |   |   |      |      |      |      | [    | ]    |
  |---------+---------+-----+-----+-----+---+-------+---+---+------+------+------+------+------+------|
  | RGB SD  | RGB SI  |     |     |     |   |       |   |   |      |      |      |      |      |      |
  |---------+---------+-----+-----+-----+---+-------+---+---+------+------+------+------+------+------|
  | RGB VD  | RGB VI  |     |     |     |   |       |   |   | MUTE | VOL- | VOL+ |      |      |      |
  |---------+---------+-----+-----+-----+---+-------+---+---+------+------+------+------+------+------|
  | RGB RMD | RGB MD  |     |     |     |   |       |   |   |      |      | PREV | PLAY | STOP | NEXT |
  |---------+---------+-----+-----+-----+---+-------+---+---+------+------+------+------+------+------|
 */

  [_FN] = LAYOUT_ortho_5x15
  ( /* FUNCTION */
   RGB_TOG, RGB_TOG, KC_GRV,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, KC_MINS, KC_PLUS, _______, _______,
   RGB_HUD, RGB_HUI, _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC,
   RGB_SAD, RGB_SAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
   RGB_VAD, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______,
   RGB_RMOD,RGB_MOD, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT
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
