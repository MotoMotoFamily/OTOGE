#pragma once

#include "C_Note.h"
#include "C_Judge.h"
#include "Inside.h"
#include "C_Deltatime.h"

#define NOTE_MAX  (29)
#define NOTE_CHECKLINE_MAX (-150)
#define NOTE_CHECKLINE_MIN (-250)
#define NOTE_DEADLINE (-300)

class Game_manager
{
public:
	Game_manager()
	{
		
		 
		deltaTime_content = 0.15f;
	}

	//�m�[�g�Ȃǂ̏�����
	void Init();

	//update�p�֐�
	void Update();

	//draw�p�֐�
	void draw();

	//�p�b�h�̃{�^�����͂�ǂݍ��݌�A
	//�|�W�V�����ɂ�蔻�f����B
	void Judge_by_joypad(int _button_num, float _x);


	//����p�t���O�������Ă���Ȃ画�菈��
	//���̏������N���X���ɂ���邩�ǂ����B
	void Add_judge_effect(int _now_combo, int _now_score);


	//�m�[�g���͈͊O�ɍs�����Ƃ���
	//�R���{���O�ɂ���B//�̂���PLAYER_HP�ɂ���߂�B
	void Judge_of_deadline(int _now_combo);


private:

	Cnote note[NOTE_MAX]; // �m�[�g���m�[�g���������@�ŏI�I�Ɏ����������Ă��炤
    Cjudge judge[NOTE_MAX]; // �W���b�W���m�[�g��������
	Deltatime get_deltatime;	//�f���^�^�C�������炤
	float deltaTime_content;
	
	Vec2f note_size = Vec2f(15.5f, 6.25f);



};