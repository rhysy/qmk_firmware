/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define SSD1306OLED

#define USE_SERIAL_PD2

//#define TAPPING_FORCE_HOLD // WARNING: Breaks TT (tap toggle) layer change key if uncommented

#undef TAPPING_TERM
#define TAPPING_TERM 200        // How long before a tap becomes a hold, if set above 500, a key tapped during the tapping term will turn it into a hold too
#define TAPPING_TOGGLE 2        // Number of times to tap to actuate secondary key function
#undef PERMISSIVE_HOLD          // Makes tap and hold keys trigger the hold if another key is pressed before releasing, even if it hasn't hit the TAPPING_TERM
#define IGNORE_MOD_TAP_INTERRUPT // Makes it possible to do rolling combos (zx) with keys that convert to other keys on hold, by enforcing the TAPPING_TERM for both keys.

//  ================== One Shot Modifier Feature ==================
#define ONESHOT_TAP_TOGGLE 2  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */

//  ================== COMBO Feature ==================
// * Hit multiple keys at once and produce a different effect. Ex. A && S == ESC
// * Must set COMBO_ENABLE = yes in rules.mk to activate.
#define COMBO_COUNT 1     // Number of combos defined
//#define COMBO_TERM 300    // Override TAPPING_TERM for COMBOS if defined

//  ================== Underglow ==================
#undef RGBLED_NUM
#define RGBLED_NUM 24
//#define RGBLIGHT_SPLIT            // Implicitly defined when RGBLED_SPLIT is defined
#define RGBLED_SPLIT { 12, 12 }
#define RGBLIGHT_LIMIT_VAL 255
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17
#define RGBLIGHT_SLEEP

// Animations
//#define RGBLIGHT_ANIMATIONS - enables all animations
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_STATIC_GRADIENT

#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_KNIGHT_LENGTH 3

#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_SNAKE_LENGTH 5
