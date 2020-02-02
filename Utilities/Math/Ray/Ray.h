#pragma once

#include <Utilities/Math/Vector3/Vector3.h>

namespace RayTracer
{
	namespace Math
	{
		class Ray
		{
			public:
				Ray(Vector3 origin, Vector3 direction)
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
				Vector3 m_origin;
				Vector3 m_direction;
		};
	}
}