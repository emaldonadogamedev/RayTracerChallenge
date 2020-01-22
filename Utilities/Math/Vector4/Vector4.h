#pragma once

#include <iostream>

namespace RayTracer
{
	namespace Math
	{
		class Vector4
		{
		public:
			Vector4(float x = 0.f, float y = 0.f, float z = 0.f, float w = 0.0f);
			~Vector4();

			float Dot(const Vector4& rhs) const;			

			friend Vector4 operator+(const Vector4& rhs, const Vector4& lhs);
			friend Vector4 operator-(const Vector4& rhs, const Vector4& lhs);
			friend float operator*(const Vector4& rhs, const Vector4& lhs);

			friend std::ostream& operator<<(std::ostream& output, const Vector4& value);

			float x;
			float y;
			float z;
			float w;
		};
	}
}