#pragma once
#include "Integrator.h"

class TestIntegrator :
	public Integrator
{
public:
	TestIntegrator();
	virtual ~TestIntegrator();

	virtual void Li(Ray* ray);
};

