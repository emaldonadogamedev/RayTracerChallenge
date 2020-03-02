#include <Utilities/precompiled/precompiled.h>

#include "ShapeRenderer.h"

#include "../Lights/Lights.h"
#include "../Materials/Materials.h"
#include "../../Utilities/Math/Vector3/Vector3.h"
#include "../../Utilities/Math/MathConstants/MathUtilities.h"

using RayTracer::Math::Vector4;

Vector4 RayTracer::Rendering::CaculatePhongLighting(PhongMaterial& material, const Light& light, const Vector3& point, const Vector3& eyeVec, const Vector3& normal)
{
	const Vector4 effectiveColor = material.color * light.color;

	const Vector3 lightVec = (light.position - point).Normalized();

	const Vector4 ambient = effectiveColor * material.m_ambient;

	const float lightDotNormal = std::fmaxf(0.f, lightVec.Dot(normal));

	const Vector4 diffuse = effectiveColor * material.m_diffuse * lightDotNormal;

	const Vector3 reflectionVec = MathUtilities::Reflect(-lightVec, normal);
	
	float reflectDotEyeVec = std::fmaxf(0.f, reflectionVec.Dot(eyeVec));

	const Vector4 specular = std::pow(reflectDotEyeVec, material.m_shininess) * material.m_specular * light.color;

	return ambient + diffuse + specular;
}