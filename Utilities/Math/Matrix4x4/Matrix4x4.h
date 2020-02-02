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

				static Matrix4x4 GetRotationMatrix_X(float xRot);
				static Matrix4x4 GetRotationMatrix_Y(float yRot);
				static Matrix4x4 GetRotationMatrix_Z(float zRot);

				static Matrix4x4 GetScaleMatrix(float xScale, float yScale, float zScale);

				static Matrix4x4 GetShearingMatrix();

				virtual Matrix4x4& operator=(const Matrix4x4& rhs);
				virtual Matrix4x4& operator=(const SquareMatrix& rhs);
		};
	}
}