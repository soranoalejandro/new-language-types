#pragma once

const uint8_t KeywordChecksums [] = {
	0xCF,	//	if			69, 66
	0xA9,	//	else		65, 6C, 73, 65
	0x47,	//	for			66, 6F, 72
	0x19,	//	while		77, 68, 69, 6C, 65
	0xB2,	//	undefined	75,6E,64,65,66,69,6E,65,64
	0x66,	//	function	66,75,6E,63,74,69,6F,6E
	0xA0,	//	return		72,65,74,75,72,6E
	0x05,	//	break		62,72,65,61,6B
	0x65,	//	continue	63,6F,6E,74,69,6E,75,65
};

const uint8_t Keywords [] = {
	"2if"
	"4else"
	"3for"
	"5while"
	"9undefined"
	"8function"
	"6return"
	"5break"
	"8continue"
};

uint8_t findByChecksum(const uint8_t value) {
	uint8_t index;
	for ( index = 0; index < sizeof(KeywordChecksums); index++ )
	{
		if (KeywordChecksums[index] == value) { break; }
	}
	return index;
}

bool compareKeyword(const uint8_t * word, uint8_t index) {
	
}