#include QMK_KEYBOARD_H
#include "version.h"

enum custom_keycodes {
    MY_KC_RGB_COLOR1 = SAFE_RANGE,
    MY_KC_RGB_COLOR2,
    MY_KC_RGB_COLOR3,
    MY_KC_UMLAUT_A,
    MY_KC_UMLAUT_O,
    MY_KC_UMLAUT_U,
    MY_KC_SHARP_S
};

// Include the file that was generated from the key-map JSON file.
#include "ergodox_ez-shine-jobor.inc"

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
        case MY_KC_RGB_COLOR1:
            if (record->event.pressed) {
                rgblight_enable();
                rgblight_mode(1);
                rgblight_setrgb(RGB_PURPLE);
            }
            return false;
        case MY_KC_RGB_COLOR2:
            if (record->event.pressed) {
                rgblight_enable();
                rgblight_mode(1);
                rgblight_setrgb(RGB_CHARTREUSE);
            }
            return false;
        case MY_KC_RGB_COLOR3:
            if (record->event.pressed) {
                rgblight_enable();
                rgblight_mode(1);
                rgblight_setrgb(RGB_CORAL);
            }
            return false;
        case MY_KC_UMLAUT_A:
            if (record->event.pressed) {
                tap_compose_doublequote_key(KC_A);
            }
            return false;
        case MY_KC_UMLAUT_O:
            if (record->event.pressed) {
                tap_compose_doublequote_key(KC_O);
            }
            return false;
        case MY_KC_UMLAUT_U:
            if (record->event.pressed) {
                tap_compose_doublequote_key(KC_U);
            }
            return false;
        case MY_KC_SHARP_S:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_PAUSE)"ss");
            }
            return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#else
    rgblight_setrgb(RGB_OFF);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};
