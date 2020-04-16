#!/bin/bash

export PATH=/home/rasaf/bin/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.linux64_1.17.0.201812190825/tools/compiler/bin/:$PATH

echo -e "\n\n\n\n"
echo "--------------------------------------------------------------------------------"
make ckeys/handwire_101:default CTPC=yes
echo -e "\n"
echo "check https://github.com/qmk/qmk_firmware/blob/57fbf072f145bcf560c812a7976ba0f4f702f946/keyboards/ckeys/handwire_101/readme.md"
echo "--------------------------------------------------------------------------------"

echo -e "\n\n\n\n"
echo "--------------------------------------------------------------------------------"
make ckeys/thedora:default
echo -e "\n"
echo "check https://github.com/qmk/qmk_firmware/blob/0968cf8b00ee1ee98edcd37b83573a327b2e8e29/keyboards/ckeys/thedora/readme.md"
echo "--------------------------------------------------------------------------------"

echo -e "\n\n\n\n"
echo "--------------------------------------------------------------------------------"
make handwired/floorboard:default
echo -e "\n"
echo "check https://github.com/qmk/qmk_firmware/blob/96d4ba84c245066ae0ccd0f8216d7f11f80e5d98/keyboards/handwired/floorboard/readme.md"
echo "--------------------------------------------------------------------------------"
