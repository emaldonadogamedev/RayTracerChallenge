#pragma once

#include <vector>

using std::vector;

namespace RayTracer
{
	namespace Math
	{
		class SquareMatrix
		{
		public:
			SquareMatrix(const unsigned int dimension);
			~SquareMatrix();

			virtual float Determinant() const;

			void  SubMatrix(SquareMatrix& result, unsigned int rowExclude, unsigned int colExclude);

			void SetElement(int row, int col, float value);

			unsigned int GetMatrixDimension() const;

			SquareMatrix GetTranspose() const;

			friend SquareMatrix operator*(const SquareMatrix& lhs, const SquareMatrix& rhs);

			virtual const std::vector<float>& operator[](int index) const;

			virtual SquareMatrix& operator=(const SquareMatrix& rhs);

			static SquareMatrix GetIdentity(const unsigned int dimension);

			static const SquareMatrix Identity2x2;
			static const SquareMatrix Identity3x3;
			static const SquareMatrix Identity4x4;

		protected:
			const unsigned int m_dimension;
			std::vector<std::vector<float>> m_data;
		};
	}
}