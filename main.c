/******************************************************************************
* File Name:   main.c
*
* Description: This is the source code for the CYW43907 Secure TCP Client Example
*              for ModusToolbox.
*
* Related Document: See README.md
*
*
*******************************************************************************
* $ Copyright 2021-2023 Cypress Semiconductor $
*******************************************************************************/

/* Header file includes */
#include "cyhal.h"
#include "cybsp.h"
#include "cy_retarget_io.h"

/* FreeRTOS header file */
#include <FreeRTOS.h>
#include <task.h>

/* Secure TCP client task header file. */
#include "secure_tcp_client.h"

/******************************************************************************
* Macros
********************************************************************************/
/* RTOS related macros. */
#define TCP_SECURE_CLIENT_TASK_STACK_SIZE  (5 * 1024)
#define TCP_SECURE_CLIENT_TASK_PRIORITY    (1)

/*******************************************************************************
* Function Name: main
********************************************************************************
* Summary:
* This is the main function for CYW43907 CPU. It does
*    1. UART console output and input
*    2. Uses SSL certificates for TCP connection 
*    3. LED ON/OFF based on the TCP packet received
*
* Parameters:
*  void
*
* Return:
*  int
*
*******************************************************************************/
int main(void)
{
    /* Initialize the device and board peripherals */
    CY_ASSERT(CY_RSLT_SUCCESS == cybsp_init());
    
    /* Enable global interrupts */
    __enable_irq();

    /* Initialize retarget-io to use the debug UART port */
    cy_retarget_io_init(CYBSP_DEBUG_UART_TX, CYBSP_DEBUG_UART_RX,
                        CY_RETARGET_IO_BAUDRATE);

    /* Initialize the User LED. */
    cyhal_gpio_init(CYBSP_USER_LED2, CYHAL_GPIO_DIR_OUTPUT,
                        CYHAL_GPIO_DRIVE_STRONG, CYBSP_LED_STATE_OFF);

    /* \x1b[2J\x1b[;H - ANSI ESC sequence for clear screen */
    printf("\x1b[2J\x1b[;H");

    printf("****************** "
           "CYW43907 Secure TCP Client"
           "****************** \r\n\n");

    /* Create the task to establish a secure connection to a remote TCP server */
    xTaskCreate(tcp_secure_client_task, "Network task", TCP_SECURE_CLIENT_TASK_STACK_SIZE,
                NULL, TCP_SECURE_CLIENT_TASK_PRIORITY, NULL);

    /* Start the FreeRTOS scheduler */
    vTaskStartScheduler();

    /* Should never get here */
    CY_ASSERT(0);

}

/* [] END OF FILE */
