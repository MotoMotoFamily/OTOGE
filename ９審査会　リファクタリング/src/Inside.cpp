#include "Inside.h"

// 第１引数の座標から第２引数と第３引数の距離を測り、その範囲内ならtrueを返す。
bool Is_Inside(float _pos1, float dis_max, float dis_min)
{
	if (_pos1 > dis_min && _pos1 < dis_max) return true;

	return false;
}