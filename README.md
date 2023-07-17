# sa8x8-fw

[![Build sa8x8-fw](https://github.com/OpenRTX/sa8x8-fw/actions/workflows/main.yaml/badge.svg)](https://github.com/OpenRTX/sa8x8-fw/actions/workflows/main.yaml)

This repository contains a replacement firmware application for the NiceRF SA8x8 family of radio modules.

Operation of modules running this firmware is similar to that of the official factory firmware as commands are sent via a UART at 9600 Baud, however two special commands enable I2C register level control to a module's internal RDA1846S transceiver.

Configuration of modules through this low level interface facilitates the use of advanced digital modes that are otherwise inaccessible.

## Command Set

 - AT+VERSION
 - AT+PEEK=_REG_
 - AT+POKE=_REG_,_VAL_

## Supported Modules

 - [SA868S-V Open Edition](https://a.aliexpress.com/_mNLKxyC) (<33 dBm @ VHF)
 - [SA868S-U Open Edition](https://a.aliexpress.com/_mP5z5EG) (<33 dBm @ UHF)

## Build Environment

If you have rl78-elf-gcc, just clone the repository and run `make` to generate a firmware image flashable with `rl78flash`. A [script](https://github.com/OpenRTX/sa8x8-fw/blob/main/tools/build-rl78-elf-toolchain.sh) is provided for building a recent toolchain as an OCI container image using `buildah` and the resulting container will be used to automate release generation in the near future.

## Firmware Flashing

The [rl78flash](https://github.com/msalau/rl78flash) tool by Maksim Salau enables flashing SA8x8 modules through the RL78 serial bootloader. The physical [programming interface](https://github.com/msalau/rl78flash/blob/master/hw/rl78s-hw.png) (mode 1 or mode 3) requires a 115200 Baud UART operating at 3.3V and two Schottky diodes, such as 1N5817. The intention is to minimize voltage drop while operating at this logic level, so the exact part is not important. Be sure to specify the relevant mode while running `rl78flash`.

    $ rl78flash -i /dev/ttyUSB0 -m 1 -a sa8x8-fw.s37 -v
    rl78flash v0.7.0
    Device: R5F1026A
    Code size: 16 kB
    Data size: 2 kB
    Protocol configuration: protocol=0, code_block=1024, data_block=1024
    Erase code flash
    Erase data flash
    Read file "sa8x8-fw.s37"
    Write code flash
    Write data flash
    Verify Code flash
    Verify Data flash
    Reset MCU

## Programming Pinout

From rear of module:

    +-----------------------------+
    |                      NRST O |
    |  +--+     SA868S    TOOL0 O |
    |  |  |     VER:2.0     GND O |
    |  +--+                 VCC O |
    |                             |
    +-----------------------------+

When possible, use spring-loaded pins (pogo pins) to program these modules. Programming pads are prone to shearing off when wires soldered to the pads are under strain. The pitch of the pads is 2mm.

## Acknowledgements

Many thanks to [NiceRF Wireless Technology Co., Ltd.](https://www.nicerf.com/) and [Amo Xu](https://github.com/amoxu) for their efforts in making reprogrammable modules available to radioamateurs and also to [Shenzhen Xinyuan Electronic Technology Co., Ltd.](https://www.lilygo.cc/) for quickly producing a capable development platform using these modules, the [T-TWR Plus](https://www.lilygo.cc/products/t-twr-plus).

## Related Resources

 - [OpenRTX](https://openrtx.org/)

