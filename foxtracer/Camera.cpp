#include "Camera.h"


Camera::Camera(void)
{
}


Camera::~Camera(void)
{
}


//filmloc 0->1
//aperture - to +, small
Ray Camera::getRay(const Sample2D& filmloc, const Sample2D& aperture)
{
	//position on sensor XY, Z is depth (0 at sensor)
	Vec3 senspos(filmloc.x - 0.5f, 1.0f + filmloc.y - 0.5f, 0);
	
	//position on aperture
	Vec3 aperturepos(aperture.x, 0.75f + aperture.y, this->focallength);

	Vec3 direction = aperturepos - senspos;
	Vec3NormalizeOut(&direction);

	return Ray(senspos,direction);
}


void Camera::exposeSensor(size_t i, size_t j, Integrator* integrator, Ray* theray)
{
	i2(this->sensor, i, j);
}