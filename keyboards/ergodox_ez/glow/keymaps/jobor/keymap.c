#include QMK_KEYBOARD_H

#define process_record_user oryx_process_record_user
#include "oryx_source/keymap.c"
#undef process_record_user

void tap_compose_doublequote_key(uint16_t keycode) {
    const uint8_t orig_mods = get_mods();
    clear_mods();
    tap_code(KC_PAUSE);
    SEND_STRING("\"");
    set_mods(orig_mods);
    tap_code(keycode);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case KC_F24:
            if (record->event.pressed) {
                tap_compose_doublequote_key(KC_A);
            }
            return false;
        case KC_F23:
            if (record->event.pressed) {
                tap_compose_doublequote_key(KC_O);
            }
            return false;
        case KC_F22:
            if (record->event.pressed) {
                tap_compose_doublequote_key(KC_U);
            }
            return false;
        case KC_F21:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_PAUSE)"ss");
            }
            return false;
        }
    }
    return oryx_process_record_user(keycode, record);
}
