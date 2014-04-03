#include "SimpleSampler1D.h"


SimpleSampler1D::SimpleSampler1D() : Sampler1D()
{
}

SimpleSampler1D::SimpleSampler1D(size_t numSamples) : Sampler1D(numSamples)
{
}


SimpleSampler1D::~SimpleSampler1D()
{
}


Sample1D SimpleSampler1D::getNextSample()
{
	Sample1D returnme;
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

