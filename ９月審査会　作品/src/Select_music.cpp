#include "Select_music.h"

void Cselect_music::Draw()
{
	
     //‰¼’u‚«‘I‘ğˆ‚ÌF
	Color color[3] = { Color::blue, Color::red, Color::green };
	
	for (int i = 0; i < 3; ++i)
	{
		drawFillBox(0, select_move_pos_y - 100 * i, 300, 50, color[i]);
	}
	
	drawFillBox(-200, 0, 50, 50, Color::white);
}

void Cselect_music::Update()
{
	MUSIC_INFO music_info[] =
	{
		{ SIO, "res/sio_song.txt", "res/sio_song.txt", "res/SIO.wav" },
		{ ROCK, "res/rock_song.txt", "res/rock_song", "res/rock.wav" }

	};
	if (Cjudge::pad.isPushButton(14))
	{
		if (select_num >= 2) return;
		select_num += 1;
		select_move_pos_y += 100;
	}

	if (Cjudge::pad.isPushButton(12))
	{
		if (select_num <= 0) return;
		select_num -= 1;
		select_move_pos_y -= 100;
	}

	if (Cjudge::pad.isPushButton(0))
	{

		switch (select_num)
		{
		case MUSIC::BACK_TITLE:
		  
			//title‚É–ß‚éˆ—
			
			break;
		case MUSIC::SIO:
			Cselect_music::Set_music_info(music_info[0]);
			is_select = true;
			break;
		case MUSIC::ROCK:
			Cselect_music::Set_music_info(music_info[1]);
			is_select = true;
			break;
	
		default:
			break;
		}


	}



	
}

void Cselect_music::Set_music_info(MUSIC_INFO _info)
{
	select_music_info = _info;
}

MUSIC_INFO Cselect_music::Get_music_info()
{
	return select_music_info;
}

