#include "Utilities/precompiled/precompiled.h"

#include "Utilities/Math/SquareMatrix/SquareMatrix.h"

using namespace RayTracer::Math;

int main(int argc, char** argv)
{
	SquareMatrix sqrMtx(4);

	////DET = -2120
	//sqrMtx.SetElement(0, 0, 6.f); sqrMtx.SetElement(0, 1, 4.f); sqrMtx.SetElement(0, 2, 4.f); sqrMtx.SetElement(0, 3, 4.f);
	//sqrMtx.SetElement(1, 0, 5.f); sqrMtx.SetElement(1, 1, 5.f); sqrMtx.SetElement(1, 2, 7.f); sqrMtx.SetElement(1, 3, 6.f);
	//sqrMtx.SetElement(2, 0, 4.f); sqrMtx.SetElement(2, 1, -9.f); sqrMtx.SetElement(2, 2, 3.f); sqrMtx.SetElement(2, 3, -7.f);
	//sqrMtx.SetElement(3, 0, 9.f); sqrMtx.SetElement(3, 1, 1.f); sqrMtx.SetElement(3, 2, 7.f); sqrMtx.SetElement(3, 3, -6.f);

	//DET = 0
	sqrMtx.SetElement(0, 0, -4.f); sqrMtx.SetElement(0, 1, 2.f); sqrMtx.SetElement(0, 2, -2.f); sqrMtx.SetElement(0, 3, -3.f);
	sqrMtx.SetElement(1, 0, 9.f); sqrMtx.SetElement(1, 1, 6.f); sqrMtx.SetElement(1, 2, 2.f); sqrMtx.SetElement(1, 3, 6.f);
	sqrMtx.SetElement(2, 0, 0.f); sqrMtx.SetElement(2, 1, -5.f); sqrMtx.SetElement(2, 2, 1.f); sqrMtx.SetElement(2, 3, -5.f);
	sqrMtx.SetElement(3, 0, 0.f); sqrMtx.SetElement(3, 1, 0.f); sqrMtx.SetElement(3, 2, 0.f); sqrMtx.SetElement(3, 3, -0.f);

	float d = sqrMtx.Determinant();

	return 0;
}