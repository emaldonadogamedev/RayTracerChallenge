#include "Vector2.h"

using namespace RayTracer::Math;

Vector2::Vector2(float _x /*= 0.f*/, float _y /*= 0.f*/)
{
	x = _x;
	y = _y;
}

Vector2::~Vector2()
{

}

float Vector2::Dot(const Vector2& rhs) const
{
	return (x * rhs.x) + (y * rhs.y);
}

Vector2& RayTracer::Math::Vector2::operator=(const Vector2& rhs)
{
	x = rhs.x;
	y = rhs.y;

	return *this;
}

float RayTracer::Math::Vector2::Length() const
{
	return 0.f;
}

float RayTracer::Math::Vector2::LengthSquared() const
{
	return 0.f;
}

Vector2 RayTracer::Math::Vector2::Normalized() const
{
	return Vector2();
}

void Vector2::Normalize()
{

}
