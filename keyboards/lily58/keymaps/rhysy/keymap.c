#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif


extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

//Tap Dance Declarations
enum {
  TD_GRV_EQUALS = 0,
  TD_SHIFT_CAPS
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {  
  // Tap once for Dash, twice for Equals	
  [TD_GRV_EQUALS]  = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_PEQL),
  // Tap once for Shift, twice for Caps Lock
  [TD_SHIFT_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
// Other declarations would go here, separated by commas, if you have them
};

extern uint8_t is_master;

enum custom_keycodes {
	BACK = SAFE_RANGE,
	FORWARD
};

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | `|=  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Enter  /       \Space \  |BackSP|LOWER | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_QWERTY] = LAYOUT(
			KC_ESC,  KC_1,	KC_2,   KC_3,   KC_4,   KC_5,                  		KC_6,   KC_7,   KC_8,   KC_9,   KC_0,    TD(TD_GRV_EQUALS), \
		   	KC_TAB,  KC_Q, 	KC_W, 	KC_E, 	KC_R, 	KC_T, 						KC_Y, 	KC_U, 	KC_I, 	KC_O, 	KC_P, 	 KC_MINS, \
		   	KC_LCTL, KC_A, 	KC_S, 	KC_D, 	KC_F, 	KC_G, 						KC_H, 	KC_J, 	KC_K, 	KC_L, 	KC_SCLN, KC_QUOT, \
   TD(TD_SHIFT_CAPS),KC_Z, 	KC_X, 	KC_C, 	KC_V, 	KC_B,	KC_LBRC,KC_RBRC, 	KC_N, 	KC_M, 	KC_COMM,KC_DOT, KC_SLSH, KC_RSFT, \
   								KC_LALT, KC_LGUI, MO(1), KC_ENT, 			KC_SPC, KC_BSPC, TG(1), KC_BSLS \
 ),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | PREV | NEXT |VOL UP| CUT  | COPY |-------.    ,-------|PG UP |  UP  |PG DWN|   =  |   +  |   -  |
 * |------+------+------+------+------+------| BACK  |    |FORWARD|------+------+------+------+------+------|
 * |      | PLAY | MUTE |VOL DN|PASTE |PASTE |-------|    |-------| LEFT | DOWN |RIGHT |   .  |   *  |   /  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /Enter  /       \Space \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_LOWER] = LAYOUT(
	KC_TRNS,  KC_TRNS, 	KC_TRNS,  KC_TRNS,  	KC_TRNS,  KC_TRNS, 						KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, \
	KC_F1,    KC_F2, 	KC_F3, 	  KC_F4, 		KC_F5, 	  KC_F6, 						KC_F7, 	  KC_F8, 	KC_F9, 	  KC_F10, 	KC_F11,   KC_F12, \
	KC_TRNS,  KC_MPRV, 	KC_MNXT,  KC__VOLUP, 	KC_CUT,   KC_COPY, 						KC_PGUP,  KC_UP, 	KC_PGDN,  KC_PEQL,  KC_PPLS,  KC_PMNS, \
	KC_TRNS,  KC_MPLY, 	KC__MUTE, KC__VOLDOWN,	KC_PSTE,  KC_PSTE, 	 BACK,     FORWARD, KC_LEFT,  KC_DOWN, 	KC_RGHT,  KC_PDOT, 	KC_PAST,  KC_PSLS, \
							KC_TRNS,    KC_TRNS,  	KC_TRNS,  KC_ENT, 				KC_SPC, KC_TRNS, KC_TRNS, KC_UNDO \
 ),
	
 [_RAISE] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, BL_INC, BL_TOGG, BL_ON, BL_BRTG, KC_NO, KC_NO, KC_NO, KC_NO, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, BL_DEC, BL_STEP, BL_OFF, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};


int RGB_current_mode;

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

// Log keys
// Deactivate other layers when activating a new layer.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
	#ifdef SSD1306OLED
	    set_keylog(keycode, record);
	#endif
    // set_timelog();
  }

  switch (keycode) {
    case TG(1):
      if (record->event.pressed) {
        layer_off(_RAISE);        
      } 
      break;
    case TG(2):
      if (record->event.pressed) {
        layer_off(_LOWER);        
      } 
      break;
  	case KC_CUT:
  		if (record->event.pressed) {
  			SEND_STRING(SS_LGUI("x"));
  		}
  		return false;
	case KC_COPY:
		if (record->event.pressed) {
			SEND_STRING(SS_LGUI("c"));
		}
		return false;
	case KC_PSTE:
		if (record->event.pressed) {
			SEND_STRING(SS_LGUI("v"));
		}
		return false;
	case BACK:
		if (record->event.pressed) {
			SEND_STRING(SS_LGUI(SS_TAP(X_LEFT)));
		}
		return false;
	case FORWARD:
	    if (record->event.pressed) {
	    	SEND_STRING(SS_LGUI(SS_TAP(X_RIGHT)));
	    }
	    return false;
  }
  return true;
}

// Change LED colors based on layer
layer_state_t layer_state_set_user(layer_state_t state) {
	if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
		rgblight_setrgb(RGB_PINK);
	}

    switch (biton32(state)) {
    case _RAISE:
        rgblight_setrgb (RGB_ORANGE);
        break;
    case _LOWER:
        rgblight_setrgb (RGB_MAGENTA);
        break;
    case _QWERTY:
        rgblight_setrgb (RGB_TEAL);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0x00,  0xFF, 0xFF);
        break;
    }
  return state;
}
