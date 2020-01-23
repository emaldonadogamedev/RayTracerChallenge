#include "Utilities/precompiled/precompiled.h"
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

float RayTracer::Math::Vector2::Length() const
{
	const float l = LengthSquared();

	if (l <= MY_EPSILON)
	{
		return 0.f;
	}

	return std::sqrtf(l);
}

float RayTracer::Math::Vector2::LengthSquared() const
{
	return (x*x) + (y*y);
}

Vector2 RayTracer::Math::Vector2::Normalized() const
{
	Vector2 result = Vector2();
	const float l = Length();

	if (l > MY_EPSILON)
	{
		result.x /= l;
		result.y /= l;
	}

	return result;
}

void RayTracer::Math::Vector2::Zero()
{
	x = y = 0.f;
}

void Vector2::Normalize()
{
	const float l = Length();

	if (l > MY_EPSILON)
	{
		x /= l;
		y /= l;
	}
}

Vector2 RayTracer::Math::operator+(const Vector2& lhs, const Vector2& rhs)
{
	return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
}

Vector2 RayTracer::Math::operator+(const Vector2& lhs, const float rhs)
{
	return Vector2(lhs.x + rhs, lhs.y + rhs);
}

Vector2 RayTracer::Math::operator-(const Vector2& lhs, const Vector2& rhs)
{
	return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
}

Vector2 RayTracer::Math::operator-(const Vector2& lhs, const float rhs)
{
	return Vector2(lhs.x - rhs, lhs.y - rhs);
}

Vector2 RayTracer::Math::Vector2::operator-()const
{
	return Vector2(-x, -y);
}

Vector2 RayTracer::Math::operator*(const Vector2& lhs, const Vector2& rhs)
{
	return Vector2(lhs.x * rhs.x, lhs.y * rhs.y);
}

Vector2 RayTracer::Math::operator*(const Vector2& lhs, const float rhs)
{
	return Vector2(lhs.x * rhs, lhs.y * rhs);
}

Vector2 RayTracer::Math::operator/(const Vector2& lhs, const float rhs)
{
	return Vector2(lhs.x / rhs, lhs.y / rhs);
}

Vector2& RayTracer::Math::Vector2::operator=(const Vector2& rhs)
{
	x = rhs.x;
	y = rhs.y;

	return *this;
}

ostream& RayTracer::Math::operator<<(ostream& output, const Vector2& value)
{
	output << "(X = " << value.x << ", Y = " << value.y <<")";

	return output;
}