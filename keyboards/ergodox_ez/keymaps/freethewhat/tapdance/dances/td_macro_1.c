static tap td_macro_1_state = {
    .is_press_action = true,
    .state           = 0
};

void td_macro_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_macro_1_state.state = current_dance(state);
    keyrecord_t kr;
    kr.event.pressed = false;
    int action = DYN_REC_STOP;

    switch (td_macro_1_state.state) {
        case SINGLE_TAP: action = DYN_MACRO_PLAY1; break;
        case SINGLE_HOLD: action = DYN_REC_START1; break;
        case DOUBLE_TAP: action = DYN_MACRO_PLAY1; break;
        case DOUBLE_SINGLE_TAP: action = DYN_MACRO_PLAY1;
    }

    process_dynamic_macro( action, &kr );
};

void td_macro_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    td_macro_1_state.state = 0;
};