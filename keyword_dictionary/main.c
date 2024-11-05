#include <avr/io.h>
#include "keyword_dictionary.h"

int main(void) {
	PORTC = findByChecksum(0xA0 + GPIOR0);
	GPIOR1 = 35 >> 1;
	PORTB = 25;
}