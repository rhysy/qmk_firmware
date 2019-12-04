#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /* DEFAULT
  * ,----------------------------------------------------------------------------------------------.
  * | ESC |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  +  |  BackSp  |  ~  |
  * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+----------+-----|
  * |   TAB  |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  {  |  }  |   \   | DEL |
  * |--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-------+-----|
  * |   CAPS   |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |   RETURN  | PGUP|
  * |----------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----------+-----|
  * |   SHIFT    |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  <  |  >  |  ?  |  SHIFT  |  UP | PGDN|
  * |------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+---------+-----+-----|
  * | CTRL |  ALT | LGUI |             SPACE                   | WIN |MO(1)| ALT | LEFT| DOWN|RIGHT|
  * '----------------------------------------------------------------------------------------------'
 */
#define CTRL_CAPS   LCTL_T(KC_CAPS)

  [0] = LAYOUT_65_ansi(
    KC_ESC,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,  KC_EQL,  KC_BSPC,   KC_GRV, \
    KC_TAB,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,  KC_RBRC, KC_BSLS, KC_DEL,\
    CTRL_CAPS,    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, KC_QUOT,     KC_ENT,     KC_PGUP, \
    KC_LSFT,        KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH,   KC_RSFT,  KC_UP,    KC_PGDN, \
    KC_LCTL,         KC_LALT, KC_LGUI,                 KC_SPC,                KC_RGUI,  MO(1), KC_RALT, KC_LEFT,  KC_DOWN,  KC_RGHT
   ),

 /* LAYER 1
  * ,----------------------------------------------------------------------------------------------.
  * |     |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |          |     |
  * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+----------+-----|
  * |        |RGBTG| MD+ | HUE+| HUE-| SAT+| SAT-| BRT+| BRT-|     |PTSRN|SC LK|PAUSE| RESET |     |
  * |--------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-------+-----|
  * |          | SPD+| SPD-|     |     |     |     |     |     |     |     |     | EEPROM RST|     |
  * |----------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----------+-----|
  * |            |     |     |     |     |     |     |     |     |     |     |         | VOL+| MUTE|
  * |------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+---------+-----+-----|
  * |      |      |      |                                     |     |     |     | PREV| VOL-| MEXT|
  * '----------------------------------------------------------------------------------------------'
 */
	[1] = LAYOUT_65_ansi(KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_TRNS, KC_TRNS, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, RESET, KC_TRNS, LCTL_T(KC_TRNS), RGB_SPI, RGB_SPD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, EEP_RST, KC_MPLY, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_VOLD, KC_MNXT)
};

void rgb_matrix_indicators_user(void) {
    if (IS_LED_ON(host_keyboard_leds(), USB_LED_CAPS_LOCK)) {
        rgb_matrix_set_color(8, 0xFF, 0xFF, 0xFF);
    }
}
