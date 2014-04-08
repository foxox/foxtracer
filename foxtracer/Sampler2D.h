#pragma once
#include "sampler.h"

#include "Sample2D.h"

class Sampler2D :
	public Sampler
{
protected:
	FloatRange sampleRangeX;
	FloatRange sampleRangeY;

public:
	//Sampler2D(void);
	Sampler2D(size_t numSamples, FloatRange sampleRangeX, FloatRange sampleRangeY) : Sampler(numSamples), sampleRangeX(sampleRangeX), sampleRangeY(sampleRangeY) {}
	virtual ~Sampler2D(void);

	virtual Sample2D getNextSample() = 0;
};

