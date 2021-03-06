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
	//const Ray transformedRay = m_invTransformMtx * ray;

	const Vector3 sphereToRay = ray.m_origin - m_position;// - Vector3(0,0,0);

	const float a = ray.m_direction.LengthSquared();
	const float b = 2.0f * ray.m_direction.Dot(sphereToRay);
	const float c = sphereToRay.LengthSquared() - 1.0f;

	const float discriminant = (b*b) - (4.0f * a * c);

	if (discriminant <= MY_EPSILON)
	{
		//no intersection
		intersectionData.m_shapeIntersected = nullptr;
		return false;
	}

	const float descriminantSqrt = std::sqrtf(discriminant);
	const float TwoA = 2.0f * a;

	const float t1 = (-b - descriminantSqrt) / TwoA;
	const float t2 = (-b + descriminantSqrt) / TwoA;

	if (t1 <= 0.f && t2 <= 0.f)
	{
		//t values are neg, so no intersection, or intersection with object that's behind the cam.
		intersectionData.m_shapeIntersected = nullptr;
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

Vector3 RayTracer::Shapes::Shpere::CalculateNormal(const Vector3& intersectionPoint) const
{
	//Old way, assumming that the shape is always at the position in world space, no other transformations
	return (intersectionPoint - m_position).Normalized();

	//Vector4 objSpacePos = m_invTransformMtx * Vector4(intersectionPoint.x, intersectionPoint.y, intersectionPoint.z, 1.0f);
	//
	//Vector4 worldSpaceNormal = (m_transformMtx * objSpacePos);
	//worldSpaceNormal.w = 0.f;
	//
	//worldSpaceNormal.Normalize();
	//
	//return Vector3(worldSpaceNormal.x, worldSpaceNormal.y, worldSpaceNormal.z);
}