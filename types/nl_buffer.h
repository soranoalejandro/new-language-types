#pragma once
#include <avr/pgmspace.h>


typedef struct nl_buffer {
	uint8_t len;
	uint8_t sum;
	uint8_t data[];
} nl_buffer;

typedef nl_buffer nl_name;

void copy_c_string_to_nl_buffer(const char *str, nl_buffer *buffer) {
	uint8_t *destination = &buffer->data[0];
	uint8_t sum = 0;
	uint8_t data;
	do {
		data = *str++;
		if(data == '\0') break;
		sum += data;
		*destination++ = data;
	} while (1);
	uint8_t len = destination - 2 - (uint8_t *)buffer;
	buffer->len = len;
	buffer->sum = sum;
}

void copy_c_string_to_nl_buffer_p(const char *str, nl_buffer *buffer) {
	uint8_t *destination = &buffer->data[0];
	uint8_t sum = 0;
	uint8_t data;
	do {
		data = pgm_read_byte(str++);
		if(data == '\0') break;
		sum += data;
		*destination++ = data;
	} while (1);
	uint8_t len = destination - 2 - (uint8_t *)buffer;
	buffer->len = len;
	buffer->sum = sum;
}