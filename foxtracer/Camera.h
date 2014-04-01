#pragma once

#include "foxmath3.h"

using namespace FM;

class Camera
{
private:

public:

	Vec3 pos;
	Mat4 rot;

	Quantum*;

	Camera(void);
	~Camera(void);
};

