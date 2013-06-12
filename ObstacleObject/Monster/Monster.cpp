#include "Monster.h"

MONSTER::MONSTER(SceneManager *a_SceneMgr,std::queue< Ogre::Vector3 > a_goalQueue ) : SelectableObject(a_SceneMgr)
{
	HP = 100;

	goalQueue = a_goalQueue;
	if( !goalQueue.empty() )
	{
		GoalPos = goalQueue.front();
		goalQueue.pop();
	} 
		

}
MONSTER::~MONSTER()
{
	delete(data);
}
	
void MONSTER::setGoalPos(Vector3 a)
{
	GoalPos=a;
}

Vector3 MONSTER::getPos()
{
	return mSceneNode->getPosition();
}

bool MONSTER::isReachGoalPos()
{
	Vector3 pos = mSceneNode->getPosition();
	return goalQueue.empty() && pos==GoalPos ;
}

bool MONSTER::isAlive()
{
	return HP>0;
}

Real MONSTER::minusHP(Real damage)
{
	HP-=damage;
	return HP;
}

void MONSTER::setHP(Real hp)
{
	HP=hp;
}

void MONSTER::updateViewDirection()
{/*
	if (mTarget == 0) return;
	Vector3 pos = mTarget->getPosition();
	Vector3 target_pos = mSceneNode->getPosition();
	target_pos.x = pos.x;
	target_pos.z = pos.z;

	mSceneNode->lookAt(target_pos, Node::TS_WORLD);
	mSceneNode->yaw(Radian(3.14159));*/
}

void MONSTER::update(const Ogre::FrameEvent& evt)
{
	
	Vector3 pos = mSceneNode->getPosition();
	
	Vector3 diff = GoalPos-pos;
	
	//抵達目前的goal
	if(diff.length()<5)
	{
		mSceneNode->setPosition(GoalPos);

		if( !goalQueue.empty() )
		{
			GoalPos = goalQueue.front();
			goalQueue.pop();
		}
			

	} 
	else
	{
		diff.normalise();
		mSceneNode->translate(80*diff*evt.timeSinceLastFrame);
		mSceneNode->setDirection(-diff,Ogre::SceneNode::TS_WORLD);
	}
	
	updateViewDirection();
}

void MONSTER::r(Real angle)
{
	mSceneNode->roll(Degree(angle));
}

MonsterData* MONSTER::getData()
{
	return data;
}
void MONSTER::setData(MonsterData* mData)
{
	if(data!=NULL) delete(data);
	data = mData;
}