#include <Utilities/precompiled/precompiled.h>

#include "Matrix4x4.h"

using namespace RayTracer::Math;

RayTracer::Math::Matrix4x4::Matrix4x4()
	:SquareMatrix(4)
{

}

RayTracer::Math::Matrix4x4::~Matrix4x4()
{

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
		for (unsigned int i = 0; i < m_dimension; ++i)
		{
			for (unsigned int j = 0; j < m_dimension; ++j)
			{
				m_data[i][j] = rhs[i][j];
			}
		}
	}

	throw std::exception("ERROR: must match the same dimension of 4x4");
}

Matrix4x4& RayTracer::Math::Matrix4x4::operator=(const Matrix4x4& rhs)
{
	for (unsigned int i = 0; i < m_dimension; ++i)
	{
		for (unsigned int j = 0; j < m_dimension; ++j)
		{
			m_data[i][j] = rhs.m_data[i][j];
		}
	}

	return *this;
}
