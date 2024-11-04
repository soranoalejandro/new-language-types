#pragma once

//uint8_t lastChar;
//uint8_t tokenType;	//	1 number, 2 id
//uint8_t lengthOrDelimiter;

void token_unknown(uint8_t c);
void token_number(uint8_t c);
void token_id(uint8_t c);

//	scan function pointer
void (*scanFunction)(uint8_t c) = &token_unknown;

void token_number(uint8_t c) {
	if (c == ' ' || c == '\n'  || c == '\r') return;
	scanFunction = &token_unknown; return;
}

void token_id(uint8_t c) {
	if (c >= '0' && c <= '9' ) { return; }
	if (c >= 'A' && c <= 'Z' ) { return; }
	if (c >= 'a' && c <= 'z' ) { return; }
	scanFunction = &token_unknown; return;
}

void token_unknown(uint8_t c) {
	if (c == '\n' || c == '\r') return;
	if (c == ' ') return;
	if (c >= '0' && c <= '9' ) { scanFunction =& token_number; return; }
	if (c >= 'A' && c <= 'Z' ) { scanFunction =& token_id; return; }
	if (c >= 'a' && c <= 'z' ) { scanFunction =& token_id; return; }
	return;
}