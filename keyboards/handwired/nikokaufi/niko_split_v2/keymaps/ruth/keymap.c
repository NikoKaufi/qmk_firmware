// Copyright 2024 Nikolaj Kaufmann
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_german.h"

/* TAP-DANCE*/
#ifdef TAP_DANCE_ENABLE
    enum {
        TD_ESC_AF4
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
        [TD_ESC_AF4] = ACTION_TAP_DANCE_FN(escaltf4)
    };
#endif

/* CUSTOM KEYCODES */
enum custom_keycodes {
    O_ON = SAFE_RANGE,
    O_OFF,
    O_BUP,
    O_BDN
};
#define SPC1 LT(1,KC_SPACE)
#define ALT2 LT(2,KC_LALT)
#define ENT3 LT(3,KC_ENT)
#define ESC_AF4 TD(TD_ESC_AF4)
#define BSP_ADV TD(TD_BSP_ADV)
    // home row mods
#define A_SHI (LSFT_T(KC_A))
#define S_ALT (LALT_T(KC_S))
#define D_STRG (LCTL_T(KC_D))
#define F_WIN (LWIN_T(KC_F))
#define J_WIN (RWIN_T(KC_J))
#define K_STRG (RCTL_T(KC_K))
#define L_ALT (RALT_T(KC_L))
#define OE_SHI (RSFT_T(DE_ODIA))

