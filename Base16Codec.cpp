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

#include <iostream>
using namespace std;

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
				cout << "Found capital: '" << c << "'" << endl;
				c += 'a' - 'A';
			}

			if (c >= 'a' && c <= 'f')
			{
				cout << "Found letter: '" << c << "' ";
				c -= 'a' - 10;
				cout << "Value: " << (int)c << endl;
			}
			else if (c >= '0' && c <= '9')
			{
				cout << "Found digit: '" << c << "' ";
				c -= '0';
				cout << "Value: " << (int)c << endl;
			}
			else
			{
				cerr << "==== WHAT THE HECK?!" << endl << endl;
			}

			if (z == 0)
			{
				decoded[j] = (c << 4) & 0xF0;
			}
			else
			{
				decoded[j] |= c & 0x0F;
			}
		}
		cout << "Decoded is now: '" << decoded[j] << "'" << endl;
		j++;
	}
	return {decoded, returnSize};
}
