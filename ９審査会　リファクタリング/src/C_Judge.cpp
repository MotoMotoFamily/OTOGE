#include "C_Judge.h"


	void Cjudge::Draw()  //判定してから書く
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

	}

	void Cjudge::Check_draw_judge(float _icon_pos_y)  //Insideがtrueのときさらに判定
	{

		if (Is_Inside(_icon_pos_y, EXCELENT_DISTANCE_MAX, EXCELENT_DISTANCE_MIN))
		{
			judge_num = JUDGEMENT_TYPE::EXCELENT;
		}
		else if (Is_Inside(_icon_pos_y, GOOD_DISTANCE_NUM1_MAX, GOOD_DISTANCE_NUM1_MIN)
			|| Is_Inside(_icon_pos_y, GOOD_DISTANCE_NUM2_MAX, GOOD_DISTANCE_NUM2_MIN))
		{
			judge_num = JUDGEMENT_TYPE::GOOD;
		}
		else judge_num = JUDGEMENT_TYPE::BAD;
		is_draw_active = true;
	}
	int Cjudge::Get_Score(int _score)  // score判定
	{
		if (is_plus_score == false)
		{
			_score = _score + (combo * plus_score_point + plus_score_point);
			is_plus_score = true;
		}
		return _score;
	}
	int Cjudge::Get_Combo(int _combo)  // コンボ判定
	{
		if (is_combo == false)
		{
			combo = _combo + combo_plus;
			is_combo = true;
		}
		return combo;
	}

	int Cjudge::Reset_Combo()  // missしたときにcomboを０にする
	{
		return combo_reset;
	}