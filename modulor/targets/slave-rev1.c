#include <avr/interrupt.h>
#include <avr/io.h>

const unsigned long F_CPU = 3686400;
const unsigned long BAUD = 9600;

volatile uint8_t *const DDR_RGB = &DDRB;
volatile uint8_t *const PORT_RGB = &PORTB;
const uint8_t PIN_RED = 2;
const uint8_t PIN_BLUE = 0;
const uint8_t PIN_GREEN = 4;

volatile uint8_t *const DDR_STATUS = &DDRD;
volatile uint8_t *const PORT_STATUS = &PORTD;
const uint8_t PIN_STATUS = 6;

extern _Noreturn int slave();
extern void slave_TIMER0_COMPA();
extern void slave_USART_RX();

ISR(USART_RX_vect) {
	slave_USART_RX();
}

ISR(TIMER0_COMPA_vect) {
	slave_TIMER0_COMPA();
}

int main() {
	slave();
}
