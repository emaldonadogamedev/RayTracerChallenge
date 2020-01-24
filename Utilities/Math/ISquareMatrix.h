#pragma once

#include <vector>

using std::vector;

namespace RayTracer
{
	namespace Math
	{
		class ISquareMatrix
		{
		public:
			ISquareMatrix(const unsigned int dimension)
				:m_dimension(dimension)
			{
				m_data.resize(m_dimension);
				for (auto& row : m_data)
				{
					row.resize(m_dimension, 0.f);
				}
			}
			~ISquareMatrix()
			{
			}

			virtual float Determinant() const = 0;

			void  SubMatrix(ISquareMatrix& result, unsigned int rowExclude, unsigned int colExclude)
			{
				
			}

			unsigned int GetMatrixDimension() const
			{
				return m_dimension;
			}

			virtual const std::vector<float>& operator[](int index) const
			{
				return m_data[index];
			}

			virtual ISquareMatrix& operator=(const ISquareMatrix& rhs)
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

		protected:
			const unsigned int m_dimension;
			std::vector<std::vector<float>> m_data;
		};
	}
}