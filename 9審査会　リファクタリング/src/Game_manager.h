#pragma once

#include "C_Note.h"
#include "C_Judge.h"
#include "Inside.h"
#include "C_Deltatime.h"

#define NOTE_MAX  (29)
#define NOTE_CHECKLINE_MAX (-150)
#define NOTE_CHECKLINE_MIN (-250)
#define NOTE_DEADLINE (-300)
#define PLAYER_Y (-200)

class Game_manager
{
public:
	Game_manager()
	{
		Note_initialize();
		deltaTime_content = 0.15f;
	}

	//ノートなどの初期化
	void Note_initialize();

	//update用関数
	void Update();

	//draw用関数
	void Draw();

	//パッドのボタン入力を読み込み後、
	//ポジションにより判断する。
	void Judge_by_joypad(int _button_num, float _x);


	//判定用フラグが入っているなら判定処理
	//下の処理をクラス内にいれるかどうか。
	void Add_judge_effect(int _now_combo, int _now_score);


	//ノートが範囲外に行ったときに
	//コンボを０にする。//のちにPLAYER_HPにからめる。
	void Judge_of_deadline(int _now_combo);


private:
	Cnote note[NOTE_MAX];
	Cjudge judge[NOTE_MAX];

	Deltatime deltatime_geter;	//デルタタイムをもらう
	float deltaTime_content;
	struct note_position{
		float x;
		float y;
	};
	
	Vec2f note_size = Vec2f(15.5f, 6.25f);

	

};