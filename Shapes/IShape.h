#pragma once

#include "../Utilities/Math/Vector3/Vector3.h"

using RayTracer::Math::Vector3;

class RayTracer::Math::Ray;

namespace RayTracer
{
	namespace Shapes
	{
		class IShape
		{
			public:
				virtual bool Intersects(const Ray& ray) const = 0;

			protected:
				Vector3 m_position;
		};
	}
}