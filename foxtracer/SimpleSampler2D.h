#pragma once
#include "sampler2d.h"
class SimpleSampler2D :
	public Sampler2D
{
public:
	SimpleSampler2D(void);
	SimpleSampler2D(size_t numSamples,
		std::default_random_engine* _pRNGEngine,
		FloatRange sampleRangeX, FloatRange sampleRangeY)
		:
		Sampler2D(numSamples, _pRNGEngine, sampleRangeX, sampleRangeY) {}
	virtual ~SimpleSampler2D(void);

	virtual void reinitialize() {}

	virtual Sample2D getNextSample();
};

