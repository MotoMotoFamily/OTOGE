#include "lib/framework.hpp"
#include "C_App.h"
#include "Game_manager.h"
#include <iostream>
#include <fstream>

const AppEnv& app = CApp::get();

int main() {
	CApp::get();
	size_t gamepad_num = CApp::get().numGamePad();
	Media sio_song("res/SIO.wav");
	Game_manager Game_manage;

	sio_song.play();
	sio_song.gain(0.3f);


  while (CApp::get().isOpen()) 
  {
    CApp::get().begin();

	Game_manage.Update();
	Game_manage.Draw();
	
    CApp::get().end();
  }
}


