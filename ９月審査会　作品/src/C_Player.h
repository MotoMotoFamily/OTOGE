#pragma once
#include "lib/framework.hpp"

#define PLAYER_Y (-200)
#define PLAYER_ICON_NUMBER (6)
#define PARTITION_FUNCTION_OF_CIRCLE  (30)
#define PLAYER_MAX_HP (200)
#define START_PLAYER_HP (80)
#define RECOVERY_HP (5)
#define DIVIDE_HP (20)

//�̂��Ƀv���C���[��HP�Ȃǂ̗v�f�@�{�@�A�j���[�V�����`�������܂�
class Cplayer
{
public:
	Cplayer():
		player_size(30,7.5f),
		player_hp(START_PLAYER_HP)
	{


	}
	
	//�`�揈��
	void Draw();
	void Draw_player_hp();
	
	//����������
	void Update();
	
	//Miss�����Ƃ���player_hp�����炷�B
	void Divide_player_hp();

	//�ǂ�������o���x��hp����
	void Recovery_player_hp();
	
	//player�������Ă��邩�ǂ���
	bool Is_player_active();


private:

	int player_hp;
	Vec2f player_size;




};