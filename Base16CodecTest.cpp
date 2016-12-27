#include "gtest/gtest.h"

#include <cstdlib>
#include <ctime>

#include "Base16Codec.h"

TEST(Base16, randomEncodeCycle)
{
	for (int i = 0; i < 100; i++)
	{
		std::size_t size = std::rand() % 10240;
		char* data = new char[size];

		for (std::size_t j = 0; j < size; j++)
		{
			data[j] = std::rand() & 0xFF;
		}

		Codec encoded = Base16::encode({data, size});
		Codec decoded = Base16::decode(encoded);

		ASSERT_EQ(size, decoded.length);
		for (std::size_t j = 0; j < size; j++)
		{
			EXPECT_EQ(data[j], decoded.data[j]);
		}

		delete [] data;
		delete [] encoded.data;
		delete [] decoded.data;
	}
}
