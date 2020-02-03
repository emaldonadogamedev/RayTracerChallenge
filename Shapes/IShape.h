#pragma once

#include "../Utilities/Math/Vector3/Vector3.h"

using RayTracer::Math::Vector3;

namespace RayTracer
{
	namespace Math {
		class Ray;
		class IntersectionData;
	}

	namespace Shapes
	{


		class IShape
		{
			public:
				virtual bool Intersects(const Math::Ray& ray, Math::IntersectionData& intersectionData) const = 0;

				//Transform data
				Vector3 m_position;
				Vector3 m_rotation;
				Vector3 m_scale;
		};
	}
}