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

#include "keycodes.h"
#include "features/layer_lock.h"
#include "features/oneshot.h"
#include "features/swapper.h"
#include "features/repeat_key.h"

#define LT_SPC LT(NAV, KC_SPC)
#define LT_TAB LT(NAV, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       LT(ADJUST,KC_TAB),    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MT(MOD_LCTL,KC_ESC),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  REPEAT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, MO(NAV),  LT_SPC,     KC_LSFT, MO(SYMBOL), TG(NUMPAD)
                                      //`--------------------------'  `--------------------------'

  ),

  [COLEMAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       LT(ADJUST,KC_TAB),   KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                         KC_J,    KC_L,    KC_U,    KC_Y,   KC_SCLN,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MT(MOD_LCTL,KC_ESC),    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                         KC_H,    KC_N,    KC_E,    KC_I, KC_O, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  _______,     _______, _______, TG(NUMPAD)
                                      //`--------------------------'  `--------------------------'
  ),

  [GAME] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,  _______,    _______,    _______,    _______,    _______,                         _______,    _______,    _______,    _______,   _______,  _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, _______,    _______,    _______,    _______,    _______,                         _______,    _______,    _______,    _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, _______,    _______,    _______,    _______,    _______,                         _______,    _______, _______,  _______, _______,  _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, MO(NAV),  _______,     _______, _______, MO(ADJUST)
                                      //`--------------------------'  `--------------------------'

  ),

  [NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ESC, OS_CTRL, OS_GUI, OS_ALT, OS_SHFT, CW_TOGG,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, KC_ENT, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, SW_WIN, SW_SWIN, SW_SCTAB, SW_CTAB, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_DEL, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     KC_ENT, _______, LLOCK
                                      //`--------------------------'  `--------------------------'
  ),

  [GAME_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______,    _______,    _______,                         _______,    _______,    _______,    _______,   _______,  _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, _______,                          _______,    _______,    _______,    _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_F1, KC_F2, KC_F3,    KC_F4,    KC_F5,                         _______,    _______, _______,  _______, _______,  _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, _______,  _______,     _______, _______, MO(ADJUST)
                                      //`--------------------------'  `--------------------------'
  ),

  [SYMBOL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_GRV, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,                      KC_MINS,  OS_SHFT, OS_ALT, OS_GUI, OS_CTRL,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_TILD, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,                      KC_UNDS, XXXXXXX, KC_LT, KC_GT, KC_QUES, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  KC_SPC,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, OS_CTRL, OS_GUI, OS_ALT, OS_SHFT, XXXXXXX,                      KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_MS_BTN1, KC_MS_BTN2, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______,  _______,     XXXXXXX, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),


  [ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_MPRV, KC_MPLY, KC_MUTE, KC_MNXT, QK_BOOTLOADER,                XXXXXXX, KC_F9, KC_F10, KC_F11, KC_F12, TG(GAME),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_VOLU, RGB_SPI,                      DF(COLEMAK), KC_F5, KC_F6, KC_F7, KC_F8, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_VOLD, RGB_SPD,                      DF(QWERTY), KC_F1, KC_F2, KC_F3, KC_F4, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     KC_RALT, KC_RGUI, KC_RCTL
                                      //`--------------------------'  `--------------------------'
  ),

  [NUMPAD] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_PAST, KC_P7, KC_P8, KC_P9, KC_PSLS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_PEQL, KC_P4, KC_P5, KC_P6, KC_PMNS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ENT, KC_PDOT, KC_P1, KC_P2, KC_P3, KC_PPLS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_BSPC, KC_P0,  _______,     XXXXXXX, XXXXXXX, TG(NUMPAD)
                                      //`--------------------------'  `--------------------------'
  )
};

