#pragma once
#include "lib/framework.hpp"

class Deltatime
{
	Deltatime()
	{
		 lastFrameTime = clock();
		 deltaTime = 0.0f;



	}

public:
	float Get();


private:
	float lastFrameTime = clock();
	float deltaTime = 0.0f;


};