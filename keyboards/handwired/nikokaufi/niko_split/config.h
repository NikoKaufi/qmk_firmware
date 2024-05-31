// Copyright 2024 Nikolaj Kaufmann (@NikoKaufi)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

/* Encoder Configuration */
#ifdef ENCODER_ENABLE
    //left
    #define ENCODERS_PAD_A { GP14 }
    #define ENCODERS_PAD_B { GP15 }
    #define ENCODER_RESOLUTION 4
    #define ENCODER_DEFAULT_POS 0x3
    // JUST if other pins are used on the right side:
    #define ENCODERS_PAD_A_RIGHT { GP15 }
    #define ENCODERS_PAD_B_RIGHT { GP14 }
    #define ENCODER_RESOLUTIONS_RIGHT 4
    #define ENCODER_DEFAULT_POS_RIGHT 0x3
#endif

/* JUST IF other pins are used on the right side: */
    // #define MATRIX_COL_PINS_RIGHT { GP8, GP7, GP6, GP5, GP4, GP3, GP2 }
    // #define MATRIX_ROW_PINS_RIGHT { GP13, GP12, GP11, GP10, GP9 }

/* serial communication between halfs */
#define SERIAL_USART_FULL_DUPLEX    // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN GP0     // USART TX pin      //5v=1, gnd=2, GP1=3, GP0=4
#define SERIAL_USART_RX_PIN GP1     // USART RX pin
    // #define SERIAL_PIO_USE_PIO1      //changes the state machine to PIO1 (standard PIO0)

#define EE_HANDS        //define right/left side by EEPROM/flash option

#define SPLIT_USB_TIMEOUT 2000      //This sets the maximum timeout when detecting master/slave
#define SPLIT_USB_TIMEOUT_POLL 10   // This sets the poll frequency when detecting master/slave

#define SPLIT_WATCHDOG_ENABLE       //reboot the keyboard if no successful communication occurs within:
#define SPLIT_WATCHDOG_TIMEOUT 2500

/* bootmagic for right half */
#define BOOTMAGIC_ROW_RIGHT 5
#define BOOTMAGIC_COLUMN_RIGHT 6

/* Tap-Dance */
#define TAPPING_TERM 175

/* rgb general */
#define WS2812_DI_PIN GP16       //PIN for RGB
#define RGBLIGHT_LED_COUNT 2     //LED_COUNT total
#define WS2812_BYTE_ORDER WS2812_BYTE_ORDER_RGB     //changing byte order
#define RGBLIGHT_SLEEP           //turn off LED, when host is in sleep
    // #define RGBLIGHT_HUE_STEP 8  //8=default
    // #define RGBLIGHT_SAT_STEP 17 //17=default?
    // #define RGBLIGHT_VAL_STEP 17 //17=default?
    // #define RGBLIGHT_LIMIT_VAL 255   //max brightness, 255=default
#define RGBLIGHT_DEFAULT_HUE 169 //color after flashing (0=red, 85=green, 169=blue) (https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgblight.md)
    // #define RGBLIGHT_DEFAULT_VAL 255 //brighness after flashing
    // #define RGBLIGHT_DEFAULT_SAT 0   //saturation after flashing, UINT8_MAX (255)=default

/* rgb split */
#define RGBLED_SPLIT { 1, 1 }   //the number of LEDs connected on each half
#define RGBLIGHT_SPLIT          //sync RGB between halfs
