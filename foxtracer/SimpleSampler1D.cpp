#include "SimpleSampler1D.h"


SimpleSampler1D::SimpleSampler1D() : Sampler()
{
}

SimpleSampler1D::SimpleSampler1D(size_t numSamples) : Sampler(numSamples)
{
}


SimpleSampler1D::~SimpleSampler1D()
{
}


Sample SimpleSampler1D::getNextSample()
{
	Sample returnme;
	//TODO: form sample to return from SimpleSampler1D
	returnme = 0.0f;
	return returnme;
}


//vector<Sample> SimpleSampler1D::getNextSampleBatch()
//{
//	return getNextSampleBatch(this->numSamples);
//}

//vector<Sample> SimpleSampler1D::getNextSampleBatch(size_t num)
//{
//	vector<Sample> returnme;
//	//TODO: return batch of samples
//
//	return returnme;
//}

