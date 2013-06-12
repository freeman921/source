#ifndef __TowerManager_h_
#define __TowerManager_h_

#include "Tower.h"

#define MAX_NUM_TOWER 512

class TowerManager
{
private:
	TOWER *mTowerArr[ MAX_NUM_TOWER ];
	MonsterManager* mMonsterMgr;
	Ogre::SceneManager* mSceneMgr;
	BulletManager  *mBulletMgr;
public:
	TowerManager(Ogre::SceneManager* a_SceneMgr,MonsterManager* a_MonsterMgr,BulletManager  *a_BulletMgr);
	~TowerManager();
	bool create(String mesh_name,Vector3 pos, Real r);
	void update(const Ogre::FrameEvent& evt);
};

#endif