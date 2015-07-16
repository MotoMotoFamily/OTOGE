#include "C_Note.h"


	bool Cnote::Init(float _x, float _y, Vec2f _size) // ������
	{
		if (note.is_init)return false;
		note.pos_x = _x;
		note.pos_y = _y;
		note.size = _size;
		note.is_init = true;
		return true;
	};
	void Cnote::Draw()// �`�揈��
	{
		if (note.is_active)
			drawFillCircle(note.pos_x, note.pos_y, note.size.x(), note.size.y(), 30, Color::red);
	}
	bool Cnote::Is_active()//�~�X����p
	{
		return note.is_active;
	}

	void Cnote::Is_dead()// hit��̕`�揈���I���p
	{
		note.is_active = false;
	}

	void Cnote::Move(float _speed)// �ړ�����
	{
		if (note.is_active)
			note.pos_y -= _speed;
	}

	//�m�[�g�̍��W���ق��̊֐��ɓn��
	float Cnote::Get_note_pos_y()
	{
		return note.pos_y;
	}

