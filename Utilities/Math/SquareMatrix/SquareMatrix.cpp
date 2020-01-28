#include <Utilities/precompiled/precompiled.h>

#include "SquareMatrix.h"

using namespace RayTracer::Math;

RayTracer::Math::SquareMatrix::SquareMatrix(const unsigned int dimension) :m_dimension(dimension)
{
	m_data.resize(m_dimension);
	for (auto& row : m_data)
	{
		row.resize(m_dimension, 0.f);
	}
}

RayTracer::Math::SquareMatrix::~SquareMatrix()
{

}

float RayTracer::Math::SquareMatrix::Determinant() const
{
	float result = 0.f;
	if (m_dimension == 2)
	{
		result = (m_data[0][0]*m_data[1][1]) - (m_data[0][1]*m_data[1][0]);
	}
	else
	{
		for (int c = 0; c < m_dimension; ++c)
		{
			result += m_data[0][c] * CoFactor(0, c);
		}
	}
	return result;
}

SquareMatrix RayTracer::Math::SquareMatrix::SubMatrix(unsigned int rowExclude, unsigned int colExclude) const
{
	SquareMatrix result(m_dimension - 1);

	int currRow = 0, currCol;

	for (int row = 0; row < m_dimension; ++row)
	{
		if (row != rowExclude)
		{
			currCol = 0;

			for (int col = 0; col < m_dimension; ++col)
			{
				if (col != colExclude)
				{
					result.m_data[currRow][currCol] = m_data[row][col];

					++currCol;
				}
			}

			++currRow;
		}
	}

	return result;
}

void RayTracer::Math::SquareMatrix::SetElement(int row, int col, float value)
{
	m_data[row][col] = value;
}

unsigned int RayTracer::Math::SquareMatrix::GetMatrixDimension() const
{
	return m_dimension;
}

SquareMatrix RayTracer::Math::SquareMatrix::GetTranspose() const
{
	SquareMatrix result(m_dimension);

	for (unsigned int i = 0; i < m_dimension; ++i)
	{
		for (unsigned int j = 0; j < m_dimension; ++j)
		{
			result.SetElement(i, j, m_data[j][i]);
		}
	}

	return result;
}

SquareMatrix RayTracer::Math::SquareMatrix::GetInverse() const
{
	SquareMatrix result(m_dimension);

	const float determinant = Determinant();
	if (std::abs(determinant) > MY_EPSILON)
	{
		for (int row = 0; row < m_dimension; row++)
		{
			for (int col = 0; col < m_dimension; col++)
			{
				float c = CoFactor(row, col);
				result.m_data[col][row] = c / determinant;
			}
		}
	}

	return result;
}

SquareMatrix RayTracer::Math::operator*(const SquareMatrix& lhs, const SquareMatrix& rhs)
{
	if (lhs.m_dimension == rhs.m_dimension)
	{
		SquareMatrix result(lhs.m_dimension);

		for (unsigned int row = 0; row < lhs.m_dimension; ++row)
		{
			for (unsigned int col = 0; col < lhs.m_dimension; ++col)
			{
				float temp = 0.f;

				for (unsigned int iter = 0; iter < lhs.m_dimension; ++iter)
				{
					temp += (lhs[row][iter] + rhs[iter][col]);
				}

				result.m_data[row][col] = temp;
			}
		}

		return result;
	}

	throw std::exception("Square matrices need to have same amount of rows/columns!");
}

const std::vector<float>& RayTracer::Math::SquareMatrix::operator[](int index) const
{
	return m_data[index];
}

SquareMatrix& RayTracer::Math::SquareMatrix::operator=(const SquareMatrix& rhs)
{
	if (m_dimension == rhs.m_dimension)
	{
		for (unsigned int i = 0; i < m_dimension; ++i)
		{
			for (unsigned int j = 0; j < m_dimension; ++j)
			{
				m_data[i][j] = rhs.m_data[i][j];
			}
		}
	}

	return *this;
}

SquareMatrix RayTracer::Math::SquareMatrix::GetIdentity(const unsigned int dimension)
{
	//starts as all Zero
	SquareMatrix result(dimension);

	for (unsigned int iter = 0; iter < dimension; ++iter)
	{
		result.m_data[iter][iter] = 1.f;
	}

	return result;
}

float RayTracer::Math::SquareMatrix::Minor(int row, int col) const
{
	return SubMatrix(row, col).Determinant();
}

float RayTracer::Math::SquareMatrix::CoFactor(int row, int col) const
{
	return Minor(row, col) * (((row + col) % 2) == 0 ? 1.f : -1.f);
}

const SquareMatrix RayTracer::Math::SquareMatrix::Identity2x2 = GetIdentity(2);
const SquareMatrix RayTracer::Math::SquareMatrix::Identity3x3 = GetIdentity(3);
const SquareMatrix RayTracer::Math::SquareMatrix::Identity4x4 = GetIdentity(4);