#pragma once
#include "sampler2d.h"

class VanDerCorputSobolSampler2D :
	public Sampler2D
{
protected:
	size_t samplenum;

public:
	VanDerCorputSobolSampler2D(void);
	VanDerCorputSobolSampler2D(size_t numSamples,
		std::default_random_engine* _pRNGEngine,
		FloatRange sampleRangeX, FloatRange sampleRangeY) :
		Sampler2D(numSamples, _pRNGEngine, sampleRangeX, sampleRangeY),
		samplenum(0)
	{
	}
	virtual ~VanDerCorputSobolSampler2D(void);

	virtual Sample2D getNextSample();
};

