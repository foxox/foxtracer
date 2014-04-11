#include "SimpleSampler1D.h"


//SimpleSampler1D::SimpleSampler1D() : Sampler1D()
//{
//}

SimpleSampler1D::SimpleSampler1D(size_t numSamples, std::default_random_engine* _pRNGEngine, FloatRange sampleRange) : Sampler1D(numSamples, _pRNGEngine, sampleRange)
{

}


SimpleSampler1D::~SimpleSampler1D()
{
}


Sample1D SimpleSampler1D::getNextSample()
{
	Sample1D returnme;
	//TODO: use RNG to make sample, then return it
	//this->
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

