// Copyright 2025 Nikolaj Kaufmann
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "sendstring_german.h"

/* TAP-DANCE*/
#ifdef TAP_DANCE_ENABLE
    enum {
        TD_ESC_AF4,
        TD_HASH_AP
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
    };
    void double_apostroph_left(tap_dance_state_t *state, void *user_data) {
        if (state->count >= 2) {
            SEND_STRING("''" SS_TAP(X_LEFT));
            reset_tap_dance(state);
        }
        else {
            tap_code(DE_HASH);
        }
    };

    tap_dance_action_t tap_dance_actions[] = {
        [TD_ESC_AF4] = ACTION_TAP_DANCE_FN(escaltf4),
        [TD_HASH_AP] = ACTION_TAP_DANCE_FN(double_apostroph_left)
    };
#endif

/* CUSTOM KEYCODES */
enum custom_keycodes {
    OFF = SAFE_RANGE,
    STP,
    O_ON,
    O_OFF,
    O_BUP,
    O_BDN
};
#define SPC2 LT(2,KC_SPACE)
#define ALT3 LT(3,KC_LALT)
#define ENT4 LT(4,KC_ENT)
#define ESC_AF4 TD(TD_ESC_AF4)
#define HASH_AP TD(TD_HASH_AP)
    // home row mods
#define A_SHI (LSFT_T(KC_A))
#define S_ALT (LALT_T(KC_S))
#define D_STRG (LCTL_T(KC_D))
#define F_WIN (LWIN_T(KC_F))
#define J_WIN (RWIN_T(KC_J))
#define K_STRG (RCTL_T(KC_K))
#define L_ALT (RALT_T(KC_L))
#define OE_SHI (RSFT_T(DE_ODIA))
    // for NEO
#define H_WIN (LWIN_T(KC_H))
#define I_ALT (LALT_T(KC_I))
#define E_STRG (LCTL_T(KC_E))
// #define A_SHI
#define T_SHI (RSFT_T(KC_T))
#define R_STRG (RCTL_T(KC_R))
#define N_ALT (RALT_T(KC_N))
#define S_WIN (RWIN_T(KC_S))

#define ONE_SHI (LSFT_T(KC_1))
#define ZER_SHI (RSFT_T(DE_0))

