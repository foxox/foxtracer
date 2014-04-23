#include "Sample2D.h"


Sample2D::Sample2D(void)
{
}


Sample2D::~Sample2D(void)
{
}

float Sample2D::Sample2DDistance(const Sample2D& a, const Sample2D& b)
{
	float x = b.x - a.x;
	float y = b.y - a.y;
	return sqrt(x*x + y*y);
}

float Sample2D::Sample2DDistanceSquared(const Sample2D& a, const Sample2D& b)
{
	float x = b.x - a.x;
	float y = b.y - a.y;
	return x*x + y*y;
}