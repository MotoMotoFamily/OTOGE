#include "Inside.h"

// ��P�����̍��W�����Q�����Ƒ�R�����̋����𑪂�A���͈͓̔��Ȃ�true��Ԃ��B
bool Get_Inside(float _pos1, float dis_max, float dis_min)
{
	if (_pos1 > dis_min && _pos1 < dis_max) return true;

	return false;
}