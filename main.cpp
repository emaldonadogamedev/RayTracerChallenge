#include "Utilities/precompiled/precompiled.h"
#include "Utilities/Math/Vector3/Vector3.h"

using namespace RayTracer::Math;

int main(int argc, char** argv)
{
	Vector3 vec(89.f, 12.f);

	std::cout << Vector3(-87.f, -11.f) * vec;

	return 0;
}