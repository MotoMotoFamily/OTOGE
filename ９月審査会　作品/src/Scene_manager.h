#pragma once

#include "lib/framework.hpp"
#include "C_App.h"
#include "Game_manager.h"
#include "Select_music.h"
#include <memory>

class Scene_manager
{
public:

	Scene_manager():
		scene_type(SCENE::TITLE)
	{

	}
	enum SCENE
	{
		TITLE,
		CONFIG,
		SELECT_MUSIC,
		MAIN_GAME,
		RESULT
	};


	void Draw()
	{
		switch (scene_type)
		{

		case SCENE::TITLE:
		{
			drawFillBox(0, 0, 100, 100, Color::blue);
		}
		break;
		case SCENE::SELECT_MUSIC:
		{
			select_music.Draw();
		}
		break;

		case SCENE::MAIN_GAME:
		{

			game_manage->Draw();

		}
		break;
		default:
			break;
		}

	}

	void Update()
	{
		switch (scene_type)
		{
		   case SCENE::TITLE:
		 {
			time++;
			if (time > 120)
			{
				scene_type = SCENE::SELECT_MUSIC;
			}
		 }
		 break;

		   case SCENE::SELECT_MUSIC:
		   {

			   select_music.Update();
			   if (select_music.Get_to_select_music())
			   {
				   game_manage = new Game_manager;
				   game_manage -> Note_initialize(select_music.Get_music_info());
				   scene_type = SCENE::MAIN_GAME;
			   }
		   }
		   break;

		   case SCENE::MAIN_GAME:
		   {
			   game_manage->Update();
		   }
		}
	}

private:

	SCENE scene_type;
	Cselect_music select_music;
	Game_manager* game_manage;
	int time = 0;

};

