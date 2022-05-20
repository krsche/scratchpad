# 1. Socketcan Getting Started <!-- omit in toc -->

Almost anything you might now from industry tools such as CANAlyzer can be done on the linux command-line.  
Get started with these notes.  
The analysis section is where the real magic happens.  

__Table of Contents:__

- [1. Installation](#1-installation)
- [2. Setup](#2-setup)
- [3. Capture & Replay](#3-capture--replay)
- [4. Analysis & Tools](#4-analysis--tools)
- [5. Special Drivers](#5-special-drivers)
  - [5.1. Peak PCAN](#51-peak-pcan)


## 1. Installation

```bash
# Socketcan tools (candump, cansend, etc.)
sudo apt install can-utils

# Cantools (decode, monitor, plot, etc.)
sudo apt install python3-pip
python3 -m pip install cantools
```

## 2. Setup

```bash
# check if kernel module is avail, loaded, load it
find /lib/modules/$(uname -r) -type f -name '*.ko*' | grep can
lsmod | grep can
sudo modprobe can   # base socketcan
sudo modprobe vcan  # virtual can driver
sudo modprobe pcan  # peak pcan driver

# bring real can interface up
ip link list
ip link set can0 type can help
ip link set can0 type can bitrate 500000 listen-only on
ip -details link show can0
sudo ip link set can0 up

# bring vcan0 interface up
sudo ip link add dev vcan0 type vcan
sudo ip link set up vcan0

# listen
candump can0

# send
cansend can0 18F#1234567890ABCDEF
```

## 3. Capture & Replay

You can either capture the human-readable output from candump, or the compressed format.  
`canplayer` expects the compressed format, but conversion can easily be done (see below).

> __candump human-readable output:__  
> `(000.000000)  can0  12E   [8]  C8 7F FD 7F F0 FF FF 00`  
>
> __candump compact format:__ this is used when capturing via `candump -l somename.txt`  
> `(000.000000) can0 12E#C87FFD7FF0FFFF00`

__Goal:__ Replay frames captured from `can0` on `vcan0`

```bash
# Capture 
candump can0 -t z > capture.txt             # human-readable format
candump can0 -t z -l capture-compact.txt    # compact format

# Replay (note the vcan0=can0 assignment)
cat capture.txt | awk '{print ""$1" "$2" "$3"#"$5$6$7$8$9$10$11$12 }' | canplayer vcan0=can0
cat capture-compact.txt | canplayer vcan0=can0
```

## 4. Analysis & Tools

```bash
# Decoding w/ DBC
candump can0 | cantools decode --single-line mycar.dbc
candump can0 | cantools monitor --single-line mycar.dbc

# Plot specific DBC signals from a capture (human-readable candump output captured)
cat capture.txt | cantools plot mycar.dbc 'Wheel_Speed_*'

# Monitor Messages without scrolling (good overview of bus)
can_viewer.py -c can0 -i socketcan
```

## 5. Special Drivers

### 5.1. Peak PCAN

The Peak socketcan driver is included in the linux kernel, but there is also another version of it.  
The included version of the driver is compiled in `netdev` mode, while `chardev` is also available when compiling manually.  

This alternative driver mode (`chardev`) is required for `pcanview` on linux, but breaks socketcan compatibility.  

> __⚠️ Warning__
>
> `pcanview` on linux is no GUI program like on windows, rather it is terminal-only (ncurses based).

In order to install it, download the sources from the [PEAK Website](https://www.peak-system.com/fileadmin/media/linux/index.htm), navigate to the folder and build it with:  

```bash
make clean
make NET=NETDEV_SUPPORT # for netdev mode (socketcan compatible)
make # for chardev mode (pcanview compatible)
sudo make install
```