/* LAYER NAMES */
enum layer_names {
    _0_QUERTZ,
    _1_NEO,
    _2_NAV,
    _3_NUM,
    _4_RGB

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
    [_0_QUERTZ] = LAYOUT_split_3x6_3(
        ESC_AF4, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
        KC_TAB,  A_SHI,   S_ALT,   D_STRG,  F_WIN,   KC_G,
        DE_LABK, DE_Y,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,
                                            KC_LCTL, SPC2,    ALT3,
        //right
                 DE_Z,    KC_U,    KC_I,    KC_O,    KC_P,    DE_UDIA,
                 KC_H,    J_WIN,   K_STRG,  L_ALT,   OE_SHI,  DE_ADIA,
        KC_MPLY, KC_N,    KC_M,    KC_COMM, KC_DOT,  DE_MINS, DE_SS,
        KC_RALT, KC_BSPC, ENT4
        ),
    /*  [1]
     * ┌───┬───┬───┬───┬───┬───┐            ┌───┬───┬───┬───┬───┬───┐
     * │ESC│ K │ U │ Ü │ . │ Ä |            | V | G | C | L | J | F |
     * ├───┼───┼───┼───┼───┼───┤            |───┼───┼───┼───┼───┼───┤
     * │TAB│ H │ I │ E │ A │ O |            | D | T | R | N | S | ß |
     * ├───┼───┼───┼───┼───┼───┼───┐    ┌───┼───┼───┼───┼───┼───┼───┤
     * │ < │ X │ Y │ Ö │ , | Q |MUT|    |PLP| B | P | W | M | Z | - |
     * └───┴───┴───┴───┼───┼───┼───┤    ├───┼───┼───┼───┴───┴───┴───┘
     *                 |CTL|SPC|ALT|    |AGR|<- |ENT|
     *                 └───┴───┴───┘    └───┴───┴───┘
     */
    [_1_NEO] = LAYOUT_split_3x6_3(
        ESC_AF4, KC_K,    KC_U,    DE_UDIA, KC_DOT,  DE_ADIA,
        KC_TAB,  H_WIN,   I_ALT,   E_STRG,  A_SHI,   KC_O,
        DE_LABK, KC_X,    DE_Y,    DE_ODIA, KC_COMM, KC_Q,    KC_MUTE,
                                            KC_LCTL, SPC2,    ALT3,
        //right
                 KC_V,    KC_G,    KC_C,    KC_L,    KC_J,    KC_F,
                 KC_D,    T_SHI,   R_STRG,  N_ALT,   S_WIN,   DE_SS,
        KC_MPLY, KC_B,    KC_P,    KC_W,    KC_M,    DE_Z,    DE_MINS,
        KC_RALT, KC_BSPC, ENT4
    ),
    /*  [2]
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
    [_2_NAV] = LAYOUT_split_3x6_3(
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
    /*  [3]
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
    [_3_NUM] = LAYOUT_split_3x6_3(
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
        KC_TAB,  ONE_SHI, KC_2,    KC_3,    KC_4,    KC_5,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                            KC_NO,   KC_LCTL, _______,
        //right
                 KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
                 KC_6,    KC_7,    KC_8,    KC_9,    ZER_SHI, HASH_AP,
        KC_NO,   KC_NO,   KC_NO,   KC_COMM, KC_DOT,  DE_MINS, KC_NO,
        KC_RALT, KC_BSPC, KC_RGUI
        ),
    /*  [4]
     * ┌───┬───┬───┬───┬───┬───┐            ┌───┬───┬───┬───┬───┬───┐
     * │TOG│MOU│VAU│HUU│SAU│SPU|            |   |   |OOF|OBU|   |   |
     * ├───┼───┼───┼───┼───┼───┤            ├───┼───┼───┼───┼───┼───┤
     * │   │RMO│VAD│HUD│SAD│SPD|            |   |   |OON|OBD|   |   |
     * ├───┼───┼───┼───┼───┼───┼───┐    ┌───┼───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   |   |TOG|    |   |   |   |   |   |   |   |
     * └───┴───┴───┴───┼───┼───┼───┤    ├───┼───┼───┼───┴───┴───┴───┘
     *                 |STP|OFF|   |    |   |   |/3\|
     *                 └───┴───┴───┘    └───┴───┴───┘
     */
    [_4_RGB] = LAYOUT_split_3x6_3(
        RM_TOGG, RM_NEXT, RM_VALU, RM_HUEU, RM_SATU, RM_SPDU,
        KC_NO,   RM_PREV, RM_VALD, RM_HUED, RM_SATD, RM_SPDD,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RM_TOGG,
                                            STP,     OFF,     KC_NO,
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
    [_0_QUERTZ] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU),   ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    [_1_NEO] =    {ENCODER_CCW_CW(KC_VOLD,  KC_VOLU),  ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    [_2_NAV] =    {ENCODER_CCW_CW(KC_WH_L,  KC_WH_R),  ENCODER_CCW_CW(KC_WH_U, KC_WH_D)},
    [_3_NUM] =    {ENCODER_CCW_CW(KC_NO,    KC_NO),    ENCODER_CCW_CW(KC_NO,   KC_NO)},
    [_4_RGB] =    {ENCODER_CCW_CW(RM_PREV,  RM_NEXT),  ENCODER_CCW_CW(KC_NO,   KC_NO)}
    };
#endif //ENCODER_MAP

/* Combo */
enum combo_events {
    DEL,
    LEADER,
    CAPWD,
    DESK_RI,
    DESK_LE,
    NEO_ON,
    NEO_OFF,
};
#ifdef COMBO_ENABLE
    const uint16_t PROGMEM spc_bspc_del[]  = {SPC2,    KC_BSPC, COMBO_END};
    const uint16_t PROGMEM leader_key[]    = {F_WIN,   J_WIN,   COMBO_END};
    const uint16_t PROGMEM caps_word[]     = {A_SHI,   OE_SHI,  COMBO_END};
    const uint16_t PROGMEM desktop_right[] = {KC_G,    DE_H,    COMBO_END};
    const uint16_t PROGMEM desktop_left[]  = {KC_B,    KC_N,    COMBO_END};
    const uint16_t PROGMEM neo_on[]        = {ESC_AF4, DE_UDIA, COMBO_END};
    const uint16_t PROGMEM neo_off[]       = {ESC_AF4, KC_F,    COMBO_END};
    combo_t key_combos[] = {
        [DEL] = COMBO(spc_bspc_del, KC_DEL),
        [LEADER]  = COMBO(leader_key, QK_LEAD),
        [CAPWD]   = COMBO(caps_word, CW_TOGG),
        [DESK_RI] = COMBO_ACTION(desktop_right),
        [DESK_LE] = COMBO_ACTION(desktop_left),
        [NEO_ON]  = COMBO(neo_on, DF(1)),
        [NEO_OFF] = COMBO(neo_off, DF(0))
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

/* LEADER (KEY) */
#ifdef LEADER_ENABLE
    void leader_end_user(void) {
        if (leader_sequence_one_key(KC_A)) {
            SEND_STRING("select top 100 * from ");
        } else if (leader_sequence_one_key(KC_S)) {
            SEND_STRING("select ");
        } else if (leader_sequence_two_keys(KC_S, KC_S)) {
            SEND_STRING("STORNODAT is null ");
        } else if (leader_sequence_one_key(KC_F)) {
            SEND_STRING("from ");
        } else if (leader_sequence_one_key(KC_W)) {
            SEND_STRING("where ");
        } else if (leader_sequence_one_key(KC_I)) {
            SEND_STRING("inner join ");
        } else if (leader_sequence_one_key(KC_J)) {
            SEND_STRING("left join ");
        }
    }
#endif

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
            case SPC2: return true;
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
#ifdef OLED_ENABLE
    int oled_helligkeit = 128;
    bool process_record_user(uint16_t keycode, keyrecord_t *record) {
        switch (keycode) {
            // case OFF: //Herunterfahren
            //     if (record->event.pressed) {
            //         SEND_STRING(SS_LGUI("r"));
            //         SEND_STRING(SS_DELAY(300));
            //         SEND_STRING("shutdown -s -t 10 -f -c "Herunterfahren in 10 Sekunden!"");
            //         SEND_STRING(SS_DELAY(300));
            //         SEND_STRING(SS_TAP(X_ENTER));
            //     }else { /*when keycode is released*/ } break;
            // case STP: //Herunterfahren abbrechen
            //     if (record->event.pressed) {
            //         SEND_STRING(SS_LGUI("r"));
            //         SEND_STRING(SS_DELAY(300));
            //         SEND_STRING("shutdown -a");
            //         SEND_STRING(SS_DELAY(300));
            //         SEND_STRING(SS_TAP(X_ENTER));
            //     }else { /*when keycode is released*/ } break;

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
                case SPC2:
                    if (record->event.pressed) {
                        isJumping  = true;
                        showedJump = false;
                    } else {
                        isJumping = false;
                    }
                    break;      //KEYBOARD PET STATUS END

        }
        return true;
    }; //ENDE MACROS
#endif //OLED

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
                case 2:
                    rgb_matrix_set_color(led_index, RGB_BLUE);
                    break;
                case 3:
                    rgb_matrix_set_color(led_index, RGB_RED);
                    break;
                default:
                    break;
            }
    }
    return false;
};













