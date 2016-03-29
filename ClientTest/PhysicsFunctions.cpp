#include "StdAfx.h"
#include "PhysicsFunctions.h"
#include "GlobalValue.h"


bool CheckCollision_Rect2Rect( SDL_Rect r1, SDL_Rect r2 )
{
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = r1.x;
	rightA = r1.x + r1.w;
	topA = r1.y;
	bottomA = r1.y + r1.h;

	//Calculate the sides of rect B
	leftB = r2.x;
	rightB = r2.x + r2.w;
	topB = r2.y;
	bottomB = r2.y + r2.h;

	//If any of the sides from A are outside of B
	if( bottomA <= topB )
	{
		return false;
	}

	if( topA >= bottomB )
	{
		return false;
	}

	if( rightA <= leftB )
	{
		return false;
	}

	if( leftA >= rightB )
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}

Vector2D GetActorRealPos(Vector2D& vPos)
{
	return (vPos + Vector2D(-CHARACTER_W/2, -CHARACTER_H));
}