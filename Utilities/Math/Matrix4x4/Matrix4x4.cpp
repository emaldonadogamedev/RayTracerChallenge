#include <Utilities/precompiled/precompiled.h>

#include "Matrix4x4.h"

using namespace RayTracer::Math;

RayTracer::Math::Matrix4x4::Matrix4x4()
	:SquareMatrix(4)
{
}

RayTracer::Math::Matrix4x4::Matrix4x4(const SquareMatrix& sqrMtx)
	: SquareMatrix(4)
{
	CopyValues(sqrMtx);
}

RayTracer::Math::Matrix4x4::~Matrix4x4()
{
}

void RayTracer::Math::Matrix4x4::SetToTranslationMatrix(float xPos, float yPos, float zPos)
{
	SetToIdentity();

	SetElement(0, 3, xPos);
	SetElement(1, 3, yPos);
	SetElement(2, 3, zPos);
}

void RayTracer::Math::Matrix4x4::SetToRotationMatrix_X(float xRot)
{
	const float cosAngle(std::cos(xRot));
	const float sinAngle(std::sin(xRot));

	SetToIdentity();

	SetElement(1, 1, cosAngle);
	SetElement(1, 2, -sinAngle);

	SetElement(2, 1, sinAngle);
	SetElement(2, 2, cosAngle);
}

void RayTracer::Math::Matrix4x4::SetToRotationMatrix_Y(float yRot)
{
	const float cosAngle(std::cos(yRot));
	const float sinAngle(std::sin(yRot));

	SetToIdentity();

	SetElement(0, 0, cosAngle);
	SetElement(0, 2, sinAngle);

	SetElement(2, 0, -sinAngle);
	SetElement(2, 2, cosAngle);
}

void RayTracer::Math::Matrix4x4::SetToRotationMatrix_Z(float zRot)
{
	const float cosAngle(std::cos(zRot));
	const float sinAngle(std::sin(zRot));

	SetToIdentity();

	SetElement(0, 0, cosAngle);
	SetElement(0, 1, -sinAngle);

	SetElement(1, 0, sinAngle);
	SetElement(1, 1, cosAngle);
}

void RayTracer::Math::Matrix4x4::SetToScaleMatrix(float xScal, float yScal, float zScal)
{
	SetToIdentity();

	SetElement(0, 0, xScal);
	SetElement(1, 1, yScal);
	SetElement(2, 2, zScal);
}

RayTracer::Math::Matrix4x4 RayTracer::Math::Matrix4x4::GetTranslationMatrix(float xPos, float yPos, float zPos)
{
	Matrix4x4 result;

	result.SetElement(0, 0, 1.0f);
	result.SetElement(1, 1, 1.0f);
	result.SetElement(2, 2, 1.0f);
	result.SetElement(3, 3, 1.0f);

	result.SetElement(0, 3, xPos);
	result.SetElement(1, 3, yPos);
	result.SetElement(2, 3, zPos);

	return result;
}

Matrix4x4 RayTracer::Math::Matrix4x4::GetRotationMatrix_X(float xRot)
{
	Matrix4x4 result;

	const float cosAngle(std::cos(xRot));
	const float sinAngle(std::sin(xRot));

	result.SetElement(0, 0, 1.0f);

	result.SetElement(1, 1, cosAngle);
	result.SetElement(1, 2, -sinAngle);

	result.SetElement(2, 1, sinAngle);
	result.SetElement(2, 2, cosAngle);

	result.SetElement(3, 3, 1.0f);

	return result;
}

Matrix4x4 RayTracer::Math::Matrix4x4::GetRotationMatrix_Y(float yRot)
{
	Matrix4x4 result;

	const float cosAngle(std::cos(yRot));
	const float sinAngle(std::sin(yRot));

	result.SetElement(1, 1, 1.0f);

	result.SetElement(0, 0, cosAngle);
	result.SetElement(0, 2, sinAngle);

	result.SetElement(2, 0, -sinAngle);
	result.SetElement(2, 2, cosAngle);

	result.SetElement(3, 3, 1.0f);

	return result;
}

Matrix4x4 RayTracer::Math::Matrix4x4::GetRotationMatrix_Z(float zRot)
{
	Matrix4x4 result;

	const float cosAngle(std::cos(zRot));
	const float sinAngle(std::sin(zRot));

	result.SetElement(2, 2, 1.0f);

	result.SetElement(0, 0, cosAngle);
	result.SetElement(0, 1, -sinAngle);

	result.SetElement(1, 0, sinAngle);
	result.SetElement(1, 1, cosAngle);

	result.SetElement(3, 3, 1.0f);

	return result;
}

Matrix4x4 RayTracer::Math::Matrix4x4::GetScaleMatrix(float xScale, float yScale, float zScale)
{
	Matrix4x4 result;

	result.SetElement(0, 0, xScale);
	result.SetElement(1, 1, yScale);
	result.SetElement(2, 2, zScale);
	result.SetElement(3, 3, 1.0f);

	return result;
}

Matrix4x4 RayTracer::Math::Matrix4x4::GetShearingMatrix()
{
	Matrix4x4 result;

	result.SetElement(0, 0, 1.0f);
	result.SetElement(1, 1, 1.0f);
	result.SetElement(2, 2, 1.0f);
	result.SetElement(3, 3, 1.0f);

	return result;
}

Matrix4x4& RayTracer::Math::Matrix4x4::operator=(const SquareMatrix& rhs)
{
	if (rhs.GetMatrixDimension() == m_dimension)
	{
		CopyValues(rhs);
		return *this;
	}

	throw std::exception("ERROR: must match the same dimension of 4x4");
}

Matrix4x4& RayTracer::Math::Matrix4x4::operator=(const Matrix4x4& rhs)
{
	CopyValues(rhs);

	return *this;
}

 Matrix4x4 RayTracer::Math::operator*(const Matrix4x4& lhs, const Matrix4x4& rhs)
{
	const SquareMatrix* const ptrLhs = &lhs;
	const SquareMatrix* const ptrRhs = &rhs;

	return Matrix4x4((*ptrLhs) * (*ptrRhs));
}

Vector4 RayTracer::Math::operator*(const Matrix4x4& lhs, const Vector4& rhs)
{
	Vector4 result;

	for (int r = 0; r < 4; ++r)
	{
		for (int c = 0; c < 4; ++c)
		{
			result.m_data[r] +=  lhs.m_data[r][c] * rhs.m_data[c];
		}
	}

	return result;
}