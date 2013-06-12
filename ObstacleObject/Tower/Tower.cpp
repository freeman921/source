#include "Tower.h"


TOWER::TOWER(SceneManager *a_SceneMgr,MonsterManager *a_MonsterMgr,BulletManager  *a_BulletMgr) : SelectableObject(a_SceneMgr)
{
	CD = 0;
	MaxCD = 1;
	Range=500;
	TargetID=-1;
	mMonsterMgr=a_MonsterMgr;
	mBulletMgr = a_BulletMgr;
}

void TOWER::setRange(Real r)
{
	Range=r;
}

void TOWER::shoot(int TargetID)
{
	//mMonsterMgr->s(TargetID);	
	//BULLET b(mSceneMgr,mMonsterMgr,TargetID,200,40);
	//b.setMesh("b","box.mesh");
	//b.setPosition(mSceneNode->getPosition());

	mBulletMgr->create("sphere.mesh",mSceneNode->getPosition(),TargetID);
	
}

void TOWER::update(const Ogre::FrameEvent& evt)
{
	CD+=evt.timeSinceLastFrame;

	if(CD>=MaxCD)
	{		
		if(TargetID != -1 && mMonsterMgr->isMonsterExist(TargetID) && ( mMonsterMgr->findMonsterPosByID(TargetID)-mSceneNode->getPosition()).length() <= Range )
		{
			shoot(TargetID);
			CD=0;
		}
		else
		{		
			TargetID = mMonsterMgr->findNearestMonsterID(mSceneNode->getPosition(),Range);
			if(TargetID != -1)
			{
				shoot(TargetID);
				CD=0;
			}
		}
	}

	if( TargetID != -1 && mMonsterMgr->isMonsterExist(TargetID) )
	{
		Ogre::Vector3 target = mMonsterMgr->findMonsterPosByID(TargetID);
		Ogre::Vector3 dir = target-mSceneNode->getPosition();
		mSceneNode->setDirection(dir,Ogre::SceneNode::TS_WORLD);
	}
}