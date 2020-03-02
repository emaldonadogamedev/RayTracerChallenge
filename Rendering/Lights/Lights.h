#pragma once
#include "../../Utilities/Math/Vector3/Vector3.h"
#include "../../Utilities/Math/Vector4/Vector4.h"

namespace RayTracer
{
	namespace Rendering
	{
		using namespace RayTracer::Math;

		//Basically a point light
		struct Light 
		{
			Vector3 position;
			Vector4 color;
		};
	}
}