#define ONE_SHI (LSFT_T(KC_1))
#define ZER_SHI (RSFT_T(DE_0))

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
     * │ESC│ Q │ W │ E │ R │ T |            | Z | U | I | O | P | Ü |
     * ├───┼───┼───┼───┼───┼───┤            |───┼───┼───┼───┼───┼───┤
     * │TAB│ A │ S │ D │ F │ G |            | H | J | K | L | Ö | Ä |
     * ├───┼───┼───┼───┼───┼───┼───┐    ┌───┼───┼───┼───┼───┼───┼───┤
     * │ < │ Y │ X │ C │ V | B |MUT|    |PLP| N | M | , | . | - | ß |
     * └───┴───┴───┴───┼───┼───┼───┤    ├───┼───┼───┼───┴───┴───┴───┘
     *                 |CTL|SPC|ALT|    |AGR|<- |ENT|
     *                 └───┴───┴───┘    └───┴───┴───┘
     */
    [_0_ALPHA] = LAYOUT_split_3x6_3(
        ESC_AF4, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
        KC_TAB,  A_SHI,   S_ALT,   D_STRG,  F_WIN,   KC_G,
        DE_LABK, DE_Y,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,
                                            KC_LCTL, SPC1,    ALT2,
        //right
                 DE_Z,    KC_U,    KC_I,    KC_O,    KC_P,    DE_UDIA,
                 KC_H,    J_WIN,   K_STRG,  L_ALT,   OE_SHI,  DE_ADIA,
        KC_MPLY, KC_N,    KC_M,    KC_COMM, KC_DOT,  DE_MINS, DE_SS,
        KC_RALT, KC_BSPC, ENT3
        ),
    /*  [1]
     * ┌───┬───┬───┬───┬───┬───┐            ┌───┬───┬───┬───┬───┬───┐
     * │GES│   │   │MS↑│   │PgU|            |PgD|   | ↑ |   |   |+*~|
     * ├───┼───┼───┼───┼───┼───┤            ├───┼───┼───┼───┼───┼───┤
     * │CAP│SHI│MS←│MS↓│MS→│Po1|            |End| ← | ↓ | → |SHI|#' |
     * ├───┼───┼───┼───┼───┼───┼───┐    ┌───┼───┼───┼───┼───┼───┼───┤
     * │LCK│   │   │   │   |MS1|MS1|    |MS2|NKR|   |MS3|   |   |   |
     * └───┴───┴───┴───┼───┼───┼───┤    ├───┼───┼───┼───┴───┴───┴───┘
     *                 |CTL|/1\|ALT|    |AGR|<- |Win|
     *                 └───┴───┴───┘    └───┴───┴───┘
     */
    [_1_NAV] = LAYOUT_split_3x6_3( 
        QK_GESC, KC_NO,   KC_NO,   KC_MS_U, KC_NO,   KC_PGUP,
        KC_CAPS, KC_LSFT, KC_MS_L, KC_MS_D, KC_MS_R, KC_HOME,
        QK_LLCK, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BTN1, KC_BTN1,
                                            KC_LCTL, QK_LLCK, KC_LALT,
        //right
                 KC_PGDN, KC_NO,   KC_UP,   KC_NO,   KC_NO,   DE_PLUS,
                 KC_END,  KC_LEFT, KC_DOWN, KC_RGHT, KC_RSFT, DE_HASH,
        KC_BTN2, NK_TOGG, KC_NO,   KC_BTN2, KC_NO,   KC_NO,   KC_NO,
        KC_RALT, KC_BSPC, KC_RGUI
        ),
    /*  [2]
     * ┌───┬───┬───┬───┬───┬───┐            ┌───┬───┬───┬───┬───┬───┐
     * |F12│F1 │F2 │F3 │F4 │F5 │            |F6 |F7 |F8 |F9 |F10|F11|
     * ├───┼───┼───┼───┼───┼───┤            ├───┼───┼───┼───┼───┼───┤
     * │TAB│ 1 │ 2 │ 3 │ 4 │ 5 |            | 6 | 7 | 8 | 9 | 0 |#' |
     * ├───┼───┼───┼───┼───┼───┼───┐    ┌───┼───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   |   |   |    |   |   |   |,; |.: |-_ |   |
     * └───┴───┴───┴───┼───┼───┼───┤    ├───┼───┼───┼───┴───┴───┴───┘
     *                 |   |CTL|/2\|    |AGR|<- |Win|
     *                 └───┴───┴───┘    └───┴───┴───┘
     */
    [_2_NUM] = LAYOUT_split_3x6_3(
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
        KC_TAB,  ONE_SHI, KC_2,    KC_3,    KC_4,    KC_5,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                            KC_NO,   KC_LCTL, _______,
        //right
                 KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
                 KC_6,    KC_7,    KC_8,    KC_9,    ZER_SHI, DE_HASH,
        KC_NO,   KC_NO,   KC_NO,   KC_COMM, KC_DOT,  DE_MINS, KC_NO,
        KC_RALT, KC_BSPC, KC_RGUI
        ),
    /*  [3]
     * ┌───┬───┬───┬───┬───┬───┐            ┌───┬───┬───┬───┬───┬───┐
     * │TOG│MOU│VAU│HUU│SAU│SPU|            |   |   |OOF|OBU|   |   |
     * ├───┼───┼───┼───┼───┼───┤            ├───┼───┼───┼───┼───┼───┤
     * │   │RMO│VAD│HUD│SAD│SPD|            |   |   |OON|OBD|   |   |
     * ├───┼───┼───┼───┼───┼───┼───┐    ┌───┼───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   |   |TOG|    |   |   |   |   |   |   |   |
     * └───┴───┴───┴───┼───┼───┼───┤    ├───┼───┼───┼───┴───┴───┴───┘
     *                 |   |   |   |    |   |   |/3\|
     *                 └───┴───┴───┘    └───┴───┴───┘
     */
    [_3_RGB] = LAYOUT_split_3x6_3(
        RM_TOGG, RM_NEXT, RM_VALU, RM_HUEU, RM_SATU, RM_SPDU,
        KC_NO,   RM_PREV, RM_VALD, RM_HUED, RM_SATD, RM_SPDD,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RM_TOGG,
                                            KC_NO,   KC_NO,   KC_NO,
        //right
                 KC_NO,   KC_NO,   O_ON,    O_BUP,   KC_NO,   KC_NO,
                 KC_NO,   KC_NO,   O_OFF,   O_BDN,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   _______
        )

};

