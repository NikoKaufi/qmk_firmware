// Copyright 2024 Nikolaj Kaufmann (@NikoKaufi)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* serial communication between halfs */
#define SERIAL_USART_FULL_DUPLEX     // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN GP16     // USART TX pin
#define SERIAL_USART_RX_PIN GP12     // USART RX pin

#define EE_HANDS        //define right/left side by EEPROM/flash option

/* i2c -> OLED*/
#ifdef INIT_EE_HANDS_LEFT
    #define I2C1_SDA_PIN GP26   // left SDA pin for I2C1
    #define I2C1_SCL_PIN GP27   // left SCL pin for I2C1
#endif
#ifdef INIT_EE_HANDS_RIGHT
    #define I2C1_SDA_PIN GP6    // right SDA pin for I2C1
    #define I2C1_SCL_PIN GP11   // right SCL pin for I2C1
#endif
#define OLED_TIMEOUT 90000      //in ms, default = 60000

/* Tap-Dance */
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD         // Rollen über doppelt belegte Tasten unterbindet Kombinationen WÄHREND TAPPING-TERM
#define TAPPING_TERM_PER_KEY
#define RETRO_TAPPING_PER_KEY   // 2.Belegung wird nur aktiv, wenn weitere Taste gedrückt wird


/* Encoder Configuration */
// #ifdef ENCODER_ENABLE
//     #define ENCODER_DEFAULT_POS 0x3
//     #define ENCODER_DEFAULT_POS_RIGHT 0x3
// #endif

// #define RGB_MATRIX_LED_FLUSH_LIMIT 16
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
