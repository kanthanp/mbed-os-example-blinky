/* mbed Microcontroller Library
 * Copyright (c) 2022 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "PinNames.h"
#include "mbed.h"
#include "stats_report.h"

DigitalOut led1(LED_BLUE);

#define SLEEP_TIME                  5000 // (msec)
#define PRINT_AFTER_N_LOOPS         20

// main() runs in its own thread in the OS
int main()
{
    SystemReport sys_state( SLEEP_TIME * PRINT_AFTER_N_LOOPS /* Loop delay time in ms */);

    int count = 0;
    while (true) {

        // Blink LED and wait 10 seconds
        led1 = !led1;
        wait_ms(SLEEP_TIME);
        printf("BLUE LED blinking every 5000ms!!");
        printf("Testing KSC Next Mbed flavour!!");

        if ((0 == count) || (PRINT_AFTER_N_LOOPS == count)) {
            // Following the main thread wait, report on the current system status
            sys_state.report_state();
            count = 0;
        }
        ++count;
    }
}
