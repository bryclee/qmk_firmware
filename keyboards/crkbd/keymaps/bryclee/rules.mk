MOUSEKEY_ENABLE = yes     # Mouse keys
RGBLIGHT_ENABLE = yes    # Enable WS2812 RGB underlight.
RGB_MATRIX_ENABLE = no
VIA_ENABLE      = no    # Enable VIA
OLED_ENABLE     = no
LTO_ENABLE      = yes		# Link Time Optimization
CAPS_WORD_ENABLE = yes
SRC += features/swapper.c features/layer_lock.c rgb.c
