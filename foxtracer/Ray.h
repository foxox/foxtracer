#pragma once

#include "Shape3d.h"

class Ray
{
public:
	Ray(void);
	~Ray(void);
};

class Intersection
{
public:
	Shape3d* shape;
	uint faceIndex;

	Ray* incomingRay;

	Intersection(Ray* _incomingRay, Shape3d* _shape, uint _faceIndex);
};
