#pragma once
#include "lib/framework.hpp"

#define PLAYER_Y (-200)
#define PLAYER_ICON_NUMBER (6)
#define PARTITION_FUNCTION_OF_CIRCLE  (30)



//�̂��Ƀv���C���[��HP�Ȃǂ̗v�f�@�{�@�A�j���[�V�����`�������܂�
class Cplayer
{
public:
	Cplayer() :
		player_size(30, 7.5f)
	{


	}

	//�`�揈��
	void Draw();
	//����������
	void Update();





private:

	Vec2f player_size;




};