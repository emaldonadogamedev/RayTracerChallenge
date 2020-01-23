#pragma once

#include "../Utilities/Math/Vector4/Vector4.h"

using RayTracer::Math::Vector4;

namespace RayTracer
{
	namespace Shapes
	{
		class IShape
		{
			protected:
				Vector4 m_position;
		};
	}
}