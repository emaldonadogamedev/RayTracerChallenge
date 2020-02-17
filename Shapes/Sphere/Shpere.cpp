#include <Utilities/precompiled/precompiled.h>

#include "Shpere.h"
#include "../../Shapes/IntersectionData.h"
#include "../../Utilities/Math/Ray/Ray.h"

using namespace RayTracer::Math;

RayTracer::Shapes::Shpere::Shpere()
	:IShape()
{

}

RayTracer::Shapes::Shpere::~Shpere()
{

}

bool RayTracer::Shapes::Shpere::Intersects(const Ray& ray, IntersectionData& intersectionData) const
{
	const Vector3 sphereToRay = ray.m_origin - Vector3(0,0,0);

	const float a = ray.m_direction.LengthSquared();
	const float b = 2.0f * ray.m_direction.Dot(sphereToRay);
	const float c = sphereToRay.LengthSquared() - 1.0f;

	const float discriminant = (b*b) - (4.0f * a * c);

	if (discriminant <= MY_EPSILON)
	{
		//no intersection
		return false;
	}

	const float descriminantSqrt = std::sqrtf(discriminant);
	const float TwoA = 2.0f * a;

	const float t1 = (-b - descriminantSqrt) / TwoA;
	const float t2 = (-b + descriminantSqrt) / TwoA;

	if (t1 <= 0.f && t2 <= 0.f)
	{
		//t values are neg, so no intersection, or intersection with object that's behind the cam.
		return false;
	}

	intersectionData.m_shapeIntersected = this;

	if (t1 <= 0.f)
	{
		intersectionData.m_tValue = t2;
		intersectionData.m_tExtra = t1;
	}
	else if (t2 <= 0.f)
	{
		intersectionData.m_tValue = t1;
		intersectionData.m_tExtra = t2;
	}
	else 
	{
		intersectionData.m_tValue = std::min(t1, t2);
		intersectionData.m_tExtra = std::max(t1, t2);
	}

	return true;
}