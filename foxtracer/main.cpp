#include <iostream>
using namespace std;

#include "Camera.h"

#include "SimpleSampler2D.h"
#include "StratifiedSampler2D.h"
#include "LatinHypercubeSampler2D.h"
#include "HaltonSampler2D.h"
#include "HammerslySampler2D.h"
#include "VanDerCorputSobolSampler2D.h"
#include "DartThresholdSampler2D.h"
#include "BestCandidateSampler2D.h"

#include "HaltonScrambledSampler2D.h"
#include "HammerslyScrambledSampler2D.h"
#include "VanDerCorputSobolScrambledSampler2D.h"


#define FOXTRACERFOLDER
#include "../samplerexamples/PixelSampleExampleGenerators.h"

#include <random>

void generateExampleImage2DSampleGrid(Sampler2D* sampler, string name);
void generateExampleImageInfiniteCheckers(Sampler2D* sampler, string name);

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

	//sampler = new SimpleSampler2D(numSamples, &mt, xrange, yrange);
	//generateExampleImage2DSampleGrid(sampler, "SimpleSampler2D");
	//delete sampler;
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

	//0,2 sequence
	sampler = new VanDerCorputSobolSampler2D(numSamples, &mt, xrange, yrange);
	generateExampleImage2DSampleGrid(sampler, "VanDerCorputSobolSampler2D");
	delete sampler;

	////failed samples go to 0,0 (reduce threshold or sample count)
	//sampler = new DartThresholdSampler2D(numSamples, &mt, xrange, yrange, 0.002f);
	//generateExampleImage2DSampleGrid(sampler, "DartThresholdSampler2D");
	//delete sampler;
	//sampler = new BestCandidateSampler2D(numSamples, &mt, xrange, yrange, 10);
	//generateExampleImage2DSampleGrid(sampler, "BestCandidateSampler2D");
	//delete sampler;


	//sampler = new HaltonScrambledSampler2D(numSamples, &mt, xrange, yrange);
	//generateExampleImage2DSampleGrid(sampler, "HaltonScrambledSampler2D");
	//delete sampler;

	//sampler = new HammerslyScrambledSampler2D(numSamples, &mt, xrange, yrange);
	//generateExampleImage2DSampleGrid(sampler, "HammerslyScrambledSampler2D");
	//delete sampler;

	sampler = new VanDerCorputSobolScrambledSampler2D(numSamples, &mt, xrange, yrange);
	generateExampleImage2DSampleGrid(sampler, "VanDerCorputSobolScrambledSampler2D");
	delete sampler;





	//CHECKERS

	numSamples = 4;

	//sampler = new SimpleSampler2D(numSamples, &mt, xrange, yrange);
	//generateExampleImageInfiniteCheckers(sampler, "SimpleSampler2D");
	//delete sampler;
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

	//0,2 sequence
	sampler = new VanDerCorputSobolSampler2D(numSamples, &mt, xrange, yrange);
	generateExampleImageInfiniteCheckers(sampler, "VanDerCorputSobolSampler2D");
	delete sampler;

	////failed samples go to 0,0 (reduce threshold or sample count)
	//sampler = new DartThresholdSampler2D(numSamples, &mt, xrange, yrange, 0.7f * (xrange.high-xrange.low) / sqrt(static_cast<float>(numSamples)));
	//generateExampleImageInfiniteCheckers(sampler, "DartThresholdSampler2D");
	//delete sampler;	
	//sampler = new BestCandidateSampler2D(numSamples, &mt, xrange, yrange, 10);
	//generateExampleImageInfiniteCheckers(sampler, "BestCandidateSampler2D");
	//delete sampler;


	//sampler = new HaltonScrambledSampler2D(numSamples, &mt, xrange, yrange);
	//generateExampleImageInfiniteCheckers(sampler, "HaltonScrambledSampler2D");
	//delete sampler;

	//sampler = new HammerslyScrambledSampler2D(numSamples, &mt, xrange, yrange);
	//generateExampleImageInfiniteCheckers(sampler, "HammerslyScrambledSampler2D");
	//delete sampler;

	sampler = new VanDerCorputSobolScrambledSampler2D(numSamples, &mt, xrange, yrange);
	generateExampleImageInfiniteCheckers(sampler, "VanDerCorputSobolScrambledSampler2D");
	delete sampler;




	return 0;
}

