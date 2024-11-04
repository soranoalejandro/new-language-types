#pragma once

#define low_nibble(b)		( b & 0x0f )
#define high_nibble(b)		( (b >> 4) & 0x0f )
#define nibble_swap(b)		( (b >> 4) | (b << 4) )
#define nibble_to_bcd(n)	( n < 10? n : n - 10 + 0x10 )
#define nibble_to_ascii(n)	( n < 10? d + '0' : d + 'A' )

#define u8_to_hex_ascii_buffer	(buffer, n) { buffer[0] = nibble_to_ascii(low_nibble(n)); buffer[1] = nibble_to_ascii(high_nibble(n)); }

