#pragma once

#include "foxmath3.h"
#include "common.h"

#include "Ray.h"
#include "Integrator.h"

#include "Quantum.h"

#include "Sample2D.h"

using namespace FM;

class Camera
{
private:
	size_t width;
	size_t height;
	//float near;
	//float far;
	//float fovh;

	float focallength;

public:

	//Vec3 pos;
	//Mat4 rot;

	Quantum* sensor;
	size_t sensorJSIZE;

	Camera(void);
	inline Camera(size_t _width, size_t _height, float _focallength)//float _fovh, float _near, float _far)
		: width(_width), height(_height),
		//near(_near), far(_far),
		//fovh(_fovh)
		focallength(_focallength)
	{}
	virtual ~Camera(void);

	inline size_t getWidth() { return this->width; }
	inline size_t getHeight() { return this->height; }

	Ray getRay(const Sample2D& filmloc, const Sample2D& aperture);
	void exposeSensor(size_t i, size_t j, Integrator* integrator, Ray* theray);
};

