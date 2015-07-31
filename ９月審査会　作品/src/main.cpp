#include "lib/framework.hpp"
#include "C_App.h"
#include "Scene_manager.h"


int main() {
	CApp::get();
	size_t gamepad_num = CApp::get().numGamePad();

	Scene_manager scene_manage;
  while (CApp::get().isOpen()) 
  {
	  CApp::get().begin();
	  
	
	  scene_manage.Update();
	  scene_manage.Draw();


    CApp::get().end();
  }
}


