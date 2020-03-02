#pragma once

#include "../../Utilities/Math/Vector4/Vector4.h"

namespace RayTracer
{
	namespace Math {
		class Vector3;
	}

	namespace Rendering
	{
		using namespace RayTracer::Math;

		struct Light;
		class PhongMaterial;

		extern Vector4 CaculatePhongLighting(PhongMaterial& material, const Light& light, const Vector3& point,  const Vector3& eyeVec, const Vector3& normal);
	}
}