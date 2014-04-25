#pragma once

#include "foxmath3.h"
using namespace FM;

class Ray
{
public:
	const Vec3 origin;
	const Vec3 direction;

	Ray(void);
	
	Ray(const Vec3& _origin, const Vec3& _direction)
		:
		origin(_origin),
		direction(_direction)
	{}

	~Ray(void);

	inline Vec3 atTime(float time)
	{
		return this->origin + time * this->direction;
	}
};
