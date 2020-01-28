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
