static tap td_macro_2_state = {
    .is_press_action = true,
    .state           = 0
};

void td_macro_2_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_macro_2_state.state = current_dance(state);
    keyrecord_t kr;
    kr.event.pressed = false;
    int action = DYN_REC_STOP;

    switch (td_macro_2_state.state) {
        case SINGLE_TAP: action = DYN_MACRO_PLAY2; break;
        case SINGLE_HOLD: action = DYN_REC_START2; break;
        case DOUBLE_TAP: action = DYN_MACRO_PLAY2; break;
        case DOUBLE_SINGLE_TAP: action = DYN_MACRO_PLAY2;
    }

    process_dynamic_macro( action, &kr );
};

void td_macro_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    td_macro_2_state.state = 0;
};