#include <avr/io.h>

#include "target.h"

void bus_init() {
	int baud = F_CPU / (BAUD * 16L) - 1;
	UBRRH = baud >> 8;
	UBRRL = baud;

	UCSRB = (1 << RXEN) | (1 << RXCIE);
}
