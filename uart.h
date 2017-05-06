/*
 * uart.h
 *
 *  Created on: Apr 30, 2017
 *      Author: nikagarw
 */

#ifndef UART_H_
#define UART_H_

#include<avr/io.h>
#include<avr/interrupt.h>

#define BR		9600
#define BPS		((F_CPU/(BR * 16UL)) - 1)

void uart_send(uint8_t senddata);
uint8_t uart_receive();
void uart_init();


#endif /* UART_H_ */
