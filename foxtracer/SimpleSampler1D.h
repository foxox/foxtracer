#pragma once
#include "Sampler1D.h"

class SimpleSampler1D :
	public Sampler1D
{
public:
	//SimpleSampler1D();
	SimpleSampler1D(size_t numSamples, std::default_random_engine* _pRNGEngine, FloatRange sampleRange);
	virtual ~SimpleSampler1D();

	virtual Sample1D getNextSample();
	//virtual vector<Sample> getNextSampleBatch();
	//virtual vector<Sample> getNextSampleBatch(size_t num);
};

