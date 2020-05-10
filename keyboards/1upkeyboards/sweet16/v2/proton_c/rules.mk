# MCU name
MCU = STM32F303

# vvv --------------------
# "overwrite" defaults from mcu_selection.mk
MCU_LDSCRIPT = STM32F303xE
BOARD = ST_NUCLEO64_F303RE
# ^^^ --------------------

## Features
CONSOLE_ENABLE = yes
ENCODER_ENABLE = no
AUDIO_ENABLE = yes
