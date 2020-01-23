#pragma once

#include <iostream>

using std::ostream;

namespace RayTracer 
{
	namespace Math 
	{
		class Vector2 
		{
			public:
				Vector2(float _x = 0.f, float _y = 0.f);
				~Vector2();

				float Dot(const Vector2& rhs) const;
				float Length() const;
				float LengthSquared() const;
				Vector2 Normalized() const;
				void Normalize();
				void Zero();

				friend Vector2 operator+(const Vector2& lhs, const Vector2& rhs);
				friend Vector2 operator+(const Vector2& lhs, const float rhs);

				friend Vector2 operator-(const Vector2& lhs, const Vector2& rhs);
				friend Vector2 operator-(const Vector2& lhs, const float rhs);
				Vector2 operator-()const;

				friend Vector2 operator*(const Vector2& lhs, const Vector2& rhs);
				friend Vector2 operator*(const Vector2& lhs, const float rhs);

				friend Vector2 operator/(const Vector2& lhs, const float rhs);

				Vector2& operator=(const Vector2& rhs);

				friend ostream& operator<<(std::ostream& output, const Vector2& value);

				float x;
				float y;
		};
	}
}