#include "Bullet.h"

BULLET::BULLET(SceneManager *a_SceneMgr,MonsterManager *a_MonsterMgr,int id=-1,Real sp=200,Real d=40) : ObstacleObject(a_SceneMgr)
{
	TargetID=id;
	Speed=sp;
	Damage=d;
	mMonsterMgr=a_MonsterMgr;

	hit= false;
}
void BULLET::setTargetID(int id)
{
	TargetID=id;
}

void BULLET::setSpeed(Real sp)
{
	Speed=sp;
}

void BULLET::setDamage(Real d)
{
	Damage=d;
}

void BULLET::update(const Ogre::FrameEvent& evt)
{
	if( !mMonsterMgr->isMonsterExist(TargetID) ) return ;

	Vector3 TargetPos = mMonsterMgr->findMonsterPosByID(TargetID);
	Vector3 pos = mSceneNode->getPosition();
	Vector3 diff = TargetPos - pos;
	if(diff.length()<Speed*evt.timeSinceLastFrame)
	{
		mSceneNode->setPosition(TargetPos);
		mMonsterMgr->damage(TargetID,Damage);
		hit = true;
	}
	else
	{
		diff.normalise();
		mSceneNode->translate(Speed*diff*evt.timeSinceLastFrame);
	}
}

bool BULLET::isHit()
{
	return hit;
}

int BULLET::getTargetID()
{
	return TargetID;
}