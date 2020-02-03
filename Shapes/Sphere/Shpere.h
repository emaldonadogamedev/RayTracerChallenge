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

				virtual bool Intersects(const Math::Ray& ray, Math::IntersectionData& intersectionData) const override;
		};
	}	
}