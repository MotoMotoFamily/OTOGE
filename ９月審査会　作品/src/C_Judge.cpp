#include "C_Judge.h"


const GamePad& Cjudge::pad = CApp::get().gamePad(0);






void Cjudge::Draw()  //���肵�Ă��珑��
{
    if (is_draw_active == true && draw_time < draw_flame_count)
	{
		++draw_time;
		if (judge_num == JUDGEMENT_TYPE::EXCELENT)
			drawFillBox(draw_pos.x(), draw_pos.y(), draw_size.x(), draw_size.y(), Color::blue);
		if (judge_num == JUDGEMENT_TYPE::GOOD)
			drawFillBox(draw_pos.x(), draw_pos.y(), draw_size.x(), draw_size.y(), Color::red);
		if (judge_num == JUDGEMENT_TYPE::BAD)
			drawFillBox(draw_pos.x(), draw_pos.y(), draw_size.x(), draw_size.y(), Color::yellow);
	}
	if (draw_time >= draw_flame_count)
	{
		is_draw_active = false;
		is_combo = false;
		is_plus_score = false;
		

	}
}

JUDGEMENT_TYPE Cjudge::Judgging(float _note_pos_y)  //Inside��true�̂Ƃ�����ɔ���
{
	struct RESULT_TABLE
	{
		float distance;
		JUDGEMENT_TYPE type;

	};

	const RESULT_TABLE table[] = {
		{ OUT_RANGE , JUDGEMENT_TYPE::BAD   },
		{ GOOD_RANGE , JUDGEMENT_TYPE::GOOD     },
		{ EXCELENT_RANGE, JUDGEMENT_TYPE::EXCELENT }

	};

	auto distance = Get_distance(PLAYER_Y,_note_pos_y);

	if (distance > OUT_RANGE)
	{
		return judge_num = JUDGEMENT_TYPE::NONE;
	}


	for (int i = 0; i < JUDGEMENT_TYPE::GUARD; ++i)
	{
		if (distance < table[i].distance)
		{
			judge_num = table[i].type;
			is_draw_active = true;
		}
		else 
		{
			break;
		}
	}
	
	return judge_num;
	
}

//�ۑ�
//Judge�̔��育�ƂɃX�R�A�㏸����ς���B

int Cjudge::Get_Score(int _score , JUDGEMENT_TYPE _judge)  // score����
{
	if (is_plus_score == false)
	{
		_score = _score + (combo * plus_score_point + plus_score_point + combo * _judge * plus_score_point / 2);
		is_plus_score = true;
	}
	
	return _score;
}
int Cjudge::Get_Combo(int _combo)  // �R���{����
{
	if (is_combo == false)
	{
		combo = _combo + combo_plus;
		is_combo = true;
		
	}
	
	return combo;
}

int Cjudge::Reset_Combo()  // miss�����Ƃ���combo���O�ɂ���
{
	return combo_reset;
}


float Cjudge::Get_distance(float _obj_a_y, float _obj_b_y) // �Q�_�Ԃ̐�Βl��Ԃ��B
{
	return abs(_obj_a_y - _obj_b_y);

}