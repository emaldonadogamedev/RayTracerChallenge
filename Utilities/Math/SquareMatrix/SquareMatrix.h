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

			float Determinant() const;
			SquareMatrix  SubMatrix(unsigned int rowExclude, unsigned int colExclude) const;
			unsigned int GetMatrixDimension() const;
			SquareMatrix GetTranspose() const;
			SquareMatrix GetInverse() const;

			void SetElement(int row, int col, float value);

			friend SquareMatrix operator*(const SquareMatrix& lhs, const SquareMatrix& rhs);
			virtual const std::vector<float>& operator[](int index) const;
			virtual SquareMatrix& operator=(const SquareMatrix& rhs);


			static SquareMatrix GetIdentity(const unsigned int dimension);

			static const SquareMatrix Identity2x2;
			static const SquareMatrix Identity3x3;
			static const SquareMatrix Identity4x4;

		protected:
			float Minor(int row, int col) const;
			float CoFactor(int row, int col) const;

			const unsigned int m_dimension;
			std::vector<std::vector<float>> m_data;
		};
	}
}