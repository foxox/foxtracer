#include <iostream>
using namespace std;

#include "PixelSampleExampleGenerators.h"

#include "SimpleSampler2D.h"
//#include "StratifiedSampler2D.h"
//#include "LatinHypercubeSampler2D.h"
//#include "HaltonSampler2D.h"
//#include "HammerslySampler2D.h"
//#include "VanDerCorputSobolSampler2D.h"
//#include "DartThresholdSampler2D.h"
//#include "BestCandidateSampler2D.h"

#include <random>

int main(int argc, char** argv)
{
	//generate a bunch of samples and write to an image file to show them.
	size_t numSamples = 256;
	FloatRange xrange(0, 1);
	FloatRange yrange(0, 1);
	//RNG stuff, pass into sampler
	std::tr1::random_device rd;
	std::tr1::mt19937 mt(rd());
	//std::tr1::uniform_real_distribution<> distribution(0.0, 1.0);
	
	Sampler2D* sampler;
	
	////2D GRID

	sampler = new SimpleSampler2D(numSamples, &mt, xrange, yrange);
	generateExampleImage2DSampleGrid(sampler, "SimpleSampler2D");
	delete sampler;

	//sampler = new StratifiedSampler2D(numSamples, &mt, xrange, yrange, 16, 16);
	//generateExampleImage2DSampleGrid(sampler, "StratifiedSampler2D");
	//delete sampler;

	//sampler = new LatinHypercubeSampler2D(numSamples, &mt, xrange, yrange);
	//generateExampleImage2DSampleGrid(sampler, "LatinHypercubeSampler2D");
	//delete sampler;

	////unscrambled
	//sampler = new HaltonSampler2D(numSamples, &mt, xrange, yrange);
	//generateExampleImage2DSampleGrid(sampler, "HaltonSampler2D");
	//delete sampler;

	////unscrambled
	//sampler = new HammerslySampler2D(numSamples, &mt, xrange, yrange);
	//generateExampleImage2DSampleGrid(sampler, "HammerslySampler2D");
	//delete sampler;

	////0,2 sequence
	//sampler = new VanDerCorputSobolSampler2D(numSamples, &mt, xrange, yrange);
	//generateExampleImage2DSampleGrid(sampler, "VanDerCorputSobolSampler2D");
	//delete sampler;

	////failed samples go to 0,0 (reduce threshold or sample count)
	//sampler = new DartThresholdSampler2D(numSamples, &mt, xrange, yrange, 0.002f);
	//generateExampleImage2DSampleGrid(sampler, "DartThresholdSampler2D");
	//delete sampler;

	//sampler = new BestCandidateSampler2D(numSamples, &mt, xrange, yrange, 10);
	//generateExampleImage2DSampleGrid(sampler, "BestCandidateSampler2D");
	//delete sampler;


	//CHECKERS

	numSamples = 4;

	sampler = new SimpleSampler2D(numSamples, &mt, xrange, yrange);
	generateExampleImageInfiniteCheckers(sampler, "SimpleSampler2D");
	delete sampler;

	//sampler = new StratifiedSampler2D(numSamples, &mt, xrange, yrange,
	//	static_cast<size_t>(sqrtf(static_cast<float>(numSamples))),
	//	static_cast<size_t>(sqrtf(static_cast<float>(numSamples))));
	//generateExampleImageInfiniteCheckers(sampler, "StratifiedSampler2D");
	//delete sampler;

	//sampler = new LatinHypercubeSampler2D(numSamples, &mt, xrange, yrange);
	//generateExampleImageInfiniteCheckers(sampler, "LatinHypercubeSampler2D");
	//delete sampler;

	////unscrambled
	//sampler = new HaltonSampler2D(numSamples, &mt, xrange, yrange);
	//generateExampleImageInfiniteCheckers(sampler, "HaltonSampler2D");
	//delete sampler;

	////unscrambled
	//sampler = new HammerslySampler2D(numSamples, &mt, xrange, yrange);
	//generateExampleImageInfiniteCheckers(sampler, "HammerslySampler2D");
	//delete sampler;

	////0,2 sequence
	//sampler = new VanDerCorputSobolSampler2D(numSamples, &mt, xrange, yrange);
	//generateExampleImageInfiniteCheckers(sampler, "VanDerCorputSobolSampler2D");
	//delete sampler;

	////failed samples go to 0,0 (reduce threshold or sample count)
	//sampler = new DartThresholdSampler2D(numSamples, &mt, xrange, yrange, 0.7f * (xrange.high-xrange.low) / sqrt(static_cast<float>(numSamples)));
	//generateExampleImageInfiniteCheckers(sampler, "DartThresholdSampler2D");
	//delete sampler;

	//sampler = new BestCandidateSampler2D(numSamples, &mt, xrange, yrange, 10);
	//generateExampleImageInfiniteCheckers(sampler, "BestCandidateSampler2D");
	//delete sampler;\

	return 0;
}
