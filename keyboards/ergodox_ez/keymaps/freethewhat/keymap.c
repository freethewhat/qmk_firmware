#include QMK_KEYBOARD_H
#include "version.h"

#include "macros/macro_setup.c"
//#include "combos/caps_word.c"
#include "tapdance/td_codes.c"
#include "tapdance/td_setup.c"
#include "tapdance/dances/td_media.c"
#include "tapdance/dances/td_macro_1.c"
#include "tapdance/dances/td_macro_2.c"
#include "tapdance/dances/td_delete.c"
#include "tapdance/td_actions.c"

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    MDIA,  // media keys
    ARRO,
    MACR,
    FUNC,
};

enum custom_keycodes {
  #ifdef ORYX_CONFIGURATOR
    VRSN = EZ_SAFE_RANGE,
#else
    VRSN = SAFE_RANGE,
#endif
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_HUI,                                 RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_DEL, KC_Q, KC_W, KC_F, KC_P, KC_B, MACRO_COPY_DOWN,                                 KC_TRNS, KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCOLON,      KC_DEL,
  KC_BSPACE, MT(MOD_LCTL, KC_A),MT(MOD_LGUI, KC_R),MT(MOD_LALT, KC_S),MT(MOD_LSFT, KC_T), KC_G,                                                                          KC_M,MT(MOD_LSFT, KC_N),MT(MOD_LALT, KC_E),MT(MOD_LGUI, KC_I),MT(MOD_LCTL, KC_O),KC_BSPACE,
  CAPSWRD,     KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,   KC_TRNS,                                 KC_TRNS, KC_K,              KC_H,   KC_COMMA,   KC_DOT,   KC_SLASH,  KC_TRNS,
  TD(TD_F5), KC_F8, KC_F10, TD(TD_F12), TD(TD_MACRO_1),                                                                                                TD(TD_MACRO_2),DM_REC2, KC_TRNS, KC_TRNS, KC_TRNS,
                                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                    KC_TRNS, KC_TRNS,
                                    LT(SYMB,KC_SPACE), LT(FUNC,KC_BSPACE),KC_TRNS, KC_TRNS, LT(MACR, KC_TAB),   LT(ARRO,KC_ENTER)
),
[SYMB] = LAYOUT_ergodox_pretty(
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_GRAVE,       KC_TILD,        KC_COLN,        KC_UNDS,        KC_TRNS, KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_EQUAL,       KC_SCOLON,      KC_PIPE,        KC_DQUO,        KC_TRNS,
KC_TRNS, KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                                                        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_BSLASH,      KC_QUOTE,       KC_TRNS,
KC_TRNS, KC_LABK,        KC_LBRACKET,    KC_LPRN,        KC_LCBR,        KC_MINUS,       KC_TRNS,                                 KC_TRNS, KC_PLUS,        KC_RCBR,        KC_RPRN,        KC_RBRACKET,    KC_RABK,        KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                                                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                                                KC_TRNS, KC_TRNS,
                                                                                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[ARRO] = LAYOUT_ergodox_pretty(
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_ESCAPE,      KC_HOME,        KC_UP,          KC_END,         KC_PGUP,        KC_TRNS,                                 KC_TRNS, KC_KP_ASTERISK, KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_PLUS,     KC_TRNS,
    KC_TRNS, KC_LALT,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_PGDOWN,                                                                      KC_KP_SLASH,    KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_MINUS,    KC_TRNS,
    KC_TRNS, KC_LCTRL,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                 KC_TRNS, KC_KP_DOT,      KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_ENTER,    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                                                                 KC_KP_0,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                                                    KC_TRNS, KC_TRNS,
                                                                                    KC_LSHIFT,      TD(TD_DEL),    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[FUNC] = LAYOUT_ergodox_pretty(
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,          KC_F5,    KC_TRNS,                                 KC_TRNS, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_TRNS,
KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,           KC_F11,                                                                         KC_F12,    KC_7,           KC_8,           KC_9,           KC_0,           KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_5,           KC_TRNS,    KC_TRNS,                                 KC_TRNS, KC_PSCREEN,     KC_6,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                                                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                                                KC_TRNS, KC_TRNS,
                                                                                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[MACR] = LAYOUT_ergodox_pretty(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, RESET, KC_TRNS, KC_TRNS, KC_TRNS,                                            KC_TRNS, MACRO_NOTEPAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, MACRO_WT, MACRO_CODE, KC_TRNS, TD(TD_MEDIA), KC_TRNS, KC_TRNS,                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                 KC_TRNS, KC_TRNS,
                                                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
};

void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
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

void caps_word_set_user(bool active) {
    if (active) {
        ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
        // Do something when Caps Word activates.
    } else {
        ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
        // Do something when Caps Word deactivates.
    }
}