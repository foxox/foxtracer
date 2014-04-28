#pragma once

#ifndef FOXTRACERFOLDER

#include "../foxtracer/foxmath3.h"
#include "../foxtracer/common.h"

#include "../foxtracer/Ray.h"

#include "../foxtracer/Sample2D.h"

#else

#include "foxmath3.h"
#include "common.h"

#include "Ray.h"

#include "Sample2D.h"

#endif

using namespace FM;

class ExamplePinholeCamera
{
private:
	size_t width;
	size_t height;

	float focallength;

public:

	ExamplePinholeCamera(void);
	inline ExamplePinholeCamera(size_t _width, size_t _height, float _focallength)//float _fovh, float _near, float _far)
		: width(_width), height(_height),
		focallength(_focallength)
	{}
	virtual ~ExamplePinholeCamera(void);

	inline size_t getWidth() { return this->width; }
	inline size_t getHeight() { return this->height; }

	Ray getRay(const Sample2D& filmloc, const Sample2D& aperture);
};

