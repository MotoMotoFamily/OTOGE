#include "lib/framework.hpp"
#include "C_App.h"
#include "Game_manager.h"
#include <iostream>
#include <fstream>

#define B_BUTTON (2)
#define Y_BUTTON (3)
#define X_BUTTON (0)
#define D_RIGHT (13)
#define D_UP (12)
#define D_LEFT (15)
int main() {
	CApp::get();
	size_t gamepad_num = CApp::get().numGamePad();
	Media sio_song("res/SIO.wav");
	Game_manager Game_manage;

	sio_song.play();
	sio_song.gain(0.3f);
	//const AppEnv& app = CApp::get();

  while (CApp::get().isOpen()) 
  {
    CApp::get().begin();

	Game_manage.Update();
	Game_manage.Draw();

	///まとめる関数作ります
	Game_manage.Judge_by_joypad(B_BUTTON ,250);
	Game_manage.Judge_by_joypad(Y_BUTTON ,150);
	Game_manage.Judge_by_joypad(X_BUTTON , 50);
	Game_manage.Judge_by_joypad(D_RIGHT , -50);
	Game_manage.Judge_by_joypad(D_UP   , -150);
	Game_manage.Judge_by_joypad(D_LEFT , -250);

	Game_manage.Add_judge_effect();

    CApp::get().end();
  }
}


