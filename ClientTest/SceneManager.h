#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_
#include "Singleton.h"
#include "CommonDef.h"
#include "Tile.h"

const int TOTAL_TILES = 1200;

class Actor;
class SceneManager : public Singleton<SceneManager>
{
public:
	SceneManager();
	~SceneManager();
	void Tick(int nFrameTime);

	void LoadScene(int SceneID);
	bool LoadSceneData(std::string szSceneName);
	void EnterScene(Actor* pActor);
	void RenderScene(SDL_Rect& rectView);
private:
	int m_nCurrentSceneID;
	Vector2D m_DefaultBornPoint;

	Tile* m_TileSet[TOTAL_TILES];
};

#endif