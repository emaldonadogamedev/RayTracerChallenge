#include "Utilities/precompiled/precompiled.h"

#include "Utilities/Math/SquareMatrix/SquareMatrix.h"

using namespace RayTracer::Math;

int main(int argc, char** argv)
{
	SquareMatrix sqrMtx(2);

	sqrMtx.SetElement(0,0, 11.f);
	sqrMtx.SetElement(0, 1, -2.f);
	sqrMtx.SetElement(1, 0, 3.f);
	sqrMtx.SetElement(1, 1, -9.f);

	const SquareMatrix trsPose = sqrMtx.GetTranspose();

	return 0;
}