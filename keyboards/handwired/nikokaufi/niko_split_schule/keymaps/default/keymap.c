// Copyright 2024 Nikolaj Kaufmann
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define MO1 LT(1,KC_SPACE)
#define MO2 LT(2,KC_ENT)
//EE_CLR for resetting EEPROM

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*  [0]
     * ┌───┬───┬───┬───┬───┬───┐                     ┌───┬───┬───┬───┬───┬───┐
     * │ESC│ 1 │ 2 │ 3 │ 4 │ 5 ├───┐             ┌───┤ 6 | 7 | 8 | 9 | 0 | ß |
     * ├───┼───┼───┼───┼───┼───┤DEL│             |PO1├───┼───┼───┼───┼───┼───┤
     * │TAB│ Q │ W │ E │ R │ T ├───┤             ├───┤ Z | U | I | O | P | Ü |
     * ├───┼───┼───┼───┼───┼───┤F13│             |END├───┼───┼───┼───┼───┼───┤
     * │SHI│ A │ S │ D │ F │ G ├───┤             ├───┤ H | J | K | L | Ö | Ä |
     * ├───┼───┼───┼───┼───┼───┤MUT│             |PLP├───┼───┼───┼───┼───┼───┤
     * │<|>│ Y │ X │ C │ V | B ├───┘             └───┤ N | M | , | . | - | # |
     * └───┴───┴───┴──┬┴──┬┴───┴┬───┬───┐   ┌───┬───┬┴───┴┬──┴┬──┴───┴───┴───┘
     *                |CTL| SPC |WIN|ALT|   |ALT|BSP|ENTER|CTL|
     *                └───┴─────┴───┴───┘   └───┴───┴─────┴───┘
     */
    [0] = LAYOUT_custom(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_DEL,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_F13,
        KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,
                                            KC_LCTL, MO1,     KC_LGUI, KC_LALT,
        //right                                               
                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    EE_CLR,   //<- change to KC_MINS
                 KC_HOME, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
                 KC_END,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
                 KC_MPLY, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO,
        KC_RALT, KC_BSPC, MO2,  KC_RCTL
        ),
    /*  [1]
     * ┌───┬───┬───┬───┬───┬───┐                     ┌───┬───┬───┬───┬───┬───┐
     * │^° │F1 │F2 │F3 │F4 │F5 ├───┐             ┌───┤F6 |F7 |F8 |F9 |F10|F11|
     * ├───┼───┼───┼───┼───┼───┤INS│             |PUP├───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   ├───┤             ├───┤   |   |   |   |   |F12|
     * ├───┼───┼───┼───┼───┼───┤F14│             |PDN├───┼───┼───┼───┼───┼───┤
     * │CAP│MWL│MWD│MWU│MWR│   ├───┤             ├───┤   |-LE|-UP|-DO|-RI|#' |
     * ├───┼───┼───┼───┼───┼───┤MS1│             |MS2├───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   |   ├───┘             └───┤NKR|   |   |   |   |   |
     * └───┴───┴───┴──┬┴──┬┴───┴┬───┬───┐   ┌───┬───┬┴───┴┬──┴┬──┴───┴───┴───┘
     *                |CTL|/MO1\|WIN|ALT|   |ALT|BSP| WIN |CTL|
     *                └───┴─────┴───┴───┘   └───┴───┴─────┴───┘
     */
    [1] = LAYOUT_custom(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_INS,
        KC_CAPS, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO,   KC_F14,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BTN1,
                                            KC_LCTL, _______, KC_LGUI, KC_LALT,
        //right
                          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
                 KC_PGUP, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_F12,
                 KC_PGDN, KC_NO,   KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_BSLS,
                 KC_BTN2, NK_TOGG, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_RALT, KC_BSPC, KC_RGUI, KC_RCTL
        ),
    /*  [2]
     * ┌───┬───┬───┬───┬───┬───┐                     ┌───┬───┬───┬───┬───┬───┐
     * │   │   │   │   │   │   ├───┐             ┌───┤   |   |   |   |   |   |
     * ├───┼───┼───┼───┼───┼───┤   │             |   ├───┼───┼───┼───┼───┼───┤
     * │TOG│MOD│VAI│HUI│SAI│   ├───┤             ├───┤   |   |   |   |   |   |
     * ├───┼───┼───┼───┼───┼───┤   │             |   ├───┼───┼───┼───┼───┼───┤
     * │   │RMO│VAD│HUD│SAD│   ├───┤             ├───┤   |   |   |   |   |   |
     * ├───┼───┼───┼───┼───┼───┤   │             |   ├───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   |   ├───┘             └───┤   |   |   |   |   |   |
     * └───┴───┴───┴──┬┴──┬┴───┴┬───┬───┐   ┌───┬───┬┴───┴┬──┴┬──┴───┴───┴───┘
     *                |   |     |   |   |   |   |   |/MO2\|   |
     *                └───┴─────┴───┴───┘   └───┴───┴─────┴───┘
     */
    [2] = LAYOUT_custom(
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
        ),
    /*  [3]
     * ┌───┬───┬───┬───┬───┬───┐                     ┌───┬───┬───┬───┬───┬───┐
     * │TG3│   │   │   │   │   ├───┐             ┌───┤   |   |   |   |   |   |
     * ├───┼───┼───┼───┼───┼───┤   │             |   ├───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   ├───┤             ├───┤   |   |   |   |   |   |
     * ├───┼───┼───┼───┼───┼───┤   │             |   ├───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   ├───┤             ├───┤   |   |   |   |   |   |
     * ├───┼───┼───┼───┼───┼───┤   │             |   ├───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   |   ├───┘             └───┤   |   |   |   |   |   |
     * └───┴───┴───┴──┬┴──┬┴───┴┬───┬───┐   ┌───┬───┬┴───┴┬──┴┬──┴───┴───┴───┘
     *                |   |     |   |   |   |   |   |     |   |
     *                └───┴─────┴───┴───┘   └───┴───┴─────┴───┘
     */
    [3] = LAYOUT_custom(
        TG(3),   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                                     KC_NO,   KC_NO,   KC_NO,   KC_NO,
        //right
                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                   
                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO
        )
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD,  KC_VOLU),   ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    [1] = {ENCODER_CCW_CW(KC_MS_L,  KC_MS_R),   ENCODER_CCW_CW(KC_MS_U, KC_MS_D)},
    [2] = {ENCODER_CCW_CW(RGB_MOD,  RGB_RMOD),  ENCODER_CCW_CW(KC_NO,   KC_NO)},
    [3] = {ENCODER_CCW_CW(KC_NO,    KC_NO),     ENCODER_CCW_CW(KC_NO,   KC_NO)}
};