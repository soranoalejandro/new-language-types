#pragma once

void scanLine_p(const __flash uint8_t * address, uint8_t * store) {
	uint8_t c; uint8_t tokens = 0;
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
			do {
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
	uint8_t u;
	
	do
	{
		u = *address++;
		unknown:
		if((u >= 'A') && (u <= 'z')) {
			if((u <= 'Z') || (u >= 'a')) {
				do
				{
					*store++ = u;
					u = *address++;
				} while ((u >= 'a') && (u <= 'z'));
				goto unknown;
			}
		}
	} while (u != 0);
}
