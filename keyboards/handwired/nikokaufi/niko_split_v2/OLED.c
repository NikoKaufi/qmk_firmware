//Rotation
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

/* settings */
#    define MIN_WALK_SPEED      10
#    define MIN_RUN_SPEED       40

/* advanced settings */
#    define ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
#    define ANIM_SIZE           96   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

#include "OLED_pictures.c"

    /* 32 * 32 logo */
static void render_babycat(void) {
    oled_write_raw_P(babycat, sizeof(babycat));
} //ENDE logo

/* Smart Backspace Delete */

// bool            shift_held = false;  //keine Ahnung, evtl ein Keycode
// static uint16_t held_shift = 0;      //keine Ahnung, evtl ein Keycode

/* KEYBOARD PET START */

/* variables */
uint8_t oledstatus = 1;
uint32_t anim_timer = 0;
uint8_t current_frame = 0;
uint8_t extra_frame = 0;

int   current_wpm = 0;
led_t led_usb_state;

bool isSneaking = false;
bool isJumping  = false;
bool showedJump = true;

/* Keyboard Cat */
static void render_cat(int CAT_X, int CAT_Y) {
    /* animation */
    void animate_cat(void) {
        /* jump */
        if (isJumping || !showedJump) {
            /* clear */
            oled_set_cursor(CAT_X, CAT_Y + 2);
            oled_write("     ", false);

            oled_set_cursor(CAT_X, CAT_Y - 1);

            showedJump = true;
        } else {
            /* clear */
            oled_set_cursor(CAT_X, CAT_Y - 1);
            oled_write("     ", false);

            oled_set_cursor(CAT_X, CAT_Y);
        }

        /* switch frame */
        current_frame = (current_frame + 1) % 4;

        /* current */
        if (led_usb_state.caps_lock) {
            current_frame = current_frame % 2;
            oled_write_raw_P(bark[current_frame], ANIM_SIZE);

        } else if (isSneaking) {
            current_frame = current_frame % 2;
            oled_write_raw_P(sneak[current_frame], ANIM_SIZE);

        } else if (current_wpm <= MIN_WALK_SPEED) {
            if (last_input_activity_elapsed() < 30000) {
                oled_write_raw_P(sit[current_frame], ANIM_SIZE);
            } else if (last_input_activity_elapsed() >= 30000) {
                if (last_input_activity_elapsed() > 30000 && last_input_activity_elapsed() < 30120) {
                    extra_frame = 0;
                }
                if (extra_frame <= 25) {
                    oled_write_raw_P(turn_sleep[extra_frame], ANIM_SIZE);
                    extra_frame = extra_frame +1;
                } else {
                    current_frame = current_frame % 3;
                    oled_write_raw_P(sleep[current_frame], ANIM_SIZE);
                }
            }

        } else if (current_wpm <= MIN_RUN_SPEED) {
            oled_write_raw_P(walk[current_frame], ANIM_SIZE);

        } else {
            oled_write_raw_P(run[current_frame], ANIM_SIZE);
        }


    }

    #if OLED_TIMEOUT > 0
    /* the animation prevents the normal timeout from occuring */
    if ((last_input_activity_elapsed() > OLED_TIMEOUT && last_led_activity_elapsed() > OLED_TIMEOUT) || oledstatus == 0) {
        oled_off();
        return;
    } else {
        oled_on();
    }
    #endif

    /* animation timer */
    if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
        anim_timer = timer_read32();
        animate_cat();
    }
} //ENDE Keyboard Pet

//OLED Master
static void print_left(void) {
    /* Print current mode */
    oled_set_cursor(0, 0);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_raw_P(mac_logo, sizeof(mac_logo));
    } else {
        oled_write_raw_P(windows_logo, sizeof(windows_logo));
    }

    // oled_set_cursor(0, 3);
    // switch (get_highest_layer(default_layer_state)) {
    //     case _0_QUERTZ:
    //         oled_write("QWRTZ", false);
    //         break;
    //     case _1_NAV:
    //         oled_write("GAMES", false);
    //         break;
    //     default:
    //         oled_write("UNDEF", false);
    // }

    oled_set_cursor(0, 5);
    oled_write("LAYER", false);

    /* Print current layer */
    oled_set_cursor(0, 6);
    switch (get_highest_layer(layer_state)) {
        case _2_NAV:
        // case _1_NAV:
            oled_write("Navig", false);
            break;
        case _3_NUM:
        // case _2_NUM:
            oled_write("Numbr", false);
            break;
        case _4_RGB:
        // case _3_RGB:
            oled_write("R-G-B", false);
            break;
        default:
            switch (get_highest_layer(default_layer_state)) {
                case _0_QUERTZ:
                    oled_write("Qwrtz", false);
                    break;
                case _1_NEO:
                    oled_write("N-E-O", false);
                    break;
                default:
                    oled_write("Undef", false);
                break;
            }
            break;
    }

    /* caps lock on/off */
    oled_set_cursor(0, 8);
    oled_write("CPSLK", led_usb_state.caps_lock);

    /* KEYBOARD PET */
    render_cat(0, 13);
}//ENDE OLED Master

//OLED Slave
static void print_right(void) {
    oled_set_cursor(0, 1),
    render_babycat();

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

//Bestimmung links, rechts
bool oled_task_user(void) {
    /* KEYBOARD PET VARIABLES*/
    current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

    if (is_keyboard_left()) {
        print_left();
    } else {
        print_right();
    }
    return false;
} //ENDE Master/Slave