/* IDK, nur kopiert */

    // bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    //         case held_shift:
    //             if (record->event.pressed) {
    //                 set_single_persistent_default_layer(_QWERTY);
    //             }
    //             return false;
    //         case KC_GAMING:
    //             if (record->event.pressed) {
    //                 set_single_persistent_default_layer(_GAMING);
    //             }
    //             return false;
    //         case KC_LOWER:
    //             if (record->event.pressed) {
    //                 layer_on(_LOWER);
    //                 update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //             } else {
    //                 layer_off(_LOWER);
    //                 update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //             }
    //             return false;
    //         case KC_PRVWD:
    //             if (record->event.pressed) {
    //                 if (keymap_config.swap_lctl_lgui) {
    //                     register_mods(mod_config(MOD_LALT));
    //                     register_code(KC_LEFT);
    //                 } else {
    //                     register_mods(mod_config(MOD_LCTL));
    //                     register_code(KC_LEFT);
    //                 }
    //             } else {
    //                 if (keymap_config.swap_lctl_lgui) {
    //                     unregister_mods(mod_config(MOD_LALT));
    //                     unregister_code(KC_LEFT);
    //                 } else {
    //                     unregister_mods(mod_config(MOD_LCTL));
    //                     unregister_code(KC_LEFT);
    //                 }
    //             }
    //             break;
    //         case KC_NXTWD:
    //             if (record->event.pressed) {
    //                 if (keymap_config.swap_lctl_lgui) {
    //                     register_mods(mod_config(MOD_LALT));
    //                     register_code(KC_RIGHT);
    //                 } else {
    //                     register_mods(mod_config(MOD_LCTL));
    //                     register_code(KC_RIGHT);
    //                 }
    //             } else {
    //                 if (keymap_config.swap_lctl_lgui) {
    //                     unregister_mods(mod_config(MOD_LALT));
    //                     unregister_code(KC_RIGHT);
    //                 } else {
    //                     unregister_mods(mod_config(MOD_LCTL));
    //                     unregister_code(KC_RIGHT);g
    //                 }
    //             }
    //             break;
    //         case KC_LSTRT:
    //             if (record->event.pressed) {
    //                 if (keymap_config.swap_lctl_lgui) {
    //                     /* CMD-arrow on Mac, but we have CTL and GUI swapped */
    //                     register_mods(mod_config(MOD_LCTL));
    //                     register_code(KC_LEFT);
    //                 } else {
    //                     register_code(KC_HOME);
    //                 }
    //             } else {
    //                 if (keymap_config.swap_lctl_lgui) {
    //                     unregister_mods(mod_config(MOD_LCTL));
    //                     unregister_code(KC_LEFT);
    //                 } else {
    //                     unregister_code(KC_HOME);
    //                 }
    //             }
    //             break;
    //         case KC_LEND:
    //             if (record->event.pressed) {
    //                 if (keymap_config.swap_lctl_lgui) {
    //                     /* CMD-arrow on Mac, but we have CTL and GUI swapped */
    //                     register_mods(mod_config(MOD_LCTL));
    //                     register_code(KC_RIGHT);
    //                 } else {
    //                     register_code(KC_END);
    //                 }
    //             } else {
    //                 if (keymap_config.swap_lctl_lgui) {
    //                     unregister_mods(mod_config(MOD_LCTL));
    //                     unregister_code(KC_RIGHT);
    //                 } else {
    //                     unregister_code(KC_END);
    //                 }
    //             }
    //             break;
    //         case KC_DLINE:
    //             if (record->event.pressed) {
    //                 register_mods(mod_config(MOD_LCTL));
    //                 register_code(KC_BSPC);
    //             } else {
    //                 unregister_mods(mod_config(MOD_LCTL));
    //                 unregister_code(KC_BSPC);
    //             }
    //             break;
    //         case KC_COPY:
    //             if (record->event.pressed) {
    //                 register_mods(mod_config(MOD_LCTL));
    //                 register_code(KC_C);
    //             } else {
    //                 unregister_mods(mod_config(MOD_LCTL));
    //                 unregister_code(KC_C);
    //             }
    //             return false;
    //         case KC_PASTE:
    //             if (record->event.pressed) {
    //                 register_mods(mod_config(MOD_LCTL));
    //                 register_code(KC_V);
    //             } else {
    //                 unregister_mods(mod_config(MOD_LCTL));
    //                 unregister_code(KC_V);
    //             }
    //             return false;
    //         case KC_CUT:
    //             if (record->event.pressed) {
    //                 register_mods(mod_config(MOD_LCTL));
    //                 register_code(KC_X);
    //             } else {
    //                 unregister_mods(mod_config(MOD_LCTL));
    //                 unregister_code(KC_X);
    //             }
    //             return false;
    //             break;
    //         case KC_UNDO:
    //             if (record->event.pressed) {
    //                 register_mods(mod_config(MOD_LCTL));
    //                 register_code(KC_Z);
    //             } else {
    //                 unregister_mods(mod_config(MOD_LCTL));
    //                 unregister_code(KC_Z);
    //             }
    //             return false;

    //             /* Smart Backspace Delete */

    //         case KC_RSFT:
    //         case KC_LSFT:
    //             shift_held = record->event.pressed;
    //             held_shift = keycode;
    //             break;
    //         case KC_BSPC_DEL:
    //             if (record->event.pressed) {
    //                 if (shift_held) {
    //                     unregister_code(held_shift);
    //                     register_code(KC_DEL);
    //                 } else {
    //                     register_code(KC_BSPC);
    //                 }
    //             } else {
    //                 unregister_code(KC_DEL);
    //                 unregister_code(KC_BSPC);
    //                 if (shift_held) {
    //                     register_code(held_shift);
    //                 }
    //             }
    //             return false;

    //             /* LAYER */

    //         case KC_LAYER:
    //             if (record->event.pressed) {
    //                 if (shift_held) {
    //                     if (record->event.pressed) {
    //                         if (get_highest_layer(default_layer_state) == _QWERTY) {
    //                             set_single_persistent_default_layer(_GAMING);
    //                         } else if (get_highest_layer(default_layer_state) == _GAMING) {
    //                             set_single_persistent_default_layer(_QWERTY);
    //                         }
    //                     }
    //                 } else {
    //                     layer_on(_LOWER);
    //                     update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //                 }
    //             } else {
    //                 layer_off(_LOWER);
    //                 update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //             }
    //             return false;
    //     }
    //     return true;
    // }
