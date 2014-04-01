#include "Camera.h"


Camera::Camera(void)
{
}


Camera::~Camera(void)
{
}


Ray Camera::getRay(Sample originx, Sample originy, Sample aperturex, Sample aperturey)
{
	//Create a ray given the inputs
	Ray returnme;
	//TODO: form ray in camera
	return returnme;
}


void Camera::exposeSensor(size_t i, size_t j, Integrator* integrator, Ray* theray)
{
	i2(this->sensor, i, j);
}