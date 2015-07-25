#pragma once

#include "lib/framework.hpp"
#include "C_Note.h"
#include "C_Longnote.h"
#include "C_Judge.h"
#include "Inside.h"
#include "C_Deltatime.h"
#include "C_Player.h"

#define NOTE_MAX  (256)
#define NOTE_CHECKLINE_MAX (-150)
#define NOTE_CHECKLINE_MIN (-250)
#define NOTE_DEADLINE (-230)
#define PLAYER_Y (-200)

class Game_manager
{
public:
	Game_manager() :
		now_score(0),
		now_combo(0)
	{
		
		Note_initialize();
		deltaTime_content = 0.15f;
	}

	//�m�[�g�Ȃǂ̏�����
	void Note_initialize();

	//update�p�֐�
	void Update();

	//draw�p�֐�
	void Draw();

	//�p�b�h�̃{�^�����͂�ǂݍ��݌�A
	//�|�W�V�����ɂ�蔻�f����B
	void Judge_by_joypad(int _button_num, float _x );


	//����p�t���O�������Ă���Ȃ画�菈��
	//���̏������N���X���ɂ���邩�ǂ����B
	void Add_judge_effect();


	//�m�[�g���͈͊O�ɍs�����Ƃ���
	//�R���{���O�ɂ���B//�̂���PLAYER_HP�ɂ���߂�B
	void Judge_of_deadline();


private:
	Cplayer player;
	Cnote note[NOTE_MAX];
	Cjudge judge[NOTE_MAX];
	Clongnote longnote;
	Cjudge longjudge;

	Deltatime deltatime;	//�f���^�^�C�������炤
	float deltaTime_content;
	struct note_position{
		float x;
		float y;
	};

	struct File_read
	{
		float pos_x;
		float pos_y;
		char str[5];
		bool isReadingPositionX = false;
		bool isReadingPositionY = false;
	};

	int now_score;
	int now_combo;
	
	Vec2f note_size = Vec2f(15.5f, 6.25f);
	
	

};