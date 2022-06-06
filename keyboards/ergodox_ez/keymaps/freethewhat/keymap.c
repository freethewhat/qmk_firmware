#include QMK_KEYBOARD_H
#include "version.h"

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
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           KC_TRNS,                                 KC_TRNS, KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCOLON,      KC_TRNS,
  KC_TRNS, KC_A,           KC_R,           KC_S,           KC_T,           KC_G,                                                                           KC_M,           KC_N,           KC_E,           KC_I,           KC_O,           KC_TRNS,
  KC_TRNS, MT(MOD_LSFT, KC_Z),MT(MOD_LGUI, KC_X),MT(MOD_LALT, KC_C),MT(MOD_LCTL, KC_D),KC_V,           KC_TRNS,                                 KC_TRNS, KC_K,           MT(MOD_LCTL, KC_H),MT(MOD_LALT, KC_COMMA),MT(MOD_LGUI, KC_DOT),MT(MOD_LSFT, KC_SLASH),KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, DM_REC1, DM_PLY1,                                                                                                DM_PLY2,DM_REC2, KC_TRNS, KC_TRNS, KC_TRNS,
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
                                                                                    KC_LSHIFT,      KC_DEL,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
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
    KC_TRNS, KC_TRNS, RESET,          KC_TRNS, KC_TRNS, KC_TRNS,                                                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                                                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                                                    KC_TRNS, KC_TRNS,
                                                                                    KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    return true;
};

// Runs just one time when the keyboard initializes.
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
