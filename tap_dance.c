#include "secret.c"
// Tap Dance declarations
enum {
    TAP1,
    TAP2,
    CS_M
};
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
    [CS_M] = ACTION_TAP_DANCE_TAP_HOLD(KC_M, KC_RBRC)
};

