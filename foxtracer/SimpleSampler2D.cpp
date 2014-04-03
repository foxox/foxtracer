#include "SimpleSampler2D.h"


SimpleSampler2D::SimpleSampler2D(void)
{
}


SimpleSampler2D::~SimpleSampler2D(void)
{
}

Sample2D SimpleSampler2D::getNextSample()
{
	Sample2D returnme;
	returnme.x = 0.0f;
	returnme.y = 0.0f;
	return returnme;
}