#include "C_Longnote.h"

bool Clongnote::Init(float _start_x, float _start_y, float _end_x, float _end_y, Vec2f _size) // ������
{
	if (longnote.is_init)return false;
	longnote.start_pos = Vec2f(_start_x,_start_y);
	longnote.end_pos = Vec2f(_end_x,_end_y);
	longnote.size = _size;
	longnote.is_init = true;
	return true;
};
void Clongnote::Draw()// �`�揈��
{
	if (longnote.is_active)
	{


		if (longnote.start_pos.x() < NOTE_DRAW_START_LINE)
		{
			//pull���ꂽ���ǂ���
			//true... �\�����Ȃ�  false...�\��
			if (!longnote.is_pull)
			{
				drawFillCircle(longnote.end_pos.x(), longnote.end_pos.y(), longnote.size.x(), longnote.size.y(), 30, Color::red);
				drawFillBox(longnote.start_pos.x() - longnote.size.x() , longnote.start_pos.y(), longnote.size.x() * 2, (longnote.end_pos.y() - longnote.start_pos.y()), Color::blue);
			}
			//push���ꂽ���ǂ���
			//true... �\�����Ȃ��@false...�\��
			if (!longnote.is_push)
			{
				drawFillCircle(longnote.start_pos.x(), longnote.start_pos.y(), longnote.size.x(), longnote.size.y(), 30, Color::red);
			}
		}


	}

}
bool Clongnote::Is_active()//�~�X����p
{
	return longnote.is_active;
}

void Clongnote::Kill()// hit��̕`�揈���I���p
{
	longnote.is_active = false;
}

void Clongnote::Move(float _speed)// �ړ�����
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

//�m�[�g��start���W���ق��̊֐��ɓn��
float Clongnote::Get_note_start_pos_x()const
{
	return longnote.start_pos.x();
}

//�m�[�g��start���W���ق��̊֐��ɓn��
float Clongnote::Get_note_start_pos_y()const
{
	return longnote.start_pos.y();
}

//�m�[�g��end���W���ق��̊֐��ɓn��
float Clongnote::Get_note_end_pos_x()const
{
	return longnote.end_pos.x();
}

//�m�[�g��end���W���ق��̊֐��ɓn��
float Clongnote::Get_note_end_pos_y()const
{
	return longnote.end_pos.y();
}