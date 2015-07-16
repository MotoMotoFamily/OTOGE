#pragma once
#include "lib/framework.hpp"

class Deltatime
{
	
public:
	Deltatime()
	{
		lastFrameTime = clock();
		deltaTime = 0.0f;
	}

	float Get();


private:
	float lastFrameTime = clock();
	float deltaTime = 0.0f;


};