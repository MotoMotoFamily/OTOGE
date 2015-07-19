#include "lib/framework.hpp"
#include "C_App.h"
#include "Game_manager.h"
#include <iostream>

#define NOTE_MAX  (29)
#define PARTITION_FUNCTION_OF_CIRCLE  (30)
#define NOTE_CHECKLINE_MAX (-150)
#define NOTE_CHECKLINE_MIN (-250)
#define PLAYER_ICON_NUMBER (6)
#define NOTE_DEADLINE (-300)

int main() {
	CApp::get();

	size_t gamepad_num = CApp::get().numGamePad();
	Font font("res/meiryo.ttc");
	font.size(50);
	Media sio_song("res/SIO.wav");
	
	int player_pos_x[PLAYER_ICON_NUMBER] = { -250,-150,-50,50,150,250 };
	int now_score = 0;
	int now_combo = 0;
	Vec2f player_size = Vec2f(30, 7.5f);
	Game_manager Game_manage;

	sio_song.play();
	sio_song.gain(0.3f);
	//const AppEnv& app = CApp::get();
	
  while (CApp::get().isOpen()) {
   
    CApp::get().begin();

	//試し用コンボ表示
	std::string COMBO = std::to_string(now_combo);
	font.draw(COMBO, Vec2f(0, 100), Color::blue);

	//試し用スコア表示
	std::string SCORE = std::to_string(now_score);
	font.draw(SCORE, Vec2f(-50, 100), Color::white);

	for (int i = 0; i < PLAYER_ICON_NUMBER; ++i)
	{
		//PLAYERのICON位置
		drawFillCircle(player_pos_x[i], PLAYER_Y, player_size.x(), player_size.y(),
			PARTITION_FUNCTION_OF_CIRCLE, Color::red);
	}

	Game_manage.Update();
	Game_manage.Draw();

    CApp::get().end();
  }
}


