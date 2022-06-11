static tap td_astr_state = {
    .is_press_action = true,
    .state           = 0
};

void td_astr_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_astr_state.state = current_dance(state);
    switch (td_astr_state.state) {
        case SINGLE_TAP: register_code16(KC_ASTERISK); break;
        case SINGLE_HOLD: register_code16(KC_LALT); break;
        case DOUBLE_TAP: register_code16(KC_ASTERISK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ASTERISK); register_code16(KC_ASTERISK);
    }
};

void td_astr_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_astr_state.state) {
        case SINGLE_TAP: unregister_code16(KC_ASTERISK); break;
        case SINGLE_HOLD: unregister_code16(KC_LALT); break;
        case DOUBLE_TAP: unregister_code16(KC_ASTERISK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ASTERISK); break;
    }
    td_astr_state.state = 0;
};