#pragma once
#include "lib/framework.hpp"
#include "Inside.h"
#include "C_App.h"

//ノートを描画し始める範囲 (のちの処理落ち対策用)
# define NOTE_DRAW_START_LINE  (400) 

class Clongnote
{
public:
	Clongnote()
	{
		longnote.is_init = false;
		longnote.is_active = true;
		longnote.is_push = false;
		longnote.is_press = false;
		longnote.is_pull = false;

	};

	bool Init(float _start_x, float _start_y, float _end_x, float _end_y, Vec2f _size);

	void Draw();
	bool Is_active();

	void Kill();

	void Move(float _speed);

	float Get_note_start_pos_x()const;
	float Get_note_start_pos_y()const;

	float Get_note_end_pos_x()const;
	float Get_note_end_pos_y()const;

	bool Get_is_active(){ return longnote.is_active; }
	void Set_is_active(bool _is_active){ longnote.is_active = _is_active; }

	bool Get_is_push_active(){ return longnote.is_push; }
	void Set_is_push_active(bool _is_active){ longnote.is_push = _is_active; }

	bool Get_is_press_active(){ return longnote.is_press; }
	void Set_is_press_active(bool _is_active){ longnote.is_press = _is_active; }

	bool Get_is_pull_active(){ return longnote.is_pull; }
	void Set_is_pull_active(bool _is_active){ longnote.is_pull = _is_active; }

private:
	struct LONGNOTE        //　ノートアイコン情報 
	{
		float start_pos_x;
		float start_pos_y;
		float end_pos_x;
		float end_pos_y;
		Vec2f size;
		bool is_active;
		bool is_push;
		bool is_press;
		bool is_pull;
		bool is_init;
	};
	LONGNOTE longnote;



};