#pragma once
#include "../../Utilities/Math/Vector4/Vector4.h"

namespace RayTracer
{
	using namespace RayTracer::Math;

	namespace Rendering
	{
		struct BaseMaterial
		{
			Vector4 color;
		};

		struct PhongMaterial : public BaseMaterial
		{
			float m_ambient;
			float m_diffuse;
			float m_specular;
			float m_shininess;// or roughness
		};
	}
}