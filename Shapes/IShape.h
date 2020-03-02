#pragma once

#include "../Utilities/Math/Matrix4x4/Matrix4x4.h"
#include "../Utilities/Math/Vector3/Vector3.h"

using RayTracer::Math::Matrix4x4;
using RayTracer::Math::Vector3;

namespace RayTracer
{
	namespace Math 
	{
		class Ray;
	}

	namespace Rendering
	{
		class BaseMaterial;
	}

	namespace Shapes
	{
		class IntersectionData;

		class IShape
		{
			public:
				IShape(const Vector3& pos = Vector3(0,0,0), const Vector3& rot = Vector3(0,0,0), const Vector3& scale = Vector3(1,1,1), Rendering::BaseMaterial* material = nullptr);

				~IShape();

				virtual bool Intersects(const Math::Ray& ray, IntersectionData& intersectionData) const = 0;
				virtual Vector3 CalculateNormal(const Vector3& intersectionPoint) const = 0;

				virtual const Vector3& GetPosition() const;
				virtual const Vector3& GetScale() const;
				virtual const Vector3& GetRotation() const;

				virtual void SetTransformData(const Vector3& pos, const Vector3& rot, const Vector3& scale);


				//Material Data
				Rendering::BaseMaterial* m_shapeMaterial;

			protected:

				void UpdateTransformationMatrices();

				//Transform data
				Vector3 m_position;
				Vector3 m_rotation;
				Vector3 m_scale;

				Matrix4x4 m_transformMtx;
				Matrix4x4 m_invTransformMtx;
		};
	}
}