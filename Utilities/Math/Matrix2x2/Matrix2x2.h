#pragma once

#include <vector>

using std::vector;

namespace RayTracer
{
	namespace Math 
	{
		class Matrix2x2 
		{
			public:
				Matrix2x2();
				~Matrix2x2();

				float Determinant() const;
				

				friend Matrix2x2 operator*(const Matrix2x2& lhs, const Matrix2x2& rhs);
				
				Matrix2x2& operator=(const Matrix2x2& rhs);

				static const Matrix2x2 IDENDITY;

			protected:
				
		};
	}
}