#include "C_Deltatime.h"

float Deltatime::Get()
{
	
	deltaTime = clock() - lastFrameTime;  
	lastFrameTime = clock();

	return deltaTime ;
}

