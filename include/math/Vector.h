/*
 * Vector2.h
 *
 *  Created on: 2 oct. 2017
 *      Author: Valentin
 */

#ifndef INCLUDE_VECTOR_H_
#define INCLUDE_VECTOR_H_

#include "math.h"

struct IVector2
{
	int x;
	int y;

	IVector2(int vX, int vY)
	{
		x = vX;
		y = vY;
	}

	IVector2 operator+=(const IVector2& a) const
	{
		return IVector2(a.x + x, a.y + y);
	}

	IVector2 operator+(const IVector2& a) const
	{
		return IVector2(a.x + x, a.y + y);
	}

	IVector2 operator*=(const float a) const
	{
		return IVector2(x * a, y * a);
	}

	IVector2 operator*(const float a) const
	{
		return IVector2(x * a, y * a);
	}
};

struct Vector2
{
	float x;
	float y;

	Vector2(float vX, float vY)
	{
		x = vX;
		y = vY;
	}

	IVector2 asIVector2()
	{
		IVector2 vec =
		{ (int) x, (int) y };

		return vec;
	}

	Vector2 operator+=(const Vector2& a) const
	{
		return Vector2(a.x + x, a.y + y);
	}

	Vector2 operator+(const Vector2& a) const
	{
		return Vector2(a.x + x, a.y + y);
	}

	Vector2 operator*=(const float a) const
	{
		return Vector2(x * a, y * a);
	}

	Vector2 operator*(const float a) const
	{
		return Vector2(x * a, y * a);
	}

	float magnitude()
	{
		return sqrt(x * x + y * y);
	}
};

#endif /* INCLUDE_VECTOR_H_ */
