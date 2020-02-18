#pragma once

namespace RayTracer
{
	namespace Math
	{
		class MathConstants
		{
			public:
				static float ToRadians(const float degrees);
				static float ToDegrees(const float radians);

				static const float PIdiv4;
				static const float PIdiv2;
				static const float PI;
				static const float TwoPI;
		};
	}
}