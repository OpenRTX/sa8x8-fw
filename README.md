# sa8x8-fw

[![Build sa8x8-fw](https://github.com/OpenRTX/sa8x8-fw/actions/workflows/main.yaml/badge.svg)](https://github.com/OpenRTX/sa8x8-fw/actions/workflows/main.yaml)

This repository contains a replacement firmware application for the NiceRF SA8x8 family of radio modules.

In contrast to the official factory firmware, two special commands (PEEK and POKE) enable direct register level control to a module's internal AT1846S transceiver. Configuration of modules through this low level interface facilitates the use of advanced digital modes that are otherwise inaccessible. Refer to the included Python API example for a basic demonstration of using the firmware to transmit an [M17](https://m17project.org) baseband.

**Note:** This firmware is not yet suitable as a drop-in replacement for the original firmware. Applications using the official factory firmware programming interface are not expected to function properly.

## Command Set

The following commands are available in this firmware:

| Command             | Description                          |
| ------------------- | ------------------------------------ |
| AT+VERSION          | Display firmware version information |
| AT+MODEL            | Display module model information     |
| AT+TURBO            | Enter high speed UART mode           |
| AT+PEEK=_REG_       | Get transceiver register contents    |
| AT+POKE=_REG_,_VAL_ | Set transceiver register contents    |
| AT+AMP=_0_/_1_      | Set power amplifier state            |
| AT+AUDIO=_0_/_1_    | Set external audio amplifier state   |

## Supported Modules

 - [SA818S-V](https://www.aliexpress.com/item/2251832038505495.html) (<30 dBm @ VHF)
 - [SA818S-U](https://www.aliexpress.com/item/2251832038505495.html) (<30 dBm @ UHF)
 - [SA818S-CE](https://www.aliexpress.com/item/3256806009764568.html) (<30 dBm @ UHF, CE-RED)
 - [SA868S-V](https://www.aliexpress.com/item/2251832776489099.html) (<33 dBm @ VHF)
 - [SA868S-U](https://www.aliexpress.com/item/2251832774928072.html) (<33 dBm @ UHF)

**Note:** The SA868S open and standard editions are the same hardware. The open edition contains no functional firmware, as it is erased following factory quality assurance, and is intended for end-user reprogramming with firmware like this one.

## Build Environment

A [script](https://github.com/OpenRTX/sa8x8-fw/blob/main/tools/build-rl78-elf-toolchain.sh) is provided for building a recent toolchain. This script requires [Buildah](https://buildah.io) and generates an OCI container image. A convenient [prebuilt toolchain](https://github.com/OpenRTX/sa8x8-fw/releases/download/v1.0.0/rl78-elf-toolchain.sif) is available as an [Apptainer](https://apptainer.org/) image. The prebuilt toolchain is the quickest way to get started with development and is also used to automate release builds on GitHub. Just clone this repository and run the following commands from inside the directory:

    $ SIF=https://github.com/OpenRTX/sa8x8-fw/releases/download/v1.0.0/rl78-elf-toolchain.sif
    $ apptainer run $SIF make clean
    $ apptainer run $SIF make sa868s_vhf
    $ apptainer run $SIF make sa868s_uhf

## Firmware Flashing

The [rl78flash](https://github.com/msalau/rl78flash) tool by Maksim Salau enables flashing SA8x8 modules through the RL78 serial bootloader. The physical [programming interface](https://github.com/msalau/rl78flash/blob/master/hw/rl78s-hw.png) (mode 1 or mode 3) requires a 115200 baud UART operating at 3.3V and two switching diodes, such as 1N4148 or 1N5817. Schottky diodes are preferred in order to minimize voltage drop while operating at this logic level, but the exact part is not important. Be sure to specify the relevant mode while running `rl78flash`.

    $ rl78flash -m 3 -a -v /dev/ttyUSB0 sa8x8-fw-sa868s-uhf.s37
    rl78flash v0.7.0
    Device: R5F1026A
    Code size: 16 kB
    Data size: 2 kB
    Protocol configuration: protocol=0, code_block=1024, data_block=1024
    Erase code flash
    Erase data flash
    Read file "sa8x8-fw-sa868s-uhf.s37"
    Write code flash
    Write data flash
    Verify Code flash
    Verify Data flash
    Reset MCU

## Programming Pinouts

### SA868S Module

From rear of module:

    +-----------------------------+
    |                      NRST O |
    |  +--+     SA868S    TOOL0 O |
    |  |  |     VER:2.0     GND O |
    |  +--+                 3V3 O |
    |                             |
    +-----------------------------+

Refer to the module [schematics](https://github.com/OpenRTX/sa8x8-fw/files/12232818/SA868-open.pdf) for more information.

**Note:** When possible, use spring-loaded pins (pogo pins) to program these modules. Programming pads are prone to shearing off when wires soldered to the pads are under strain. The pitch of the pads is 2mm.

### T-TWR Plus

The [T-TWR Plus](https://www.lilygo.cc/products/t-twr-plus) is a complete portable radio design using SA868S modules. The programming procedure for these devices is very similar to the one described above. The programming interface is exposed through a 4-pin JST SH-1.0 (1mm pitch) connector labeled **CN4** in the [schematic](https://github.com/Xinyuan-LilyGO/T-TWR/blob/master/schematic/T-TWR-Plus_Rev2.0.pdf). The connector is located on the rear of the board along the right edge, between the NeoPixel LED and a similar looking connector. The pin map is as follows, from top to bottom:

| Pin number | Silkscreen label | Function      |
|------------|------------------|---------------|
| 1          | RG               | signal ground |
| 2          | RV               | +3.3V supply  |
| 3          | RT               | RL78 TOOL0    |
| 4          | RR               | RL78 NRST     |

The connection between the USB-UART converter (with exposed flow control pins - at least the RTS one - **and set to 3.3V operation**) is shown below.

    UART_GND o-------------o T-TWR_RG
    UART_VCC o-------------o T-TWR_RV (do not connect when supplying the device over USB!)
    UART_RX  o---------+---o T-TWR_RT
    UART_TX  o----|<|--/
    UART_RTS o----|<|------o T-TWR_RR

Both 1N4148 and 1N5817 diodes have been tested and work. The correct mode to set the programmer to is `-m 3`. An alternative connection for the VCC line, so the device can be supplied with USB/battery and the JST programmer connector simultaneously:

    UART_VCC o-----|>|-----o T-TWR_RV

This diode ensures that the 3.3V voltage regulators in the UART dongle and the device can actually work together safely.

## Acknowledgements

Many thanks to [NiceRF Wireless Technology Co., Ltd.](https://www.nicerf.com/) and [Amo Xu](https://github.com/amoxu) for their efforts in making reprogrammable modules available to radioamateurs and also to [Shenzhen Xinyuan Electronic Technology Co., Ltd.](https://www.lilygo.cc/) for quickly producing a capable development platform using these modules, the [T-TWR Plus](https://www.lilygo.cc/products/t-twr-plus).

## Related Resources

 - [OpenRTX](https://openrtx.org/)

