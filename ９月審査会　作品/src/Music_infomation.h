#pragma once
#include <iostream>

enum MUSIC
{
	BACK_TITLE,
	SIO,
	ROCK

};

struct MUSIC_INFO
{
	MUSIC music;
	std::string note_txt;
	std::string longnote_txt;
	std::string music_wav;

};



