#include "C_Longnote.h"

bool Clongnote::Init(float _start_x, float _start_y, float _end_x, float _end_y, Vec2f _size) // 初期化
{
	if (longnote.is_init)return false;
	longnote.start_pos = Vec2f(_start_x,_start_y);
	longnote.end_pos = Vec2f(_end_x,_end_y);
	longnote.size = _size;
	longnote.is_init = true;
	return true;
};
void Clongnote::Draw()// 描画処理
{
	if (longnote.is_active)
	{


		if (longnote.start_pos.x() < NOTE_DRAW_START_LINE)
		{
			//pullされたかどうか
			//true... 表示しない  false...表示
			if (!longnote.is_pull)
			{
				drawFillCircle(longnote.end_pos.x(), longnote.end_pos.y(), longnote.size.x(), longnote.size.y(), 30, Color::red);
				drawFillBox(longnote.start_pos.x() - longnote.size.x() , longnote.start_pos.y(), longnote.size.x() * 2, (longnote.end_pos.y() - longnote.start_pos.y()), Color::blue);
			}
			//pushされたかどうか
			//true... 表示しない　false...表示
			if (!longnote.is_push)
			{
				drawFillCircle(longnote.start_pos.x(), longnote.start_pos.y(), longnote.size.x(), longnote.size.y(), 30, Color::red);
			}
		}


	}

}
bool Clongnote::Is_active()//ミス判定用
{
	return longnote.is_active;
}

void Clongnote::Kill()// hit後の描画処理終了用
{
	longnote.is_active = false;
}

void Clongnote::Move(float _speed)// 移動処理
{
	if (!longnote.is_push)
	{
		longnote.start_pos.y() -= _speed;
	}

	if (longnote.is_active)
	{
		longnote.end_pos.y() -= _speed;
	}
}

//ノートのstart座標をほかの関数に渡す
float Clongnote::Get_note_start_pos_x()const
{
	return longnote.start_pos.x();
}

//ノートのstart座標をほかの関数に渡す
float Clongnote::Get_note_start_pos_y()const
{
	return longnote.start_pos.y();
}

//ノートのend座標をほかの関数に渡す
float Clongnote::Get_note_end_pos_x()const
{
	return longnote.end_pos.x();
}

//ノートのend座標をほかの関数に渡す
float Clongnote::Get_note_end_pos_y()const
{
	return longnote.end_pos.y();
}