#include "Sampler.h"


//Sampler::Sampler(void) : numSamples(0)
//{
//
//}

Sampler::Sampler(size_t _numSamples, std::default_random_engine* _pRNGEngine) : numSamples(_numSamples), pRNGEngine(_pRNGEngine)
{
	//this->RNGDistribution = uniform_real_distribution(this)
}


Sampler::~Sampler(void)
{
}


size_t Sampler::getNumSamples()
{
	return this->numSamples;
}