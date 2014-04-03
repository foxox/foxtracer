#pragma once
#include "sampler2d.h"
class SimpleSampler2D :
	public Sampler2D
{
public:
	SimpleSampler2D(void);
	SimpleSampler2D(size_t numSamples) : Sampler2D(numSamples) {}
	virtual ~SimpleSampler2D(void);

	virtual Sample2D getNextSample();
};

