#pragma once

#include "../../Shapes/IShape.h"

namespace RayTracer
{
	namespace Shapes
	{
		class Shpere : public IShape
		{
			public:
				Shpere();
				~Shpere();

				virtual bool Intersects(const Math::Ray& ray, IntersectionData& intersectionData) const override;
				Vector3 CalculateNormal(const Vector3& intersectionPoint) const override;
		};
	}	
}