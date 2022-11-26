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

#include QMK_KEYBOARD_H

enum crkbd_layers {
    BASE = 0,
    QWERTY,
    GAME,
    NAV,
    SYMBOL,
    MOUSE,
    ADJUST,
    NUMPAD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       LT(ADJUST,KC_TAB),   KC_QUOT,    KC_COMM,    KC_DOT,    KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R,   KC_L,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MT(MOD_LCTL,KC_ESC),    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                         KC_D,    KC_H,    KC_T,    KC_N, KC_S, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,    KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M, KC_W,  KC_V, KC_Z,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, MO(NAV),  KC_SPC,     KC_LSFT, MO(SYMBOL), TG(NUMPAD)
                                      //`--------------------------'  `--------------------------'

  ),

  [QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       LT(ADJUST,KC_TAB),    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MT(MOD_LCTL,KC_ESC),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, MO(NAV),  KC_SPC,     KC_LSFT, MO(SYMBOL), TG(NUMPAD)
                                      //`--------------------------'  `--------------------------'

  ),

  [GAME] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    _______,    _______,    _______,    _______,    _______,                         _______,    _______,    _______,    _______,   _______,  _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    _______,    _______,    _______,    _______,    _______,                         _______,    _______,    _______,    _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    _______,    _______,    _______,    _______,    _______,                         _______,    _______, _______,  _______, _______,  _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, _______,  _______,     _______, _______, MO(ADJUST)
                                      //`--------------------------'  `--------------------------'

  ),

  [NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       A(KC_TAB),    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ESC, KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, C(S(KC_TAB)), C(KC_TAB), XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_DEL, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [SYMBOL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_GRV, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,                      XXXXXXX,  KC_LSFT, KC_LALT, KC_LGUI, KC_LCTL,  KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_TILD, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, XXXXXXX,                      KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_MS_BTN1, KC_MS_BTN2, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______,  XXXXXXX,     XXXXXXX, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),


  [ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_MPRV, KC_MPLY, KC_MUTE, KC_MNXT, RESET,                        TG(GAME), KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_VOLU, XXXXXXX,                      DF(BASE), KC_F5, KC_F6, KC_F7, KC_F8, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_VOLD, XXXXXXX,                      DF(QWERTY), KC_F1, KC_F2, KC_F3, KC_F4, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [NUMPAD] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_PAST, KC_P7, KC_P8, KC_P9, KC_PSLS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_PEQL, KC_P4, KC_P5, KC_P6, KC_PMNS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ENT, KC_PDOT, KC_P1, KC_P2, KC_P3, KC_PPLS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_BSPC, KC_P0,  _______,     XXXXXXX, XXXXXXX, TG(NUMPAD)
                                      //`--------------------------'  `--------------------------'
  )
};

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        // case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_MINS:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

#ifdef RGBLIGHT_WAKEUP_ANIMATION
#define RGBLIGHT_WAKEUP_ANIMATION_INTERVAL 25
struct Wakeup_animation {
    bool running;
    uint8_t start;
    uint8_t end;
    uint16_t last_timer;
} wakeup_anim;

void rgblight_wakeup_init(void) {
    wakeup_anim.running = true;
    wakeup_anim.last_timer = sync_timer_read();
    wakeup_anim.start = 10;
    wakeup_anim.end = 11;
    rgblight_set_effect_range(wakeup_anim.start, wakeup_anim.end);
}

void rgblight_wakeup_animation(void) {
    if (sync_timer_elapsed(wakeup_anim.last_timer) > RGBLIGHT_WAKEUP_ANIMATION_INTERVAL) {
        wakeup_anim.start = wakeup_anim.start == 0 ? 0 : wakeup_anim.start - 1;
        wakeup_anim.end = wakeup_anim.end == RGBLED_NUM ? RGBLED_NUM : wakeup_anim.end + 1;
        rgblight_set_effect_range(wakeup_anim.start, wakeup_anim.end - wakeup_anim. start);

        if (wakeup_anim.start == 0 && wakeup_anim.end == RGBLED_NUM) {
            wakeup_anim.running = false;
        } else {
            wakeup_anim.last_timer = sync_timer_read();
        }
    }
    // start animation from 10 for testing

    // check animation timer: if so, continue
    // change rgb effect to minus 1 to start, add 1 to end. Need to make sure min is 0, num leds is end - start, and end must be less than total num leds
    // if start is 0 and num rgbs == total num rgbs, clear animation state
    // reset last elapsed time
}
#endif

