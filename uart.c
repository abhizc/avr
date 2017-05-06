/*
 * uart.c
 *
 *  Created on: Apr 30, 2017
 *      Author: nikagarw
 */

#include "uart.h"

uint8_t rxbyte;

ISR(USART0_RX_vect)
{
	rxbyte = UDR0;
}

void uart_send(uint8_t senddata)
{
//	uint8_t rxbyte;
	while((UCSR0A & (1<<UDRE0)) == 0);
	UDR0 = senddata;
}


uint8_t uart_receive()
{
	while((UCSR0A & (1<<RXC0)) == 0);
	return UDR0;
}


void uart_init()
{
	//Setup part
	UBRR0H = (uint8_t)(BPS>>8);
	UBRR0L = (uint8_t)(BPS);

	UCSR0B |= (1<<TXEN0) | (1<<RXEN0) | (1<<RXCIE0);

	sei();

	//Global interrupts

}






