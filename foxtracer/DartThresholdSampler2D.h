#pragma once
#include "sampler2d.h"
class DartThresholdSampler2D :
	public Sampler2D
{
public:
	DartThresholdSampler2D(void);
	DartThresholdSampler2D(size_t numSamples, std::default_random_engine* _pRNGEngine, FloatRange sampleRangeX, FloatRange sampleRangeY) : Sampler2D(numSamples, _pRNGEngine, sampleRangeX, sampleRangeY) {}
	virtual ~DartThresholdSampler2D(void);

	virtual Sample2D getNextSample();
};

