/* HAL-only entry function */
#include "hal_data.h"
void hal_entry(void)
{
    /* Define the units to be used with the software delay function */
    const bsp_delay_units_t bsp_delay_units = BSP_DELAY_UNITS_MILLISECONDS;
    /* Set the blink frequency (must be <= bsp_delay_units */
    const uint32_t freq_in_hz = 6;
    /* Calculate the delay in terms of bsp_delay_units */
    const uint32_t delay = bsp_delay_units/freq_in_hz;
    /* LED type structure */
    bsp_leds_t leds;
    /* Get LED information for this board */
    R_BSP_LedsGet(&leds);

    // Create a simple message
    uint8_t data[] = "This is a test";

    // Catch the function call results for debugging
    ssp_err_t openResult;
    ssp_err_t writeResult;

    // Open the UART driver
    openResult = g_uart0.p_api->open(g_uart0.p_ctrl, g_uart0.p_cfg);

    // Send the message data
    writeResult = g_uart0.p_api->write(g_uart0.p_ctrl, data, 14);

    while(1)
    {
        g_ioport.p_api->pinWrite(leds.p_leds[0], IOPORT_LEVEL_LOW);

        /* Delay */
        R_BSP_SoftwareDelay(delay, bsp_delay_units);

        g_ioport.p_api->pinWrite(leds.p_leds[0], IOPORT_LEVEL_HIGH);

        /* Delay */
        R_BSP_SoftwareDelay(delay, bsp_delay_units);
    }
}

void user_uart_callback(uart_callback_args_t *p_args)
{

}
