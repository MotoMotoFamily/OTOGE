#pragma once
#include "lib/framework.hpp"

#define PLAYER_Y (-200)
#define PLAYER_ICON_NUMBER (6)
#define PARTITION_FUNCTION_OF_CIRCLE  (30)
#define PLAYER_MAX_HP (200)
#define START_PLAYER_HP (80)
#define RECOVERY_HP (5)
#define DIVIDE_HP (20)

//のちにプレイヤーにHPなどの要素　＋　アニメーション描画をいれます
class Cplayer
{
public:
	Cplayer():
		player_size(30,7.5f),
		player_hp(START_PLAYER_HP)
	{


	}
	
	//描画処理
	void Draw();
	void Draw_player_hp();
	
	//初期化処理
	void Update();
	
	//Missしたときにplayer_hpを減らす。
	void Divide_player_hp();

	//良い判定を出す度にhpを回復
	void Recovery_player_hp();
	
	//playerが生きているかどうか
	bool Is_player_active();


private:

	int player_hp;
	Vec2f player_size;




};