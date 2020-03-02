#include <Utilities/precompiled/precompiled.h>
#include "MathUtilities.h"

float RayTracer::Math::MathUtilities::ToRadians(const float degrees)
{
	return degrees * (PI / 180.f);
}

float RayTracer::Math::MathUtilities::ToDegrees(const float radians)
{
	return (180.f / PI) * radians;
}

RayTracer::Math::Vector3 RayTracer::Math::MathUtilities::Reflect(const Vector3& in, const Vector3& normal)
{
	return in - (normal * 2.0f) * in.Dot(normal);
}

RayTracer::Math::Vector4 RayTracer::Math::MathUtilities::Reflect(const Vector4& in, const Vector4& normal)
{
	return in - (normal * 2.0f) * in.Dot(normal);
}

const float RayTracer::Math::MathUtilities::PIdiv4 = 3.14159 / 4.0f;
const float RayTracer::Math::MathUtilities::PIdiv2 = 3.14159 / 2.0f;
const float RayTracer::Math::MathUtilities::PI = 3.14159;
const float RayTracer::Math::MathUtilities::TwoPI = 3.14159 * 2.0f;