#ifdef RGBLIGHT_TIMEOUT
static uint16_t key_timer;
static void refresh_rgb(void);
static void check_rgb_timeout(void);
bool is_rgb_suspended = false;
bool pre_suspend_rgb_enabled;

void refresh_rgb() {
    key_timer = timer_read();
    if (is_rgb_suspended) {
        rgblight_wakeup();
    }
}

void check_rgb_timeout() {
    if (!is_rgb_suspended && timer_elapsed(key_timer) > RGBLIGHT_TIMEOUT) {
        rgblight_suspend();
    }
}

void rgblight_wakeup(void) {
    is_rgb_suspended = false;

    if (pre_suspend_rgb_enabled) {
        rgblight_enable_noeeprom();
    }

    rgblight_timer_enable();

    #ifdef RGBLIGHT_WAKEUP_ANIMATION
    rgblight_wakeup_init();
    #endif
}

void rgblight_suspend(void) {
    if (!is_rgb_suspended) {
        pre_suspend_rgb_enabled = rgblight_is_enabled();
        is_rgb_suspended = true;
        rgblight_timer_disable();
        rgblight_disable_noeeprom();
    }
}
#endif

void matrix_scan_user(void) {
    #ifdef RGBLIGHT_WAKEUP_ANIMATION
    if (wakeup_anim.running) {
        rgblight_wakeup_animation();
    }
    #endif
}

void housekeeping_task_user(void) {
#ifdef RGBLIGHT_TIMEOUT
    check_rgb_timeout();
#endif
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef RGBLIGHT_TIMEOUT
    if (record->event.pressed) refresh_rgb();
// #else
//     sethsv(HSV_RED, (LED_TYPE *)&led[50]);
//     sethsv(HSV_RED, (LED_TYPE *)&led[10]);
//     rgblight_set();
#endif
}

void suspend_power_down_user(void) {
#ifdef RGBLIGHT_TIMEOUT
    rgblight_suspend();
#endif
}

const rgblight_segment_t PROGMEM rgb_numpad_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 4, HSV_CYAN},
    {15, 6, HSV_CYAN},
    {21, 1, 170, 220, 255},
    {26, 1, 10, 255, 255},
    {41, 1, HSV_CYAN}
);
const rgblight_segment_t PROGMEM rgb_nav_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {9, 2, HSV_GOLD},
    {13, 1, HSV_GOLD},
    {17, 2, HSV_GOLD},
    {23, 1, HSV_GOLD},
    {36, 2, HSV_GOLD},
    {44, 2, HSV_GOLD},
    {50, 1, HSV_GOLD},
    {35, 1, HSV_YELLOW},
    {38, 1, HSV_YELLOW},
    {43, 1, HSV_YELLOW},
    {46, 1, HSV_YELLOW}
);
const rgblight_segment_t PROGMEM rgb_sym_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {9, 2, 12, 255, 255},
    {17, 2, 12, 255, 255},
    {23, 1, 12, 255, 255},
    {36, 2, 12, 255, 255},
    {40, 1, 12, 255, 255},
    {44, 2, 12, 255, 255},
    {50, 1, 12, 255, 255}
);
const rgblight_segment_t PROGMEM rgb_caps_word[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 54, HSV_CHARTREUSE}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_numpad_layer,
    rgb_nav_layer,
    rgb_sym_layer,
    rgb_caps_word
);

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;

#ifdef RGBLIGHT_TIMEOUT
    refresh_rgb();
#endif
#ifdef RGBLIGHT_WAKEUP_ANIMATION
    rgblight_wakeup_init();
#endif
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, NUMPAD));
    rgblight_set_layer_state(1, layer_state_cmp(state, NAV));
    rgblight_set_layer_state(2, layer_state_cmp(state, SYMBOL));

    state = update_tri_layer_state(state, NAV, SYMBOL, MOUSE);

    return state;
}

void caps_word_set_user(bool active) {
    rgblight_set_layer_state(3, active);
}
