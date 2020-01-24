#pragma once

#include "../../Utilities/Math/Vector4/Vector4.h"
#include <string>
#include <vector>

using std::vector;

using namespace RayTracer::Math;

namespace RayTracer
{
	namespace Serialization
	{
		typedef vector<vector<Color>> ColorBuffer;

		class Canvas
		{
			public:
				Canvas(const unsigned int w = 512U, const unsigned int h = 512U);
				~Canvas();

				Color GetColor(const int row, const int col) const;
				const ColorBuffer& GetColorBuffer() const;
				const size_t GetWidth() const;
				const size_t GetHeight() const;

				void AddColorValue(unsigned int row, unsigned int col, const Color& color);
				void Resize(const unsigned int w, const unsigned int h);
				void Clear();

				const vector<Color>& operator[](int row) const;

				static const unsigned int s_MAX_DIMENSION_SIZE;

			private:
				ColorBuffer m_colorData;
		};
	}
}