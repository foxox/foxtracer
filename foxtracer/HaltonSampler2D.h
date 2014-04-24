#pragma once
#include "sampler2d.h"

class HaltonSampler2D :
	public Sampler2D
{
protected:
	size_t samplenum;

public:
	HaltonSampler2D(void);
	HaltonSampler2D(size_t numSamples,
		std::default_random_engine* _pRNGEngine,
		FloatRange sampleRangeX, FloatRange sampleRangeY) :
		Sampler2D(numSamples, _pRNGEngine, sampleRangeX, sampleRangeY),
		samplenum(0)
	{}
	virtual ~HaltonSampler2D(void);

	virtual void reinitialize()
	{
		samplenum = 0;
	}

	virtual Sample2D getNextSample();
};

