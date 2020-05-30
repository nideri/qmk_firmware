#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xfeed
#define PRODUCT_ID      0xbeef
#define DEVICE_VER      0x0001

// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_audio.md#audio-click
#define AUDIO_CLICKY

/* key matrix pins */
#define MATRIX_ROW_PINS { /* r0 */ F1, A1, C3, A0, A13, A15 /* r5 */ }
#define MATRIX_COL_PINS { /* c0 */ A10, C4, B3, B5, B13, B4, B14, B10, B15, A8, B1, A9, B2, C7, C9, C8, B8, C6 /* c17 */ }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define RGBLIGHT_ANIMATIONS
// enable spi3 tim4 tim8 in quantum/stm32/mcuconf.h
#define HAL_USE_SPI TRUE
#define RGBLED_NUM 	144


