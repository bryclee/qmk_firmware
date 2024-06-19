/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#ifdef RGBLIGHT_ENABLE
/* #define RGBLIGHT_EFFECT_BREATHING */
/* #define RGBLIGHT_EFFECT_RAINBOW_MOOD */
/* #define RGBLIGHT_EFFECT_RAINBOW_SWIRL */
/* #define RGBLIGHT_EFFECT_SNAKE */
#    define RGBLIGHT_EFFECT_KNIGHT
/* #define RGBLIGHT_EFFECT_CHRISTMAS */
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
//  #define RGBLIGHT_EFFECT_RGB_TEST
/* #define RGBLIGHT_EFFECT_ALTERNATING */
/* #define RGBLIGHT_EFFECT_TWINKLE */
#    define RGBLIGHT_LIMIT_VAL 120
#    define RGBLIGHT_HUE_STEP 10
#    define RGBLIGHT_SAT_STEP 17
#    define RGBLIGHT_VAL_STEP 17
// #define RGBLIGHT_SLEEP
#    define RGBLIGHT_TIMEOUT 60000
#    define RGBLIGHT_LAYERS
#    define RGBLIGHT_MAX_LAYERS 10
// #define RGBLIGHT_WAKEUP_ANIMATION
// #define SPLIT_TRANSACTION_IDS_USER USER_SYNC_ANIM
#    define RGBLIGHT_DEFAULT_SAT 191
#    define RGBLIGHT_DEFAULT_HUE 80
#    define RGBLIGHT_DEFAULT_VAL 86

#    define RGBLIGHT_LAYERS_RETAIN_VAL
#endif

#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS \
        150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
#    define RGB_MATRIX_HUE_STEP 8
#    define RGB_MATRIX_SAT_STEP 8
#    define RGB_MATRIX_VAL_STEP 8
#    define RGB_MATRIX_SPD_STEP 10
#    define RGB_MATRIX_STARTUP_SPD 50
#    define RGB_DISABLE_TIMEOUT 60000
#    define SPLIT_LAYER_STATE_ENABLE

#    define RGB_MATRIX_KEYPRESSES
// #    define ENABLE_RGB_MATRIX_ALPHAS_MODS
// #    define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
// #    define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
// #    define ENABLE_RGB_MATRIX_BREATHING
#    define ENABLE_RGB_MATRIX_BAND_SAT
// #    define ENABLE_RGB_MATRIX_BAND_VAL
// #    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
// #    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
// #    define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
// #    define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#    define ENABLE_RGB_MATRIX_CYCLE_ALL
// #    define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
// #    define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#    define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
// #    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
// #    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
// #    define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
// #    define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
// #    define ENABLE_RGB_MATRIX_DUAL_BEACON
// #    define ENABLE_RGB_MATRIX_RAINBOW_BEACON
// #    define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
// #    define ENABLE_RGB_MATRIX_RAINDROPS
#    define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
// #    define ENABLE_RGB_MATRIX_HUE_BREATHING
// #    define ENABLE_RGB_MATRIX_HUE_PENDULUM
// #    define ENABLE_RGB_MATRIX_HUE_WAVE
#    define ENABLE_RGB_MATRIX_PIXEL_RAIN
// #    define ENABLE_RGB_MATRIX_PIXEL_FLOW
// #    define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#endif

// #define DYNAMIC_KEYMAP_LAYER_COUNT 8 // only needed for Via

#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#define BOTH_SHIFTS_TURNS_ON_CADYNAMIC_TAPPING_TERM_ENABLEPS_WORD

#define COMBO_ONLY_FROM_LAYER QWERTY
#define COMBO_TERM 30
// #define COMBO_TERM_PER_COMBO
/* #define PERMISSIVE_HOLD */
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
/* #define TAPPING_FORCE_HOLD */
#define TAPPING_TERM 165
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM 100
// #define ACHORDION_STREAK
