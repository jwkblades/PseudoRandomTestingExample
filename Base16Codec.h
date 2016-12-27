#ifndef __BASE_16_CODEC_H
#define __BASE_16_CODEC_H

#include "Codec.h"

class Base16
{
public:
	static Codec encode(const Codec& rawData);
	static Codec decode(const Codec& encodedData);
};

#endif
