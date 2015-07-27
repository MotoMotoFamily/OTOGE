#include "C_Player.h"

void Cplayer::Draw()
{
	int player_pos_x[PLAYER_ICON_NUMBER] = { -250, -150, -50, 50, 150, 250 };
	
	for (int i = 0; i < PLAYER_ICON_NUMBER; ++i)
	{
		//PLAYER‚ÌICONˆÊ’u
		drawFillCircle(player_pos_x[i], PLAYER_Y, player_size.x(), player_size.y(),
			PARTITION_FUNCTION_OF_CIRCLE, Color::red);
	}

	Cplayer::Draw_player_hp();
}



void Cplayer::Update()
{



}



void Cplayer::Draw_player_hp()
{

	drawBox(-350, -100, 50, 200, 10, Color::white);
	drawFillBox(-350, -100, 50, player_hp, Color::green);

}

void Cplayer::Divide_player_hp()
{
	if (player_hp < DIVIDE_HP)return;

	player_hp -= DIVIDE_HP;

}

void Cplayer::Recovery_player_hp()
{
	if (player_hp >= PLAYER_MAX_HP)return;

	player_hp += RECOVERY_HP;

}

bool Cplayer::Is_player_active()
{
	if (player_hp > 0)return true;
    
	return false;
}