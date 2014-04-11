#pragma once
#include "sampler2d.h"
class StratifiedSampler2D :
	public Sampler2D
{
public:
	StratifiedSampler2D(void);
	StratifiedSampler2D(size_t numSamples, std::default_random_engine* _pRNGEngine, FloatRange sampleRangeX, FloatRange sampleRangeY) : Sampler2D(numSamples, _pRNGEngine, sampleRangeX, sampleRangeY) {}
	virtual ~StratifiedSampler2D(void);

	virtual Sample2D getNextSample();
};

