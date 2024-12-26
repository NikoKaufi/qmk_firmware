// Copyright 2024 Nikolaj Kaufmann
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_german.h"

/* TAP-DANCE*/
#ifdef TAP_DANCE_ENABLE
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
#endif

/* CUSTOM KEYCODES */
enum custom_keycodes {
    OFF = SAFE_RANGE,
    STP
};
#define SPC1 LT(1,KC_SPACE)
#define ALT2 LT(2,KC_LALT)
#define ENT_CTL RCTL_T(KC_ENT)
#define ESC_AF4 TD(TD_ESC_AF4)
#define S_SS TD(TD_S_SS)
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
     * │ESC│ Q │ W │ E │ R │ T |            | Z | U | I | O | P | Ü |
     * ├───┼───┼───┼───┼───┼───┤            |───┼───┼───┼───┼───┼───┤
     * │TAB│ A │ S │ D │ F │ G |            | H | J | K | L | Ö | Ä |
     * ├───┼───┼───┼───┼───┼───┼───┐    ┌───┼───┼───┼───┼───┼───┼───┤
     * │ < │ Y │ X │ C │ V | B |MUT|    |PLP| N | M | , | . | - | ß |
     * └───┴───┴───┴───┼───┼───┼───┤    ├───┼───┼───┼───┴───┴───┴───┘
     *                 |WIN|SPC|ALT|    |AGR|<- |ENT|
     *                 └───┴───┴───┘    └───┴───┴───┘
     */
    [_0_ALPHA] = LAYOUT_split_3x6_3(
        ESC_AF4, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
        KC_TAB,  A_SHI,   S_ALT,   D_STRG,  F_WIN,   KC_G,
        DE_LABK, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,
                                            MO(3), SPC1,    KC_LALT,   //KC_LGUI
        //right
                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    EE_CLR,	//DE_UDIA,
                 KC_H,    J_WIN,   K_STRG,  L_ALT,   OE_SHI,  DE_ADIA,
        KC_MPLY, KC_N,    KC_M,    KC_COMM, KC_DOT,  DE_MINS, DE_SS,
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

#ifdef OLED_ENABLE
    //Rotation
    oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

    //Bootloader Nachrichten
    void oled_render_boot(bool bootloader) {
        oled_clear();
        for (int i = 0; i < 16; i++) {
            oled_set_cursor(0, i);
            if (bootloader) {
                oled_write_P(PSTR("Awaiting New Firmware "), false);
            } else {
                oled_write_P(PSTR("Rebooting "), false);
            }
        }
        oled_render_dirty(true);
    }
    // bool shutdown_user(bool jump_to_bootloader) {
    //     oled_render_boot(jump_to_bootloader);
    // }

    //ENDE Bootloader

        /* 32 * 32 logo */
    static void render_logo(void) {
        static const char PROGMEM hell_logo[] = {0x00, 0x80, 0xc0, 0xc0, 0x60, 0x60, 0x30, 0x30, 0x18, 0x1c, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0x78, 0x1e, 0x06, 0x00, 0x0c, 0x1c, 0x18, 0x30, 0x30, 0x60, 0x60, 0xc0, 0xc0, 0x80, 0x00, 0x01, 0x03, 0x07, 0x06, 0x0c, 0x0c, 0x18, 0x18, 0x30, 0x70, 0x60, 0x00, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x60, 0x70, 0x30, 0x18, 0x18, 0x0c, 0x0c, 0x06, 0x07, 0x03, 0x01, 0x00, 0xf8, 0xf8, 0x80, 0x80, 0x80, 0xf8, 0xf8, 0x00, 0x80, 0xc0, 0xc0, 0x40, 0xc0, 0xc0, 0x80, 0x00, 0xf8, 0xf8, 0x00, 0xf8, 0xf8, 0x00, 0x08, 0x38, 0x08, 0x00, 0x38, 0x08, 0x30, 0x08, 0x38, 0x00, 0x1f, 0x1f, 0x01, 0x01, 0x01, 0x1f, 0x1f, 0x00, 0x0f, 0x1f, 0x1a, 0x12, 0x1a, 0x1b, 0x0b, 0x00, 0x1f, 0x1f, 0x00, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

        oled_write_raw_P(hell_logo, sizeof(hell_logo));
    } //ENDE logo

    /* 32 * 14 os logos */
    static const char PROGMEM windows_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbc, 0xbc, 0xbe, 0xbe, 0x00, 0xbe, 0xbe, 0xbf, 0xbf, 0xbf, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x0f, 0x0f, 0x00, 0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    static const char PROGMEM mac_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf0, 0xf6, 0xfb, 0xfb, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x1f, 0x1f, 0x0f, 0x0f, 0x1f, 0x1f, 0x0f, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    /* Smart Backspace Delete */

    // bool            shift_held = false;  //keine Ahnung, evtl ein Keycode
    // static uint16_t held_shift = 0;      //keine Ahnung, evtl ein Keycode

    /* KEYBOARD PET START */

    /* settings */
    #    define MIN_WALK_SPEED      10
    #    define MIN_RUN_SPEED       40

    /* advanced settings */
    #    define ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
    #    define ANIM_SIZE           96   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

    /* timers */
    uint32_t anim_timer = 0;

    /* current frame */
    uint8_t current_frame = 0;

    /* status variables */
    int   current_wpm = 0;
    led_t led_usb_state;

    bool isSneaking = false;
    bool isJumping  = false;
    bool showedJump = true;

    /* Luna */
    static void render_luna(int LUNA_X, int LUNA_Y) {
        /* Sit */
        static const char PROGMEM sit[4][ANIM_SIZE] = {/* 'sit1', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xc0, 0x38, 0x04, 0x02, 0x84, 0x08, 0x08, 0x08, 0x84, 0x02, 0x3c, 0xc0, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0xd0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20,
	0x10, 0x09, 0x06, 0x00, 0x00, 0x01, 0x00, 0x02, 0xf0, 0x09, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x09, 0x0a, 0x0a, 0x0a, 0x12, 0x11, 0x10, 0x10, 0x10,
	0x12, 0x12, 0x1e, 0x10, 0x10, 0x1e, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                                                    },
                                                    /* 'sit2', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x80, 0x70, 0x08, 0x04, 0x08, 0x10, 0x10, 0x10, 0x08, 0x04, 0x78, 0x80, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20,
	0x10, 0x13, 0x0c, 0x00, 0x00, 0x03, 0x00, 0x04, 0xe0, 0x13, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x01, 0x02, 0x04, 0x09, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x12, 0x11, 0x10, 0x10, 0x10,
	0x12, 0x12, 0x1e, 0x10, 0x10, 0x1e, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                                                    },
                                                    /* 'sit3', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x80, 0x70, 0x08, 0x04, 0x08, 0x10, 0x10, 0x10, 0x08, 0x04, 0x78, 0x80, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20,
	0x10, 0x13, 0x0c, 0x00, 0x00, 0x03, 0x00, 0x04, 0xe0, 0x13, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00,
	0x00, 0x02, 0x05, 0x05, 0x09, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x12, 0x11, 0x10, 0x10, 0x10,
	0x12, 0x12, 0x1e, 0x10, 0x10, 0x1e, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                                                    },
                                                    /*'sit4', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xc0, 0x38, 0x04, 0x02, 0x84, 0x08, 0x08, 0x08, 0x84, 0x02, 0x3c, 0xc0, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20,
	0x10, 0x09, 0x06, 0x00, 0x00, 0x01, 0x00, 0x02, 0xf0, 0x09, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x09, 0x0a, 0x0a, 0x0a, 0x0a, 0x12, 0x11, 0x10, 0x10, 0x10,
	0x12, 0x12, 0x1e, 0x10, 0x10, 0x1e, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                                                    }};

        /* Walk */
        static const char PROGMEM walk[4][ANIM_SIZE] = {/* 'walk1', 32x22px */
                                                        {
                                                            0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0xd0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x80, 0x70, 0x08, 0x04, 0x08, 0x10, 0x10, 0x10, 0x08, 0x04, 0x78, 0x80, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0x13, 0xe4, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
	0x08, 0x0b, 0x04, 0x00, 0x00, 0x03, 0x00, 0x04, 0xe0, 0x13, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x1c, 0x10, 0x1e, 0x02, 0x02, 0x02, 0x02,
	0x02, 0x02, 0x1e, 0x10, 0x10, 0x1c, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                                                        },
                                                        /* 'walk2', 32x22px */
                                                        {
                                                            0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0xe8, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xc0, 0x38, 0x04, 0x02, 0x84, 0x08, 0x08, 0x08, 0x84, 0x02, 0x3c, 0xc0, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x89, 0x72, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
	0x04, 0x05, 0x02, 0x00, 0x00, 0x81, 0x00, 0x02, 0x70, 0x89, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x04, 0x0b, 0x08, 0x0f, 0x01, 0x01, 0x01, 0x01,
	0x01, 0x01, 0x0f, 0x08, 0x08, 0x0f, 0x01, 0x06, 0x04, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                                                        },
                                                        /* 'walk3', 32x22px */
                                                        {
                                                            0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0xd0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x80, 0x70, 0x08, 0x04, 0x08, 0x10, 0x10, 0x10, 0x08, 0x04, 0x78, 0x80, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0x13, 0xe4, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
	0x08, 0x0b, 0x04, 0x00, 0x00, 0x03, 0x00, 0x04, 0xe0, 0x13, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x1c, 0x10, 0x1e, 0x02, 0x02, 0x02, 0x02,
	0x02, 0x02, 0x1e, 0x10, 0x10, 0x1c, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                                                        },
                                                        /* 'walk4', 32x22px */
                                                        {
                                                            0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0xe8, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xc0, 0x38, 0x04, 0x02, 0x84, 0x08, 0x08, 0x08, 0x84, 0x02, 0x3c, 0xc0, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x89, 0x72, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
	0x04, 0x05, 0x02, 0x00, 0x40, 0x81, 0x00, 0x02, 0xf0, 0x09, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x08, 0x08, 0x0e, 0x03, 0x05, 0x05, 0x07, 0x01, 0x01,
	0x01, 0x01, 0x01, 0x02, 0x04, 0x04, 0x0f, 0x08, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                                                        }};

        /* Run */
        static const char PROGMEM run[4][ANIM_SIZE] = {/* 'run1', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0xd0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x80, 0x70, 0x08, 0x04, 0x08, 0x10, 0x10, 0x10, 0x08, 0x04, 0x78, 0x80, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0x13, 0xe4, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
	0x08, 0x0b, 0x04, 0x00, 0x00, 0x03, 0x00, 0x04, 0xe0, 0x13, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x1c, 0x10, 0x1e, 0x02, 0x02, 0x02, 0x02,
	0x02, 0x02, 0x1e, 0x10, 0x10, 0x1c, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                                                    },

                                                    /* 'run2', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0xe8, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xc0, 0x38, 0x04, 0x02, 0x84, 0x08, 0x08, 0x08, 0x84, 0x02, 0x3c, 0xc0, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x01, 0xc2, 0x24, 0x19, 0x82, 0x84, 0x04, 0x84, 0x84, 0x84, 0x84, 0x84,
	0x84, 0x85, 0x82, 0x00, 0x00, 0xc1, 0xc0, 0x82, 0x10, 0x29, 0x44, 0x82, 0x01, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x02, 0x05, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x07, 0x04, 0x04, 0x07, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00
                                                    },
                                                    /* 'run3', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0xd0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x80, 0x70, 0x08, 0x04, 0x08, 0x10, 0x10, 0x10, 0x08, 0x04, 0x78, 0x80, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0x13, 0xe4, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
	0x08, 0x0b, 0x04, 0x00, 0x00, 0x03, 0x00, 0x04, 0xe0, 0x13, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x1c, 0x10, 0x1e, 0x02, 0x02, 0x02, 0x02,
	0x02, 0x02, 0x1e, 0x10, 0x10, 0x1c, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                                                    },
                                                    /* 'run4', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0xe8, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xc0, 0x38, 0x04, 0x02, 0x84, 0x08, 0x08, 0x08, 0x84, 0x02, 0x3c, 0xc0, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x84, 0x79, 0x02, 0x04, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84,
	0x84, 0x85, 0x82, 0x00, 0x20, 0x41, 0x80, 0x02, 0xf0, 0x09, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x04, 0x03, 0x01, 0x02, 0x02, 0x03, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x01, 0x01, 0x02, 0x03, 0x04, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                                                    }};

        /* Bark */
        static const char PROGMEM bark[2][ANIM_SIZE] = {/* 'bark1', 32x22px */
                                                        {
                                                            0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                        },

                                                        /* 'bark2', 32x22px */
                                                        {
                                                            0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                        }};

        /* Sneak */
        static const char PROGMEM sneak[2][ANIM_SIZE] = {/* 'sneak1', 32x22px */
                                                        {
                                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04, 0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06, 0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
                                                        },

                                                        /* 'sneak2', 32x22px */
                                                        {
                                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04, 0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                        }};

        /* animation */
        void animate_luna(void) {
            /* jump */
            if (isJumping || !showedJump) {
                /* clear */
                oled_set_cursor(LUNA_X, LUNA_Y + 2);
                oled_write("     ", false);

                oled_set_cursor(LUNA_X, LUNA_Y - 1);

                showedJump = true;
            } else {
                /* clear */
                oled_set_cursor(LUNA_X, LUNA_Y - 1);
                oled_write("     ", false);

                oled_set_cursor(LUNA_X, LUNA_Y);
            }

            /* switch frame */
            current_frame = (current_frame + 1) % 4;

            /* current status */
            if (led_usb_state.caps_lock) {
                oled_write_raw_P(bark[current_frame], ANIM_SIZE);

            } else if (isSneaking) {
                oled_write_raw_P(sneak[current_frame], ANIM_SIZE);

            } else if (current_wpm <= MIN_WALK_SPEED) {
                oled_write_raw_P(sit[current_frame], ANIM_SIZE);

            } else if (current_wpm <= MIN_RUN_SPEED) {
                oled_write_raw_P(walk[current_frame], ANIM_SIZE);

            } else {
                oled_write_raw_P(run[current_frame], ANIM_SIZE);
            }
        }

        #if OLED_TIMEOUT > 0
        /* the animation prevents the normal timeout from occuring */
        if (last_input_activity_elapsed() > OLED_TIMEOUT && last_led_activity_elapsed() > OLED_TIMEOUT) {
            oled_off();
            return;
        } else {
            oled_on();
        }
        #endif

        /* animation timer */
        if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
            anim_timer = timer_read32();
            animate_luna();
        }
    } //ENDE Luna

    /* KEYBOARD PET END */

    //OLED Slave Side
    static void print_logo_narrow(void) {
        render_logo();

        /* wpm counter */
        uint8_t n = get_current_wpm();
        char    wpm_str[4];
        oled_set_cursor(0, 14);
        wpm_str[3] = '\0';
        wpm_str[2] = '0' + n % 10;
        wpm_str[1] = '0' + (n /= 10) % 10;
        wpm_str[0] = '0' + n / 10;
        oled_write(wpm_str, false);

        oled_set_cursor(0, 15);
        oled_write(" wpm", false);
    } //ENDE OLED Slave

    //OLED Master Side
    static void print_status_narrow(void) {
        /* Print current mode */
        oled_set_cursor(0, 0);
        if (keymap_config.swap_lctl_lgui) {
            oled_write_raw_P(mac_logo, sizeof(mac_logo));
        } else {
            oled_write_raw_P(windows_logo, sizeof(windows_logo));
        }

        oled_set_cursor(0, 3);

        switch (get_highest_layer(default_layer_state)) {
            case _0_ALPHA:
                oled_write("QWRTZ", false);
                break;
            case _1_NAV:
                oled_write("GAMES", false);
                break;
            default:
                oled_write("UNDEF", false);
        }

        oled_set_cursor(0, 5);

        /* Print current layer */
        oled_write("LAYER", false);

        oled_set_cursor(0, 6);

        switch (get_highest_layer(layer_state)) {
            case _0_ALPHA:
                oled_write("Alpha", false);
                break;
            case _1_NAV:
                oled_write("Navig", false);
                break;
            case _2_NUM:
                oled_write("Numbr", false);
                break;
            case _3_RGB:
                oled_write("RGB", false);
                break;
            default:
                oled_write("Undef", false);
        }

        /* caps lock on/off */
        oled_set_cursor(0, 8);
        oled_write("CPSLK", led_usb_state.caps_lock);

        /* KEYBOARD PET RENDER START */

        render_luna(0, 13);

        /* KEYBOARD PET RENDER END */
    }//ENDE OLED Master

    //Variablen + Bestimmung Master/Slave
    bool oled_task_user(void) {
        /* KEYBOARD PET VARIABLES START */

        current_wpm   = get_current_wpm();
        led_usb_state = host_keyboard_led_state();

        /* KEYBOARD PET VARIABLES END */

        if (is_keyboard_master()) {
            print_status_narrow();
        } else {
            print_logo_narrow();
        }
        return false;
    } //ENDE Variablen + Master/Slave

#endif //OLED

/* MACROS */
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

        //KEYBOARD PET STATUS START
        #ifdef OLED_ENABLE
            case KC_LCTL:
            case KC_RCTL:
                if (record->event.pressed) {
                    isSneaking = true;
                } else {
                    isSneaking = false;
                }
                break;
            case KC_SPC:
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
    //         case KC_RAISE:
    //             if (record->event.pressed) {
    //                 layer_on(_RAISE);
    //                 update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //             } else {
    //                 layer_off(_RAISE);
    //                 update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //             }
    //             return false;
    //         case KC_ADJUST:
    //             if (record->event.pressed) {
    //                 layer_on(_ADJUST);
    //             } else {
    //                 layer_off(_ADJUST);
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
    //                     unregister_code(KC_RIGHT);
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
