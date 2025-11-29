// Math Utils
//
// Namespace with math functions.

#pragma once
#include "vector_2.h"

namespace core
{
	namespace utils
	{
		namespace math
		{
			// Returns a random int between min and max.
			int randomInt(int min, int max);

			// Generates a random point between mins and maxs.
			core::data::Vector2 randomPoint(int minX, int maxX, int minY, int maxY);
		}
	}
}

