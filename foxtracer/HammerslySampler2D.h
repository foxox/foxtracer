#pragma once
#include "sampler2d.h"

class HammerslySampler2D :
	public Sampler2D
{
protected:
	size_t samplenum;

public:
	HammerslySampler2D(void);
	HammerslySampler2D(size_t numSamples,
		std::default_random_engine* _pRNGEngine,
		FloatRange sampleRangeX, FloatRange sampleRangeY) :
		Sampler2D(numSamples, _pRNGEngine, sampleRangeX, sampleRangeY),
		samplenum(0)
	{
	}
	virtual ~HammerslySampler2D(void);

	virtual Sample2D getNextSample();
};

