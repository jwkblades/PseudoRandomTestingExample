#include "Base16Codec.h"

Codec Base16::encode(const Codec& rawData)
{
	static const char* chars = "0123456789abcdef";
	std::size_t returnSize = rawData.length * 2;
	char* encoded = new char[returnSize];
	std::size_t j = 0;

	for (std::size_t i = 0; i < rawData.length; i++)
	{
		encoded[j] = chars[(rawData.data[i] >> 4) & 0x0F];
		j++;
		encoded[j] = chars[rawData.data[i] & 0x0F];
		j++;
	}

	return {encoded, returnSize};
}

Codec Base16::decode(const Codec& encodedData)
{
	std::size_t returnSize = encodedData.length / 2;
	char* decoded = new char[returnSize];
	std::size_t j = 0;

	for (std::size_t i = 0; i < encodedData.length;)
	{
		decoded[j] = 0;
		for (int z = 0; z < 2; z++)
		{
			char c = encodedData.data[i++];
			if (c >= 'A' && c <= 'F')
			{
				c += 'a' - 'A';
			}

			if (c >= 'a' && c <= 'f')
			{
				c -= 'a' - 10;
			}
			else if (c >= '0' && c <= '9')
			{
				c -= '0';
			}

			decoded[j] |= (c << (4 * (1 - z)));
		}
		j++;
	}
	return {decoded, returnSize};
}
