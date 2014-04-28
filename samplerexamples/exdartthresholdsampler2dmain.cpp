#include <iostream>
using namespace std;

#include "PixelSampleExampleGenerators.h"

#include "DartThresholdSampler2D.h"

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
	
	//2D GRID

	//failed samples go to 0,0 (reduce threshold or sample count)
	sampler = new DartThresholdSampler2D(numSamples, &mt, xrange, yrange, 0.002f);
	generateExampleImage2DSampleGrid(sampler, "DartThresholdSampler2D");
	delete sampler;


	//CHECKERS

	numSamples = 4;

	//failed samples go to 0,0 (reduce threshold or sample count)
	sampler = new DartThresholdSampler2D(numSamples, &mt, xrange, yrange, 0.7f * (xrange.high-xrange.low) / sqrt(static_cast<float>(numSamples)));
	generateExampleImageInfiniteCheckers(sampler, "DartThresholdSampler2D");
	delete sampler;


	return 0;
}
