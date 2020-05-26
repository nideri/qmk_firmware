# MCU name
MCU = STM32F303

# vvv --------------------
# "overwrite" defaults in mcu_selection.mk
MCU_LDSCRIPT = STM32F303xE
BOARD = ST_NUCLEO64_F303RE
# ^^^ --------------------

## Features
CONSOLE_ENABLE = yes
ENCODER_ENABLE = no

# connect speaker to PA4 and PA5 (DAC1_CH1/2 out)
AUDIO_ENABLE = yes

#BLUETOOTH = AdafruitBLE
# connect display (128x64) I2C SCL to PB6 and SDA to PB7
OLED_DRIVER_ENABLE = yes



RGBLIGHT_ENABLE = yes
WS2812_DRIVER = tim_spi

