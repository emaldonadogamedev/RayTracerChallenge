#pragma once

#include <iostream>

using std::ostream;

namespace RayTracer
{
	namespace Math
	{
		struct Color 
		{
			Color(unsigned int _r = 0, unsigned int _g = 0, unsigned int _b = 0, unsigned int _a = 255)
				:r(_r)
				,g(_g)
				,b(_b)
				,a(_a)
			{
				
			}
			
			unsigned int r, g, b, a;

			static const unsigned int s_MAX_COLOR_VALUE = 255U;
		};

		class Vector4
		{
		public:
			Vector4(float _x = 0.f, float _y = 0.f, float _z = 0.f, float _w = 0.f);
			~Vector4();

			float Dot(const Vector4& rhs) const;
			float Length() const;
			float LengthSquared() const;
			Vector4 Normalized() const;
			void Normalize();
			void Zero();
			Vector4 AsVectorXYZ() const;
			Vector4 AsPointXYZ() const;
			Color AsColor() const;

			friend Vector4 operator+(const Vector4& lhs, const Vector4& rhs);
			friend Vector4 operator+(const Vector4& lhs, const float rhs);

			friend Vector4 operator-(const Vector4& lhs, const Vector4& rhs);
			friend Vector4 operator-(const Vector4& lhs, const float rhs);
			Vector4 operator-()const;

			friend Vector4 operator*(const Vector4& lhs, const Vector4& rhs);
			friend Vector4 operator*(const Vector4& lhs, const float rhs);

			friend Vector4 operator/(const Vector4& lhs, const float rhs);

			Vector4& operator=(const Vector4& rhs);

			friend ostream& operator<<(std::ostream& output, const Vector4& value);

			union
			{
				struct
				{
					float x;
					float y;
					float z;
					float w;
				};

				float m_data[4];
			};
		};
	}
}