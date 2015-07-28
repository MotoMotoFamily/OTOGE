#include "C_App.h"
#include "lib/framework.hpp"

CApp::CApp()
{
}

AppEnv& CApp::get()
{
	static AppEnv s_env(WINDOW_WIDTH, WINDOW_HEIGHT,
		                IS_FULL_SCREEN,IS_DYNAMMIC_SCREEN);
	return s_env;
}