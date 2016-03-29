#include "StdAfx.h"
#include "SceneManager.h"
#include "Actor.h"
#include <fstream>
#include "TileClipsData.h"
#include "Camera.h"

SceneManager::SceneManager() : m_DefaultBornPoint(LEVEL_WIDTH/2,LEVEL_HEIGHT/2)
{
	m_nCurrentSceneID = 0;
	memset(m_TileSet,0, sizeof(Tile*) * TOTAL_TILES);
}

SceneManager::~SceneManager()
{
	for(int i = 0; i< TOTAL_TILES; i++)
	{
		SAFE_DELETE(m_TileSet[i]);
	}
}

void SceneManager::Tick(int nFrameTime)
{
}

void SceneManager::LoadScene(int SceneID)
{
	m_nCurrentSceneID = SceneID;

	if(!LoadSceneData("TestScene.map"))
	{
		printf( "Failed to load Scene!\n" );
	}
}

bool SceneManager::LoadSceneData(std::string szSceneName)
{
	int x = 0, y = 0;
	//Open the map
	std::ifstream map( szSceneName.c_str() );
	if(!map)
	{
		map.close();
		return false;
	}
	//Initialize the tiles
	for( int i = 0; i < TOTAL_TILES; ++i )
	{
		//Determines what kind of tile will be made
		int nTileType = -1;
		//Read tile from map file
		map >> nTileType;
		//If the was a problem in reading the map
		if( map.fail() )
		{
			map.close();
			return false;
		}
		if( ( nTileType >= 0 ) && ( nTileType < TILE_SIZE ) )
		{
			m_TileSet[ i ] = new Tile( x, y, nTileType );
		}
		//Move to next tile spot
		x += TILE_WIDTH;
		//If we've gone too far
		if( x >= LEVEL_WIDTH )
		{
			//Move back
			x = 0;
			//Move to the next row
			y += TILE_HEIGHT;
		}
	}

	map.close();
	return true;
}

void SceneManager::RenderScene(SDL_Rect& rectView)
{
	for( int i = 0; i < TOTAL_TILES; ++i )
	{
		m_TileSet[ i ]->render( rectView );
	}
}

void SceneManager::EnterScene(Actor* pActor)
{
	if(!pActor)
	{
		return;
	}
	pActor->SetScene(m_nCurrentSceneID);
	pActor->SetDir(Vector2D(0,0));
	pActor->SetPos(m_DefaultBornPoint);
	pActor->SetSpeed(VOLECITY_RUN);


	Camera::Instance().SetLinkEntity(pActor->GetGuid());
}