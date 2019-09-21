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

//#define TAPPING_FORCE_HOLD // breaks TT key if uncommented

#undef TAPPING_TERM
#define TAPPING_TERM 300
#define TAPPING_TOGGLE 2 // Number of times to tap to actuate secondary key function
#define PERMISSIVE_HOLD  // This makes tap and hold keys (like Mod Tap) work better for fast typist, or for high TAPPING_TERM settings.
#define IGNORE_MOD_TAP_INTERRUPT

//#define COMBO_COUNT 1
//#define COMBO_TERM 300

// Underglow
#undef RGBLED_NUM
#define RGBLED_NUM 10
//#define RGBLIGHT_SPLIT
#define RGBLED_SPLIT { 5, 5 }
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
#define RGBLIGHT_EFFECT_KNIGHT_LENGTH 1

#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_SNAKE_LENGTH 5
