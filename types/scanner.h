#pragma once

void scanLine_p(const __flash uint8_t * address, uint8_t * store) {
	uint8_t c; uint8_t tokens = 0; uint8_t check;
	do {
		c = *address++;
		revisit:
		if (c == 0) { Tokens = tokens; return; }
		while(c == ' ') { c = *address++; }
		// number
		if (c >= '0' && c <= '9') {
			do {
				*store++ = c;
				c = *address++;
				while (c == '_') { c = *address++; }
			} while (c >= '0' && c <= '9');
			tokens++;
			goto revisit;
		}
		// name
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_') {
			check = 0;
			do {
				check += c;
				*store++ = c;
				c = *address++;
			} while ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9'));
			tokens++;
			goto revisit;
		}
		*store++ = c;
	} while (c != 0);
}

void scanLine_c(const uint8_t * address, uint8_t * store) {
	uint8_t u; uint8_t check, len;
	do
	{
		load_unknown:
		u = *address++;
		unknown:
		if((u >= 'A') && (u <= 'z')) {
			// lower case
			if(u >= 'a') {
				check = 0; len = 0;
				do {
					check += u; len++;
					*store++ = u;
					u = *address++;
				} while ((u >= 'a') && (u <= 'z'));
				if(u == '_' || ((u >= '0') && (u <= '9')) || ((u >= 'A') && (u <= 'Z'))) goto continue_mixed_character;
				const uint8_t keywordIndex = findByChecksum(check);
				if (keywordIndex < sizeof(KeywordChecksums)) {
					// possible keyword
					store -= len;
					if ( compareKeyword(store, keywordIndex, len ) ) {
						GPIOR2 = keywordIndex; // is a language reserved keyword
					}
					store += len;
				}
				*store++ = ' ';
				if (u == ' ') goto load_unknown;
				goto unknown;
			}
			// mixed case or underscore
			if(u <= 'Z' || u == '_') {
				check = 0; len = 0;
				continue_mixed_character:
				do {
					check += u; len++;
					*store++ = u;
					u = *address++;
				} while (((u >= 'a') && (u <= 'z')) || ((u >= 'A') && (u <= 'Z')) || ((u >= '0') && (u <= '9')) || u == '_');
				*store++ = ' ';
				if (u == ' ') goto load_unknown;
				goto unknown;
			}
		}
		// number
		if(u >= '0' && u <= '9') {
			len = 0;
			continue_number:
			// continue number after middle underscore characters
			do {
				len++;
				*store++ = u;
				u = *address++;
			} while (u >= '0' && u <= '9');
			if (u == '_') {
				do {
					u = *address++;
				} while (u == '_');
				if(u >= '0' && u <= '9') goto continue_number;
			}
			*store++ = ' ';
			if (u == ' ') goto load_unknown;
			goto unknown;
		}
		if (u == ' ') { do { u = *address++; } while ( u == ' '); goto unknown; }
	} while (u != 0);
}

// expected token types
/*
- lower case only: can be use to identify C like keywords (if, else, while)
- mixed case: general variable and function identifiers, can contain and start with _
- numbers:	can contain and ignore underscores '_' to visually separate the digits for better visualization.
- strings: accept string with ", ' or ` delimiters

*/