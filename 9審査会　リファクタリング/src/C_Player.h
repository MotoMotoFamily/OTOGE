#pragma once
#include "lib/framework.hpp"

#define PLAYER_Y (-200)
#define PLAYER_ICON_NUMBER (6)
#define PARTITION_FUNCTION_OF_CIRCLE  (30)



//のちにプレイヤーにHPなどの要素　＋　アニメーション描画をいれます
class Cplayer
{
public:
	Cplayer() :
		player_size(30, 7.5f)
	{


	}

	//描画処理
	void Draw();
	//初期化処理
	void Update();





private:

	Vec2f player_size;




};