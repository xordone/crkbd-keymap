#include QMK_KEYBOARD_H
#include <stdio.h>
#include "custom_keycodes.c"
#include "tap_dance.c"

enum layers {
    L_EN = 0,
    L_ENS = 1,
    L_RU = 2,
    L_RUS = 3,
    L_LOWER,
    L_RAISE,
    L_ADJUST,
    L_GAME
};

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)
//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
      [L_EN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV,   KC_Q,    KC_W,  KC_E, KC_R, KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_LBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,  HOME_A,  HOME_S,  HOME_D,  HOME_F,   KC_G,                        KC_H,   HOME_J,  HOME_K,  HOME_L,  HOME_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ESCAPE,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  LA_CHNG,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL,  TD(TS_CLT),  KC_SPC,     KC_ENT,      TD(TS_DLT), KC_BSPC
                                      //`--------------------------'  `--------------------------'

  ),
        [L_ENS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV,   KC_Q,    KC_W,  KC_E, KC_R, KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_LBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,  HOME_A,  HOME_S,  HOME_D,  HOME_F,   KC_G,                        KC_H,   HOME_J,  HOME_K,  HOME_L,  HOME_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ESCAPE,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,  KC_M, KC_COMM,  KC_DOT, KC_SLSH,  LA_CHNG,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL,  MO(L_LOWER),  KC_SPC,     KC_ENT,     MO(L_RAISE), KC_BSPC
                                      //`--------------------------'  `--------------------------'
                                      //`--------------------------'  `--------------------------'

  ),
        [L_RU] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV,   KC_Q,    KC_W,  KC_E, KC_R, KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_LBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,  HOME_A,  HOME_S,  HOME_D,  HOME_F,   KC_G,                        KC_H,   HOME_J,  HOME_K,  HOME_L,  HOME_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ESCAPE,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    TD(CS_M), KC_COMM,  KC_DOT, KC_SLSH,  LA_CHNG,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL,  TD(TS_RUCLT),  KC_SPC,     KC_ENT,    TD(TS_RUDLT)  , KC_BSPC
                                      //`--------------------------'  `--------------------------'

  ),
        [L_RUS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV,   KC_Q,    KC_W,  KC_E, KC_R, KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_LBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,  HOME_A,  HOME_S,  HOME_D,  HOME_F,   KC_G,                        KC_H,   HOME_J,  HOME_K,  HOME_L,  HOME_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ESCAPE,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    TD(CS_M), KC_COMM,  KC_DOT, KC_SLSH,  LA_CHNG,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL,  MO(L_LOWER),  KC_SPC,     KC_ENT,     MO(L_RAISE), KC_BSPC
                                      //`--------------------------'  `--------------------------'

  ),
//   [0] = LAYOUT_split_3x6_3(
//   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
//        KC_GRV,   KC_Q,    KC_W,  KC_E, KC_R, KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_LBRC,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       KC_TAB,  HOME_A,  HOME_S,  HOME_D,  HOME_F,   KC_G,                        KC_H,   HOME_J,  HOME_K,  HOME_L,  HOME_SCLN, KC_QUOT,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       KC_ESCAPE,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    TD(CS_M), KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
//   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//                                           KC_LCTL,  MO(1),  KC_SPC,     KC_ENT,     MO(2), KC_BSPC
//                                       //`--------------------------'  `--------------------------'

//   ),

  [L_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS,    XXXXXXX,    KC_F7,    KC_F8,    KC_F9,    KC_F12,            KC_EQUAL,    KC_7,    KC_8,    KC_9,    XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, XXXXXXX, KC_F4, KC_F5, KC_F6, KC_F10,                            KC_0, KC_4,   KC_5,KC_6, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F11,                            KC_MINUS, KC_1, KC_2, KC_3, XXXXXXX, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_TRNS, KC_TRNS,   KC_LSFT,  MO(L_ADJUST), KC_DEL
                                      //`--------------------------'  `--------------------------'
  ),
  
  [L_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, XXXXXXX,                      C(KC_LEFT), XXXXXXX, XXXXXXX, C(KC_RIGHT), XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_LT, KC_GT, KC_LBRC, KC_RBRC, XXXXXXX,                      KC_LEFT,  KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_BSLS, AG_DOT, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END, XXXXXXX, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS,    MO(L_ADJUST),  KC_TRNS,     KC_TRNS, KC_TRNS, KC_DEL
                                      //`--------------------------'  `--------------------------'
  ),

  [L_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       TD(TAP2), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TD(TAP1),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS, TO(L_GAME)
                                      //`--------------------------'  `--------------------------'
  ),
          [L_GAME] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESCAPE,   KC_Q,    KC_W,  KC_E, KC_R, KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_LBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,  KC_A,  KC_S,  KC_D,  KC_F,   KC_G,                        KC_H,   KC_J,  KC_K,  KC_L,  KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    TD(CS_M), KC_COMM,  KC_DOT, KC_SLSH,  KC_LEFT_ALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LSFT,  MO(L_LOWER),  KC_SPC,     KC_ENT,     TO(L_EN), KC_BSPC
                                      //`--------------------------'  `--------------------------'

  )
};
//for LT emulation
// Determine the tapdance state to return
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }

    if (state->count == 2) return TD_DOUBLE_SINGLE_TAP;
    else return TD_UNKNOWN; // Any number higher than the maximum state value you return above
}

//  !!!
#include "tdfunc.c"

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}
void oled_render_layer_state(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case L_EN:
        case L_ENS:
            oled_write_ln_P(PSTR("English"), false);
            rgblight_sethsv(HSV_WHITE);
            break;
        case L_RU:
        case L_RUS:
            oled_write_ln_P(PSTR("Russian"), false);
            rgblight_sethsv(HSV_BLUE);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            rgblight_sethsv(HSV_GREEN);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            rgblight_sethsv(HSV_ORANGE);
            break;
        case L_ADJUST:
            oled_write_ln_P(PSTR("Adjust"), false);
            rgblight_sethsv(HSV_RED);
            break;
        case L_GAME:
            oled_write_ln_P(PSTR("Game"), false);
            rgblight_sethsv(HSV_GOLD);
            break;
        // default:
        //     oled_write_ln_P(PSTR("Base"), false);
        //     rgblight_sethsv(HSV_BLUE);
        //     break;

    }
}

char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}
// bootmagic Я отключил, так что эти строки закоментировал
// void render_bootmagic_status(bool status) {
//     /* Show Ctrl-Gui Swap options */
//     static const char PROGMEM logo[][2][3] = {
//         {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
//         {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
//     };
//     if (status) {
//         oled_write_ln_P(logo[0][0], false);
//         oled_write_ln_P(logo[0][1], false);
//     } else {
//         oled_write_ln_P(logo[1][0], false);
//         oled_write_ln_P(logo[1][1], false);
//     }
// }

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
        qk_tap_dance_action_t *action;
        if (!lang_shift_process_record(keycode, record))
        return false;

    switch (keycode) {
    case TD(CS_M):  // list all tap dance keycodes with tap-hold configurations
    action = &tap_dance_actions[TD_INDEX(keycode)];
    if (!record->event.pressed && action->state.count && !action->state.finished) {
        tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
        tap_code16(tap_hold->tap);
        }
    }
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
void user_timer(void) {
  lang_shift_user_timer();
}

void matrix_scan_user(void) {
  user_timer();
}
#endif // OLED_ENABLE


