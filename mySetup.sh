#!/bin/bash

MY_ARM_ROOT=$HOME/bin/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.linux64_1.17.0.201812190825/
MY_OPENOCD_ROOT=$HOME/bin/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.openocd.linux64_1.23.0.201904120827/
MY_DEBUG_ROOT=$HOME/bin/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.debug_2.5.0.201904120827

export PATH=$MY_ARM_ROOT/tools/compiler/bin/:$PATH


make clean

#make ckeys/handwire_101:default CTPC=yes
make 1upkeyboards/sweet16/v2/proton_c:default #:dfu-util
#make handwired/onekey/proton_c:default 

#exit 0

st-flash erase

st-flash write .build/*.bin 0x8000000

st-flash reset

#exit 1

echo -e "\n"
echo "--------------------------------------------------------------------------------"
echo "check https://github.com/qmk/qmk_firmware/blob/57fbf072f145bcf560c812a7976ba0f4f702f946/keyboards/ckeys/handwire_101/readme.md"

echo "--------------------------------------------------------------------------------"
echo "!!! USB_DP (PA12) NEEDS A 1k5 PULL_UP RESISTOR TO VDD !!! (otherwhise device will not be recognized)"

# debug
# get an overview over toolflow
# https://stackoverflow.com/questions/38033130/how-to-use-the-gdb-gnu-debugger-and-openocd-for-microcontroller-debugging-fr
echo "--------------------------------------------------------------------------------"
echo "openocd server:"
export LD_LIBRARY_PATH=$MY_OPENOCD_ROOT/tools/openocd/lib:$LD_LIBRARY_PATH
echo "export LD_LIBRARY_PATH=$MY_OPENOCD_ROOT/tools/openocd/lib:\$LD_LIBRARY_PATH"
echo "$MY_OPENOCD_ROOT/tools/openocd/bin/openocd -f 'debug.cfg' -s $HOME/kbrd/qmk_firmware -s $MY_DEBUG_ROOT/resources/openocd/st_scripts -c 'gdb_port 3333' -c 'tcl_port 6666' -c 'telnet_port 4444'"

echo "--------------------------------------------------------------------------------"
echo "gdb:"
echo "$MY_ARM_ROOT/tools/compiler/bin/arm-none-eabi-gdb  -iex 'add-auto-load-safe-path /' -iex 'file .build/1upkeyboards_sweet16_v2_proton_c_default.elf'"

echo "--------------------------------------------------------------------------------"

exit 0
