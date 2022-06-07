enum combos {
  WFP_A
};

const uint16_t PROGMEM wfp_combo[] = {KC_W, KC_F, KC_P, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [WFP_A] = COMBO(wfp_combo, CAPSWRD)
};
