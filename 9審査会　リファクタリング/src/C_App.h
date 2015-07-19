#pragma once
#include "lib/framework.hpp"

#define WINDOW_WIDTH 750
#define WINDOW_HEIGHT 500
#define IS_FULL_SCREEN false
#define IS_DYNAMMIC_SCREEN true

class CApp
{
public:
	static AppEnv& get();
private:
	CApp();
};
