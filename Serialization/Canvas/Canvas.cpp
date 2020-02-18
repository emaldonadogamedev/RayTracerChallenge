#include <Utilities/precompiled/precompiled.h>

#include "Canvas.h"

using namespace RayTracer::Math;
using namespace RayTracer::Serialization;

Canvas::Canvas(const unsigned int w /*= 512U*/, const unsigned int h /*= 512U*/)
{
	Resize(w, h);
}

Canvas::~Canvas()
{

}

Color Canvas::GetColor(const int row, const int col) const
{
	return m_colorData[row][col];
}

const ColorBuffer& Canvas::GetColorBuffer() const
{
	return m_colorData;
}

const size_t Canvas::GetWidth() const
{
	return m_colorData[0].size();
}

const size_t Canvas::GetHeight() const
{
	return m_colorData.size();
}

void Canvas::AddColorValue(unsigned int row, unsigned int col, const Color& color)
{
	m_colorData[row][col] = color;
}

void Canvas::Resize(unsigned int w, unsigned int h)
{
	m_colorData.resize(h);

	for (auto& row : m_colorData)
	{
		row.resize(w);
	}
}

void Canvas::Clear()
{

}

const vector<Color>& Canvas::operator[](int row) const
{
	return m_colorData[row];
}

const unsigned int Canvas::s_MAX_DIMENSION_SIZE = 8192U;
