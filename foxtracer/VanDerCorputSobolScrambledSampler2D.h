#pragma once
#include "VanDerCorputSobolSampler2D.h"

class VanDerCorputSobolScrambledSampler2D :
	public VanDerCorputSobolSampler2D
{
protected:
	size_t samplenum;

	uint32_t xscramble;
	uint32_t yscramble;

public:
	VanDerCorputSobolScrambledSampler2D(void);
	VanDerCorputSobolScrambledSampler2D(size_t numSamples,
		std::default_random_engine* _pRNGEngine,
		FloatRange sampleRangeX, FloatRange sampleRangeY) :
		VanDerCorputSobolSampler2D(numSamples, _pRNGEngine, sampleRangeX, sampleRangeY),
		samplenum(0)
	{}
	virtual ~VanDerCorputSobolScrambledSampler2D(void);

	virtual void reinitialize()
	{
		samplenum = 0;

		uniform_int_distribution<uint32_t> distr(0);
		this->xscramble = static_cast<uint32_t>(distr(*this->pRNGEngine));
		this->yscramble = static_cast<uint32_t>(distr(*this->pRNGEngine));
	}

	virtual Sample2D getNextSample();
};

