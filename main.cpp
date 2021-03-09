/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "InvertedDigitalOut.h"

/* Include all of these to ensure they compile */
#include "DigitalOut.h"
#include "DigitalIn.h"
#include "DigitalInOut.h"

#include "rtos/ThisThread.h"

#include <chrono>

// Blinking rate in milliseconds
#define BLINKING_RATE     500ms

using namespace std::chrono;

int main()
{
    // Initialise the digital pin LED1 as an output
    mbed::DigitalOut led1(LED1);
    ep::InvertedDigitalOut led2(LED2);

    // led2 will be the opposite of led1

    while (true) {
        led1 = !led1;
        led2 = led1;
        rtos::ThisThread::sleep_for(BLINKING_RATE);
    }
}
