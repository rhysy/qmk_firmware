#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _FUNC   1
#define _RGB    2

enum custom_keycode {
    CP_SRN = SAFE_RANGE,    // Copy screen to clipboard
    SAV_SRN                 // Save screen to file
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /* DEFAULT
  * ,-----,-----,-----,-----,-----,-----,-----,-----,-----,-----,-----,-----,-----,----------,-----.
  * | ESC |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  +  |  BackSp  |  ~  |
  * |-----'--,--'--,--'--,--'--,--'--,--'--,--'--,--'--,--'--,--'--,--'--,--'--,--'--,-------+-----|
  * |   TAB  |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  {  |  }  |   \   | DEL |
  * |--------'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-------+-----|
  * | CTRL/CAPS|  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |   RETURN  | PGUP|
  * |----------'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-----,-----+-----|
  * |   SHIFT    |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  <  |  >  |  ?  |  SHIFT  |  UP | PGDN|
  * |------,-----',----'-,---'-----'-----'-----'-----'-----'---,-'---,-'---,-'---,-----'-----+-----|
  * | CTRL |  ALT | LGUI |             SPACE                   | ALT | OSL | CTRL| LEFT| DOWN|RIGHT|
  * '------'------'------'-------------------------------------'-----'-----'-----'-----'-----'-----'
 */
#define CTRL_CAPS   LCTL_T(KC_CAPS)

  [_QWERTY] = LAYOUT_65_ansi(
    KC_ESC,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,  KC_EQL,  KC_BSPC,   KC_GRV,  \
    KC_TAB,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,  KC_RBRC, KC_BSLS, KC_DEL,  \
    CTRL_CAPS,    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, KC_QUOT,     KC_ENT,     KC_PGUP, \
    KC_LSFT,        KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH,   KC_RSFT,   KC_UP,   KC_PGDN, \
    KC_LCTL,  KC_LALT,  KC_LGUI,                    KC_SPC,                   KC_RALT,  OSL(1),  KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
   ),

 /* FUNCTION LAYER
  * ,-----,-----,-----,-----,-----,-----,-----,-----,-----,-----,-----,-----,-----,----------,-----.
  * |     |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |   DEL    |TO(2)|
  * |-----'--,--'--,--'--,--'--,--'--,--'--,--'--,--'--,--'--,--'--,--'--,--'--,--'--,-------+-----|
  * |        |     |     |     |     |     |     |     |     |     | PLAY|     |     |       |     |
  * |--------'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-------+-----|
  * |          |     |SVSRN|     |     |     |     |     |     |     |     |     |           |     |
  * |----------'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-----,-----+-----|
  * |            |     |     |CPSRN|     |     |     | MUTE|     |     |     |         | VOL+|     |
  * |------,-----',----'-,---'-----'-----'-----'-----'-----'---,-'---,-'---,-'---,-----'-----+-----|
  * |      |      |      |                                     |     |     |     | PREV| VOL-| MEXT|
  * '------'------'------'-------------------------------------'-----'-----'-----'-----'-----'-----'
 */

  [_FUNC] = LAYOUT_65_ansi(
    KC_TRNS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,    KC_DEL,   TO(2), \
    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, \
    KC_TRNS,      KC_TRNS, SAV_SRN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,     KC_TRNS, \
    KC_TRNS,        KC_TRNS, KC_TRNS, CP_SRN, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_VOLU,
    KC_TRNS,  KC_TRNS,  KC_TRNS,                        KC_TRNS,                         KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_VOLD, KC_MNXT
    ),



