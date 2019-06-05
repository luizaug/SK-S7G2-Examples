/*
 * Timer application
 *
 * The following code blinks a led in 1Hz (e.g. 500ms on, 500ms off)
 *
 * Timer refers to PCLKD clock frequency. Thats why were used 120E6, although the main clock is 240MHz
 * Were used gpt, because it uses a 32 bit register
 *
 */


// /* HAL-only entry function */
#include "hal_data.h"

// Define the number of counts per millisecond (1 count per clock tick, clock rate is 240MHz)
// So there are 240E6 ticks per second.
// Divide by 1000 to get ticks / millisecond
#define COUNTS_PER_MILLISECOND  (120E6 / 1000)

void hal_entry(void)
{
    /* LED type structure */
    bsp_leds_t leds;

    /* Get LED information for this board */
    R_BSP_LedsGet(&leds);

    // Boolean to hold LED state
    bool isOn = true;

    // Variable to hold counts
    timer_size_t counts = 0;

    // Open the timer using the configured options from the configurator
    g_timer0.p_api->open (g_timer0.p_ctrl, g_timer0.p_cfg); //g_timer0 é uma struct do tipo timer_instance_t, e chama as funções da api

    // Main Loop
    while(1)
    {
        // Turn LED
        g_ioport.p_api->pinWrite(leds.p_leds[0], isOn);

        // Toggle LED State
        isOn = !isOn;

        // Wait for timer loop
        while (1)
        {
            // Get current counts
            g_timer0.p_api->counterGet(g_timer0.p_ctrl, &counts); // counts equivale a uint32, i.e. timer_size_t é uint32

            // Check if 500ms has elapsed => This should be a helper function at some point
            // Need to look if the PBCLK settings are stored in a define somewhere...
            if (counts > (500*COUNTS_PER_MILLISECOND))
            {
                // Reset the timer to 0
                g_timer0.p_api->reset(g_timer0.p_ctrl);
                break;
            }
        }
    }
}
