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


	//パッドによる移動処理
	void Update();

	//セレクト画面の描画
	//画面に表示している選択肢により、ゲームマネージャーに渡す情報を決める
	void Draw();

	//ゲームマネージャーに渡す情報を記憶
	void Set_music_info(MUSIC_INFO _info);

	//選んだかどうか
	bool Get_to_select_music()
	{
		return is_select;
	}


	//ゲームマネージャーに情報を渡す
	MUSIC_INFO Get_music_info();

private:

 MUSIC_INFO select_music_info;
 int select_num;
 int select_move_pos_y;
 bool is_select;



};