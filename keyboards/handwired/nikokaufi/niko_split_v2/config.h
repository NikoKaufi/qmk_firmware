// Copyright 2024 Nikolaj Kaufmann (@NikoKaufi)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* Encoder Configuration */
#ifdef ENCODER_ENABLE
    // #define ENCODER_DEFAULT_POS 0x3
    // #define ENCODER_DEFAULT_POS_RIGHT 0x3
#endif

/* serial communication between halfs */
#define SERIAL_USART_FULL_DUPLEX    // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN GP16     // USART TX pin
#define SERIAL_USART_RX_PIN GP12     // USART RX pin

#define EE_HANDS        //define right/left side by EEPROM/flash option

/* Tap-Dance */
#define TAPPING_TERM 175

// /* rgb general */
// #define WS2812_DI_PIN GP1       //PIN for RGB
// #define RGBLIGHT_LED_COUNT 56    //LED_COUNT total
// #define WS2812_BYTE_ORDER WS2812_BYTE_ORDER_RGB     //changing byte order
// #define RGBLIGHT_SLEEP           //turn off LED, when host is in sleep
//     // #define RGBLIGHT_HUE_STEP 8  //8=default
//     // #define RGBLIGHT_SAT_STEP 17 //17=default?
//     // #define RGBLIGHT_VAL_STEP 17 //17=default?
//     // #define RGBLIGHT_LIMIT_VAL 255   //max brightness, 255=default
// #define RGBLIGHT_DEFAULT_HUE 169 //color after flashing (0=red, 85=green, 169=blue) (https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgblight.md)
//     // #define RGBLIGHT_DEFAULT_VAL 255 //brighness after flashing
//     // #define RGBLIGHT_DEFAULT_SAT 0   //saturation after flashing, UINT8_MAX (255)=default

// /* rgb split */
// #define RGBLED_SPLIT { 28, 28 }   //the number of LEDs connected on each half
// #define RGBLIGHT_SPLIT          //sync RGB between halfs

#define I2C1_SDA_PIN GP26  // SDA pin for I2C1
#define I2C1_SCL_PIN GP27  // SCL pin for I2C1
