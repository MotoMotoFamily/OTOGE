#pragma once
#include "lib/framework.hpp"

class Cnote  // �m�[�g����
{
public:
	Cnote()
	{
		note.is_init = false;
		note.is_active = true;

	};
	    bool Init(float _x, float _y, Vec2f _size);
		void Draw();
		bool Is_active();

		void Is_dead();

		void Move(float _speed);

		float Get_note_pos_y();

private:
	struct NOTE        //�@�m�[�g�A�C�R����� 
	{
		float pos_x;
		float pos_y;
		Vec2f size;
		bool is_active;
		bool is_init;
	};
	NOTE note;
};
