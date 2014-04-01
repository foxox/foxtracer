#pragma once

#include "Integrator.h"

class RaycastIntegrator : public Integrator
{
private:


public:
	RaycastIntegrator(void);
	~RaycastIntegrator(void);

	void Li(Ray* ray);
};

