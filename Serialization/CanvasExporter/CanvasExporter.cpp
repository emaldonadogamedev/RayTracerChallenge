#include <Utilities/precompiled/precompiled.h>

#include "CanvasExporter.h"
#include "../Canvas/Canvas.h"

using namespace RayTracer::Serialization;

using std::ofstream;

void CanvasExporter::ExportToPPMimage(const Canvas& canvas, const std::string& filename)
{
	ofstream ppmFile;
	
	ppmFile.open(s_EXPORT_DIR + filename + s_PPM_EXTENSION);

	if (ppmFile.is_open())
	{
		//File Header
		ppmFile << "P3\n" << canvas.GetWidth() << ' ' << canvas.GetHeight() << '\n' << Color::s_MAX_COLOR_VALUE << '\n';

		const auto& colorBuffer = canvas.GetColorBuffer();

		//Image
		for (const auto& row : colorBuffer)
		{
			for (const auto& color : row)
			{
				ppmFile << color.r << ' ' << color.g << ' ' << color.b << "  ";
			}

			//end line for new row
			ppmFile << '\n';
		}

		ppmFile.close();
	}
}

const std::string CanvasExporter::s_EXPORT_DIR = "OutputImages/";
const std::string RayTracer::Serialization::CanvasExporter::s_PPM_EXTENSION = ".ppm";
