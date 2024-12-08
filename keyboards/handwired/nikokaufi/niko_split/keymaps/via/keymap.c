// Copyright 2024 Nikolaj Kaufmann
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

/* MACROS */
enum custom_keycodes {
    OFF = SAFE_RANGE,
    STP,
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case OFF:
        if (record->event.pressed) {
            SEND_STRING(SS_LGUI("r"));
            SEND_STRING(SS_DELAY(300));
            SEND_STRING("shutdown /s /t 10 /f /c @Herunterfahren in 10 Sekunden@");
            SEND_STRING(SS_DELAY(300));
            SEND_STRING(SS_TAP(X_ENTER));
        }
        else { //when keycode is released
        }
        break;
    case STP:
        if (record->event.pressed) {
            SEND_STRING(SS_LGUI("r"));
            SEND_STRING(SS_DELAY(300));
            SEND_STRING("shutdown /a");
            SEND_STRING(SS_DELAY(300));
            SEND_STRING(SS_TAP(X_ENTER));
        }
        else { //when keycode is released
        }
        break;
    }
    return true;
};

/* TAP DANCE */
enum {
    TD_ESC_AF4,
};
void escaltf4(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 3) {
        register_code(KC_LALT);
        tap_code(KC_F4);
        unregister_code(KC_LALT);
        reset_tap_dance(state);
    }
    else {
        tap_code(KC_ESC);
    }
}
tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_AF4] = ACTION_TAP_DANCE_FN(escaltf4),
};

/* CUSTOM KEYCODES */
#define SPC1 LT(1,KC_SPACE)
#define ALT2 LT(2,KC_LALT)
#define SPC3 LT(3,KC_SPACE)
#define ENT_CTL RCTL_T(KC_ENT)
#define QUO_SHI RSFT_T(KC_QUOT)
#define ESC_AF4 TD(TD_ESC_AF4)

