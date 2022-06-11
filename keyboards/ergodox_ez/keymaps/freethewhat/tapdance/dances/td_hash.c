static tap td_hash_state = {
    .is_press_action = true,
    .state           = 0
};

void td_hash_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_hash_state.state = current_dance(state);
    switch (td_hash_state.state) {
        case SINGLE_TAP: register_code16(KC_HASH); break;
        case SINGLE_HOLD: register_code16(KC_LALT); break;
        case DOUBLE_TAP: register_code16(KC_HASH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_HASH); register_code16(KC_HASH);
    }
};

void td_hash_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_hash_state.state) {
        case SINGLE_TAP: unregister_code16(KC_HASH); break;
        case SINGLE_HOLD: unregister_code16(KC_LALT); break;
        case DOUBLE_TAP: unregister_code16(KC_HASH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_HASH); break;
    }
    td_hash_state.state = 0;
};