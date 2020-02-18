#pragma once

#include <iostream>

using std::ostream;

namespace RayTracer
{
	namespace Math
	{
		class Vector3
		{
		public:
			Vector3(float _x = 0.f, float _y = 0.f, float _z = 0.f);
			~Vector3();

			float Dot(const Vector3& rhs) const;
			Vector3 Cross(const Vector3& rhs) const;
			float Length() const;
			float LengthSquared() const;
			Vector3 Normalized() const;
			void Normalize();
			void Zero();

			friend Vector3 operator+(const Vector3& lhs, const Vector3& rhs);
			friend Vector3 operator+(const Vector3& lhs, const float rhs);

			friend Vector3 operator-(const Vector3& lhs, const Vector3& rhs);
			friend Vector3 operator-(const Vector3& lhs, const float rhs);
			Vector3 operator-()const;

			friend Vector3 operator*(const Vector3& lhs, const Vector3& rhs);
			friend Vector3 operator*(const Vector3& lhs, const float rhs);

			friend Vector3 operator/(const Vector3& lhs, const float rhs);

			Vector3& operator=(const Vector3& rhs);

			friend ostream& operator<<(std::ostream& output, const Vector3& value);

			union
			{
				struct 
				{
					float x;
					float y;
					float z;
				};

				float m_data[3];
			};

			static const Vector3 X_POS;
			static const Vector3 Y_POS;
			static const Vector3 Z_POS;
		};
	}
}