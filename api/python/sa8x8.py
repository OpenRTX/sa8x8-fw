#!/usr/bin/env python3

import sys
import time
from enum import IntEnum

try:
  import serial
except ImportError as e:
  print(f"missing pyserial: {e}")
  sys.exit(1)


class AT1846S_MODE(IntEnum):
    MODE_FM   = 0
    MODE_4FSK = 1


class AT1846S_BW(IntEnum):
    BW_25K0 = 0
    BW_12K5 = 1


class AT1846S_FUNC(IntEnum):
    FUNC_OFF = 0
    FUNC_RX  = 1
    FUNC_TX  = 2


class AT1846S:
    def i2c_read():
        raise NotImplemented("i2c_read not implemented")

    def i2c_write():
        raise NotImplemented("i2c_write not implemented")

    def initialize(self):
        self.i2c_write(0x30, 0x0001)   # Soft reset
        time.sleep(0.160)

        self.i2c_write(0x30, 0x0004)   # Set pdn_reg (power down pin)

        self.i2c_write(0x04, 0x0FD0)   # Set clk_mode to 25.6MHz/26MHz
        self.i2c_write(0x0A, 0x7C20)   # Set 0x0A to its default value
        self.i2c_write(0x13, 0xA100)
        self.i2c_write(0x1F, 0x1001)   # Set gpio0 to ctcss_out/css_int/css_cmp
                                       # and gpio6 to sq, sq&ctcss/cdcss when sq_out_set=1
        self.i2c_write(0x31, 0x0031)
        self.i2c_write(0x33, 0x44A5)
        self.i2c_write(0x34, 0x2B89)
        self.i2c_write(0x41, 0x4122)   # Set voice_gain_tx (voice digital gain) to 0x22
        self.i2c_write(0x42, 0x1052)
        self.i2c_write(0x43, 0x0100)
        self.i2c_write(0x44, 0x07FF)   # Set gain_tx (voice digital gain after tx ADC downsample) to 0x7
        self.i2c_write(0x59, 0x0B90)   # Set c_dev (CTCSS/CDCSS TX FM deviation) to 0x10
                                       # and xmitter_dev (voice/subaudio TX FM deviation) to 0x2E
        self.i2c_write(0x47, 0x7F2F)
        self.i2c_write(0x4F, 0x2C62)
        self.i2c_write(0x53, 0x0094)
        self.i2c_write(0x54, 0x2A3C)
        self.i2c_write(0x55, 0x0081)
        self.i2c_write(0x56, 0x0B02)
        self.i2c_write(0x57, 0x1C00)
        self.i2c_write(0x58, 0x9CDD)   # Bit 0  = 1: CTCSS LPF bandwidth to 250Hz
                                       # Bit 3  = 1: bypass CTCSS HPF
                                       # Bit 4  = 1: bypass CTCSS LPF
                                       # Bit 5  = 0: enable voice LPF
                                       # Bit 6  = 1: bypass voice HPF
                                       # Bit 7  = 1: bypass pre/de-emphasis
                                       # Bit 11 = 1: bypass VOX HPF
                                       # Bit 12 = 1: bypass VOX LPF
                                       # Bit 13 = 0: normal RSSI LPF bandwidth
        self.i2c_write(0x5A, 0x06DB)
        self.i2c_write(0x63, 0x16AD)
        self.i2c_write(0x67, 0x0628)   # Set DTMF C0 697Hz to ???
        self.i2c_write(0x68, 0x05E5)   # Set DTMF C1 770Hz to 13MHz and 26MHz
        self.i2c_write(0x69, 0x0555)   # Set DTMF C2 852Hz to ???
        self.i2c_write(0x6A, 0x04B8)   # Set DTMF C3 941Hz to ???
        self.i2c_write(0x6B, 0x02FE)   # Set DTMF C4 1209Hz to 13MHz and 26MHz
        self.i2c_write(0x6C, 0x01DD)   # Set DTMF C5 1336Hz
        self.i2c_write(0x6D, 0x00B1)   # Set DTMF C6 1477Hz
        self.i2c_write(0x6E, 0x0F82)   # Set DTMF C7 1633Hz
        self.i2c_write(0x6F, 0x017A)   # Set DTMF C0 2nd harmonic
        self.i2c_write(0x70, 0x004C)   # Set DTMF C1 2nd harmonic
        self.i2c_write(0x71, 0x0F1D)   # Set DTMF C2 2nd harmonic
        self.i2c_write(0x72, 0x0D91)   # Set DTMF C3 2nd harmonic
        self.i2c_write(0x73, 0x0A3E)   # Set DTMF C4 2nd harmonic
        self.i2c_write(0x74, 0x090F)   # Set DTMF C5 2nd harmonic
        self.i2c_write(0x75, 0x0833)   # Set DTMF C6 2nd harmonic
        self.i2c_write(0x76, 0x0806)   # Set DTMF C7 2nd harmonic

        self.i2c_write(0x30, 0x40A4)   # Set pdn_pin (power down enable)
                                       # and set rx_on
                                       # and set mute when rxno
                                       # and set xtal_mode to 26MHz/13MHz
        time.sleep(0.160)

        self.i2c_write(0x30, 0x40A6)   # Start calibration
        time.sleep(0.160)
        self.i2c_write(0x30, 0x4006)   # Stop calibration
        time.sleep(0.160)

        self.i2c_write(0x40, 0x0031)

    def mask_set_reg(self, reg, mask, value):
        regVal = self.i2c_read(reg)
        regVal = (regVal & ~mask) | (value & mask)
        self.i2c_write(reg, regVal)

    def reload(self):
        funcMode = self.i2c_read(0x30) & 0x0060   # Get current op. status
        self.mask_set_reg(0x30, 0x0060, 0x0000)   # RX and TX off
        self.mask_set_reg(0x30, 0x0060, funcMode) # Restore op. status
        
    def bandwidth(self, band):
        if band == AT1846S_BW.BW_25K0:
            # 25kHz bandwidth
            self.i2c_write(0x15, 0x1F00)
            self.i2c_write(0x32, 0x7564)
            self.i2c_write(0x3A, 0x40C3)
            self.i2c_write(0x3C, 0x1B34)
            self.i2c_write(0x3F, 0x29D1)
            self.i2c_write(0x48, 0x1F3C)
            self.i2c_write(0x60, 0x0F17)
            self.i2c_write(0x62, 0x3263)
            self.i2c_write(0x65, 0x248A)
            self.i2c_write(0x66, 0xFFAE)
            self.i2c_write(0x7F, 0x0001)
            self.i2c_write(0x06, 0x0024)
            self.i2c_write(0x07, 0x0214)
            self.i2c_write(0x08, 0x0224)
            self.i2c_write(0x09, 0x0314)
            self.i2c_write(0x0A, 0x0324)
            self.i2c_write(0x0B, 0x0344)
            self.i2c_write(0x0C, 0x0384)
            self.i2c_write(0x0D, 0x1384)
            self.i2c_write(0x0E, 0x1B84)
            self.i2c_write(0x0F, 0x3F84)
            self.i2c_write(0x12, 0xE0EB)
            self.i2c_write(0x7F, 0x0000)

            self.mask_set_reg(0x30, 0x3000, 0x3000)

        elif band == AT1846S_BW.BW_12K5:
            # 12.5kHz bandwidth
            self.i2c_write(0x15, 0x1100)
            self.i2c_write(0x32, 0x4495)
            self.i2c_write(0x3A, 0x40C3)
            self.i2c_write(0x3F, 0x29D1)
            self.i2c_write(0x3C, 0x1B34)
            self.i2c_write(0x48, 0x19B1)
            self.i2c_write(0x60, 0x0F17)
            self.i2c_write(0x62, 0x1425)
            self.i2c_write(0x65, 0x2494)
            self.i2c_write(0x66, 0xEB2E)
            self.i2c_write(0x7F, 0x0001)
            self.i2c_write(0x06, 0x0014)
            self.i2c_write(0x07, 0x020C)
            self.i2c_write(0x08, 0x0214)
            self.i2c_write(0x09, 0x030C)
            self.i2c_write(0x0A, 0x0314)
            self.i2c_write(0x0B, 0x0324)
            self.i2c_write(0x0C, 0x0344)
            self.i2c_write(0x0D, 0x1344)
            self.i2c_write(0x0E, 0x1B44)
            self.i2c_write(0x0F, 0x3F44)
            self.i2c_write(0x12, 0xE0EB)
            self.i2c_write(0x7F, 0x0000)

            self.mask_set_reg(0x30, 0x3000, 0x0000)

        else:
            raise ValueError("unimplemented band parameter")
        
        self.reload()

    def mode(self, mode):
        if mode == AT1846S_MODE.MODE_4FSK:
            # 4-FSK mode
            self.i2c_write(0x3A, 0x00C2)
            self.i2c_write(0x33, 0x45F5)
            self.i2c_write(0x41, 0x4731)
            self.i2c_write(0x42, 0x1036)
            self.i2c_write(0x43, 0x00BB)
            self.i2c_write(0x58, 0xBCFD)  # Bit 0  = 1: CTCSS LPF bandwidth to 250Hz
                                          # Bit 3  = 1: bypass CTCSS HPF
                                          # Bit 4  = 1: bypass CTCSS LPF
                                          # Bit 5  = 1: bypass voice LPF
                                          # Bit 6  = 1: bypass voice HPF
                                          # Bit 7  = 1: bypass pre/de-emphasis
                                          # Bit 11 = 1: bypass VOX HPF
                                          # Bit 12 = 1: bypass VOX LPF
                                          # Bit 13 = 1: bypass RSSI LPF
            self.i2c_write(0x44, 0x06CC)
            self.i2c_write(0x40, 0x0031)

        elif mode == AT1846S_MODE.MODE_FM:
            # FM mode
            self.i2c_write(0x58, 0x9C05)  # Bit 0  = 1: CTCSS LPF bandwidth to 250Hz
                                          # Bit 3  = 0: enable CTCSS HPF
                                          # Bit 4  = 0: enable CTCSS LPF
                                          # Bit 5  = 0: enable voice LPF
                                          # Bit 6  = 0: enable voice HPF
                                          # Bit 7  = 0: enable pre/de-emphasis
                                          # Bit 11 = 1: bypass VOX HPF
                                          # Bit 12 = 1: bypass VOX LPF
                                          # Bit 13 = 0: normal RSSI LPF bandwidth
            self.i2c_write(0x40, 0x0030)

        else:
            raise ValueError("unimplemented mode parameter")
        
        self.reload()

    def frequency(self, freq):
        val = int((freq / 1000) * 16)
        fHi = (val >> 16) & 0xFFFF
        fLo = val & 0xFFFF

        self.i2c_write(0x29, fHi)
        self.i2c_write(0x2A, fLo)

        self.reload()

    def function(self, func):
        val = func << 5
        self.mask_set_reg(0x30, 0x0060, val)


