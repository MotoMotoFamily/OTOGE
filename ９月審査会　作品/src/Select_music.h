#pragma once
#include <iostream>
#include "lib/framework.hpp"
#include "Music_infomation.h"
#include "C_Judge.h"



class Cselect_music
{
public:

	Cselect_music() :
		select_num(0),
		select_move_pos_y(0),
		is_select(false)
	{

	}


	//�p�b�h�ɂ��ړ�����
	void Update();

	//�Z���N�g��ʂ̕`��
	//��ʂɕ\�����Ă���I�����ɂ��A�Q�[���}�l�[�W���[�ɓn���������߂�
	void Draw();

	//�Q�[���}�l�[�W���[�ɓn�������L��
	void Set_music_info(MUSIC_INFO _info);

	//�I�񂾂��ǂ���
	bool Get_to_select_music()
	{
		return is_select;
	}


	//�Q�[���}�l�[�W���[�ɏ���n��
	MUSIC_INFO Get_music_info();

private:

 MUSIC_INFO select_music_info;
 int select_num;
 int select_move_pos_y;
 bool is_select;



};