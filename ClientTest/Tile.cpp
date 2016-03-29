#include "StdAfx.h"
#include "Tile.h"
#include "PhysicsFunctions.h"
#include "TileClipsData.h"


Tile::Tile( int x, int y, int tileType )
{
	//Get the offsets
	mBox.x = x;
	mBox.y = y;

	//Set the collision box
	mBox.w = TILE_WIDTH;
	mBox.h = TILE_HEIGHT;

	//Get the tile type
	mType = tileType;
}

void Tile::render( SDL_Rect& camera )
{
	//If the tile is on screen
	if( CheckCollision_Rect2Rect( camera, mBox ) )
	{
		//if(mType == 18)
		//{
		//	gTileTexture.render( mBox.x - camera.x, mBox.y - camera.y, &gTileData[103].gTileRect );
		//}
		//Show the tile
		gTileTexture.render( mBox.x - camera.x, mBox.y - camera.y, &gTileData[mType].gTileRect );
	}
}

int Tile::getType()
{
	return mType;
}

SDL_Rect Tile::getBox()
{
	return mBox;
}
