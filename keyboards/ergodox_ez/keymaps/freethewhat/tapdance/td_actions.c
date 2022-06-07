qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_F5] = ACTION_TAP_DANCE_DOUBLE(KC_F5, LCTL(KC_F5)),
  [TD_F12] = ACTION_TAP_DANCE_DOUBLE(KC_F12, LCTL(KC_F12)),
  [TD_DEL] = ACTION_TAP_DANCE_DOUBLE(KC_DEL, S(KC_DEL)),
  [TD_MEDIA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_media_finished, td_media_reset),
  [TD_MACRO_1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_macro_1_finished, td_macro_1_reset),
  [TD_MACRO_2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_macro_2_finished, td_macro_2_reset),
};