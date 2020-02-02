#pragma once

#include <Utilities/Math/Vector3/Vector3.h>

namespace RayTracer
{
	namespace Math
	{
		class Ray
		{
			public:
				Ray(const Vector3& origin, const Vector3& direction)
					:m_origin(origin)
					,m_direction(direction)
				{
				}
				~Ray()
				{
				}

				Vector3 Evaluate(const float t) const
				{
					return m_origin + (m_direction * t);
				}

			protected:
				const Vector3 m_origin;
				const Vector3 m_direction;
		};
	}
}