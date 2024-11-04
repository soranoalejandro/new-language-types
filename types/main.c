
#include <avr/io.h>
#include <avr/pgmspace.h>
#include "nl_buffer.h"
#include "scanner.h"
//nl_buffer name;//copy_c_string_to_nl_buffer_p(code, &name);

const __flash char code [] =

"let x = 404_924_424_____23"
"do {"
"	*store++ = c;"
"	c = pgm_read_byte(address++);"
"} while (c >= '0' && c <= '9');"
"tokens++;"
"goto revisit;\n"
;

uint8_t tokens = 0;
uint8_t line[128] __attribute__ ((section (".noinit")));	// avoid zero initialization


void scanLine_p(const char * address) {
	uint8_t * store = line; uint8_t c;
	do {
		c = pgm_read_byte(address++);
		revisit:
		if (c == 0) return;
		while(c == ' ') { c = pgm_read_byte(address++); }
		// number
		if (c >= '0' && c <= '9') {
			do {
				*store++ = c;
				c = pgm_read_byte(address++);
				while (c == '_') { c = pgm_read_byte(address++); }
			} while (c >= '0' && c <= '9');
			tokens++;
			goto revisit;
		}
		// name
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_') {
			do {
				*store++ = c;
				c = pgm_read_byte(address++);
			} while ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9'));
			tokens++;
			goto revisit;
		}
		*store++ = c;
	} while (c != 0);
}

int main(void) {
	scanLine_p(code);
	PORTB = tokens;
	while (1) 
    {
		
    }
}