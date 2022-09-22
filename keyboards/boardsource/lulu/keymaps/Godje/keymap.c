// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _QWERTY,
    _FIRST,
    _SECOND,
		_GAME,
    _ADJUST
};

#define FIRST MO(_FIRST)
#define SECOND MO(_SECOND)
#define ADJUST MO(_ADJUST)
#define QWERTY TG(_QWERTY)
#define GAMER TG(_GAME)
#define SPACE LT(_FIRST, KC_SPC)
#define BACKSP LT(_SECOND, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 
/* BASE (colemak)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |  -   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | Adju | LGUI | LALT | /Space  /       \Bspce \  |Enter |Delete| QWER |
 *                   |      |      |      |/First  /         \Second\ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_BASE] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                     KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,	KC_BSLS,
  KC_LCTL, KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                     KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,  KC_F3, KC_GRV,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,  KC_MINS,
                          ADJUST,    KC_LGUI, KC_LALT, SPACE, BACKSP,   KC_ENT,   KC_DEL, QWERTY
),
/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LCTL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                          ADJUST,    KC_LGUI, KC_LALT, SPACE, BACKSP,   KC_ENT,   KC_DEL, QWERTY
),
/* FIRST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    | PGUP | NUML |  /   |  *   |  -   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   %  |   !  |   @  |   $  |      |                    | PGDN |  7   |  8   |  9   |  +   |ALT(\)|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   &  |   :  |   ~  |   ^  |      |-------.    ,-------| HOME |  4   |  5   |  6   | ENTER|      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|  END |  1   |  2   |  3   |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |  0   |  .   |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_FIRST] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   KC_PGUP, KC_LNUM, KC_PSLS, KC_PAST, KC_PMNS, _______,
  _______, KC_PERC, KC_EXLM, 	 KC_AT,	 KC_DLR, _______,                   KC_PGDN, KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS, LALT(KC_BSLS),
  _______, KC_AMPR, KC_COLN, KC_TILD, KC_CIRC, _______,                   KC_HOME, KC_KP_4, KC_KP_5, KC_KP_6, KC_PENT, _______,
  _______, _______, _______, _______, _______, _______, _______, _______,  KC_END, KC_KP_1, KC_KP_2, KC_KP_3, _______, _______,
                             _______, _______, _______,  KC_SPC, _______,  _______, KC_KP_0, KC_PDOT
),
/* FIRST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    | PGUP | NUML |  /   |  *   |  -   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   %  |   !  |   @  |   $  |      |                    | PGDN |  7   |  8   |  9   |  +   |ALT(\)|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   &  |   :  |   ~  |   ^  |      |-------.    ,-------| HOME |  4   |  5   |  6   | ENTER|      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|  END |  1   |  2   |  3   |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |  0   |  .   |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_SECOND] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     GAMER, _______, _______, _______, _______, _______,
  _______,   KC_F1,   KC_F2, 	 KC_F3,	  KC_F4, _______,                   _______, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, _______,
  _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8, _______,                   _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,
  _______,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______,
                             _______, _______, _______, _______, KC_BSPC,  _______, _______, _______
),
/* GAME */
[_GAME] = LAYOUT(
	KC_5,		KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
	KC_T,		KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
	KC_G, 	KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
	KC_F5,	KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,  KC_B,  KC_F3,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                          ADJUST,  KC_LGUI, KC_C,  KC_SPC, KC_BSPC,   KC_ENT,   KC_DEL, GAMER
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_ADJUST] = LAYOUT(
  RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  QK_BOOT,  QK_RBT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _FIRST, _SECOND, _ADJUST);
}
