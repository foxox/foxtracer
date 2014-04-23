#pragma once

#include <math.h>

class Sample2D
{
public:
	Sample2D(void);
	Sample2D(float _x, float _y) : x(_x), y(_y) {}
	virtual ~Sample2D(void);

	float x;
	float y;

	static float Sample2DDistance(const Sample2D& a, const Sample2D& b);
	static float Sample2DDistanceSquared(const Sample2D& a, const Sample2D& b);
};

