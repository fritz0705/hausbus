#include <avr/io.h>
#include <avr/interrupt.h>

#include "target.h"
#include "bus.h"
#include "bits.h"

static uint8_t pwm_counter;
static uint8_t pwm_red = 0xff;
static uint8_t pwm_blue = 0x88;
static uint8_t pwm_green = 0x00;

static uint8_t recv_counter = 0;

void slave_TIMER0_COMPA() {
	if (pwm_counter < pwm_red)
		bit_set(*PORT_RGB, PIN_RED);
	else
		bit_clear(*PORT_RGB, PIN_RED);

	if (pwm_counter < pwm_blue)
		bit_set(*PORT_RGB, PIN_BLUE);
	else
		bit_clear(*PORT_RGB, PIN_BLUE);

	if (pwm_counter < pwm_green)
		bit_set(*PORT_RGB, PIN_GREEN);
	else
		bit_clear(*PORT_RGB, PIN_GREEN);

	++pwm_counter;
}

void slave_USART_RX() {
	uint8_t byte = UDR;
	bit_flip(*PORT_STATUS, PIN_STATUS);

	switch (recv_counter) {
		case 0:
			pwm_red = byte;
			break;
		case 1:
			pwm_green = byte;
			break;
		case 2:
			pwm_blue = byte;
			break;
	}

	if (++recv_counter > 2)
		recv_counter = 0;
}

_Noreturn int slave() {
	bit_set(*DDR_STATUS, PIN_STATUS);
	bit_set(*DDR_RGB, PIN_RED);
	bit_set(*DDR_RGB, PIN_BLUE);
	bit_set(*DDR_RGB, PIN_GREEN);

	TCCR0A = (1 << WGM01);
	TCCR0B = (1 << CS00);
	OCR0A = 240;
	TIMSK = (1 << OCIE0A);
	TIFR = (1 << OCF0A);

	bus_init();

	sei();

	while(1);
}
