#include "lib/framework.hpp"
#include "C_App.h"
#include "C_Note.h"
#include "C_Judge.h"
#include "Inside.h"
#include "C_Deltatime.h"
#include <iostream>

#define NOTE_MAX  (29)
#define PARTITION_FUNCTION_OF_CIRCLE  (30)
#define ICON_CHECKLINE_MAX (-150)
#define ICON_CHECKLINE_MIN (-250)
#define PLAYER_ICON_NUMBER (6)
#define ICON_DEADLINE (-300)


int main() {
	CApp::get();

	size_t gamepad_num = CApp::get().numGamePad();
	Font font("res/meiryo.ttc");
	font.size(50);
	Media sio_song("res/SIO.wav");
	Media hit_se("res/dan.wav");
	Cnote Note[NOTE_MAX]; // ノートを29個分生成
	Cjudge judge[NOTE_MAX];
	Deltatime get_deltatime;

	int player_pos_x[PLAYER_ICON_NUMBER] = { -250,-150,-50,50,150,250 };
	int player_pos_y = -200;
	Vec2f player_size = Vec2f(30, 7.5f);
	
	int now_score = 0;
	int now_combo = 0;

	float note_x[] =
	{
		-250, -150, -50, 50, 250, 150, 50, -50, -150, -250,
		-150, -50, 50, 150, 250, 250, 150, 50, -250, -150,
		-150, -50, 50, 150,   250, 250, 150, 50, -50
	};

	float note_y[] =
	{
		950 / 4, 2200 / 4, 2400 / 4, 2600 / 4, 3500 / 4, 4400 / 4, 4600 / 4, 4800 / 4, 5000 / 4, 5200 / 4,
		5400 / 4, 5600 / 4, 5800 / 4, 6050 / 4, 7000 / 4, 7100 / 4, 7300 / 4, 7450 / 4, 7600 / 4, 8700 / 4,
		8800 / 4, 9000 / 4, 9150 / 4, 9300 / 4, 10400 / 4, 10500 / 4, 10700 / 4, 10850 / 4, 11000 / 4,
	};
	Vec2f note_size = Vec2f(15.5f, 6.25f);

	float get_note_pos_x[NOTE_MAX];
	float get_note_pos_y[NOTE_MAX];
	for (int i = 0; i < NOTE_MAX; ++i)
	{
		get_note_pos_x[i] = 0;
		get_note_pos_y[i] = 0;
	}

	bool is_judge[NOTE_MAX];
	for (int i = 0; i < NOTE_MAX; ++i)
	{
		is_judge[i] = false;
	}


	float deltatime = 0.0f;
	float deltaTime_content = 0.15f;

	sio_song.play();
	sio_song.gain(0.3f);
	
  while (CApp::get().isOpen()) {
   
    CApp::get().begin();

	deltatime = get_deltatime.Get();


	//試し用コンボ表示
	std::string COMBO = std::to_string(now_combo);
	font.draw(COMBO, Vec2f(0, 100), Color::blue);


	//試し用スコア表示
	std::string SCORE = std::to_string(now_score);
	font.draw(SCORE, Vec2f(-50, 100), Color::white);


	for (int i = 0; i < PLAYER_ICON_NUMBER; ++i)
	{
		//PLAYERのICON位置
		drawFillCircle(player_pos_x[i], player_pos_y, player_size.x(), player_size.y(),
			PARTITION_FUNCTION_OF_CIRCLE, Color::red);
	}

	for (int i = 0; i < NOTE_MAX; ++i)
	{
		Note[i].Init(note_x[i], note_y[i], note_size); // 一回のみ初期化
		Note[i].Draw(); // 描画処理
		Note[i].Move(deltatime * deltaTime_content);  // 移動処理　
	}

	//ノートから逆に座標をもらい、
	//判定するための変数にいれる。
	for (int i = 0; i < NOTE_MAX; ++i)
	{
		get_note_pos_x[i] = Note[i].Get_note_pos_x();
		get_note_pos_y[i] = Note[i].Get_note_pos_y();
	}

	//Aキーを押したなら、判定
	if (CApp::get().isPushKey('A'))
	{
		hit_se.play();
		hit_se.gain(2);

		for (int i = 0; i < NOTE_MAX; ++i)
		{ // 範囲内かつ、判定用フラグがfalseなら
			if (!is_judge[i] && judge[i].Judgging(get_note_pos_y[i]) != JUDGEMENT_TYPE::NONE) 
			{
				judge[i].Set_draw_active(true);
				is_judge[i] = true;//判定用のフラグをtrueにする
				break;
			}
		}
	}

	if (gamepad_num > 0) 
	{
		// 0番目のGamePadを取得
		const GamePad& pad = CApp::get().gamePad(0);

		// GamePadのボタン数
		int button_num = pad.buttons();

		    if (pad.isPushButton(15))
		    {
				hit_se.play();
				hit_se.gain(2);
				for (int i = 0; i < NOTE_MAX; ++i)
				{ // 範囲内かつ、判定用フラグがfalseなら
					if (!is_judge[i] && Is_Inside(get_note_pos_y[i], ICON_CHECKLINE_MAX, ICON_CHECKLINE_MIN) 
						             && Is_Inside(get_note_pos_x[i], -240, -260))
					{
						is_judge[i] = true;//判定用のフラグをtrueにする
						break;
					}
				}
		    }

			if ( pad.isPushButton(12))
			{
				hit_se.play();
				hit_se.gain(2);
				for (int i = 0; i < NOTE_MAX; ++i)
				{ // 範囲内かつ、判定用フラグがfalseなら
					if (!is_judge[i] && Is_Inside(get_note_pos_y[i], ICON_CHECKLINE_MAX, ICON_CHECKLINE_MIN)
						             && Is_Inside(get_note_pos_x[i], -140, -160))
					{
						is_judge[i] = true;//判定用のフラグをtrueにする
						break;
					}
				}
			}
			if ( pad.isPushButton(13))
			{
				hit_se.play();
				hit_se.gain(2);
				for (int i = 0; i < NOTE_MAX; ++i)
				{ // 範囲内かつ、判定用フラグがfalseなら
					if (!is_judge[i] && Is_Inside(get_note_pos_y[i], ICON_CHECKLINE_MAX, ICON_CHECKLINE_MIN)
						             && Is_Inside(get_note_pos_x[i], -40, -60))
					{
						is_judge[i] = true;//判定用のフラグをtrueにする
						break;
					}
				}
			}
			if ( pad.isPushButton(0))
			{
				hit_se.play();
				hit_se.gain(2);
				for (int i = 0; i < NOTE_MAX; ++i)
				{ // 範囲内かつ、判定用フラグがfalseなら
					if (!is_judge[i] && Is_Inside(get_note_pos_y[i], ICON_CHECKLINE_MAX, ICON_CHECKLINE_MIN)
						             && Is_Inside(get_note_pos_x[i], 60, 40))
					{
						is_judge[i] = true;//判定用のフラグをtrueにする
						break;
					}
				}
			}
			if ( pad.isPushButton(3))
			{
				hit_se.play();
				hit_se.gain(2);
				for (int i = 0; i < NOTE_MAX; ++i)
				{ // 範囲内かつ、判定用フラグがfalseなら
					if (!is_judge[i] && Is_Inside(get_note_pos_y[i], ICON_CHECKLINE_MAX, ICON_CHECKLINE_MIN)
						             && Is_Inside(get_note_pos_x[i], 160, 140))
					{
						is_judge[i] = true;//判定用のフラグをtrueにする
						break;
					}
				}
			}
			if ( pad.isPushButton(2))
			{
				hit_se.play();
				hit_se.gain(2);
				for (int i = 0; i < NOTE_MAX; ++i)
				{ // 範囲内かつ、判定用フラグがfalseなら
					if (!is_judge[i] && Is_Inside(get_note_pos_y[i], ICON_CHECKLINE_MAX, ICON_CHECKLINE_MIN)
						             && Is_Inside(get_note_pos_x[i], 260, 240))
					{
						is_judge[i] = true;//判定用のフラグをtrueにする
						break;
					}
				}
			}
	}


	for (int i = 0; i < NOTE_MAX; ++i)
	{

		//判定用フラグが入っているなら判定処理
		//下の処理をクラス内にいれるかどうか。
		if (is_judge[i] == true)
		{

			Note[i].Is_dead();
			judge[i].Judgging(get_note_pos_y[i]);
			judge[i].Draw();
			now_combo = judge[i].Get_Combo(now_combo);
		    now_score = judge[i].Get_Score(now_score);
		
		}
		//ミスしたまま指定した範囲をすぎたら、コンボを０にする。
		if (is_judge[i] == false && get_note_pos_y[i] < ICON_DEADLINE)
		{

			now_combo = judge[i].Reset_Combo();
		
		}

	}



    
    CApp::get().end();
  }
}
