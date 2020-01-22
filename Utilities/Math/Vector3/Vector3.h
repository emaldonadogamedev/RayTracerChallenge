#pragma once

#include <iostream>

namespace RayTracer
{
	namespace Math
	{
		class Vector3
		{
		public:
			Vector3(float x = 0.f, float y = 0.f, float z = 0.f);
			~Vector3();

			float Dot(const Vector3& rhs) const;

			friend Vector3 operator+(const Vector3& rhs, const Vector3& lhs);
			friend Vector3 operator-(const Vector3& rhs, const Vector3& lhs);
			friend float operator*(const Vector3& rhs, const Vector3& lhs);

			friend std::ostream& operator<<(std::ostream& output, const Vector3& value);

			float x;
			float y;
			float z;;
		};
	}
}