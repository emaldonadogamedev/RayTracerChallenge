#pragma once
#include "../Vector3/Vector3.h"
#include "../Vector4/Vector4.h"

namespace RayTracer
{
	namespace Math
	{
		class MathUtilities
		{
			public:
				static float ToRadians(const float degrees);
				static float ToDegrees(const float radians);

				static Vector3 Reflect(const Vector3& in, const Vector3& normal);
				static Vector4 Reflect(const Vector4& in, const Vector4& normal);

				static const float PIdiv4;
				static const float PIdiv2;
				static const float PI;
				static const float TwoPI;
		};
	}
}