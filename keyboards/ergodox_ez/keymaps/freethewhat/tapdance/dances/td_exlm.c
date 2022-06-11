static tap td_exlm_state = {
    .is_press_action = true,
    .state           = 0
};

void td_exlm_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_exlm_state.state = current_dance(state);
    switch (td_exlm_state.state) {
        case SINGLE_TAP: register_code16(KC_EXLM); break;
        case SINGLE_HOLD: register_code16(KC_LCTL); break;
        case DOUBLE_TAP: register_code16(KC_EXLM); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_EXLM); register_code16(KC_EXLM);
    }
};

void td_exlm_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_exlm_state.state) {
        case SINGLE_TAP: unregister_code16(KC_EXLM); break;
        case SINGLE_HOLD: unregister_code16(KC_LCTL); break;
        case DOUBLE_TAP: unregister_code16(KC_EXLM); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_EXLM); break;
    }
    td_exlm_state.state = 0;
};