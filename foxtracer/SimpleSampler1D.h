#pragma once
#include "Sampler.h"

class SimpleSampler1D :
	public Sampler
{
public:
	SimpleSampler1D();
	SimpleSampler1D(size_t numSamples);
	virtual ~SimpleSampler1D();

	virtual Sample getNextSample();
	//virtual vector<Sample> getNextSampleBatch();
	//virtual vector<Sample> getNextSampleBatch(size_t num);
};

