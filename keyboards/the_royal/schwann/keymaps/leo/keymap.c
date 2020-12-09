#include QMK_KEYBOARD_H

enum layer_names {
  _QWERTY,
  _LOWER,
  _RAISE,
  _OTHER
};

enum schwann_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE
};

//Tap Dance Declarations
enum {
  TD_RST
};

void dance_rst_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 2) {
    reset_keyboard();
    reset_tap_dance(state);
  }
}

//All tap dance functions would go here. Only showing this one.
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_RST] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, NULL, dance_rst_reset)
};


#define XXXXX KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   *        |     Gui     |           Space (Hold: Lower)           |    Raise    |
   *        `---------------------------------------------------------------------'
   */
  [_QWERTY] = LAYOUT_big_boy(
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,    KC_BSPC,
    KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH, KC_ENT,
              KC_LGUI,                            LT(_LOWER, KC_SPACE),                          RAISE
  ),

  /* Lower
   * ,-----------------------------------------------------------------------------------.
   * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | `    |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | Left | Down |  Up  |Right | Alt  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   *        |     Gui     |                  Lower                  |    Raise    |
   *        `---------------------------------------------------------------------'
   */

  [_LOWER] = LAYOUT_big_boy(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_RALT,
             _______,                                 LOWER,                                  _______
  ),

  /* Raise
   * ,-----------------------------------------------------------------------------------.
   * | Esc  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  ~   |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Alt  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | Left | Down |  Up  |Right | Alt  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   *        |     Gui     |                  Lower                  |    Raise    |
   *        `---------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT_big_boy(
    KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_TILD,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_LEFT,    KC_DOWN,    KC_UP,   KC_RGHT, KC_RALT,
             _______,                                 LOWER,                                        _______
),

  /* Other Layer
   * ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
   * │RSET│ XX │ XX │ XX │ XX │ XX │ XX │ XX │ XX │SAT+│Hue+│Brt+│
   * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
   * │ XX │ XX │ XX │ XX │ XX │ XX │ XX │ XX │ XX │SAT-│Hue-│Brt-│
   * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
   * │ XX │ XX │ XX │ XX │ XX │ XX │ XX │ XX │ XX │ XX │ XX │RGB!│
   * └────┼────┴────┼────┴────┴────┴────┴────┴────┼────┴────┼────┘
   *      │    \`     │                             │         │
   *      └─────────┴─────────────────────────────┴─────────┘
   */
  [_OTHER] = LAYOUT_big_boy(
    RESET,      XXXXXXX,   XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,  RGB_SAI,  RGB_HUI,  RGB_VAI,
    XXXXXXX,    XXXXXXX,   XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,  RGB_SAD,  RGB_HUD,  RGB_VAD,
    XXXXXXX,    XXXXXXX,   XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RGB_MOD,
                _______,                                     _______,                                            _______
  )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _OTHER);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _OTHER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _OTHER);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _OTHER);
      }
      return false;
      break;
  }
  return true;
};
