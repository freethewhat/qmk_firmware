static tap td_dlr_state = {
    .is_press_action = true,
    .state           = 0
};

void td_dlr_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_dlr_state.state = current_dance(state);
    switch (td_dlr_state.state) {
        case SINGLE_TAP: register_code16(KC_DOLLAR); break;
        case SINGLE_HOLD: register_code16(KC_LSFT); break;
        case DOUBLE_TAP: register_code16(KC_DOLLAR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DOLLAR); register_code16(KC_DOLLAR);
    }
};

void td_dlr_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_dlr_state.state) {
        case SINGLE_TAP: unregister_code16(KC_DOLLAR); break;
        case SINGLE_HOLD: unregister_code16(KC_LSFT); break;
        case DOUBLE_TAP: unregister_code16(KC_DOLLAR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOLLAR); break;
    }
    td_dlr_state.state = 0;
};