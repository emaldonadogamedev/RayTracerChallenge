#include "Utilities/precompiled/precompiled.h"

#include "Serialization/CanvasExporter/CanvasExporter.h"
#include "Serialization/Canvas/Canvas.h"

using namespace RayTracer::Serialization;

int main(int argc, char** argv)
{
	Canvas can(512, 512);

	CanvasExporter::ExportToPPMimage(can, "test");

	return 0;
}