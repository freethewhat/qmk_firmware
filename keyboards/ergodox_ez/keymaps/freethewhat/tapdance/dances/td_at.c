static tap td_at_state = {
    .is_press_action = true,
    .state           = 0
};

void td_at_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_at_state.state = current_dance(state);
    switch (td_at_state.state) {
        case SINGLE_TAP: register_code16(KC_AT); break;
        case SINGLE_HOLD: register_code16(KC_LWIN); break;
        case DOUBLE_TAP: register_code16(KC_AT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_AT); register_code16(KC_AT);
    }
};

void td_at_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_at_state.state) {
        case SINGLE_TAP: unregister_code16(KC_AT); break;
        case SINGLE_HOLD: unregister_code16(KC_LWIN); break;
        case DOUBLE_TAP: unregister_code16(KC_AT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_AT); break;
    }
    td_at_state.state = 0;
};