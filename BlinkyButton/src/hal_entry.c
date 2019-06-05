/***********************************************************************************************************************
 * Copyright [2015-2017] Renesas Electronics Corporation and/or its licensors. All Rights Reserved.
 * 
 * This file is part of Renesas SynergyTM Software Package (SSP)
 *
 * The contents of this file (the "contents") are proprietary and confidential to Renesas Electronics Corporation
 * and/or its licensors ("Renesas") and subject to statutory and contractual protections.
 *
 * This file is subject to a Renesas SSP license agreement. Unless otherwise agreed in an SSP license agreement with
 * Renesas: 1) you may not use, copy, modify, distribute, display, or perform the contents; 2) you may not use any name
 * or mark of Renesas for advertising or publicity purposes or in connection with your use of the contents; 3) RENESAS
 * MAKES NO WARRANTY OR REPRESENTATIONS ABOUT THE SUITABILITY OF THE CONTENTS FOR ANY PURPOSE; THE CONTENTS ARE PROVIDED
 * "AS IS" WITHOUT ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE, AND NON-INFRINGEMENT; AND 4) RENESAS SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, OR
 * CONSEQUENTIAL DAMAGES, INCLUDING DAMAGES RESULTING FROM LOSS OF USE, DATA, OR PROJECTS, WHETHER IN AN ACTION OF
 * CONTRACT OR TORT, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THE CONTENTS. Third-party contents
 * included in this file may be subject to different terms.
 **********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : hal_entry.c
* Description  : This is a very simple example application that blinks all LEDs on a board.
***********************************************************************************************************************/

#include "hal_data.h"

/*******************************************************************************************************************//**
 * @brief  Blinky example application
 *
 * Blinks all leds at a rate of 1 second using the software delay function provided by the BSP.
 * Only references two other modules including the BSP, IOPORT.
 *
 **********************************************************************************************************************/
void hal_entry(void) {

	/* Define the units to be used with the software delay function */
	const bsp_delay_units_t bsp_delay_units = BSP_DELAY_UNITS_MILLISECONDS;
	/* Set the blink frequency (must be <= bsp_delay_units */
    const uint32_t freq_in_hz = 6;
	/* Calculate the delay in terms of bsp_delay_units */
    const uint32_t delay = bsp_delay_units/freq_in_hz;
	/* LED type structure */
    bsp_leds_t leds;
	/* LED state variable */
    ioport_level_t level = IOPORT_LEVEL_HIGH;
    /* Button */
    ioport_level_t buttonS4;

    /* Get LED information for this board */
    R_BSP_LedsGet(&leds);

    /* If this board has no LEDs then trap here */
    if (0 == leds.led_count)
    {
        while(1);   // There are no LEDs on this board
    }

    int state = 0;

    while(1)
    {
        /* Read button S4*/
        g_ioport.p_api->pinRead(IOPORT_PORT_00_PIN_06, &buttonS4);

        /* State Machine */
        switch (state)
        {
            case 0:
                g_ioport.p_api->pinWrite(leds.p_leds[0], IOPORT_LEVEL_LOW);
                g_ioport.p_api->pinWrite(leds.p_leds[1], IOPORT_LEVEL_LOW);
                g_ioport.p_api->pinWrite(leds.p_leds[2], IOPORT_LEVEL_LOW);
                if (buttonS4 == IOPORT_LEVEL_HIGH)
                    state = 1;
                else
                    state = 5;
                break;
            case 1:
                g_ioport.p_api->pinWrite(leds.p_leds[0], IOPORT_LEVEL_HIGH); 
                g_ioport.p_api->pinWrite(leds.p_leds[1], IOPORT_LEVEL_LOW);
                g_ioport.p_api->pinWrite(leds.p_leds[2], IOPORT_LEVEL_LOW);
                if (buttonS4 == IOPORT_LEVEL_HIGH)
                    state = 2;
                else
                    state = 0;
                break;
            case 2:
                g_ioport.p_api->pinWrite(leds.p_leds[0], IOPORT_LEVEL_HIGH);
                g_ioport.p_api->pinWrite(leds.p_leds[1], IOPORT_LEVEL_HIGH);
                g_ioport.p_api->pinWrite(leds.p_leds[2], IOPORT_LEVEL_LOW);
                if (buttonS4 == IOPORT_LEVEL_HIGH)
                    state = 3;
                else
                    state = 1;
                break;
            case 3:
                g_ioport.p_api->pinWrite(leds.p_leds[0], IOPORT_LEVEL_HIGH);
                g_ioport.p_api->pinWrite(leds.p_leds[1], IOPORT_LEVEL_HIGH);
                g_ioport.p_api->pinWrite(leds.p_leds[2], IOPORT_LEVEL_HIGH);
                if (buttonS4 == IOPORT_LEVEL_HIGH)
                    state = 4;
                else
                    state = 2;
                break;
            case 4:
                g_ioport.p_api->pinWrite(leds.p_leds[0], IOPORT_LEVEL_LOW);
                g_ioport.p_api->pinWrite(leds.p_leds[1], IOPORT_LEVEL_HIGH);
                g_ioport.p_api->pinWrite(leds.p_leds[2], IOPORT_LEVEL_HIGH);
                if (buttonS4 == IOPORT_LEVEL_HIGH)
                    state = 5;
                else
                    state = 3;
                break;
            case 5:
                g_ioport.p_api->pinWrite(leds.p_leds[0], IOPORT_LEVEL_LOW);
                g_ioport.p_api->pinWrite(leds.p_leds[1], IOPORT_LEVEL_LOW);
                g_ioport.p_api->pinWrite(leds.p_leds[2], IOPORT_LEVEL_HIGH);
                if (buttonS4 == IOPORT_LEVEL_HIGH)
                    state = 0;
                else
                    state = 4;
                break;
        }

        /* Delay */
        R_BSP_SoftwareDelay(delay, bsp_delay_units);
    }
}
