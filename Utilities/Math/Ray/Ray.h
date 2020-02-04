#pragma once

#include "../../../Utilities/Math/Vector3/Vector3.h"

namespace RayTracer
{
	namespace Math
	{
		class Matrix4x4;

		class Ray
		{
			public:
				Ray(const Vector3& origin, const Vector3& direction);
				~Ray();

				Vector3 Evaluate(const float t) const;

				friend Ray operator*(const Matrix4x4& lhs, const Ray& rhs);

				const Vector3 m_origin;
				const Vector3 m_direction;
		};
	}
}