/* ENCODER */
#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_0_ALPHA] = {ENCODER_CCW_CW(KC_VOLD,  KC_VOLU),   ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    [_1_NAV] =   {ENCODER_CCW_CW(KC_WH_L,  KC_WH_R),   ENCODER_CCW_CW(KC_WH_U, KC_WH_D)},
    [_2_NUM] =   {ENCODER_CCW_CW(KC_NO,    KC_NO),     ENCODER_CCW_CW(KC_NO,   KC_NO)},
    [_3_RGB] =   {ENCODER_CCW_CW(RM_PREV,  RM_NEXT),   ENCODER_CCW_CW(KC_NO,   KC_NO)}
    };
#endif //ENCODER_MAP

/* Combo */
enum combo_events {
  DEL,
  DESK_RI,
  DESK_LE,
};
#ifdef COMBO_ENABLE
    const uint16_t PROGMEM spc_bspc_del[]  = {SPC1, KC_BSPC, COMBO_END};
    const uint16_t PROGMEM desktop_right[] = {KC_T, DE_Z, COMBO_END};
    const uint16_t PROGMEM desktop_left[]  = {KC_G, KC_H, COMBO_END};
    combo_t key_combos[] = {
        [DEL] = COMBO(spc_bspc_del, KC_DEL),
        [DESK_RI] = COMBO_ACTION(desktop_right),
        [DESK_LE] = COMBO_ACTION(desktop_left)
    };
    void process_combo_event(uint16_t combo_index, bool pressed) {
        switch(combo_index) {
            case DESK_RI:
                if (pressed) {
                    register_code(KC_LCTL);
                    register_code(KC_LGUI);
                    tap_code(KC_RGHT);
                    unregister_code(KC_LCTL);
                    unregister_code(KC_LGUI);
                }
                break;
            case DESK_LE:
                if (pressed) {
                    register_code(KC_LCTL);
                    register_code(KC_LGUI);
                    tap_code(KC_LEFT);
                    unregister_code(KC_LCTL);
                    unregister_code(KC_LGUI);
                }
                break;
        }
    }
#endif //Combo

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
            case ONE_SHI: return 750;
            case ZER_SHI: return 750;
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
            case ONE_SHI: return true;
            case ZER_SHI: return true;
            default: return false;
        }
    }
#endif //TAP_DANCE

#ifdef OLED_ENABLE
    #include "OLED.c"
#endif //OLED

/* MACROS */
int oled_helligkeit = 128;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        #ifdef OLED_ENABLE
            case O_ON:
                if (record->event.pressed) {
                    oledstatus = 1;
                }else { /*when keycode is released*/ } break;
            case O_OFF:
                if (record->event.pressed) {
                    oledstatus = 0;
                }else { /*when keycode is released*/ } break;
            case O_BUP:
                if (record->event.pressed) {
                    oled_helligkeit = oled_helligkeit + 16;
                    oled_set_brightness(oled_helligkeit);
                }else { /*when keycode is released*/ } break;
            case O_BDN:
                if (record->event.pressed) {
                    oled_helligkeit = oled_helligkeit - 16;
                    oled_set_brightness(oled_helligkeit);
                }else { /*when keycode is released*/ } break;

            //KEYBOARD PET Sneak/Jump
            case KC_LCTL:
            case KC_RCTL:
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

//RGB on active keys
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED &&
                keymap_key_to_keycode(layer, (keypos_t){col,row}) == KC_NO) {
                    rgb_matrix_set_color(index, RGB_OFF);
                }
            }
        }
        const int led_index = 8; // 8 = ESC
            switch(get_highest_layer(layer_state)) {
                case 1:
                    rgb_matrix_set_color(led_index, RGB_BLUE);
                    break;
                case 2:
                    rgb_matrix_set_color(led_index, RGB_RED);
                    break;
                default:
                    break;
            }
    }
    return false;
};