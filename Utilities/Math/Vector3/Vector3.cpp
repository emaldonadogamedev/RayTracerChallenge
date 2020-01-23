#include "Utilities/precompiled/precompiled.h"
#include "Vector3.h"

using namespace RayTracer::Math;

Vector3::Vector3(float _x /*= 0.f*/, float _y /*= 0.f*/, float _z /*= 0.f*/)
{
	x = _x;
	y = _y;
	z = _z;
}

Vector3::~Vector3()
{

}

float Vector3::Dot(const Vector3& rhs) const
{
	return (x * rhs.x) + (y * rhs.y) + (z * rhs.z);
}

Vector3 RayTracer::Math::Vector3::Cross(const Vector3& rhs) const
{
	return Vector3(
		(y * rhs.z) - (z * rhs.y),
		(z * rhs.x) - (x * rhs.z),
		(x * rhs.y) - (y * rhs.x));
}

float RayTracer::Math::Vector3::Length() const
{
	const float l = LengthSquared();

	if (l <= MY_EPSILON)
	{
		return 0.f;
	}

	return std::sqrtf(l);
}

float RayTracer::Math::Vector3::LengthSquared() const
{
	return (x * x) + (y * y) + (z*z);
}

Vector3 RayTracer::Math::Vector3::Normalized() const
{
	Vector3 result = Vector3();
	const float l = Length();

	if (l > MY_EPSILON)
	{
		result.x /= l;
		result.y /= l;
		result.z /= l;
	}

	return result;
}

void RayTracer::Math::Vector3::Zero()
{
	x = y = z = 0.f;
}

const Vector3 RayTracer::Math::Vector3::X_POS = Vector3(1.f, 0.f, 0.f);

const Vector3 RayTracer::Math::Vector3::Y_POS = Vector3(0.f, 1.f, 0.f);

const Vector3 RayTracer::Math::Vector3::Z_POS = Vector3(0.f, 0.f, 1.f);

void Vector3::Normalize()
{
	const float l = Length();

	if (l > MY_EPSILON)
	{
		x /= l;
		y /= l;
		z /= l;
	}
}

Vector3 RayTracer::Math::operator+(const Vector3& lhs, const Vector3& rhs)
{
	return Vector3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

Vector3 RayTracer::Math::operator+(const Vector3& lhs, const float rhs)
{
	return Vector3(lhs.x + rhs, lhs.y + rhs, lhs.z + rhs);
}

Vector3 RayTracer::Math::operator-(const Vector3& lhs, const Vector3& rhs)
{
	return Vector3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

Vector3 RayTracer::Math::operator-(const Vector3& lhs, const float rhs)
{
	return Vector3(lhs.x - rhs, lhs.y - rhs, lhs.z - rhs);
}

Vector3 RayTracer::Math::Vector3::operator-()const
{
	return Vector3(-x, -y, -z);
}

Vector3 RayTracer::Math::operator*(const Vector3& lhs, const Vector3& rhs)
{
	return Vector3(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
}

Vector3 RayTracer::Math::operator*(const Vector3& lhs, const float rhs)
{
	return Vector3(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
}

Vector3 RayTracer::Math::operator/(const Vector3& lhs, const float rhs)
{
	return Vector3(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);
}

Vector3& RayTracer::Math::Vector3::operator=(const Vector3& rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;

	return *this;
}

ostream& RayTracer::Math::operator<<(ostream& output, const Vector3& value)
{
	output << "(X = " << value.x << ", Y = " << value.y << ", Z = " << value.z << ")";

	return output;
}