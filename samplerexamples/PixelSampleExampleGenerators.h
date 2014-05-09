#include "ExamplePinholeCamera.h"
#include "Sampler2D.h"

//For _mkdir
#include <direct.h>

#define EXAMPLEIMAGESIZE 244
#define EXAMPLENUMSAMPLES 16

void generateExampleImage2DSampleGrid(Sampler2D* sampler, string name);
void generateExampleImageInfiniteCheckers(Sampler2D* sampler, string name, float* const u, float* const v);

float intersectCheckerboard(ExamplePinholeCamera* camera, Sample2D filmloc, float u, float v)
{
	filmloc.x /= camera->getWidth();
	filmloc.y /= camera->getHeight();
	filmloc.x += u;
	filmloc.y += v;

	Sample2D aperture(0.0, 0.0);

	//Get the ray
	Ray shootme = camera->getRay(filmloc, aperture);

	//Find XZ intercept
	float t = -1.0f * shootme.origin.y / shootme.direction.y;
	Vec3 intercept = shootme.atTime(t) * 2.0f;

	//Intercept happened?
	if (t > 0)
	{
		//Determine checker color
		long long interceptintx = static_cast<long long>(intercept.x);
		long long interceptintz = static_cast<long long>(intercept.z);
		if ((interceptintx + interceptintz) % 2 == 0)
		{
			return 1.0f;
		}
	}

	return 0.0f;
}

void generateExampleImageInfiniteCheckers(Sampler2D* sampler, string name, float* const u, float* const v)
{
	//For this case, let the "sensor" just be this image array:
	const size_t imageoutSideSize = EXAMPLEIMAGESIZE;
	const size_t imageoutISIZE = imageoutSideSize;
	const size_t imageoutJSIZE = imageoutSideSize;
	const size_t imageoutKSIZE = 3;
	unsigned char* imageout = new unsigned char[imageoutISIZE*imageoutJSIZE*imageoutKSIZE];
	memset(imageout, 255, imageoutISIZE*imageoutJSIZE*imageoutKSIZE*sizeof(unsigned char));

	ExamplePinholeCamera camera(imageoutISIZE, imageoutJSIZE, 1.0f);

	size_t normalNumSamples = sampler->getNumSamples();

	//Cast!
	size_t i = 0;
	size_t j = 0;
	for (i = 0; i < camera.getWidth(); i++)
	{
		for (j = 0; j < camera.getHeight(); j++)
		{
			//New pixel, reinitialize sampler
			//TODO: consider scrambling here if needed (look for weird aliasing)
			sampler->reinitialize();

			*u = static_cast<float>(i) / static_cast<float>(camera.getWidth());
			*v = static_cast<float>(j) / static_cast<float>(camera.getHeight());

			unsigned char r = 0;
			unsigned char g = 0;
			unsigned char b = 0;

			float sampleavg = 0.0f;

			//if (i == 122 && j == 230)
			//{
			//	cout << "Test this pixel." << endl;
			//}

			//Sample several times
			for (unsigned int k = 0; k < sampler->getNumSamples(); k++)
			{
				//generate origin and aperture ray samples for this pixel (later this may be a batch)
				Sample2D filmloc = sampler->getNextSample();

				sampleavg += intersectCheckerboard(&camera, filmloc, *u, *v);
			}

			sampleavg /= static_cast<float>(sampler->getNumSamples());
			r = static_cast<unsigned char>(255.0f * sampleavg);
			g = r;
			b = r;

			//special marks for adaptivesampler
			if (sampler->getNumSamples() != normalNumSamples)
			{
				g = 9*g/10;
				b = 9*b/10;
				r = min(255, r + r / 10);
			}

			//if (i == 122 && j == 230)
			//{
			//	r = 0;
			//	g = 0;
			//	b = 255;
			//}

			//Write checker color
			i3(imageout, j, i, 0) = r;
			i3(imageout, j, i, 1) = g;
			i3(imageout, j, i, 2) = b;

		}//j loop
	}//i loop

	//Make the directory
	_mkdir("examples");

	ImageOutRGB2BMP("examples/" + name + "InfiniteCheckers" + ".bmp", imageoutISIZE, imageoutJSIZE, imageout);
}//function to generate infinite checker pattern

void generateExampleImage2DSampleGrid(Sampler2D* sampler, string name)
{
	const size_t imageoutSideSize = 244;
	const size_t imageoutISIZE = imageoutSideSize;
	const size_t imageoutJSIZE = imageoutSideSize;
	const size_t imageoutKSIZE = 3;
	unsigned char* imageout = new unsigned char[imageoutISIZE*imageoutJSIZE*imageoutKSIZE];
	memset(imageout, 255, imageoutISIZE*imageoutJSIZE*imageoutKSIZE*sizeof(unsigned char));

	//Draw lines
	const size_t numDivs = 16;
	for (size_t i = 1; i < numDivs; i++)
	{
		size_t i10 = i * imageoutSideSize / numDivs;

		//Draw row
		for (size_t j = 0; j < imageoutJSIZE; j++)
		{
			//i3(imageout, i10, j, 0) = 128;
			i3(imageout, i10, j, 1) = 128;
			i3(imageout, i10, j, 2) = 128;
		}

		//Draw col
		for (size_t j = 0; j < imageoutISIZE; j++)
		{
			//i3(imageout, j, i10, 0) = 128;
			i3(imageout, j, i10, 1) = 128;
			i3(imageout, j, i10, 2) = 128;
		}
	}

	//Samples!
	for (size_t i = 0; i < sampler->getNumSamples(); i++)
	{
		Sample2D samp = sampler->getNextSample();

		size_t x = static_cast<size_t>(samp.x * static_cast<float>(imageoutISIZE));
		size_t y = static_cast<size_t>(samp.y * static_cast<float>(imageoutJSIZE));

		i3(imageout, y, x, 0) = 0;
		i3(imageout, y, x, 1) = 0;
		i3(imageout, y, x, 2) = 0;
	}

	//Make the directory
	_mkdir("examples");

	ImageOutRGB2BMP("examples/" + name + "SampleGrid" + ".bmp", imageoutISIZE, imageoutJSIZE, imageout);
}//end 2d sample grid image generation function
