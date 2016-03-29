#ifndef _COMMON_DEF_H_
#define _COMMON_DEF_H_
#include "Vector2D.h"

#define SAFE_DELETE(p) { if(p) { delete p; p = NULL; } }

const float MIN_FLOAT = 0.0001f;

const int VOLECITY_RUN = 96*4;

const int ANIM_PLAY_FRAME_COUNT = 4;


#endif