#pragma once
#include "Sampler2D.h"
class AdaptiveSampler2D :
	public Sampler2D
{
protected:
	Sampler2D* sampler;
	size_t samplecount;
	Sample2D* samples;
	size_t numSamplesExpanded;
	const size_t maxNumSamples;

	float (*evaluateSample)(Sample2D, float, float);

	float* const u;
	float* const v;

	inline bool needsMoreSamples()
	{
		for (size_t i = 1; i < this->samplecount; i++)
		{
			float a = this->evaluateSample(this->samples[i], *u, *v);
			float b = this->evaluateSample(this->samples[i - 1], *u, *v);
			if (a != b)
				return true;
		}
		return false;
	}

public:
	AdaptiveSampler2D(void);
	AdaptiveSampler2D(size_t numSamples,
		std::default_random_engine* _pRNGEngine,
		FloatRange sampleRangeX, FloatRange sampleRangeY,
		Sampler2D* _sampler,
		float (*_evaluateSample)(Sample2D, float, float),
		float* _u, float* _v)
		:
		Sampler2D(numSamples, _pRNGEngine, sampleRangeX, sampleRangeY),
		sampler(_sampler),
		samplecount(0),
		samples(new Sample2D[numSamples]),
		numSamplesExpanded(numSamples),
		maxNumSamples(10*numSamples),
		evaluateSample(_evaluateSample),
		u(_u), v(_v)
	{}

	virtual ~AdaptiveSampler2D(void);

	virtual size_t getNumSamples()
	{
		return this->numSamplesExpanded;
	}

	virtual void reinitialize()
	{
		this->sampler->reinitialize();
		this->samplecount = 0;
		this->numSamplesExpanded = this->numSamples;
	}

	virtual Sample2D getNextSample();
};

