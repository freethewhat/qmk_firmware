static tap td_ampr_state = {
    .is_press_action = true,
    .state           = 0
};

void td_ampr_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_ampr_state.state = current_dance(state);
    switch (td_ampr_state.state) {
        case SINGLE_TAP: register_code16(KC_AMPR); break;
        case SINGLE_HOLD: register_code16(KC_LSFT); break;
        case DOUBLE_TAP: register_code16(KC_AMPR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_AMPR); register_code16(KC_AMPR);
    }
};

void td_ampr_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_ampr_state.state) {
        case SINGLE_TAP: unregister_code16(KC_AMPR); break;
        case SINGLE_HOLD: unregister_code16(KC_LSFT); break;
        case DOUBLE_TAP: unregister_code16(KC_AMPR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_AMPR); break;
    }
    td_ampr_state.state = 0;
};