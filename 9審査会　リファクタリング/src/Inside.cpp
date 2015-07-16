#include "Inside.h"

// ‘æ‚Pˆø”‚ÌÀ•W‚©‚ç‘æ‚Qˆø”‚Æ‘æ‚Rˆø”‚Ì‹——£‚ð‘ª‚èA‚»‚Ì”ÍˆÍ“à‚È‚çtrue‚ð•Ô‚·B
bool Get_Inside(float _pos1, float dis_max, float dis_min)
{
	if (_pos1 > dis_min && _pos1 < dis_max) return true;

	return false;
}