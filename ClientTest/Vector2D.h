#ifndef _VECTOR_2D_H_
#define _VECTOR_2D_H_

class Vector2D 
{
public:
	Vector2D(float x, float y);
	Vector2D(const Vector2D& v);

	Vector2D& operator=(const Vector2D& rh);
	Vector2D& operator+=(const Vector2D& rh);
	Vector2D operator*(const float rh);
	Vector2D operator+(const Vector2D& rh);

	friend Vector2D operator* (const float lh, const Vector2D& rh); 

public:
	bool IsZero(float min_value = 0.0f);
	bool IsEqual(const Vector2D v, float min_value = 0.0f);

	void Normalize();
public:
	float x,y;
};

Vector2D operator* (const float lh, const Vector2D& rh); 

#endif