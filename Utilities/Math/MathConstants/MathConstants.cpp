#include <Utilities/precompiled/precompiled.h>
#include "MathConstants.h"

float RayTracer::Math::MathConstants::ToRadians(const float degrees)
{
	return degrees * (PI / 180.f);
}

float RayTracer::Math::MathConstants::ToDegrees(const float radians)
{
	return (180.f / PI) * radians;
}

const float RayTracer::Math::MathConstants::PIdiv4 = 3.14159 / 4.0f;
const float RayTracer::Math::MathConstants::PIdiv2 = 3.14159 / 2.0f;
const float RayTracer::Math::MathConstants::PI = 3.14159;
const float RayTracer::Math::MathConstants::TwoPI = 3.14159 * 2.0f;