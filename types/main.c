
#include <avr/io.h>
#include <avr/pgmspace.h>
#include "nl_buffer.h"
#include "variables.h"
#include "keywords.h"
#include "scanner.h"
#include "code.h"
//nl_buffer name;//copy_c_string_to_nl_buffer_p(code, &name);

const __flash uint8_t mydata[] = "Mariana";

int main(void) {
	// uint8_t * store = line;
	scanLine_c(code, line);
	PORTB = Tokens;
	//const __flash uint8_t * index = mydata + DDRB;
	//PINB = *index++;
	//PINB = *index++;
	//PINB = *index++;
	while (1) 
    {
		
    }
}
