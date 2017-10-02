/*
 * Vector2.h
 *
 *  Created on: 2 oct. 2017
 *      Author: Valentin
 */

#ifndef INCLUDE_VECTOR_H_
#define INCLUDE_VECTOR_H_

struct IVector2
{
	int x;
	int y;

	IVector2(int vX, int vY)
	{
		x = vX;
		y = vY;
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
		IVector2 vec = { (int) x, (int) y };

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
};


#endif /* INCLUDE_VECTOR_H_ */
