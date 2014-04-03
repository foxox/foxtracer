#pragma once
#include "Sampler.h"
#include "Sample1D.h"
class Sampler1D :
	public Sampler
{
public:
	Sampler1D(void);
	Sampler1D(size_t numSamples) : Sampler(numSamples) {}
	virtual ~Sampler1D(void);
};

