#include "Ray.h"


Ray::Ray(void)
{

}


Ray::~Ray(void)
{

}



Intersection::Intersection(Ray* _incomingRay, Shape3d* _shape, uint _faceIndex)
{
	this->incomingRay = _incomingRay;
	this->shape = _shape;
	this->faceIndex = _faceIndex;
}