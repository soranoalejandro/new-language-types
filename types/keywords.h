#pragma once
#include "avr/pgmspace.h"

typedef struct nl_dictionary_entry {
	uint8_t len;
	uint8_t sum;
	uint8_t data[];
} nl_dictionary_entry;


const __flash uint8_t Keywords [] = {
	7, 0, 'i','f',' ',' ',' ',' ',' ',
	7, 0, 'f','o','r',' ',' ',' ',' ',
	7, 0, 'e','l','s','e',' ',' ',' ',
	7, 0, 'w','h','i','l','e',' ',' ',
	7, 0, 'm','a','t','c','h',' ',' ',
};