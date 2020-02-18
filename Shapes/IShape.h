#pragma once

#include "../Utilities/Math/Vector3/Vector3.h"

using RayTracer::Math::Vector3;

namespace RayTracer
{
	namespace Math 
	{
		class Ray;
	}

	namespace Shapes
	{
		class IntersectionData;

		class IShape
		{
			public:
				IShape(const Vector3& pos = Vector3(0,0,0), const Vector3& rot = Vector3(0,0,0), const Vector3& scale = Vector3(1,1,1))
					:m_position(pos)
					,m_rotation(rot)
					,m_scale(scale)
				{
				}

				~IShape()
				{
				}

				virtual bool Intersects(const Math::Ray& ray, IntersectionData& intersectionData) const = 0;
				virtual Vector3 CalculateNormal(const Vector3& intersectionPoint) const = 0;

				//Transform data
				Vector3 m_position;
				Vector3 m_rotation;
				Vector3 m_scale;
		};
	}
}