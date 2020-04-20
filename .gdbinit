# connect to openocd on port 3333 on local machine
target remote 127.0.0.1:3333

# enable "gui"
tui enable

# set breakpoint at main
break main

# load .elf file, needed e.g. for 'list' cmd
#file ./Debug/handyHashDice.elf
