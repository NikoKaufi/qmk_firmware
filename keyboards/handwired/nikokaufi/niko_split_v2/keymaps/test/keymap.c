// Copyright 2024 Nikolaj Kaufmann
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_german.h"

/* TAP-DANCE*/
#ifdef TAP_DANCE_ENABLE
    enum {
        TD_ESC_AF4
        // TD_S_SS
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
    // void sss(tap_dance_state_t *state, void *user_data) {
    //     if (state->count >= 3) {
    //         tap_code(DE_SS);
    //     }
    //     else {
    //         tap_code(KC_S);
    //     }
    // }
    tap_dance_action_t tap_dance_actions[] = {
        [TD_ESC_AF4] = ACTION_TAP_DANCE_FN(escaltf4)
        // [TD_S_SS] = ACTION_TAP_DANCE_FN(sss)
    };
#endif

/* CUSTOM KEYCODES */
enum custom_keycodes {
    OFF = SAFE_RANGE,
    STP
};
#define SPC1 LT(1,KC_SPACE)
#define ALT2 LT(2,KC_LALT)
#define ENT3 LT(3,KC_ENT)
#define ESC_AF4 TD(TD_ESC_AF4)
// #define S_SS TD(TD_S_SS)
    // home row mods
#define A_SHI (LSFT_T(KC_A))
#define S_ALT (LALT_T(KC_S))
#define D_STRG (LCTL_T(KC_D))
#define F_WIN (LWIN_T(KC_F))
#define J_WIN (RWIN_T(KC_J))
#define K_STRG (RCTL_T(KC_K))
#define L_ALT (RALT_T(KC_L))
#define OE_SHI (RSFT_T(DE_ODIA))

/* LAYER NAMES */
enum layer_names {
    _0_ALPHA,
    _1_NAV,
    _2_NUM,
    _3_RGB,
};
/* KEYMAP */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*  [0]
     * ┌───┬───┬───┬───┬───┬───┐            ┌───┬───┬───┬───┬───┬───┐
     * │ 1 │ Q │ W │ E │ R │ T |            | Z | U | I | O | P | Ü |
     * ├───┼───┼───┼───┼───┼───┤            |───┼───┼───┼───┼───┼───┤
     * │ 2 │ A │ S │ D │ F │ G |            | H | J | K | L | Ö | Ä |
     * ├───┼───┼───┼───┼───┼───┼───┐    ┌───┼───┼───┼───┼───┼───┼───┤
     * │ 3 │ Y │ X │ C │ V | B | 5 |    | 6 | N | M | , | . | - | ß |
     * └───┴───┴───┴───┼───┼───┼───┤    ├───┼───┼───┼───┴───┴───┴───┘
     *                 | 4 |SPC|ALT|    |AGR|<- |ENT|
     *                 └───┴───┴───┘    └───┴───┴───┘
     */
    [_0_ALPHA] = LAYOUT_split_3x6_3(
        KC_1,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
        KC_2,    A_SHI,   S_ALT,   D_STRG,  F_WIN,   KC_G,
        KC_3,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_5,
                                            KC_4,    SPC1,    KC_LALT,
        //right
                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    DE_UDIA,
                 KC_H,    J_WIN,   K_STRG,  L_ALT,   OE_SHI,  DE_ADIA,
        KC_6,    KC_N,    KC_M,    KC_COMM, KC_DOT,  DE_MINS, DE_SS,
        KC_RALT, KC_BSPC, KC_ENT
        ),
    /*  [1]
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
    [_1_NAV] = LAYOUT_split_3x6_3(
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
    [_2_NUM] = LAYOUT_split_3x6_3(
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
    [_3_RGB] = LAYOUT_split_3x6_3(
        RM_TOGG, RM_NEXT, RM_VALU, RM_HUEU, RM_SATU, RM_SPDU,
        KC_NO,   RM_PREV, RM_VALD, RM_HUED, RM_SATD, RM_SPDD,
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
#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_0_ALPHA] = {ENCODER_CCW_CW(KC_VOLD,  KC_VOLU),   ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    [_1_NAV] =   {ENCODER_CCW_CW(KC_WH_L,  KC_WH_R),   ENCODER_CCW_CW(KC_WH_U, KC_WH_D)},
    [_2_NUM] =   {ENCODER_CCW_CW(KC_NO,    KC_NO),     ENCODER_CCW_CW(KC_NO,   KC_NO)},
    [_3_RGB] =   {ENCODER_CCW_CW(KC_NO,    KC_NO),     ENCODER_CCW_CW(KC_NO,   KC_NO)}
    };
#endif //ENCODER_MAP

/* TAP-DANCE */
#ifdef TAP_DANCE_ENABLE
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {  //custom Tapping-Term pro Taste
    switch (keycode) {
        case A_SHI: return 750;
        case OE_SHI: return 750;
        case S_ALT: return 750;
        case L_ALT: return 750;
        case D_STRG: return 750;
        case K_STRG: return 750;
        default: return TAPPING_TERM; //200
    }
}
bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) { //2. Belegung wird nur aktiv, wenn weitere Taste gedrückt
    switch (keycode) {
        case A_SHI: return true;
        case OE_SHI: return true;
        case S_ALT: return true;
        case L_ALT: return true;
        case D_STRG: return true;
        case K_STRG: return true;
        case SPC1: return true;
        default: return false;
    }
}
#endif //TAP_DANCE

#ifdef OLED_ENABLE
    #include "OLED.c"
#endif //OLED

/* MACROS */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OFF: //Herunterfahren
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
        case STP: //Herunterfahren abbrechen
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

        //KEYBOARD PET Sneak/Jump
        #ifdef OLED_ENABLE
            case D_STRG:
            case K_STRG:
                if (record->event.pressed) {
                    isSneaking = true;
                } else {
                    isSneaking = false;
                }
                break;
            case SPC1:
                if (record->event.pressed) {
                    isJumping  = true;
                    showedJump = false;
                } else {
                    isJumping = false;
                }
                break;      //KEYBOARD PET STATUS END
        #endif //OLED
    }
    return true;
}; //ENDE MACROS
