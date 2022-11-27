#include "swapper.h"

void update_shiftable_swapper(
    bool *active,
    uint16_t cmdish,
    uint16_t tabish,
    uint16_t trigger,
    uint16_t shifted_trigger,
    uint16_t keycode,
    keyrecord_t *record
) {
    if (keycode == trigger || keycode == shifted_trigger) {
        if (record->event.pressed) {
            if (!*active) {
                *active = true;
                register_code(cmdish);
            }
            if (keycode == shifted_trigger) {
                tap_code16(S(tabish));
            } else {
                tap_code(tabish);
            }
        }
    } else if (*active) {
        // cmdish is unregistered once some other key is pressed or released
        // NOTE: there is a bug depending on the order of these if you do not release this code before calling another swapper
        // Both cmdish codes will be active in that case
        unregister_code(cmdish);
        *active = false;
    }
}

