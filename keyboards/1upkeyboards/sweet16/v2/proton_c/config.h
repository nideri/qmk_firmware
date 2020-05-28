#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xfeed
#define PRODUCT_ID      0xbeef
#define DEVICE_VER      0x0001

// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_audio.md#audio-click
#define AUDIO_CLICKY

/* key matrix pins */
#define MATRIX_ROW_PINS { B0, C1, A0, A1 }
#define MATRIX_COL_PINS { B5, B4, B3, A10 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define RGBLIGHT_ANIMATIONS
// enable spi3 tim4 tim8 in quantum/stm32/mcuconf.h
#define HAL_USE_SPI TRUE
#define RGBLED_NUM 	144


