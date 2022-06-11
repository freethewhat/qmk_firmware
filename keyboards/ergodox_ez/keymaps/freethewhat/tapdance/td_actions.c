qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_F5] = ACTION_TAP_DANCE_DOUBLE(KC_F5, LCTL(KC_F5)),
  [TD_F12] = ACTION_TAP_DANCE_DOUBLE(KC_F12, LCTL(KC_F12)),
  [TD_DEL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_del_finished, td_del_reset),
  [TD_MEDIA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_media_finished, td_media_reset),
  [TD_MACRO_1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_macro_1_finished, td_macro_1_reset),
  [TD_MACRO_2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_macro_2_finished, td_macro_2_reset),
  [TD_EXLM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_exlm_finished, td_exlm_reset),
  [TD_AT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_at_finished, td_at_reset),
  [TD_HASH] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_hash_finished, td_hash_reset),
  [TD_DLR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_dlr_finished, td_dlr_reset),
  [TD_AMPR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_ampr_finished, td_ampr_reset),
  [TD_ASTR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_astr_finished, td_astr_reset),
};