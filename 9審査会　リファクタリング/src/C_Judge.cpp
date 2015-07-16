#include "C_Judge.h"


	void Cjudge::draw()  //���肵�Ă��珑��
	{
		if (is_draw_active == true && draw_time < draw_flame_count)
		{
			++draw_time;
			if (judge_num == JUDGE::EXCELENT)
				drawFillBox(draw_pos.x(), draw_pos.y(), draw_size.x(), draw_size.y(), Color::blue);
			if (judge_num == JUDGE::GOOD)
				drawFillBox(draw_pos.x(), draw_pos.y(), draw_size.x(), draw_size.y(), Color::red);
			if (judge_num == JUDGE::BAD)
				drawFillBox(draw_pos.x(), draw_pos.y(), draw_size.x(), draw_size.y(), Color::yellow);
		}

	}

	void Cjudge::check_draw_judge(float _icon_pos_y)  //Inside��true�̂Ƃ�����ɔ���
	{

		if (Get_Inside(_icon_pos_y, EXCELENT_DISTANCE_MAX, EXCELENT_DISTANCE_MIN))
		{
			judge_num = JUDGE::EXCELENT;
		}
		else if (Get_Inside(_icon_pos_y, GOOD_DISTANCE_NUM1_MAX, GOOD_DISTANCE_NUM1_MIN)
			|| Get_Inside(_icon_pos_y, GOOD_DISTANCE_NUM2_MAX, GOOD_DISTANCE_NUM2_MIN))
		{
			judge_num = JUDGE::GOOD;
		}
		else judge_num = JUDGE::BAD;
		is_draw_active = true;
	}
	int Cjudge::Get_Score(int _score)  // score����
	{
		if (is_plus_score == false)
		{
			_score = _score + (combo * plus_score_point + plus_score_point);
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