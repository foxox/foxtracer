#pragma once
#include "Sampler.h"
#include "Sample1D.h"
class Sampler1D :
	public Sampler
{
protected:
	FloatRange sampleRange;
public:
	//Sampler1D(void);
	Sampler1D(size_t numSamples, FloatRange sampleRange) : Sampler(numSamples), sampleRange(sampleRange) {}
	virtual ~Sampler1D(void);
};

