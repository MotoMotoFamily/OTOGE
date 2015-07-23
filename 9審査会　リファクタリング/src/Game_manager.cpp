#include"Game_manager.h"
Media hit_se("res/dan.wav");

//////////////////////////////////////////////////////////
//　　　　　　　　外部ファイルから読み込み　　　　　　　　　 //
//////////////////////////////////////////////////////////


void Game_manager::Note_initialize()
{
	note_position note_pos[NOTE_MAX];

	File_read read[NOTE_MAX];

	std::fstream file("res/sio_song.txt");

	for (int i = 0; i < NOTE_MAX; ++i)
	{
		file >> read[i].str[0] >> read[i].str[1] >> read[i].pos_x >> read[i].str[2] >> read[i].str[3] >> read[i].str[4] >> read[i].pos_y;
	}
	for (int i = 0; i < NOTE_MAX; ++i)
	{
		int index = 0;

		if (read[i].str[0] == 'E')
		{
			break;
		}
		if (read[i].str[index] == 'X' && read[i].str[++index] == ':')
		{
			read[i].isReadingPositionX = true;
		}
		if (read[i].str[++index] == ',' && read[i].str[++index] == 'Y' && read[i].str[++index] == ':')
		{
			read[i].isReadingPositionY = true;
		}

		if (read[i].isReadingPositionX)
		{
			note_pos[i].x = read[i].pos_x;
			read[i].isReadingPositionX = false;
		}
		if (read[i].isReadingPositionY == true)
		{
			note_pos[i].y = read[i].pos_y;
			read[i].isReadingPositionY = false;
		}

	}
	for (int i = 0; i < NOTE_MAX; ++i)
	{
		note[i].Init(note_pos[i].x,note_pos[i].y, note_size);
	}
}




void Game_manager::Update()
{
	float time = deltatime.Get();
	for (int i = 0; i < NOTE_MAX; ++i)
	{
		note[i].Move(time * deltaTime_content);
	}
	
}

void Game_manager::Draw()
{
	Font font("res/meiryo.ttc");
	font.size(50);

	//試し用コンボ表示
	std::string COMBO = std::to_string(now_combo);
	font.draw(COMBO, Vec2f(-150, 200), Color::blue);

	//試し用スコア表示
	std::string SCORE = std::to_string(now_score);
	font.draw(SCORE, Vec2f(-50, 200), Color::white);

	//プレイヤーアイコン表示
	player.Draw();

	for (int i = 0; i < NOTE_MAX; ++i)
	{
		note[i].Draw();
	}
	
}


void Game_manager::Judge_by_joypad(int _button_num, float _x)
{
	if (!Cjudge::pad.isPushButton(_button_num)) return;

	hit_se.play();

	for (int i = 0; i < NOTE_MAX; ++i)
	{
		//範囲内かつ、判定用フラグがfalseなら
		if (judge[i].Get_is_active() && Is_Inside(note[i].Get_note_pos_y(), NOTE_CHECKLINE_MAX, NOTE_CHECKLINE_MIN)
			&& Cjudge::Get_distance(_x, note[i].Get_note_pos_x()) <= PLAYER_WIDTH / 2)
		{
			judge[i].Set_is_active(false);
			note[i].Kill();
			judge[i].Set_draw_active(true);
			break;
		}

	}
	
}


void Game_manager::Add_judge_effect()
{

	for (int i = 0; i < NOTE_MAX; ++i)
	{
		if (Game_manager::judge[i].Get_draw_active() )
		{
			judge[i].Judgging(note[i].Get_note_pos_y());
			judge[i].Draw();
			now_combo = judge[i].Get_Combo(now_combo);
			now_score = judge[i].Get_Score(now_score);
		}
		
	}
	
}

void Game_manager::Judge_of_deadline()
{
	for (int i = 0; i < NOTE_MAX; ++i)
	{
		if (Game_manager::note[i].Is_active() && note[i].Get_note_pos_y() < NOTE_MAX)
		{
			note[i].Kill();
			now_combo = judge[i].Reset_Combo();
		}
		
	}
}