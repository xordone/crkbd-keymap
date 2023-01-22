enum custom_keycodes {
	M_DOT = SAFE_RANGE
};

void tap_alt_code2(uint16_t mods, uint8_t n1, uint8_t n2) {
	unregister_mods(mods);
	register_mods(MOD_BIT(KC_LEFT_ALT));
	if (n1 == 0) {
		tap_code(KC_KP_0);
	} else {
		tap_code(KC_KP_1 + n1 - 1);
	}
	if (n2 == 0) {
		tap_code(KC_KP_0);
	} else {
		tap_code(KC_KP_1 + n2 - 1);
	}
	unregister_mods(MOD_BIT(KC_LEFT_ALT));
	register_mods(mods);
}

void tap_alt_code3(uint16_t mods, uint8_t n1, uint8_t n2, uint8_t n3) {
	unregister_mods(mods);
	register_mods(MOD_BIT(KC_LEFT_ALT));
	if (n1 == 0) {
		tap_code(KC_KP_0);
	} else {
		tap_code(KC_KP_1 + n1 - 1);
	}
	if (n2 == 0) {
		tap_code(KC_KP_0);
	} else {
		tap_code(KC_KP_1 + n2 - 1);
	}
	if (n3 == 0) {
		tap_code(KC_KP_0);
	} else {
		tap_code(KC_KP_1 + n3 - 1);
	}
	unregister_mods(MOD_BIT(KC_LEFT_ALT));
	register_mods(mods);
}
