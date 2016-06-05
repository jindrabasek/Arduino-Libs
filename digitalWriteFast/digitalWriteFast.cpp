/*
 * digitalWriteFast.cpp
 *
 *  Created on: 3. 6. 2016
 *      Author: jindra
 */

#include <Arduino.h>
#include <digitalWriteFast.h>
#include <stdint.h>

void digitalWriteSemiFast(uint8_t pin, uint8_t val)
{
    if (val == LOW) {
        *portOutputRegister(digitalPinToPort(pin)) &= ~digitalPinToBitMask(pin);
    } else {
        *portOutputRegister(digitalPinToPort(pin)) |= digitalPinToBitMask(pin);
    }
}

int digitalReadSemiFast(uint8_t pin)
{
    return (*portInputRegister(digitalPinToPort(pin)) & digitalPinToBitMask(pin)) ? HIGH : LOW;
}