/* KEYMAP */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*  [0]
     * ┌───┬───┬───┬───┬───┬───┐                     ┌───┬───┬───┬───┬───┬───┐
     * │ESC│ 1 │ 2 │ 3 │ 4 │ 5 ├───┐             ┌───┤ 6 | 7 | 8 | 9 | 0 | ß |
     * ├───┼───┼───┼───┼───┼───┤DEL│             |PO1├───┼───┼───┼───┼───┼───┤
     * │TAB│ Q │ W │ E │ R │ T ├───┤             ├───┤ Z | U | I | O | P | Ü |
     * ├───┼───┼───┼───┼───┼───┤F13│             |END├───┼───┼───┼───┼───┼───┤
     * │SHI│ A │ S │ D │ F │ G ├───┤             ├───┤ H | J | K | L | Ö | Ä |
     * ├───┼───┼───┼───┼───┼───┤MUT│             |PLP├───┼───┼───┼───┼───┼───┤
     * │<|>│ Y │ X │ C │ V | B ├───┘             └───┤ N | M | , | . | - |SHI|
     * └───┴───┴───┴──┬┴──┬┴───┴┬───┬───┐   ┌───┬───┬┴───┴┬──┴┬──┴───┴───┴───┘
     *                |CTL| SPC |ALT|WIN|   |ALT|BSP| SPC |ENT|
     *                └───┴─────┴───┴───┘   └───┴───┴─────┴───┘
     */
    [0] = LAYOUT_custom(
        ESC_AF4, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_DEL,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_F13,
        KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,
                                            KC_LCTL, SPC1,    ALT2,    KC_LGUI,
        //right
                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
                 KC_HOME, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
                 KC_END,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, QUO_SHI,
                 KC_MPLY, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_RALT, KC_BSPC, SPC3,    ENT_CTL
        ),
    /*  [1]
     * ┌───┬───┬───┬───┬───┬───┐                     ┌───┬───┬───┬───┬───┬───┐
     * │^° │F1 │F2 │F3 │F4 │F5 ├───┐             ┌───┤F6 |F7 |F8 |F9 |F10|´` |
     * ├───┼───┼───┼───┼───┼───┤INS│             |PUP├───┼───┼───┼───┼───┼───┤
     * │   │F11│F12│MS↑│   │   ├───┤             ├───┤   |   | ↑ |   |   |+*~|
     * ├───┼───┼───┼───┼───┼───┤F14│             |PDN├───┼───┼───┼───┼───┼───┤
     * │SHI│   │MS←│MS↓│MS→│   ├───┤             ├───┤   | ← | ↓ | → |   |#' |
     * ├───┼───┼───┼───┼───┼───┤MS1│             |MS2├───┼───┼───┼───┼───┼───┤
     * │CAP│   │   │   │   |MS1├───┘             └───┤NKR|   |   |   |   |   |
     * └───┴───┴───┴──┬┴──┬┴───┴┬───┬───┐   ┌───┬───┬┴───┴┬──┴┬──┴───┴───┴───┘
     *                |CTL| /1\ |ALT|WIN|   |ALT|BSP| WIN |CTL|
     *                └───┴─────┴───┴───┘   └───┴───┴─────┴───┘
     */
    [1] = LAYOUT_custom(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
        KC_NO,   KC_F11,  KC_F12,  KC_MS_U, KC_NO,   KC_NO,   KC_INS,
        KC_LSFT, KC_NO,   KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,   KC_F14,
        KC_CAPS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BTN1, KC_BTN1,
                                            KC_LCTL, _______, KC_LALT, KC_LGUI,
        //right
                          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_EQL,
                 KC_PGUP, KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO,   KC_RBRC,
                 KC_PGDN, KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,   KC_BSLS,
                 KC_BTN2, NK_TOGG, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_RALT, KC_BSPC, KC_RGUI, KC_RCTL
        ),
    /*  [2]
     * ┌───┬───┬───┬───┬───┬───┐                     ┌───┬───┬───┬───┬───┬───┐
     * │OFF│STP│   │   │   │   ├───┐             ┌───┤   |   |   |   |   |ß?\|
     * ├───┼───┼───┼───┼───┼───┤   │             |   ├───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   ├───┤             ├───┤   |   |   |   |   |+*~|
     * ├───┼───┼───┼───┼───┼───┤   │             |   ├───┼───┼───┼───┼───┼───┤
     * │SHI│ 1 │ 2 │ 3 │ 4 │ 5 ├───┤             ├───┤ 6 | 7 | 8 | 9 | 0 |#' |
     * ├───┼───┼───┼───┼───┼───┤   │             |   ├───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   |   ├───┘             └───┤   |   |,; |.: |-_ |   |
     * └───┴───┴───┴──┬┴──┬┴───┴┬───┬───┐   ┌───┬───┬┴───┴┬──┴┬──┴───┴───┴───┘
     *                |   |     |/2\|   |   |ALT|BSP| SHI |CTL|
     *                └───┴─────┴───┴───┘   └───┴───┴─────┴───┘
     */
    [2] = LAYOUT_custom(
        OFF,     STP,     KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_LSFT, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                            KC_NO,   KC_NO,   _______, KC_NO,
        //right
                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MINS,
                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RBRC,
                 KC_NO,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
                 KC_NO,   KC_NO,   KC_NO,   KC_COMM, KC_DOT,  KC_SLSH, KC_NO,
        KC_RALT, KC_BSPC, KC_RSFT, KC_RCTL
        ),
    /*  [3]
     * ┌───┬───┬───┬───┬───┬───┐                     ┌───┬───┬───┬───┬───┬───┐
     * │   │   │   │   │   │   ├───┐             ┌───┤   |   |   |   |   |   |
     * ├───┼───┼───┼───┼───┼───┤   │             |   ├───┼───┼───┼───┼───┼───┤
     * │TOG│MOD│VAI│HUI│SAI│   ├───┤             ├───┤   |   |   |   |   |   |
     * ├───┼───┼───┼───┼───┼───┤   │             |   ├───┼───┼───┼───┼───┼───┤
     * │   │RMO│VAD│HUD│SAD│   ├───┤             ├───┤   |   |   |   |   |   |
     * ├───┼───┼───┼───┼───┼───┤   │             |   ├───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   |   ├───┘             └───┤   |   |   |   |   |   |
     * └───┴───┴───┴──┬┴──┬┴───┴┬───┬───┐   ┌───┬───┬┴───┴┬──┴┬──┴───┴───┴───┘
     *                |   |     |   |   |   |   |   | /3\ |   |
     *                └───┴─────┴───┴───┘   └───┴───┴─────┴───┘
     */
    [3] = LAYOUT_custom(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, KC_NO,   KC_NO,
        KC_NO,   RGB_RMOD,RGB_VAD, RGB_HUD, RGB_SAD, KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                            KC_NO,   KC_NO,   KC_NO,   KC_NO,
        //right
                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   _______, KC_NO
        )

};

/* ENCODER */
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD,  KC_VOLU),   ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    [1] = {ENCODER_CCW_CW(KC_WH_L,  KC_WH_R),   ENCODER_CCW_CW(KC_WH_U, KC_WH_D)},
    [2] = {ENCODER_CCW_CW(KC_NO,    KC_NO),     ENCODER_CCW_CW(KC_NO,   KC_NO)},
    [3] = {ENCODER_CCW_CW(KC_NO,    KC_NO),     ENCODER_CCW_CW(KC_NO,   KC_NO)}
    };
#endif
