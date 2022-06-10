enum macro_keycodes {
    MACRO_WT = SAFE_RANGE,
    MACRO_CODE,
    MACRO_NOTEPAD,
    MACRO_COPY_DOWN,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MACRO_WT:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_TAP(X_R)) SS_DELAY(100) SS_TAP(X_W) SS_DELAY(100) SS_TAP(X_T) SS_DELAY(100) SS_TAP(X_ENTER));
            }
            break;
        case MACRO_CODE:
            if (record->event.pressed) {
                SEND_STRING("code .");
                SEND_STRING(SS_TAP(X_ENTER));
            }
            break;
        case MACRO_NOTEPAD:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_TAP(X_R)) SS_DELAY(100));
                SEND_STRING("notepad.exe");
                SEND_STRING(SS_TAP(X_ENTER));
            }
            break;
        case MACRO_COPY_DOWN:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_LEFT))) SS_DELAY(100) SS_LCTL(SS_TAP(X_C)) SS_DELAY(100) SS_TAP(X_TAB) SS_DELAY(100) SS_LCTL(SS_TAP(X_V)));
            }
            break;
        default:
            break;
    }
    return true;
};