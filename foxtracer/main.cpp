#include <iostream>
using namespace std;

#include "Screen.h"
#include "Integrator.h"
#include "Shape3d.h"

int main(int argc, char** argv)
{
	cout << "test";

	//Screen screen(800, 600);
	Camera camera(800, 600, 90, 5, 0.1);
	Integrator* integrator;

	Shape3d dragon("dragonmesh.obj");
	
	//for now, start casting right away

	uint i = 0, j = 0;
	for (i = 0; i < camera.getWidth(); i++)
	{
		for (j = 0; j < camera.getHeight(); j++)
		{
			Ray shootme = camera->getRay(i, j);
			Quantum
			camera.setSensor(i, j, integrator, shootme);
		}
	}



	//TODO: openGL part

	return 0;
}

//void draw();