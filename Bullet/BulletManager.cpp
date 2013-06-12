
#include "BulletManager.h"



BulletManager::BulletManager(Ogre::SceneManager* a_SceneMgr,MonsterManager* a_MonsterMgr)
{
	this->mSceneMgr = a_SceneMgr;
	this->mMonsterMgr = a_MonsterMgr;

	for(int i=0;i<MAX_NUM_BULLET;i++)
	{
		mBulletArr[i] = NULL;
	}

}
bool BulletManager::create(String mesh_name,Vector3 pos,int target_id)
{

	bool sucess =false;
	
	for(int i=0;i<MAX_NUM_BULLET;i++)
	{
		if ( mBulletArr[i] != NULL ) continue;

		mBulletArr[i] = new BULLET(mSceneMgr,mMonsterMgr,target_id,200,10);
		mBulletArr[i]->setPosition( pos );
		mBulletArr[i]->setMesh("b",mesh_name);
		mBulletArr[i]->scale(0.2,0.2,0.2);
		sucess=true;
		break;
	}

	return sucess;
}
void BulletManager::update(const Ogre::FrameEvent& evt)
{

	for(int i=0;i<MAX_NUM_BULLET;i++)
	{

		if( mBulletArr[i] == NULL ) continue;
		mBulletArr[i]->update(evt);

		int id = mBulletArr[i]->getTargetID();
		if( !mMonsterMgr->isMonsterExist(id) || mBulletArr[i]->isHit() )
		{
			deleteBullet( i );
		}


	}

}


bool BulletManager::deleteBullet( int id )
{
	if( mBulletArr[id] == NULL ) return false;

	delete( mBulletArr[id] );
	mBulletArr[id] = NULL;

	return true;
}