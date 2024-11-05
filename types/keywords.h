#pragma once
#include "avr/pgmspace.h"

typedef struct nl_dictionary_entry {
	uint8_t len;
	uint8_t sum;
	uint8_t data[];
} nl_dictionary_entry;

typedef struct nl_keyword_entry {
	uint8_t len;
	uint8_t data[10];
} nl_keyword_entry;

const nl_keyword_entry Keywords_p [] = {
	{ 2, "if" },
	{ 4, "else" },
	{ 3, "for" },
	{ 5, "while" },
	{ 9, "undefined" },
	{ 8, "function" },
	{ 6, "return" },
	{ 5, "break" },
	{ 8, "continue" },
};

uint8_t compareKeyword(const uint8_t * word, const uint8_t index, const uint8_t len) {
	if (Keywords_p[index].len == len) {
		for ( uint8_t iterator = 0; iterator < len; iterator++ ) {
			if ( Keywords_p[index].data[iterator] != word[iterator] ) return 0;
		}
		return 1;
	}
	return 0;
}

const uint8_t KeywordChecksums [] = {
	0xCF,	//	if			69,66
	0xA9,	//	else		65,6C,73,65
	0x47,	//	for			66,6F,72
	0x19,	//	while		77,68,69,6C,65
	0xB2,	//	undefined	75,6E,64,65,66,69,6E,65,64
	0x66,	//	function	66,75,6E,63,74,69,6F,6E
	0xA0,	//	return		72,65,74,75,72,6E
	0x05,	//	break		62,72,65,61,6B
	0x65,	//	continue	63,6F,6E,74,69,6E,75,65
};

uint8_t findByChecksum(const uint8_t value) {
	uint8_t index;
	for ( index = 0; index < sizeof(KeywordChecksums); index++ )
	{
		if (KeywordChecksums[index] == value) { break; }
	}
	return index;
}