//void generateExampleImageInfiniteCheckers(Sampler2D* sampler, string name)
//{
//	//For this case, let the "sensor" just be this image array:
//	const size_t imageoutSideSize = 244;
//	const size_t imageoutISIZE = imageoutSideSize;
//	const size_t imageoutJSIZE = imageoutSideSize;
//	const size_t imageoutKSIZE = 3;
//	unsigned char* imageout = new unsigned char[imageoutISIZE*imageoutJSIZE*imageoutKSIZE];
//	memset(imageout, 255, imageoutISIZE*imageoutJSIZE*imageoutKSIZE*sizeof(unsigned char));
//
//	Camera camera(imageoutISIZE, imageoutJSIZE, 1.0f);
//
//	//Cast!
//	size_t i = 0;
//	size_t j = 0;
//	for (i = 0; i < camera.getWidth(); i++)
//	{
//		for (j = 0; j < camera.getHeight(); j++)
//		{
//			//New pixel, reinitialize sampler
//			//TODO: consider scrambling here if needed (look for weird aliasing)
//			sampler->reinitialize();
//
//			float u = static_cast<float>(i) / static_cast<float>(camera.getWidth());
//			float v = static_cast<float>(j) / static_cast<float>(camera.getHeight());
//
//			unsigned char r = 0;
//			unsigned char g = 0;
//			unsigned char b = 0;
//
//			float sampleavg = 0.0f;
//
//			//Sample several times
//			for (unsigned int k = 0; k < sampler->getNumSamples(); k++)
//			{
//				//generate origin and aperture ray samples for this pixel (later this may be a batch)
//				Sample2D filmloc = sampler->getNextSample();
//				filmloc.x /= camera.getWidth();
//				filmloc.y /= camera.getHeight();
//				filmloc.x += u;
//				filmloc.y += v;
//
//				Sample2D aperture(0.0, 0.0);
//
//				//Get the ray
//				Ray shootme = camera.getRay(filmloc, aperture);
//
//				//Find XZ intercept
//				float t = -1.0f * shootme.origin.y / shootme.direction.y;
//				Vec3 intercept = shootme.atTime(t) * 2.0f;
//
//				//Intercept happened?
//				if (t > 0)
//				{
//					//Determine checker color
//					long long interceptintx = static_cast<long long>(intercept.x);
//					long long interceptintz = static_cast<long long>(intercept.z);
//					if ((interceptintx + interceptintz) % 2 == 0)
//					{
//						//r = static_cast<unsigned char>(255.0f * t);
//						//g = static_cast<unsigned char>(255.0f * t);
//						//b = static_cast<unsigned char>(255.0f * t);
//						//r = 255;
//						//g = 255;
//						//b = 255;
//						sampleavg += 1.0f;
//					}
//					//else
//					//{
//						//r = 0;
//						//g = 0;
//						//b = 0;
//					//}
//				}
//				//else
//				//{
//				//	r = 255;
//				//	g = 0;
//				//	b = 128;
//				//}
//			}
//
//			sampleavg /= static_cast<float>(sampler->getNumSamples());
//			r = static_cast<unsigned char>(255.0f * sampleavg);
//			g = r;
//			b = r;
//
//			//Write checker color
//			i3(imageout, j, i, 0) = r;
//			i3(imageout, j, i, 1) = g;
//			i3(imageout, j, i, 2) = b;
//
//		}//j loop
//	}//i loop
//
//	ImageOutRGB2BMP("examples/" + name + "InfiniteCheckers" + ".bmp", imageoutISIZE, imageoutJSIZE, imageout);
//}//function to generate infinite checker pattern
//
//void generateExampleImage2DSampleGrid(Sampler2D* sampler, string name)
//{
//	const size_t imageoutSideSize = 244;
//	const size_t imageoutISIZE = imageoutSideSize;
//	const size_t imageoutJSIZE = imageoutSideSize;
//	const size_t imageoutKSIZE = 3;
//	unsigned char* imageout = new unsigned char[imageoutISIZE*imageoutJSIZE*imageoutKSIZE];
//	memset(imageout, 255, imageoutISIZE*imageoutJSIZE*imageoutKSIZE*sizeof(unsigned char));
//
//	//Draw lines
//	const size_t numDivs = 16;
//	for (size_t i = 1; i < numDivs; i++)
//	{
//		size_t i10 = i * imageoutSideSize / numDivs;
//
//		//Draw row
//		for (size_t j = 0; j < imageoutJSIZE; j++)
//		{
//			//i3(imageout, i10, j, 0) = 128;
//			i3(imageout, i10, j, 1) = 128;
//			i3(imageout, i10, j, 2) = 128;
//		}
//
//		//Draw col
//		for (size_t j = 0; j < imageoutISIZE; j++)
//		{
//			//i3(imageout, j, i10, 0) = 128;
//			i3(imageout, j, i10, 1) = 128;
//			i3(imageout, j, i10, 2) = 128;
//		}
//	}
//
//	//Samples!
//	for (size_t i = 0; i < sampler->getNumSamples(); i++)
//	{
//		Sample2D samp = sampler->getNextSample();
//
//		size_t x = static_cast<size_t>(samp.x * static_cast<float>(imageoutISIZE));
//		size_t y = static_cast<size_t>(samp.y * static_cast<float>(imageoutJSIZE));
//
//		i3(imageout, y, x, 0) = 0;
//		i3(imageout, y, x, 1) = 0;
//		i3(imageout, y, x, 2) = 0;
//	}
//
//	ImageOutRGB2BMP("examples/" + name + "2DSampleGrid" + ".bmp", imageoutISIZE, imageoutJSIZE, imageout);
//}//end 2d sample grid image generation function
