#include "Utilities/precompiled/precompiled.h"
#include "Vector4.h"

using namespace RayTracer::Math;

Vector4::Vector4(float _x /*= 0.f*/, float _y /*= 0.f*/, float _z /*= 0.f*/, float _w /*= 0.f*/)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

Vector4::~Vector4()
{

}

float Vector4::Dot(const Vector4& rhs) const
{
	return (x * rhs.x) + (y * rhs.y) + (z * rhs.z) + (w * rhs.w);
}

float RayTracer::Math::Vector4::Length() const
{
	const float l = LengthSquared();

	if (l <= MY_EPSILON)
	{
		return 0.f;
	}

	return std::sqrtf(l);
}

float RayTracer::Math::Vector4::LengthSquared() const
{
	return (x * x) + (y * y) + (z * z) + (w * w);
}

Vector4 RayTracer::Math::Vector4::Normalized() const
{
	Vector4 result = Vector4();
	const float l = Length();

	if (l > MY_EPSILON)
	{
		result.x = x / l;
		result.y = y / l;
		result.z = z / l;
		result.w = w / l;
	}

	return result;
}

void RayTracer::Math::Vector4::Zero()
{
	x = y = z = w = 0.f;
}

Vector4 RayTracer::Math::Vector4::AsVectorXYZ() const
{
	return Vector4(x,y,z, 0.f);
}

Vector4 RayTracer::Math::Vector4::AsPointXYZ() const
{
	return Vector4(x, y, z, 1.f);
}

Color RayTracer::Math::Vector4::AsColor() const
{
	const float f = (float)Color::s_MAX_COLOR_VALUE;

	return Color(
		std::clamp((unsigned int)(f * x), 0U, 255U),
		std::clamp((unsigned int)(f * y), 0U, 255U),
		std::clamp((unsigned int)(f * z), 0U, 255U),
		std::clamp((unsigned int)(f * w), 0U, 255U)
	);
}

void Vector4::Normalize()
{
	const float l = Length();

	if (l > MY_EPSILON)
	{
		x /= l;
		y /= l;
		z /= l;
		w /= l;
	}
}

Vector4 RayTracer::Math::operator+(const Vector4& lhs, const Vector4& rhs)
{
	return Vector4(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
}

Vector4 RayTracer::Math::operator+(const Vector4& lhs, const float rhs)
{
	return Vector4(lhs.x + rhs, lhs.y + rhs, lhs.z + rhs, lhs.w + rhs);
}

Vector4 RayTracer::Math::operator-(const Vector4& lhs, const Vector4& rhs)
{
	return Vector4(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
}

Vector4 RayTracer::Math::operator-(const Vector4& lhs, const float rhs)
{
	return Vector4(lhs.x - rhs, lhs.y - rhs, lhs.z - rhs, lhs.w - rhs);
}

Vector4 RayTracer::Math::Vector4::operator-()const
{
	return Vector4(-x, -y, -z, -w);
}

Vector4 RayTracer::Math::operator*(const Vector4& lhs, const Vector4& rhs)
{
	return Vector4(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w);
}

Vector4 RayTracer::Math::operator*(const Vector4& lhs, const float rhs)
{
	return Vector4(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs);
}

Vector4 RayTracer::Math::operator/(const Vector4& lhs, const float rhs)
{
	return Vector4(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.w / rhs);
}

Vector4& RayTracer::Math::Vector4::operator=(const Vector4& rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	w = rhs.w;

	return *this;
}

ostream& RayTracer::Math::operator<<(ostream& output, const Vector4& value)
{
	output << "(X = " << value.x << ", Y = " << value.y << ", Z = " << value.z << ", W = " << value.w << ")";

	return output;
}