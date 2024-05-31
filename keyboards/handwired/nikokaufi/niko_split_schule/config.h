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

#define ENCODERS_PAD_A { GP14 }
#define ENCODERS_PAD_B { GP15 }
#define ENCODER_RESOLUTION 4

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1

#define EE_HANDS

#define SPLIT_WATCHDOG_ENABLE

#define BOOTMAGIC_ROW_RIGHT 5
#define BOOTMAGIC_COLUMN_RIGHT 6