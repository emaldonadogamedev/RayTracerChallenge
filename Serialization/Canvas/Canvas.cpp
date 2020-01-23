#include <Utilities/precompiled/precompiled.h>

#include "Canvas.h"

using namespace RayTracer::Math;
using namespace RayTracer::Serialization;

Canvas::Canvas(const unsigned int w /*= 512U*/, const unsigned int h /*= 512U*/)
{

}

Canvas::~Canvas()
{

}

Color Canvas::GetColor(const int row, const int col) const
{

}

const ColorBuffer& Canvas::GetColorBuffer() const
{

}

const size_t Canvas::GetWidth() const
{

}

const size_t Canvas::GetHeight() const
{

}

void Canvas::AddColorValue(unsigned int row, unsigned int col, const Color& color)
{

}

void Canvas::Resize(unsigned int w, unsigned int h)
{

}

void Canvas::Clear()
{

}

const vector<Color>& Canvas::operator[](int row) const
{

}

const unsigned int Canvas::s_MAX_DIMENSION_SIZE = 8192U;
