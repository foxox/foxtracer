#pragma once
#include "Sampler.h"

class SimpleSampler :
	public Sampler
{
public:
	SimpleSampler();
	virtual ~SimpleSampler();

	virtual Sample getSample();
	virtual vector<Sample> getSampleBatch();
};

