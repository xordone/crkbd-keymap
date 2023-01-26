#include "secret.c"
// Tap Dance declarations
enum {
    TAP1,
    TAP2,
    CS_M,
    TS_DLT, 
    TS_CLT, 
    TS_RUCLT, 
    TS_RUDLT
    
};
// LT emulatuion
// Define a type containing as many tapdance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_SINGLE_TAP
} td_state_t;

// Create a global instance of the tapdance state type
static td_state_t td_state;

// Declare your tapdance functions:

// Function to determine the current tapdance state
td_state_t cur_dance(qk_tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void ruclt_finished(qk_tap_dance_state_t *state, void *user_data);
void clt_finished(qk_tap_dance_state_t *state, void *user_data);
void clt_reset(qk_tap_dance_state_t *state, void *user_data);
void rudlt_finished(qk_tap_dance_state_t *state, void *user_data);
void dlt_finished(qk_tap_dance_state_t *state, void *user_data);
void dlt_reset(qk_tap_dance_state_t *state, void *user_data);

// // Determine the tapdance state to return
// td_state_t cur_dance(qk_tap_dance_state_t *state) {
//     if (state->count == 1) {
//         if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
//         else return TD_SINGLE_HOLD;
//     }

//     if (state->count == 2) return TD_DOUBLE_SINGLE_TAP;
//     else return TD_UNKNOWN; // Any number higher than the maximum state value you return above
// }

// // Handle the possible states for each tapdance keycode you define:

// void altlp_finished(qk_tap_dance_state_t *state, void *user_data) {
//     td_state = cur_dance(state);
//     switch (td_state) {
//         case TD_SINGLE_TAP:
//             register_code16(KC_LSFT);
//             register_code16(KC_SLSH);
//             break;
//         case TD_SINGLE_HOLD:
//             register_mods(layer_on(L_LOWER)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
//             break;
//         case TD_DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
//             tap_code16(KC_NO);
//             register_code16(KC_NO);
//             break;
//         default:
//             break;
//     }
// }

// void altlp_reset(qk_tap_dance_state_t *state, void *user_data) {
//     switch (td_state) {
//         case TD_SINGLE_TAP:
//             unregister_code16(KC_SLSH);
//             unregister_code16(KC_LSFT);
//             break;
//         case TD_SINGLE_HOLD:
//             unregister_mods(layer_off(L_LOWER)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
//             break;
//         case TD_DOUBLE_SINGLE_TAP:
//             unregister_code16(KC_NO);
//             break;
//         default:
//             break;
//     }
// }

// //

// for tap/hold
typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

void tap_dance_tap_hold_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(qk_tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }
// 
void dancing_pass(qk_tap_dance_state_t *state, void *user_data) {

    if (state->count >= 3) {
        send_string(td1_string);
    }
    reset_tap_dance(state);
}
void secret_pass(qk_tap_dance_state_t *state, void *user_data) {

    if (state->count >= 3) {
        send_string(td2_string);
    }
    reset_tap_dance(state);
}

qk_tap_dance_action_t tap_dance_actions[] = {

    [TAP1] = ACTION_TAP_DANCE_FN(dancing_pass),
    [TAP2] = ACTION_TAP_DANCE_FN(secret_pass),
    [CS_M] = ACTION_TAP_DANCE_TAP_HOLD(KC_M, KC_RBRC),
    [TS_RUCLT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ruclt_finished, clt_reset), 
    [TS_CLT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, clt_finished, clt_reset), 
    [TS_RUDLT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rudlt_finished, dlt_reset), 
    [TS_DLT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dlt_finished, dlt_reset)

};

