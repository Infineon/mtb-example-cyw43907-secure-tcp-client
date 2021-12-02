/******************************************************************************
* File Name:   secure_tcp_client.h
*
* Description: This file contains declaration of task related to secure TCP
* client operation.
*
*******************************************************************************
* $ Copyright 2021 Cypress Semiconductor $
*******************************************************************************/

#ifndef SECURE_TCP_CLIENT_H_
#define SECURE_TCP_CLIENT_H_

/*******************************************************************************
* Macros
********************************************************************************/
/* Maximum number of connection retries to the TCP server. */
#define MAX_TCP_SERVER_CONN_RETRIES           (5)

/* Length of the TCP data packet. */
#define MAX_TCP_DATA_PACKET_LENGTH            (20)

/* Length of the LED ON/OFF command issued from the TCP server. */
#define TCP_LED_CMD_LEN                       (1)

/* Set this macro to '1' to enable IPv6 protocol. Default value is '0' to use
 * IPv4 protocol.
 */
#define USE_IPV6_ADDRESS                      (0)
#define TCP_SERVER_PORT                       (50007)
#define RTOS_TICK_TO_WAIT                     (50u)
#define UART_INPUT_TIMEOUT_MS                 (1u)
#define UART_BUFFER_SIZE                      (50u)

/*******************************************************************************
* Function Prototype
********************************************************************************/
void tcp_secure_client_task(void *arg);

#endif /* SECURE_TCP_CLIENT_H_ */
