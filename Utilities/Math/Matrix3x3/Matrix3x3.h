#pragma once

#include <iostream>

using std::ostream;

namespace RayTracer
{
	namespace Math
	{
		class Matrix3x3
		{
			public:
				Matrix3x3();
				~Matrix3x3();
		
				union {
					float m[9];
					float arr[3][3];
				};
		};
	}
}