class SA8x8:
    def __init__(self, ser):
        self.ser = ser

        self.xcvr = AT1846S()
        self.xcvr.i2c_read  = lambda reg: self.peek(reg)
        self.xcvr.i2c_write = lambda reg, val: self.poke(reg, val)

    @property
    def version(self):
        self.ser.write(b'AT+VERSION\r\n')
        return self.ser.readline().strip(b'\r\n').decode('utf-8')

    def peek(self, reg):
        msg = f'AT+PEEK={reg}\r\n'
        self.ser.write(msg.encode('utf-8'))
        val = int(self.ser.readline().strip(b'\r\n').decode('utf-8'))
        return val

    def poke(self, reg, val):
        msg = f'AT+POKE={reg},{val}\r\n'
        self.ser.write(msg.encode('utf-8'))
        res = self.ser.readline().strip(b'\r\n').decode('utf-8')
        return True if res == b'OK' else False


def main():
    with serial.Serial() as ser:
        ser.baudrate = 115200
        ser.port = '/dev/ttyUSB0'
        ser.open()

        m = SA8x8(ser)
        print(m.version)

        m.xcvr.initialize()
        m.xcvr.mode(AT1846S_MODE.MODE_4FSK)
        m.xcvr.bandwidth(AT1846S_BW.BW_25K0)

        m.xcvr.i2c_write(0x41, 0x0070)
        m.xcvr.i2c_write(0x44, 0x0022)

        while True:
            m.xcvr.frequency(145_000_000)

            m.xcvr.function(AT1846S_FUNC.FUNC_RX)
            time.sleep(5)

            m.xcvr.function(AT1846S_FUNC.FUNC_TX)
            time.sleep(5)


if __name__ == '__main__':
    main()

