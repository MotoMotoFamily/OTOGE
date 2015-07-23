#pragma once
#include "lib/framework.hpp"
#include "Inside.h"
#include "C_App.h"

#define PARTITION_FUNCTION_OF_CIRCLE  (30)
#define EXCELENT_DISTANCE_MAX (-185)  
#define EXCELENT_DISTANCE_MIN (-215)
#define GOOD_DISTANCE_NUM1_MAX (-165)
#define GOOD_DISTANCE_NUM1_MIN (-185)
#define GOOD_DISTANCE_NUM2_MAX (-215)
#define GOOD_DISTANCE_NUM2_MIN (-235)
#define EXCELENT_RANGE (15)
#define GOOD_RANGE (20)
#define OUT_RANGE (50)
#define PLAYER_WIDTH (20)
#define TEXTURE_SIZE (100)
#define DRAW_POSITION (-50)
#define PLAYER_Y (-200)


enum JUDGEMENT_TYPE  // ジャスト判定
{
	NONE = -1,
	BAD,
	GOOD,
	EXCELENT,
	GUARD
};



class Cjudge
{   // 判定用クラス

public:
	Cjudge() :
		draw_pos(DRAW_POSITION,DRAW_POSITION),
		draw_size(TEXTURE_SIZE,TEXTURE_SIZE),
		draw_flame_count(10),
		combo(0),
		combo_plus(1),
		combo_reset(0),
		judge_num(JUDGEMENT_TYPE::NONE),
		draw_time(0),
		combo_cut_pos_y(0),
		plus_score_point(10),
		is_plus_score(false),
		is_combo(false),
		is_draw_active(false),
		is_active(true)
		
	{


	};

	bool Get_is_active(){ return is_active; }
	void Set_is_active(bool _is_active){ is_active = _is_active; }
	bool Get_draw_active(){ return is_draw_active; }
	void Set_draw_active(bool _draw_active){ is_draw_active = _draw_active; }
	void Draw();  //判定してから描画
	JUDGEMENT_TYPE Judgging(float _icon_pos_y);  //Insideがtrueのときさらに判定
	int Get_Score(int _score);  // score判定
	int Get_Combo(int _combo);  // コンボ判定
	int Reset_Combo();  // missしたときにcomboを０にする
	static float Get_distance(float _obj_a_y, float _obj_b_y);// ２点間の絶対値を返す。


	// 0番目のGamePadを取得
	static const GamePad& pad;

private:
	Vec2f draw_pos;
	Vec2f draw_size;
	int draw_flame_count;
	int combo;
	int combo_plus;
	int draw_time;
	JUDGEMENT_TYPE judge_num;
	int combo_cut_pos_y;
	int plus_score_point;
	int combo_reset;
	bool is_active;
	bool is_plus_score;
	bool is_combo;
	bool is_draw_active;
};


