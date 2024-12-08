// Copyright 2024 Nikolaj Kaufmann
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_german.h"

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
    TD_S_SS
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
void sss(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 3) {
        tap_code(DE_SS);
    }
    else {
        tap_code(KC_S);
    }
}
tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_AF4] = ACTION_TAP_DANCE_FN(escaltf4),
    [TD_S_SS] = ACTION_TAP_DANCE_FN(sss),
};

/* CUSTOM KEYCODES */
#define SPC1 LT(1,KC_SPACE)
#define ALT2 LT(2,KC_LALT)
#define ENT_CTL RCTL_T(KC_ENT)
#define ESC_AF4 TD(TD_ESC_AF4)
#define S_SS TD(TD_S_SS)
// home row mods
#define A_SHI (LSFT_T(KC_A))
#define S_ALT (LALT_T(TD_S_SS))
#define D_STRG (LCTL_T(KC_D))
#define F_WIN (LWIN_T(KC_F))
#define J_WIN (RWIN_T(KC_J))
#define K_STRG (RCTL_T(KC_K))
#define L_ALT (RALT_T(KC_L))
#define OE_SHI (RSFT_T(DE_ODIA))

/* KEYMAP */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*  [0]
     * ┌───┬───┬───┬───┬───┬───┐            ┌───┬───┬───┬───┬───┬───┐
     * │ESC│ Q │ W │ E │ R │ T |            | Z | U | I | O | P | Ü |
     * ├───┼───┼───┼───┼───┼───┤            |───┼───┼───┼───┼───┼───┤
     * │TAB│ A │ S │ D │ F │ G |            | H | J | K | L | Ö | Ä |
     * ├───┼───┼───┼───┼───┼───┼───┐    ┌───┼───┼───┼───┼───┼───┼───┤
     * │ < │ Y │ X │ C │ V | B |MUT|    |PLP| N | M | , | . | - | ? |
     * └───┴───┴───┴───┼───┼───┼───┤    ├───┼───┼───┼───┴───┴───┴───┘
     *                 | ? |SPC|ALT|    |AGR|<- |ENT|
     *                 └───┴───┴───┘    └───┴───┴───┘
     */
    [0] = LAYOUT_split_3x6_3(
        ESC_AF4, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
        KC_TAB,  A_SHI,   S_ALT,   D_STRG,  F_WIN,   KC_G,
        DE_LABK, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,
                                            KC_NO,   SPC1,    KC_LALT,
        //right
                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    DE_UDIA,
                 KC_H,    J_WIN,   K_STRG,  L_ALT,   OE_SHI,  DE_ADIA,
        KC_MPLY, KC_N,    KC_M,    KC_COMM, KC_DOT,  DE_MINS, KC_RSFT,
        KC_RALT, KC_BSPC, KC_ENT
        ),
    /*  [1]
     *
     * ┌───┬───┬───┬───┬───┬───┐            ┌───┬───┬───┬───┬───┬───┐
     * │   │   │   │MS↑│   │   |            |   |   | ↑ |   |   |+*~|
     * ├───┼───┼───┼───┼───┼───┤            ├───┼───┼───┼───┼───┼───┤
     * │SHI│   │MS←│MS↓│MS→│   |            |   | ← | ↓ | → |   |#' |
     * ├───┼───┼───┼───┼───┼───┼───┐    ┌───┼───┼───┼───┼───┼───┼───┤
     * │CAP│   │   │   │   |MS1|MS1|    |   |NKR|   |   |   |   |   |
     * └───┴───┴───┴───┼───┼───┼───┤    ├───┼───┼───┼───┴───┴───┴───┘
     *                 |   |   |   |    |   |   |   |
     *                 └───┴───┴───┘    └───┴───┴───┘
     */
    [1] = LAYOUT_split_3x6_3(
        KC_NO,   KC_NO,   KC_NO,   KC_MS_U, KC_NO,   KC_NO,
        KC_LSFT, KC_NO,   KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,
        KC_CAPS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BTN1, KC_BTN1,
                                            KC_LCTL, _______, KC_LALT,
        //right
                 KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO,   DE_PLUS,
                 KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,   DE_HASH,
        KC_BTN2, NK_TOGG, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_RALT, KC_BSPC, KC_RGUI
        ),
    /*  [2]
     * ┌───┬───┬───┬───┬───┬───┐            ┌───┬───┬───┬───┬───┬───┐
     * │F1 │F2 │F3 │F4 │F5 │F6 |            |F7 |F8 |F9 |F10|F11|F12|
     * ├───┼───┼───┼───┼───┼───┤            ├───┼───┼───┼───┼───┼───┤
     * │SHI│ 1 │ 2 │ 3 │ 4 │ 5 |            | 6 | 7 | 8 | 9 | 0 |#' |
     * ├───┼───┼───┼───┼───┼───┼───┐    ┌───┼───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   |   |   |    |   |   |,; |.: |-_ |   |   |
     * └───┴───┴───┴───┼───┼───┼───┤    ├───┼───┼───┼───┴───┴───┴───┘
     *                 |   |   |   |    |   |   |   |
     *                 └───┴───┴───┘    └───┴───┴───┘
     */
    [2] = LAYOUT_split_3x6_3(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
        KC_LSFT, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                            KC_NO,   KC_NO,   KC_NO,
        //right
                 KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
                 KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
        KC_NO,   KC_NO,   KC_COMM, KC_DOT,  DE_MINS, KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO
        ),
    /*  [3]
     * ┌───┬───┬───┬───┬───┬───┐            ┌───┬───┬───┬───┬───┬───┐
     * │TOG│MOD│VAI│HUI│SAI│   |            |   |   |   |   |   |   |
     * ├───┼───┼───┼───┼───┼───┤            ├───┼───┼───┼───┼───┼───┤
     * │   │RMO│VAD│HUD│SAD│   |            |   |   |   |   |   |   |
     * ├───┼───┼───┼───┼───┼───┼───┐    ┌───┼───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   |   |   |    |   |   |   |   |   |   |   |
     * └───┴───┴───┴───┼───┼───┼───┤    ├───┼───┼───┼───┴───┴───┴───┘
     *                 |   |   |   |    |   |   |   |
     *                 └───┴───┴───┘    └───┴───┴───┘
     */
    [3] = LAYOUT_split_3x6_3(
        RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, KC_NO,
        KC_NO,   RGB_RMOD,RGB_VAD, RGB_HUD, RGB_SAD, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                            KC_NO,   KC_NO,   KC_NO,
        //right
                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO
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
