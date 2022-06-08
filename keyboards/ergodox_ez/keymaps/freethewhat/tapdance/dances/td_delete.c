static tap td_del_state = {
    .is_press_action = true,
    .state           = 0
};

void td_del_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_del_state.state = current_dance(state);
    switch (td_del_state.state) {
        case SINGLE_TAP: register_code16(KC_DEL); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_DEL)); break;
        case DOUBLE_TAP: register_code16(KC_DEL); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DEL); register_code16(KC_MEDIA_PLAY_PAUSE);
    }
};

void td_del_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_del_state.state) {
        case SINGLE_TAP: unregister_code16(KC_DEL); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_DEL)); break;
        case DOUBLE_TAP: unregister_code16(KC_DEL); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DEL); break;
    }
    td_del_state.state = 0;
};