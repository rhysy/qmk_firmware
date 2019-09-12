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
  TD_SHIFT_CAPS,
  TD_F1_TAB
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  // Tap once for Dash, twice for Equals
  [TD_GRV_EQUALS]  = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_PEQL),
  // Tap once for Shift, twice for Caps Lock
  [TD_SHIFT_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
  // Tap once for F1, twice for Tab
  [TD_F1_TAB]  = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_TAB)
};

extern uint8_t is_master;

enum custom_keycodes {
	BACK = SAFE_RANGE,
	FORWARD,
	CP_SRN, // Copy screen to clipboard
    SAV_SRN // Save screen to file
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
#define SFT_CAPS   TD(TD_SHIFT_CAPS)
#define F_CMD      LGUI_T(KC_F)
#define J_CMD      RGUI_T(KC_J)
#define D_ALT      LALT_T(KC_D)
#define K_ALT      RALT_T(KC_K)

 [_QWERTY] = LAYOUT(
	KC_ESC,   KC_1,   KC_2,   KC_3,   KC_4,    KC_5,                  		KC_6,   KC_7,   KC_8,    KC_9,   KC_0,    TD(TD_GRV_EQUALS), \
	KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,    KC_T, 						KC_Y, 	KC_U, 	KC_I, 	 KC_O, 	 KC_P, 	  KC_MINS, \
	KC_LCTL,  KC_A,   KC_S,   D_ALT,  F_CMD,   KC_G, 						KC_H, 	J_CMD, 	K_ALT, 	 KC_L, 	 KC_SCLN, KC_QUOT, \
    SFT_CAPS, KC_Z,   KC_X,   KC_C,   KC_V,    KC_B,   KC_LBRC,  KC_RBRC, 	KC_N, 	KC_M, 	KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, \
   						KC_LALT, KC_LGUI, TT(1), KC_ENT, 			KC_SPC, KC_BSPC, TT(2), KC_BSLS \
 ),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |F1|TAB|  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | PREV | NEXT |VOL UP| CUT  | COPY |-------.    ,-------|   =  |PG UP |  UP  |PG DWN|   +  |   -  |
 * |------+------+------+------+------+------| BACK  |    |FORWARD|------+------+------+------+------+------|
 * |      | PLAY | MUTE |VOL DN|PASTE |PASTE |-------|    |-------|   .  | LEFT | DOWN |RIGHT |   *  |   /  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /Enter  /       \Space \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
#define VOLUP_ALT    LALT_T(KC__VOLUP)
#define CUT_CMD      LGUI_T(KC_CUT)
#define PGUP_CMD     RGUI_T(KC_PGUP)
#define UP_ALT       RALT_T(KC_UP)
#define F1_TAB       TD(TD_F1_TAB)

 [_LOWER] = LAYOUT(
	KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  	   KC_TRNS,   KC_TRNS, 						 KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS, \
	F1_TAB,    KC_F2, 	  KC_F3, 	 KC_F4, 	   KC_F5, 	  KC_F6, 						 KC_F7, 	KC_F8, 	   KC_F9, 	 KC_F10,    KC_F11,    KC_F12, \
	KC_TRNS,   KC_MPRV,   KC_MNXT,   VOLUP_ALT,    CUT_CMD,   KC_COPY, 						 KC_PEQL,   PGUP_CMD,  UP_ALT, 	 KC_PGDN,   KC_PPLS,   KC_PMNS, \
	KC_TRNS,   KC_MPLY,   KC__MUTE,  KC__VOLDOWN,  KC_PSTE,   KC_PSTE,   BACK,     FORWARD,  KC_PDOT,   KC_LEFT,   KC_DOWN,  KC_RGHT,   KC_PAST,   KC_PSLS, \
							    KC_TRNS,    KC_TRNS,  	KC_TRNS,   KC_ENT, 			     KC_SPC,   KC_TRNS,   KC_TRNS,   KC_UNDO \
 ),
 /* RAISE
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * | N/A  | N/A  | N/A  |SV SRN|CP SRN | N/A |                    | N/A  | N/A  | N/A  | N/A  | N/A  | N/A  |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * | N/A  | N/A  | N/A  | N/A  | N/A  | N/A  |                    | N/A  | N/A  | N/A  | N/A  | N/A  | N/A  |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * | BL+  |BL TGL|BL ON |BL BTH| N/A  | N/A  |-------.    ,-------| N/A  | N/A  |RGB TG|HUE + |SAT + |BRT + |
  * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
  * | BL-  |BL CYL|BL OFF| N/A  | N/A  | N/A  |-------|    |-------| N/A  | N/A  |RGB MD|HUE - |SAT - |BRT  -|
  * `-----------------------------------------/       /     \      \-----------------------------------------'
  *                   |      |      |      | /       /       \      \  | DEL  |      |      |
  *                   |      |      |      |/       /         \      \ |      |      |      |
  *                   `----------------------------'           '------''--------------------'
  */
 [_RAISE] = LAYOUT(
    KC_NO,  KC_NO,   KC_NO,  SAV_SRN,  CP_SRN, KC_NO,                  KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,    KC_NO, \
    KC_NO,  KC_NO,   KC_NO,  KC_NO,    KC_NO,  KC_NO,                  KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,    KC_NO, \
    BL_INC, BL_TOGG, BL_ON,  BL_BRTG,  KC_NO,  KC_NO,                  KC_NO,  KC_NO,  RGB_TOG, RGB_HUI, RGB_SAI,  RGB_VAI, \
    BL_DEC, BL_STEP, BL_OFF, KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  RGB_MOD, RGB_HUD, RGB_SAD,  RGB_VAD, \
                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_DEL, KC_TRNS, KC_TRNS
 )
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
const char *read_host_led_state(void);

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
    matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
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
	case KC_UNDO:
		if (record->event.pressed) {
			SEND_STRING(SS_LGUI("z"));
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
    case RGB_MOD:
        if (record->event.pressed) {
        } else {
            // Save the LED mode change value for restoration later
            RGB_current_mode = rgblight_config.mode;
        }
        return true;
  }
  return true;
}

// Change LED colors based on layer
layer_state_t layer_state_set_user(layer_state_t state) {
	if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
		rgblight_setrgb(RGB_PINK);
	}

    switch (biton32(state)) {
        case _RAISE:
            rgblight_mode(1);
            rgblight_setrgb(RGB_ORANGE);
            break;
        case _LOWER:
            rgblight_mode(1);
            rgblight_setrgb (RGB_MAGENTA);
            break;
        case _QWERTY:
            rgblight_mode(RGB_current_mode);
            rgblight_sethsv(rgblight_config.hue, rgblight_config.sat, rgblight_config.val);
            break;
        default: //  for any other layers, or the default layer
            rgblight_setrgb(0x00,  0xFF, 0xFF);
            break;
    }
  return state;
}
