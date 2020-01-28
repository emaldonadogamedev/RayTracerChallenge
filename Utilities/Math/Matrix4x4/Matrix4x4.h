#pragma once

#include "../SquareMatrix/SquareMatrix.h"

namespace RayTracer
{
	namespace Math
	{
		class Matrix4x4 : public SquareMatrix
		{
			public:
				Matrix4x4();
				~Matrix4x4();

				void SetToTranslationMatrix(float xPos, float yPos, float zPos);
				void SetToRotationMatrix(float xRot, float yRot, float zRot);
				void SetToScaleMatrix(float xScal, float yScal, float zScal);

				static Matrix4x4 GetTranslationMatrix(float xPos, float yPos, float zPos);
				static Matrix4x4 GetRotationMatrix(float xRot, float yRot, float zRot);
				static Matrix4x4 GetScaleMatrix(float xRot, float yRot, float zRot);

				virtual Matrix4x4& operator=(const Matrix4x4& rhs);
		};
	}
}