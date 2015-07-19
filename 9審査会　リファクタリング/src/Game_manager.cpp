#include"Game_manager.h"


void Game_manager::Note_initialize()
{
	note_position note_pos[] =
	{
		{ -250, 950 / 4 }, { -150, 2200 / 4 }, { -50, 2400 / 4 }, { 50, 2600 / 4 }, { 250, 3500 / 4 },
		{ 150, 4400 / 4 }, { 50, 4600 / 4 }, { -50, 4800 / 4 }, { -150, 5000 / 4 }, { -250, 5200 / 4 },
		{ -150, 5400 / 4 }, { -50, 5600 / 4 }, { 50, 5800 / 4 }, { 150, 6050 / 4 }, { 250, 7000 / 4 },
		{ 250, 7100 / 4 }, { 150, 7300 / 4 }, { 50, 7450 / 4 }, { -250, 7600 / 4 }, { -150, 8700 / 4 },
		{ -150, 8800 / 4 }, { -50, 9000 / 4 }, { 50, 9150 / 4 }, { 150, 9300 / 4 }, { 250, 10400 / 4 },
		{ 250, 10500 / 4 }, { 150, 10700 / 4 }, { 50, 10850 / 4 }, { -50, 11000 / 4 },

	};
	for (int i = 0; i < NOTE_MAX; ++i)
	{
		note[i].Init(note_pos[i].x,note_pos[i].y, note_size);
	}
}




void Game_manager::Update()
{
	float deltatime = deltatime_geter.Get();
	for (int i = 0; i < NOTE_MAX; ++i)
	{
		note[i].Move(deltatime * deltaTime_content);
	}
	
}

void Game_manager::Draw()
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