#include "TowerManager.h"

TowerManager::TowerManager(Ogre::SceneManager* a_SceneMgr,MonsterManager* a_MonsterMgr,BulletManager  *a_BulletMgr)
{
	mSceneMgr = a_SceneMgr;
	mMonsterMgr = a_MonsterMgr;
	mBulletMgr = a_BulletMgr;

	for(int i=0;i<MAX_NUM_TOWER;i++)
	{
		mTowerArr[i] = NULL;
	}

}
TowerManager::~TowerManager()
{
	for(int i=0;i<MAX_NUM_TOWER;i++)
	{
		if( mTowerArr[i] != NULL)delete(mTowerArr[i]);
	}

}
bool TowerManager::create(String mesh_name, Vector3 pos, Real r) //range
{
	bool sucess =false;
	
	for(int i=0;i<MAX_NUM_TOWER;i++)
	{
		if ( mTowerArr[i] != NULL ) continue;

		mTowerArr[i] = new TOWER(mSceneMgr,mMonsterMgr,mBulletMgr);
		mTowerArr[i]->setPosition(pos);
		mTowerArr[i]->setMesh("t",mesh_name);
		mTowerArr[i]->setRange(r);
		
		sucess=true;
		break;
	}

	return sucess;
}
void TowerManager::update(const Ogre::FrameEvent& evt)
{

	for(int i=0;i<MAX_NUM_TOWER;i++)
	{
		if ( mTowerArr[i] == NULL ) continue;

		mTowerArr[i]->update(evt);
	}

}