#include "vector_2.h"

namespace core
{
	namespace data
	{
		Vector2 Vector2::operator+(const Vector2& other) const
		{
			return Vector2{ this->x + other.x, this->y + other.y };
		}

		Vector2& Vector2::operator+=(const Vector2& other)
		{
			this->x += other.x;
			this->y += other.y;

			return *this;
		}

		bool Vector2::operator==(const Vector2& other) const
		{
			return this->x == other.x && this->y == other.y;
		}
	}
}