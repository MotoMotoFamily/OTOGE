#include"Game_manager.h"

void Game_manager::Init()
{


	


	for (int i = 0; i < NOTE_MAX; ++i)
	{
		//note[i].Init(note_x[i], note_y[i], note_size);



	}
}





void Game_manager::Update()
{
	for (int i = 0; i < NOTE_MAX; ++i)
	{

		note[i].Move(get_deltatime.Get() * deltaTime_content);

	}

}

void Game_manager::draw()
{
	for (int i = 0; i < NOTE_MAX; ++i)
	{
		note[i].Draw();


	}
}


void Game_manager::Judge_by_joypad(int _button_num, float _x)
{
	if (!Cjudge::pad.isPushButton(_button_num)) return;

	for (int i = 0; i < NOTE_MAX; ++i)
	{
		//範囲内かつ、判定用フラグがfalseなら
		if (judge[i].Get_is_active() && Is_Inside(note[i].Get_note_pos_y(), NOTE_CHECKLINE_MAX, NOTE_CHECKLINE_MIN)
			&& Cjudge::Get_distance(_x, note[i].Get_note_pos_x()) <= PLAYER_WIDTH / 2)
		{
			judge[i].Set_is_active(false);
			note[i].Kill();
			break;
		}

	}

}


void Game_manager::Add_judge_effect(int _now_combo, int _now_score)
{

	for (int i = 0; i < NOTE_MAX; ++i)
	{
		if (Game_manager::judge[i].Get_is_active() )
		{
			judge[i].Set_is_active(false);
			judge[i].Judgging(note[i].Get_note_pos_y());
			judge[i].Draw();
			_now_combo = judge[i].Get_Combo(_now_combo);
			_now_score = judge[i].Get_Score(_now_score);

		}

	}

}

void Game_manager::Judge_of_deadline(int _now_combo)
{
	for (int i = 0; i < NOTE_MAX; ++i)
	{
		if (Game_manager::judge[i].Get_is_active() && note[i].Get_note_pos_y() < NOTE_MAX)
		{
			_now_combo = judge[i].Reset_Combo();
		}

	}
}