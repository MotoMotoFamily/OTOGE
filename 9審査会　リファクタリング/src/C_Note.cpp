#include "C_Note.h"


	bool Cnote::Init(float _x, float _y, Vec2f _size) // 初期化
	{
		if (note.is_init)return false;
		note.pos_x = _x;
		note.pos_y = _y;
		note.size = _size;
		note.is_init = true;
		return true;
	};
	void Cnote::Draw()// 描画処理
	{
		if (note.is_active)
			drawFillCircle(note.pos_x, note.pos_y, note.size.x(), note.size.y(), 30, Color::red);
	}
	bool Cnote::Is_active()//ミス判定用
	{
		return note.is_active;
	}

	void Cnote::Is_dead()// hit後の描画処理終了用
	{
		note.is_active = false;
	}

	void Cnote::Move(float _speed)// 移動処理
	{
		if (note.is_active)
			note.pos_y -= _speed;
	}

	//ノートの座標をほかの関数に渡す
	float Cnote::Get_note_pos_y()
	{
		return note.pos_y;
	}

