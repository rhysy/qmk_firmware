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

extern uint8_t is_master;

enum custom_keycodes {
	CP_SRN = SAFE_RANGE, // Copy screen to clipboard
    SAV_SRN              // Save screen to file
};

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |ESC|` |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LALT | LGUI |LOWER | /Enter  /       \Space \  |BackSP|RAISE |  =+  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
#define F_CMD      LGUI_T(KC_F)
#define J_CMD      RGUI_T(KC_J)
#define D_ALT      LALT_T(KC_D)
#define K_ALT      RALT_T(KC_K)
#define S_SFT      LSFT_T(KC_S)
#define L_SFT      RSFT_T(KC_L)
#define QUOT_CTRL  RCTL_T(KC_QUOT)
#define A_CTL      LCTL_T(KC_A)
#define SCLN_CTL   RCTL_T(KC_SCLN)

 [_QWERTY] = LAYOUT(
	KC_GESC,  KC_1,   KC_2,   KC_3,   KC_4,    KC_5,                  		KC_6,   KC_7,   KC_8,    KC_9,   KC_0,     KC_MINS, \
	KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,    KC_T, 						KC_Y, 	KC_U, 	KC_I, 	 KC_O, 	 KC_P, 	   KC_BSLS, \
	KC_LCTL,  A_CTL,  S_SFT,  D_ALT,  F_CMD,   KC_G, 						KC_H, 	J_CMD, 	K_ALT, 	 L_SFT,  SCLN_CTL, QUOT_CTRL, \
    KC_LSFT,  KC_Z,   KC_X,   KC_C,   KC_V,    KC_B,   KC_LBRC,  KC_RBRC, 	KC_N, 	KC_M, 	KC_COMM, KC_DOT, KC_SLSH,  KC_RSFT, \
   						KC_LALT, KC_LGUI, OSL(1), KC_ENT, 			KC_SPC, KC_BSPC, OSL(2), KC_EQL \
 ),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |F1|ESC|  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      | N/A  | N/A  |                    |      |PG UP |  UP  |PG DWN| HOME | N/A  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |SHIFT | ALT  | CMD  | MUTE |-------.    ,-------|  =+  | LEFT | DOWN |RIGHT | END  | CTRL |
 * |------+------+------+------+------+------|  N/A  |    |  DEL  |------+------+------+------+------+------|
 * |      |      | CUT  | COPY |PASTE |PASTE |-------|    |-------| N/A  | N/A  | N/A  | N/A  | N/A  | N/A  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      | UNDO |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
#define LEFT_CMD     GUI_T(KC_LEFT)
#define DOWN_ALT     ALT_T(KC_DOWN)
#define RIGHT_SFT    RSFT_T(KC_RGHT)
#define END_CTL      RCTL_T(KC_END)

 [_LOWER] = LAYOUT(
	KC_ESC,    KC_F2, 	  KC_F3, 	 KC_F4, 	KC_F5, 	   KC_F6, 						   KC_F7, 	  KC_F8, 	 KC_F9, 	 KC_F10,     KC_F11,    KC_F12, \
	KC_TRNS,   KC_TRNS,	  KC_TRNS, 	 KC_TRNS, 	KC_NO,     KC_NO,					       KC_TRNS,   KC_PGUP, 	 KC_UP, 	 KC_PGDN,    KC_HOME,   KC_NO, \
	KC_TRNS,   KC_TRNS,   KC_LSFT,   KC_LALT,   KC_LGUI,   KC__MUTE,					   KC_EQL,    LEFT_CMD,  DOWN_ALT,   RIGHT_SFT,  END_CTL,   KC_RCTL, \
	KC_TRNS,   KC_TRNS,   KC_CUT,    KC_COPY,   KC_PSTE,   KC_PSTE,     KC_NO,   KC_DEL,   KC_NO,     KC_NO,     KC_NO,      KC_NO,      KC_NO,     KC_NO, \
							    KC_TRNS,    KC_TRNS,  KC_TRNS,   KC_TRNS, 			 KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_UNDO \
 ),
 /* RAISE
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * |      | N/A  | N/A  |SV SRN|CP SRN| N/A  |                    | N/A  |  7   |  8   |  9   |  +   |BackSp|
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |      | PLAY | PREV | NEXT |VOL DN|VOL UP|                    | N/A  |  4   |  5   |  6   |  -   | N/A  |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |      |RGBMD+|HUE + |SAT + |BRT + | MUTE |-------.    ,-------| N/A  |  1   |  2   |  3   |  *   | N/A  |
  * |------+------+------+------+------+------|   (   |    |   )   |------+------+------+------+------+------|
  * |      |RGBMD-|HUE - |SAT - |BRT - |RGB TG|-------|    |-------| N/A  |  =   |  0   |  .   |  /   | N/A  |
  * `-----------------------------------------/       /     \      \-----------------------------------------'
  *                   |      |      |      | /       /       \      \  | DEL  |      |      |
  *                   |      |      |      |/       /         \      \ |      |      |      |
  *                   `----------------------------'           '------''--------------------'
  */
 [_RAISE] = LAYOUT(
    KC_TRNS,  KC_NO,    KC_NO,    SAV_SRN,  CP_SRN,      KC_NO,                      KC_NO,   KC_7,    KC_8,   KC_9,    KC_PPLS,   KC_BSPC, \
    KC_TRNS,  KC_MPLY,  KC_MPRV,  KC_MNXT,  KC__VOLDOWN, KC__VOLUP,                  KC_NO,   KC_4,    KC_5,   KC_6,    KC_PMNS,   KC_NO, \
    KC_TRNS,  RGB_MOD,  RGB_HUI,  RGB_SAI,  RGB_VAI,     KC__MUTE,                   KC_NO,   KC_1,    KC_2,   KC_3,    KC_PAST,   KC_NO, \
    KC_TRNS,  RGB_RMOD, RGB_HUD,  RGB_SAD,  RGB_VAD,     RGB_TOG, KC_LPRN,  KC_RPRN, KC_NO,   KC_PEQL, KC_0,   KC_PDOT, KC_PSLS,   KC_NO, \
                            KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,          KC_TRNS,  KC_DEL,  KC_TRNS, KC_TRNS
 )
};


int RGB_current_mode;

// EEPROM support for retaining RGB mode after power cycle. QMK bug workaround...
typedef union {
  uint32_t raw;
  struct {
    int     rgb_mode;
  };
} user_config_t;

user_config_t user_config;

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

void keyboard_post_init_user(void) {
  // Read the user config from EEPROM
  user_config.raw = eeconfig_read_user();
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_host_led_state(void);
const char *read_rgb_info(void);
//const char *read_keylog(void);
//const char *read_keylogs(void);

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
    matrix_write_ln(matrix, read_rgb_info());
    matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_keylog());
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

// Variable to signify a CTRL modifier was pressed.
static uint8_t ctl = 0;

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
    case TT(1):
      if (record->event.pressed) {
        // Only enable _DEFAULT and _LOWER at any given time
        layer_off(_RAISE);
      }
      break;
    case TT(2):
      if (record->event.pressed) {
        // Only enable _DEFAULT and _RAISE at any given time
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
    case RGB_RMOD:
        if (record->event.pressed) {
            // Allow for editing RGB mode from where we last left off rather than start at mode 1 again
            // since layer gets set to mode 1 for _RAISE where this key is available.
            rgblight_mode(user_config.rgb_mode);
        } else {
            // Save the LED mode change value for restoration later when returning to default layer
            user_config.rgb_mode = rgblight_config.mode;
            // Save RGB mode to eeprom so we can retain RGB mode after power cycle
            eeconfig_update_user(user_config.raw);
        }
        return true;
    case KC_GESC: {
        if( record -> event.pressed ) {
            const uint8_t mods = get_mods();
            if( ! mods ) return true;

            ctl = mods & ( MOD_BIT( KC_LCTL ) | MOD_BIT( KC_RCTL ) );

            if( ! ctl ) return true;

            // Send KC_GRAVE when CTRL + KC_GESC is pressed. Send the KC_GRAVE solo, then re-register CTRL after.
            unregister_mods( ctl );
            register_code( KC_GRAVE );
            register_mods( ctl );
            return false;
        }

            if( ! ctl ) return true;

            unregister_code( KC_GRAVE );
            ctl = 0;

            return false;
        }
  }
  return true;
}

void update_led(void) {
    if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
        rgblight_mode(15);
        rgblight_setrgb_red();
    } else {
        switch (biton32(layer_state)) {
            case _RAISE:
                rgblight_mode(1);
                rgblight_setrgb_green();
                //layer_off(_LOWER);
                break;
            case _LOWER:
                rgblight_mode(1);
                rgblight_setrgb_magenta();
                //layer_off(_RAISE);
                break;
            default: //  for any other layers, or the default layer
                rgblight_mode(user_config.rgb_mode);
                rgblight_sethsv(rgblight_config.hue, rgblight_config.sat, rgblight_config.val);
                break;
        }
    }
}

// Change LED colors based on layer
layer_state_t layer_state_set_user(layer_state_t state) {
    update_led();
    return state;
}

void led_set_user(uint8_t usb_led) {
    update_led();
}
