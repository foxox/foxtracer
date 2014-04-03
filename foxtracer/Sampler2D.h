#pragma once
#include "sampler.h"

#include "Sample2D.h"

class Sampler2D :
	public Sampler
{
public:
	Sampler2D(void);
	Sampler2D(size_t numSamples) : Sampler(numSamples) {}
	virtual ~Sampler2D(void);

	virtual Sample2D getNextSample() = 0;
};

