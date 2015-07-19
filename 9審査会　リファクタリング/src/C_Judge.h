#pragma once
#include "lib/framework.hpp"
#include "Inside.h"
#define PARTITION_FUNCTION_OF_CIRCLE  (30)
#define EXCELENT_DISTANCE_MAX (-185)  
#define EXCELENT_DISTANCE_MIN (-215)
#define GOOD_DISTANCE_NUM1_MAX (-165)
#define GOOD_DISTANCE_NUM1_MIN (-185)
#define GOOD_DISTANCE_NUM2_MAX (-215)
#define GOOD_DISTANCE_NUM2_MIN (-235)
#define EXCELENT_RANGE (15)
#define GOOD_RANGE (20)
#define PLAYER_Y (-200)
#define PLAYER_WIDTH (20)


enum JUDGEMENT_TYPE  // �W���X�g����
{
	NONE = -1,
	BAD,
	GOOD,
	EXCELENT,
	GUARD
};






class Cjudge
{   // ����p�N���X

public:
	Cjudge() :
		draw_pos(-50, -50),
		draw_size(100, 100),
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
	void Update();
	void Draw();  //���肵�Ă���`��
	JUDGEMENT_TYPE Judgging(float _icon_pos_y);  //Inside��true�̂Ƃ�����ɔ���
	int Get_Score(int _score);  // score����
	int Get_Combo(int _combo);  // �R���{����
	int Reset_Combo();  // miss�����Ƃ���combo���O�ɂ���
	static float Get_distance(float _obj_a_y, float _obj_b_y);// �Q�_�Ԃ̐�Βl��Ԃ��B


	void Set_draw_active(bool _is_active) 
	{

		is_draw_active = _is_active;

	}

	// 0�Ԗڂ�GamePad���擾
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


