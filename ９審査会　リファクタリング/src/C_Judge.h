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
		judge_num(0),
		draw_time(0),
		combo_cut_pos_y(0),
		plus_score_point(10),
		is_plus_score(false),
		is_combo(false),
		is_draw_active(false)
	{

	};


	void Draw();  //���肵�Ă���`��
	void Check_draw_judge(float _icon_pos_y);  //Inside��true�̂Ƃ�����ɔ���
	int Get_Score(int _score);  // score����
	int Get_Combo(int _combo);  // �R���{����

	int Reset_Combo();  // miss�����Ƃ���combo���O�ɂ���

private:
	enum JUDGEMENT_TYPE  // �W���X�g����
	{
		BAD,
		GOOD,
		EXCELENT
	};
	Vec2f draw_pos;
	Vec2f draw_size;
	int draw_flame_count;
	int combo;
	int combo_plus;
	int draw_time;
	int judge_num;
	int combo_cut_pos_y;
	int plus_score_point;
	int combo_reset;
	bool is_plus_score;
	bool is_combo;
	bool is_draw_active;
};


