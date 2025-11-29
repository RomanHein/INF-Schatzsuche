// Vector 2
//
// Data structure used to describe a point on a 2d map.

#pragma once

namespace core
{
	namespace data
	{
		struct Vector2
		{
			int x, y;

			//
			// === Operators ===
			//

			Vector2 operator+(const Vector2& other) const;
			Vector2& operator+=(const Vector2& other);
			bool operator==(const Vector2& other) const noexcept;
			bool operator!=(const Vector2& other) const noexcept;
			bool operator<(const Vector2& other) const noexcept;
			bool operator>(const Vector2& other) const noexcept;
		};
	}
}