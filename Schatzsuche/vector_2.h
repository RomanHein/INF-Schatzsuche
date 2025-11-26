#pragma once

namespace core
{
	namespace data
	{
		struct Vector2
		{
			int x, y;

			Vector2 operator+(const Vector2& other) const;
			Vector2& operator+=(const Vector2& other);
			bool operator==(const Vector2& other) const;
		};
	}
}