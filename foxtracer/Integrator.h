#pragma once

#include "Ray.h"

class Integrator
{
private:

public:
	virtual void Li(Ray* ray)=0;
};

