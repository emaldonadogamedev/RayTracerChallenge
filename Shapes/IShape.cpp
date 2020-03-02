#include <Utilities/precompiled/precompiled.h>

#include "IShape.h"

RayTracer::Shapes::IShape::IShape(const Vector3& pos /*= Vector3(0,0,0)*/, const Vector3& rot /*= Vector3(0,0,0)*/, const Vector3& scale /*= Vector3(1,1,1)*/, Rendering::BaseMaterial* material /*= nullptr*/) :m_position(pos)
, m_rotation(rot)
, m_scale(scale)
, m_shapeMaterial(material)
{
	UpdateTransformationMatrices();
}

RayTracer::Shapes::IShape::~IShape()
{
}

const Vector3& RayTracer::Shapes::IShape::GetPosition() const
{
	return m_position;
}

const Vector3& RayTracer::Shapes::IShape::GetScale() const
{
	return m_scale;
}

const Vector3& RayTracer::Shapes::IShape::GetRotation() const
{
	return m_rotation;
}

void RayTracer::Shapes::IShape::SetTransformData(const Vector3& pos, const Vector3& rot, const Vector3& scale)
{
	m_position = pos;
	m_rotation = rot;
	m_scale = scale;

	UpdateTransformationMatrices();
}

void RayTracer::Shapes::IShape::UpdateTransformationMatrices()
{
	m_transformMtx = 
		Matrix4x4::GetScaleMatrix(m_scale.x, m_scale.y, m_scale.z);
		//* Matrix4x4::GetTranslationMatrix(m_position.x, m_position.y, m_position.z);

		//TODO: test with scale and Rot, then 
		//* Matrix4x4::GetRotationMatrix_X(m_rotation.x)
		//* Matrix4x4::GetRotationMatrix_Y(m_rotation.y)
		//* Matrix4x4::GetRotationMatrix_Z(m_rotation.z);

	m_invTransformMtx = m_transformMtx.GetInverse();
}