enum combos {
    CB_MINS,
    CB_UNDS,
    CB_ENT,
    CB_TAB,
    CB_REVREPEAT,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM mins_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM unds_combo[] = {KC_L, KC_P, COMBO_END};
const uint16_t PROGMEM ent_combo[] = {KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM revrepeat_combo[] = {KC_SLSH, REPEAT, COMBO_END};

combo_t key_combos[] = {
    [CB_MINS] = COMBO(mins_combo, KC_MINS),
    [CB_UNDS] = COMBO(unds_combo, KC_UNDS),
    [CB_ENT] = COMBO(ent_combo, KC_ENT),
    [CB_TAB] = COMBO(tab_combo, KC_TAB),
    [CB_REVREPEAT] = COMBO(revrepeat_combo, REVREPEAT),
};

#ifdef RGBLIGHT_LAYERS
#define _GREEN          95, 150, 255
#define _GOLD           36, 150, 255
#define _CORAL          11, 176, 255
const rgblight_segment_t PROGMEM rgb_numpad_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 4, HSV_CYAN},
    {15, 6, HSV_CYAN},
    {21, 1, 170, 220, 255},
    {26, 1, 10, 255, 255},
    {33, 8, HSV_BLACK},
    {41, 1, HSV_CYAN},
    {42, 12, HSV_BLACK}
);
const rgblight_segment_t PROGMEM rgb_nav_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {9, 2, _GOLD},
    {17, 2, _GOLD},
    {23, 1, _GOLD},
    {36, 2, _GOLD},
    {44, 2, _GOLD},
    {50, 1, _GOLD},
    {13, 1, _GOLD},
    {35, 1, HSV_YELLOW},
    {38, 1, HSV_YELLOW},
    {43, 1, HSV_YELLOW},
    {46, 1, HSV_YELLOW}
);
const rgblight_segment_t PROGMEM rgb_sym_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {9, 2, _CORAL},
    {17, 2, _CORAL},
    {23, 1, _CORAL},
    {36, 2, _CORAL},
    {40, 1, _CORAL},
    {44, 2, _CORAL},
    {50, 1, _CORAL}
);
const rgblight_segment_t PROGMEM rgb_adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 3, _GREEN},
    {17, 2, _GREEN},
    {23, 1, _GREEN},
    {34, 3, _GREEN}
);
const rgblight_segment_t PROGMEM rgb_game_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 1, HSV_RED},
    {13, 2, HSV_RED},
    {24, 3, HSV_RED},
    {33, 1, HSV_RED},
    {40, 2, HSV_RED},
    {51, 3, HSV_RED}
);
const rgblight_segment_t PROGMEM rgb_caps_word[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 54, HSV_CHARTREUSE}
);
const rgblight_segment_t PROGMEM rgb_osm_ctl[] = RGBLIGHT_LAYER_SEGMENTS(
    {22, 1, HSV_WHITE},
    {49, 1, HSV_WHITE}
);
const rgblight_segment_t PROGMEM rgb_osm_gui[] = RGBLIGHT_LAYER_SEGMENTS(
    {19, 1, HSV_WHITE},
    {46, 1, HSV_WHITE}
);
const rgblight_segment_t PROGMEM rgb_osm_alt[] = RGBLIGHT_LAYER_SEGMENTS(
    {16, 1, HSV_WHITE},
    {43, 1, HSV_WHITE}
);
const rgblight_segment_t PROGMEM rgb_osm_sft[] = RGBLIGHT_LAYER_SEGMENTS(
    {11, 1, HSV_WHITE},
    {38, 1, HSV_WHITE}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_numpad_layer,
    rgb_nav_layer,
    rgb_sym_layer,
    rgb_adjust_layer,
    rgb_game_layer,
    rgb_caps_word,
    rgb_osm_ctl,
    rgb_osm_gui,
    rgb_osm_alt,
    rgb_osm_sft
);
enum lighting_layers {
    L_NUMPAD = 0,
    L_NAV,
    L_SYM,
    L_ADJUST,
    L_GAME,
    L_CAPSW,
    L_OSMCTL,
    L_OSMGUI,
    L_OSMALT,
    L_OSMSFT
};
#endif

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

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case MO(SYMBOL):
        case MO(NAV):
        case LT_TAB:
        case LT_SPC:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case KC_LSFT:
        case OS_SHFT:
        case OS_ALT:
        case OS_CTRL:
        case OS_GUI:
        case MO(SYMBOL):
        case MO(NAV):
        case LT_TAB:
        case LT_SPC:
            return true;
        default:
            return false;
    }
}

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    bool shifted = (mods & MOD_MASK_SHIFT);
    switch (keycode) {
        case KC_ENT:
            return shifted ? KC_ENT : S(KC_ENT);
        case KC_TAB:
            return shifted ? KC_TAB : S(KC_TAB);
        case KC_N:
            return shifted ? KC_N : S(KC_N);
        case KC_ASTR:
            return KC_HASH;
        case KC_HASH:
            return KC_ASTR;
    }

    return KC_TRNS;
}

bool sw_win_active = false;
bool sw_ctab_active = false;
oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_gui_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
    if (!process_repeat_key_with_alt(keycode, record, REPEAT, REVREPEAT)) { return false; }

    update_shiftable_swapper(
        &sw_win_active, KC_LALT, KC_TAB, SW_WIN, SW_SWIN,
        keycode, record
    );
    update_shiftable_swapper(
        &sw_ctab_active, KC_LCTL, KC_TAB, SW_CTAB, SW_SCTAB,
        keycode, record
    );
    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_gui_state, KC_LGUI, OS_GUI,
        keycode, record
    );

    return true;
}

#ifdef RGBLIGHT_WAKEUP_ANIMATION
#include <transactions.h>
#define RGBLIGHT_WAKEUP_ANIMATION_INTERVAL 10
struct Wakeup_animation {
    bool running;
    bool sync_follower;
    uint8_t last_mode;
    uint8_t last_val;
    uint8_t pos;
    uint8_t end;
    uint16_t last_timer;
} wakeup_anim;
struct _anim_sync_info {
    uint8_t start_time;
} anim_sync_info;

