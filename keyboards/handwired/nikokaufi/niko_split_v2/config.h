// Copyright 2024 Nikolaj Kaufmann (@NikoKaufi)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* serial communication between halfs */
#define SERIAL_USART_FULL_DUPLEX    // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN GP16     // USART TX pin
#define SERIAL_USART_RX_PIN GP12     // USART RX pin

#define EE_HANDS        //define right/left side by EEPROM/flash option

/* Tap-Dance */
#define TAPPING_TERM 200

/* i2c -> OLED*/
#define I2C1_SDA_PIN GP26  // SDA pin for I2C0 ?
#define I2C1_SCL_PIN GP27  // SCL pin for I2C0 ?
#define I2C_DRIVER_RIGHT I2CD2
#define I2C2_SDA_PIN_RIGHT GP6
#define I2C2_SCL_PIN_RIGHT GP5

/* Encoder Configuration */
// #ifdef ENCODER_ENABLE
//     #define ENCODER_DEFAULT_POS 0x3
//     #define ENCODER_DEFAULT_POS_RIGHT 0x3
// #endif

// #define RGB_MATRIX_LED_FLUSH_LIMIT 16
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_VAL_STEP 9
// #define RGBLIGHT_SPLIT
// #define SPLIT_LAYER_STATE_ENABLE
