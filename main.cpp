
#include <iostream>
#include <cstring>
#include "Base16Codec.h"

using namespace std;

int main(void)
{
	std::size_t size = 30;
	char* testString = new char[size];

	strncpy(testString, "BetaWar", size);

	Codec encoded = Base16::encode({testString, strlen(testString)});
	cout << "Encoded: " << encoded.data << endl;

	Codec decoded = Base16::decode(encoded);
	cout << "Decoded: " << decoded.data << " (" << decoded.length << ")" << endl;

	return 0;
}
