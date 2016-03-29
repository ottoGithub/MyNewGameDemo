#ifndef _PHYSICS_FUNCTIONS_H_
#define _PHYSICS_FUNCTIONS_H_
#include "Vector2D.h"



bool CheckCollision_Rect2Rect( SDL_Rect r1, SDL_Rect r2 );

Vector2D GetActorRealPos(Vector2D& vPos);

#endif