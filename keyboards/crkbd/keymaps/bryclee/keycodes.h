#pragma once

enum crkbd_layers {
    QWERTY = 0,
    DVORAK,
    COLEMAK,
    GAME,
    NAV,
    GAME_NAV,
    SYMBOL,
    MOUSE,
    ADJUST,
    NUMPAD
};
enum custom_keycodes {
    SW_WIN = SAFE_RANGE,
    SW_SWIN,
    SW_CTAB,
    SW_SCTAB,
    OS_SHFT,
    OS_CTRL,
    OS_ALT,
    OS_GUI,
    LLOCK
};
