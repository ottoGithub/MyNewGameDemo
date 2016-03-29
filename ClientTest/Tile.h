#ifndef _TILE_H_
#define _TILE_H_

//The tile
class Tile
{
public:
	//Initializes position and type
	Tile( int x, int y, int tileType );

	//Shows the tile
	void render( SDL_Rect& camera );

	//Get the tile type
	int getType();

	//Get the collision box
	SDL_Rect getBox();

private:
	//The attributes of the tile
	SDL_Rect mBox;

	//The tile type
	int mType;
};

#endif