 /* RGB LAYER
  * ,-----,-----,-----,-----,-----,-----,-----,-----,-----,-----,-----,-----,-----,----------,-----.
  * |     |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |   DEL    |TO(0)|
  * |-----'--,--'--,--'--,--'--,--'--,--'--,--'--,--'--,--'--,--'--,--'--,--'--,--'--,-------+-----|
  * |        |     |     | SPD+|     |     |     |     |     |     |     |     |     |       |     |
  * |--------'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-------+-----|
  * |          |     | SAT+| SPD-|     |     | HUE+|     |     |     |     |     |           |     |
  * |----------'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-,---'-----,-----+-----|
  * |            |     | SAT-|     |     |     | HUE-|     |     |     |     |         | BRT+|RGBTG|
  * |------,-----',----'-,---'-----'-----'-----'-----'-----'---,-'---,-'---,-'---,-----'-----+-----|
  * |      |      |      |                                     |     |     |     | MOD+| BRT-| MOD-|
  * '------'------'------'-------------------------------------'-----'-----'-----'-----'-----'-----'
 */

  [_RGB] = LAYOUT_65_ansi(
    KC_TRNS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,    KC_DEL,   TO(0), \
    KC_TRNS,    KC_TRNS, KC_TRNS, RGB_SPI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, \
    KC_TRNS,      KC_TRNS, RGB_SAI, RGB_SPD, KC_TRNS, KC_TRNS, RGB_HUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,     KC_TRNS, \
    KC_TRNS,        KC_TRNS, RGB_SAD, KC_TRNS, KC_TRNS, KC_TRNS, RGB_HUD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    RGB_VAI, RGB_TOG, \
    KC_TRNS,  KC_TRNS,  KC_TRNS,                        KC_TRNS,                         KC_TRNS, KC_TRNS, KC_TRNS, RGB_MOD, RGB_VAD, RGB_RMOD
    )
};

int rgb_current_mode;
HSV current_hsv;

void matrix_init_user(void) {
    #ifdef RGB_MATRIX_ENABLE
        //  rgb_matrix_config.raw = eeprom_read_dword(EECONFIG_RGB_MATRIX);
        rgb_current_mode = rgb_matrix_config.mode;
        current_hsv = rgb_matrix_config.hsv;
    #endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
      switch (keycode) {
            case RGB_MOD:
            case RGB_RMOD:
            case RGB_HUI:
            case RGB_HUD:
            case RGB_SAI:
            case RGB_SAD:
            case RGB_VAI:
            case RGB_VAD:
                if (record->event.pressed) {}
                else {
                    rgb_current_mode = rgb_matrix_config.mode;
                    current_hsv = rgb_matrix_config.hsv;
                }
                return true;
            case CP_SRN:
                if (record->event.pressed) {
                    SEND_STRING(SS_LGUI(SS_LCTRL(SS_LSFT("4"))));
                }
                return false;
            case SAV_SRN:
                if (record->event.pressed) {
                    SEND_STRING(SS_LGUI(SS_LSFT("4")));
                }
                return false;
      }
      return true;
}

void rgb_matrix_layer_helper (uint8_t hue, uint8_t sat, uint8_t val) {
    HSV hsv = {hue, sat, val};
    RGB rgb = hsv_to_rgb(hsv);
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        // if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) { Only changes the modifier key colors
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
}

int last_layer_state;

void rgb_matrix_indicators_user(void) {
    if (!g_suspend_state) {
        if (IS_LED_ON(host_keyboard_leds(), USB_LED_CAPS_LOCK)) {
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_layer_helper(HSV_MAGENTA);
            rgb_matrix_set_color(8, 0xFF, 0xFF, 0xFF);
        } else {
            switch(biton32(layer_state)) {
                case _QWERTY:
                    // Default layer will use whatever is in EEPROM
                    rgb_matrix_mode_noeeprom(rgb_current_mode);
                    break;
                case _FUNC:
                    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
                    rgb_matrix_layer_helper(HSV_CYAN);
                    break;
                case _RGB: // RGB mod layer
                    if (last_layer_state != 2) {
                        // Set layer to default layer's profile to allow for modification
                        rgb_matrix_mode_noeeprom(rgb_current_mode);
                    }
                    break;
            }
        }

        last_layer_state = biton32(layer_state);
    }
}
