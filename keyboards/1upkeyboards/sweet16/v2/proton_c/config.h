#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xfeed
#define PRODUCT_ID      0xbeef
#define DEVICE_VER      0x0001

// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_audio.md#audio-click
#define AUDIO_CLICKY

/* key matrix pins */
#define MATRIX_ROW_PINS { B0, A1, A0, B8 }
#define MATRIX_COL_PINS { B5, B4, B3, B2 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

/*
// https://docs.qmk.fm/#/feature_backlight?id=arm-configuration
//#define BACKLIGHT_BREATHING
#define BACKLIGHT_PIN B7
#define BACKLIGHT_PWM_DRIVER PWMD4
#define BACKLIGHT_PWM_CHANNEL 3
#define BACKLIGHT_PAL_MODE 2
*/



/* Encoder pins */
//#define ENCODERS_PAD_A { A2 }
//#define ENCODERS_PAD_B { A1 }
//#define ENCODER_RESOLUTION 4
