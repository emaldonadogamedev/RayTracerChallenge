#include <Utilities/precompiled/precompiled.h>

#include "Ray.h"
#include "../../../Utilities/Math/Vector4/Vector4.h"
#include "../../../Utilities/Math/Matrix4x4/Matrix4x4.h"

RayTracer::Math::Ray::Ray(const Vector3& origin, const Vector3& direction)
	:m_origin(origin)
	,m_direction(direction)
{

}

RayTracer::Math::Ray::~Ray()
{

}

RayTracer::Math::Vector3 RayTracer::Math::Ray::Evaluate(const float t) const
{
	return m_origin + (m_direction * t);
}

RayTracer::Math::Ray RayTracer::Math::operator*(const Matrix4x4& lhs, const Ray& rhs)
{
	const Vector4 orgTransformed = lhs * Vector4(rhs.m_origin.x, rhs.m_origin.y, rhs.m_origin.z, 1.0f);
	const Vector4 dirTransformed = lhs * Vector4(rhs.m_direction.x, rhs.m_direction.y, rhs.m_direction.z, 0.f);

	return Ray(
		Vector3(orgTransformed.x, orgTransformed.y, orgTransformed.z),
		Vector3(dirTransformed.x, dirTransformed.y, dirTransformed.z)
	);

}
