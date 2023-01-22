#include "secret.c"
// Tap Dance declarations
enum {
    TAP1,
    TAP2
};


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
};

