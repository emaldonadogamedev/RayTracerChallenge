#pragma once

#include <string>

namespace RayTracer
{
	namespace Serialization
	{
		class Canvas;

		class CanvasExporter
		{
			public:
				static void ExportToPPMimage(const Canvas& canvas, const std::string& filename);

			private:
				static const std::string s_EXPORT_DIR;
		};
	}
}