#ifndef __BulletManager_h_
#define __BulletManager_h_

#include "Bullet.h"
#include "Ogre.h"

#define MAX_NUM_BULLET 2560

class BulletManager
{

private:

	BULLET *mBulletArr[ MAX_NUM_BULLET ] ;
	MonsterManager* mMonsterMgr;
	Ogre::SceneManager* mSceneMgr;

	bool deleteBullet( int id );
public:

	BulletManager(Ogre::SceneManager* a_SceneMgr,MonsterManager* a_MonsterMgr);
	bool create(String mesh_name,Vector3 pos,int target_id);
	void update(const Ogre::FrameEvent& evt);
	
};

#endif