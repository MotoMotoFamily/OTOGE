#include "C_Player.h"

void Cplayer::Draw()
{
	int player_pos_x[PLAYER_ICON_NUMBER] = { -250, -150, -50, 50, 150, 250 };

	for (int i = 0; i < PLAYER_ICON_NUMBER; ++i)
	{
		//PLAYER��ICON�ʒu
		drawFillCircle(player_pos_x[i], PLAYER_Y, player_size.x(), player_size.y(),
			PARTITION_FUNCTION_OF_CIRCLE, Color::red);
	}
}


// ���ƂŃX�e�[�^�X�Ȃǂ̕ω��v�f�����킦�܂��B
void Cplayer::Update()
{




}