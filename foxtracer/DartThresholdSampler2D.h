#pragma once
#include "sampler2d.h"
class DartThresholdSampler2D :
	public Sampler2D
{
protected:
	Sample2D* const samples;
	size_t samplenum;
	const float threshold;

public:
	DartThresholdSampler2D(void);
	DartThresholdSampler2D(size_t numSamples,
		std::default_random_engine* _pRNGEngine,
		FloatRange sampleRangeX, FloatRange sampleRangeY, float _threshold)
		:
		Sampler2D(numSamples, _pRNGEngine, sampleRangeX, sampleRangeY),
		samples(new Sample2D[numSamples]),
		samplenum(0),
		threshold(_threshold)
	{}
	virtual ~DartThresholdSampler2D(void);

	virtual void reinitialize()
	{
		samplenum = 0;
	}

	virtual Sample2D getNextSample();
};

