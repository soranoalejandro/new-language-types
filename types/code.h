#pragma once

//const __flash uint8_t code [] =
const uint8_t code [] =

"uint8_t index; "
"for ( index = 0; index < sizeof(KeywordChecksums); index++ ) "
"{ "
	"if (KeywordChecksums[index] == value) { break; } "
"} "
"return index;  \n "

;

