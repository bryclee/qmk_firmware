
#include QMK_KEYBOARD_H
#include "keycodes.h"

#ifdef RGB_MATRIX_ENABLE
static const uint8_t toprow_keys[] = { 9, 10, 17, 18, 23, 36, 37, 44, 45, 50 };

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (is_caps_word_on()) {
        for (uint8_t i = led_min; i <= led_max; i++) {
            rgb_matrix_set_color(i, RGB_CHARTREUSE);
        }
        return false;
    }

    if (IS_LAYER_ON(ADJUST)) {
        static const uint8_t greens[] = {10, 11, 12, 17, 18, 23, 34, 35, 36 };
        static const uint8_t greens_len = 9;
        uint8_t i;
        for (i = 0; i < greens_len; i++) {
            rgb_matrix_set_color(greens[i], RGB_GREEN);
        }
    }

    if (IS_LAYER_ON(NAV)) {
        for (uint8_t i = 0; i < 10; i++) {
            rgb_matrix_set_color(toprow_keys[i], 120, 100, 0);
        }
        rgb_matrix_set_color(13, 120, 100, 0);

        rgb_matrix_set_color(35, RGB_YELLOW);
        rgb_matrix_set_color(38, RGB_YELLOW);
        rgb_matrix_set_color(43, RGB_YELLOW);
        rgb_matrix_set_color(46, RGB_YELLOW);
    }

    if (IS_LAYER_ON(SYMBOL)) {
        for (uint8_t i = 0; i < 10; i++) {
            rgb_matrix_set_color(toprow_keys[i], 100, 10, 0);
        }
        rgb_matrix_set_color(40, 220, 30, 0);
    }

    if (IS_LAYER_ON(NUMPAD)) {
        static const uint8_t cyan_keys[] = { 10, 11, 12, 13, 15, 16, 17, 18, 19, 20, 41};
        static const uint8_t cyan_len = 11;
        for (uint8_t i = 0; i < cyan_len; i++) {
            rgb_matrix_set_color(cyan_keys[i], RGB_CYAN);
        }
        rgb_matrix_set_color(21, 170, 40, 220);
        rgb_matrix_set_color(26, 240, 40, 0);
    }

    if (IS_LAYER_ON(GAME)) {
        for (uint8_t i = led_min; i <= led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_MODIFIER) {
                rgb_matrix_set_color(i, RGB_CYAN);
            }
        }
    }
    return false;
}
#endif

