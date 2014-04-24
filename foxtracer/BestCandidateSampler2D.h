#pragma once
#include "sampler2d.h"

#include <map>
using namespace std;

class BestCandidateSampler2D :
	public Sampler2D
{
protected:
	Sample2D* const samples;
	size_t samplenum;
	const size_t numCandidates;
	
public:
	BestCandidateSampler2D(void);
	BestCandidateSampler2D(size_t numSamples,
		std::default_random_engine* _pRNGEngine,
		FloatRange sampleRangeX, FloatRange sampleRangeY, size_t _numCandidates)
		:
		Sampler2D(numSamples, _pRNGEngine, sampleRangeX, sampleRangeY),
		samples(new Sample2D[numSamples]),
		samplenum(0),
		numCandidates(_numCandidates)
	{}
	virtual ~BestCandidateSampler2D(void);
	virtual void reinitialize()
	{
		this->samplenum = 0;
	}

	virtual Sample2D getNextSample();
};

