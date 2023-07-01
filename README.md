# sa8x8-fw

This repository contains a replacement firmware application for the NiceRF SA8x8 family of radio modules.

Operation of modules running this firmware is similar to that of the official factory firmware as commands are sent via a UART at 115200 Baud, however two special commands enable I2C register level control to a module's internal RDA1846S transceiver. Configuration of modules through this low level interface facilitates the use of advanced digital modes that are otherwise inaccessible.

## Command Set

 - AT+VERSION
 - AT+PEEK=_REG_
 - AT+POKE=_REG_,_VAL_

## Supported Modules

 - [SA868S-V Open Edition](https://a.aliexpress.com/_mNLKxyC) (<33 dBm @ VHF)
 - [SA868S-U Open Edition](https://a.aliexpress.com/_mP5z5EG) (<33 dBm @ UHF)

## Build Environment

 - rl78-gcc

## Firmware Flashing

 - rl78flash

## Acknowledgements

Many thanks to [NiceRF Wireless Technology Co., Ltd.](https://www.nicerf.com/) and [Amo Xu](https://github.com/amoxu) for their efforts in making reprogrammable modules available to radioamateurs and also to [Shenzhen Xinyuan Electronic Technology Co., Ltd.](https://www.lilygo.cc/) for quickly producing a capable development platform using these modules, the [T-TWR Plus](https://www.lilygo.cc/products/t-twr-plus).

## Related Resources

 - [OpenRTX](https://openrtx.org/)

