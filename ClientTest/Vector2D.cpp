#include "Vector2D.h"
#include <math.h>

Vector2D::Vector2D(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2D::Vector2D(const Vector2D& v)
{
	x = v.x;
	y = v.y;
}

Vector2D& Vector2D::operator=(const Vector2D& rh)
{
	x = rh.x;
	y = rh.y;
	return *this;
}

Vector2D Vector2D::operator*(const float rh)
{
	Vector2D temp(rh * x, rh *y);
	return temp;
}

Vector2D operator* (const float lh, const Vector2D& rh)
{
	Vector2D temp(lh * rh.x, lh * rh.y);
	return temp;
}

Vector2D& Vector2D::operator+=(const Vector2D& rh)
{
	x += rh.x;
	y += rh.y;
	return *this;
}

Vector2D Vector2D::operator+(const Vector2D& rh)
{
	Vector2D temp(rh.x + x, rh.y + y);
	return temp;
}

void Vector2D::Normalize()
{
	float fInvLen = sqrt(x*x + y*x);
	x *= fInvLen;
	y *= fInvLen;
}

bool Vector2D::IsZero(float min_value /* = 0.0f */)
{
	return (x*x + y*y <= min_value * min_value);
}


bool Vector2D::IsEqual(const Vector2D v, float min_value /* = 0.0f */)
{
	return (v.x - x) * (v.x - x) + (v.y - y) * (v.y - y) <= min_value;
}