void rgblight_wakeup_init(void) {
    wakeup_anim.running = true;
    wakeup_anim.last_mode = rgblight_get_mode();
    wakeup_anim.last_val = rgblight_get_val();
    wakeup_anim.pos = 0;
#ifdef RGBLED_SPLIT
    uint8_t num_split[2] = RGBLED_SPLIT;
    wakeup_anim.end = num_split[0];
    wakeup_anim.sync_follower = true;
#else
    wakeup_anim.end = RGBLED_NUM;
#endif
    wakeup_anim.last_timer = sync_timer_read();

    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);

    for (uint8_t i = 0; i < RGBLED_NUM; i++) {
        sethsv(HSV_OFF, (LED_TYPE *)&led[i]);
    }
    rgblight_set();
}

bool rgblight_wakeup_animation_need_close(void) {
#ifdef RGBLIGHT_SPLIT
    if (!is_keyboard_master()) {
        return false;
    }
#endif
    return true;
}

void rgblight_wakeup_animation(void) {
    if (sync_timer_elapsed(wakeup_anim.last_timer) > RGBLIGHT_WAKEUP_ANIMATION_INTERVAL) {
        sethsv(HSV_WHITE, (LED_TYPE *)&led[wakeup_anim.pos]);
    #ifdef RGBLED_SPLIT
        sethsv(HSV_WHITE, (LED_TYPE *)&led[wakeup_anim.end + wakeup_anim.pos]);
    #endif
        wakeup_anim.pos++;
        rgblight_set();

        if (wakeup_anim.pos == wakeup_anim.end) {
            wakeup_anim.running = false;
            if (rgblight_wakeup_animation_need_close()) {
                if (wakeup_anim.last_mode != RGBLIGHT_MODE_STATIC_LIGHT) {
                    rgblight_mode_noeeprom(wakeup_anim.last_mode);
                }
            }
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

void user_sync_anim_slave_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
    if (in_buflen == sizeof(anim_sync_info)) {
        memcpy(&anim_sync_info, in_data, in_buflen);
        wakeup_anim.running = true;
        wakeup_anim.last_timer = anim_sync_info.start_time;
        wakeup_anim.pos = 0;
    #ifdef RGBLED_SPLIT
        uint8_t num_split[2] = RGBLED_SPLIT;
        wakeup_anim.end = num_split[0];
    #else
        wakeup_anim.end = RGBLED_NUM;
    #endif
    }
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
#ifdef RGBLIGHT_WAKEUP_ANIMATION
    if (wakeup_anim.sync_follower) {
        anim_sync_info.start_time = wakeup_anim.last_timer;
        if (transaction_rpc_send(USER_SYNC_ANIM, sizeof anim_sync_info, &anim_sync_info)) {
            wakeup_anim.sync_follower = false;
        }
    }
#endif
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef RGBLIGHT_TIMEOUT
    if (record->event.pressed) refresh_rgb();
#endif
#ifdef RGBLIGHT_LAYERS
    rgblight_set_layer_state(L_OSMCTL, os_ctrl_state > os_up_unqueued);
    rgblight_set_layer_state(L_OSMGUI, os_gui_state > os_up_unqueued);
    rgblight_set_layer_state(L_OSMALT, os_alt_state > os_up_unqueued);
    rgblight_set_layer_state(L_OSMSFT, os_shft_state > os_up_unqueued);
#endif
}

void suspend_power_down_user(void) {
#ifdef RGBLIGHT_TIMEOUT
    rgblight_suspend();
#endif
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    if (layer_state_cmp(state, COLEMAK)) {
        rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 4);
    } else if (layer_state_cmp(state, QWERTY)) {
        rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_MOOD + 2);
    }

    return state;
}

void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_LAYERS
    rgblight_layers = rgb_layers;
#endif

#ifdef RGBLIGHT_WAKEUP_ANIMATION
    transaction_register_rpc(USER_SYNC_ANIM, user_sync_anim_slave_handler);
#endif

#ifdef RGBLIGHT_TIMEOUT
    refresh_rgb();
#endif
}

layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_LAYERS
    rgblight_set_layer_state(L_NUMPAD, layer_state_cmp(state, NUMPAD));
    rgblight_set_layer_state(L_NAV, layer_state_cmp(state, NAV));
    rgblight_set_layer_state(L_SYM, layer_state_cmp(state, SYMBOL));
    rgblight_set_layer_state(L_ADJUST, layer_state_cmp(state, ADJUST));
    rgblight_set_layer_state(L_GAME, layer_state_cmp(state, GAME));
#endif

    state = update_tri_layer_state(state, NAV, SYMBOL, MOUSE);
    state = update_tri_layer_state(state, GAME, NAV, GAME_NAV);

    // if (get_highest_layer(state) >= COLEMAK && is_combo_enabled()) {
    //     combo_disable();
    // } else if (!is_combo_enabled()) {
    //     combo_enable();
    // }

    return state;
}

void caps_word_set_user(bool active) {
#ifdef RGBLIGHT_LAYERS
    rgblight_set_layer_state(L_CAPSW, active);
#endif
}

#ifdef RGB_MATRIX_ENABLE
#endif
