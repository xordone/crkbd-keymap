// Handle the possible states for each tapdance keycode you define:

void ruclt_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(KC_LSFT);
            register_code16(KC_SLSH);
            unregister_code16(KC_SLSH);
            unregister_code16(KC_LSFT);
            register_code16(KC_SPC);
            unregister_code16(KC_SPC);
            break;
        case TD_SINGLE_HOLD:
            layer_on(L_LOWER); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        // case TD_DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
        //     tap_code16(KC_NO);
        //     register_code16(KC_NO);
        //     break;
        default:
            break;
    }
}


void clt_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:

            register_code16(KC_COMM);
            unregister_code16(KC_COMM);
            register_code16(KC_SPC);
            unregister_code16(KC_SPC);
            break;
        case TD_SINGLE_HOLD:
            layer_on(L_LOWER); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        // case TD_DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
        //     tap_code16(KC_NO);
        //     register_code16(KC_NO);
        //     break;
        default:
            break;
    }
}

void clt_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            break;
        case TD_SINGLE_HOLD:
            layer_off(L_LOWER); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        // case TD_DOUBLE_SINGLE_TAP:
        //     unregister_code16(KC_NO);
        //     break;
        default:
            break;
    }
}
//
//
void rudlt_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(KC_SLSH);
            unregister_code16(KC_SLSH);
            register_code16(KC_SPC);
            unregister_code16(KC_SPC);
            shift_once_use_to_next_key(lang_get_shift_layer_number());

            break;
        case TD_SINGLE_HOLD:
            layer_on(L_RAISE); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        // case TD_DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
        //     tap_code16(KC_NO);
        //     register_code16(KC_NO);
        //     break;
        default:
            break;
    }
}


void dlt_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:

            register_code16(KC_DOT);
            unregister_code16(KC_DOT);
            register_code16(KC_SPC);
            unregister_code16(KC_SPC);
            shift_once_use_to_next_key(lang_get_shift_layer_number());

            break;
        case TD_SINGLE_HOLD:
            layer_on(L_RAISE); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        // case TD_DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
        //     tap_code16(KC_NO);
        //     register_code16(KC_NO);
        //     break;
        default:
            break;
    }
}

void dlt_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            break;
        case TD_SINGLE_HOLD:
            layer_off(L_RAISE); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        // case TD_DOUBLE_SINGLE_TAP:
        //     unregister_code16(KC_NO);
        //     break;
        default:
            break;
    }
}
//
//
