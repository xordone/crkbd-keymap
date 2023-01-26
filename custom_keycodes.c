#define CUSTOM_SAFE_RANGE SAFE_RANGE
#include "lang_shift/include.h"

enum custom_keycodes {
	CS_TEST = CUSTOM_SAFE_RANGE,
};
bool process_my_hotkeys(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
	case CS_TEST:
	if (record->event.pressed) {
	    register_code(KC_DOT);
		unregister_code(KC_DOT);
	    register_code(KC_SPC);
		unregister_code(KC_SPC);
	    }
	    return false;
	    break;
	}
	return true;
  }
// void tap_alt_code2(uint16_t mods, uint8_t n1, uint8_t n2) {
// 	unregister_mods(mods);
// 	register_mods(MOD_BIT(KC_LEFT_ALT));
// 	if (n1 == 0) {
// 		tap_code(KC_KP_0);
// 	} else {
// 		tap_code(KC_KP_1 + n1 - 1);
// 	}
// 	if (n2 == 0) {
// 		tap_code(KC_KP_0);
// 	} else {
// 		tap_code(KC_KP_1 + n2 - 1);
// 	}
// 	unregister_mods(MOD_BIT(KC_LEFT_ALT));
// 	register_mods(mods);
// }

// void tap_alt_code3(uint16_t mods, uint8_t n1, uint8_t n2, uint8_t n3) {
// 	unregister_mods(mods);
// 	register_mods(MOD_BIT(KC_LEFT_ALT));
// 	if (n1 == 0) {
// 		tap_code(KC_KP_0);
// 	} else {
// 		tap_code(KC_KP_1 + n1 - 1);
// 	}
// 	if (n2 == 0) {
// 		tap_code(KC_KP_0);
// 	} else {
// 		tap_code(KC_KP_1 + n2 - 1);
// 	}
// 	if (n3 == 0) {
// 		tap_code(KC_KP_0);
// 	} else {
// 		tap_code(KC_KP_1 + n3 - 1);
// 	}
// 	unregister_mods(MOD_BIT(KC_LEFT_ALT));
// 	register_mods(mods);
// }
