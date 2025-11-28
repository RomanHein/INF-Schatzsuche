#include "math_utils.h"
#include <cstdlib>

namespace core
{
	namespace utils
	{
		namespace math
		{
			int math::randomInt(int min, int max)
			{
				return min + std::rand() % (max - min + 1);
			}

			core::data::Vector2 math::randomPoint(int minX, int maxX, int minY, int maxY)
			{
				return { randomInt(minX, maxX), randomInt(minY, maxY) };
			}
		}
	}
}