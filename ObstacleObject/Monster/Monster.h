#ifndef __Monster_h__
#define __Monster_h__
#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreLogManager.h>
#include <OgreRoot.h>
#include <OgreViewport.h>
#include <OgreSceneManager.h>

#include "../SelectableObject.h"

class MonsterData;

class MONSTER : public SelectableObject {
protected:
	void updateViewDirection();

	MonsterData* data;

	Real HP;
	Vector3 GoalPos;
	
	std::queue< Ogre::Vector3 > goalQueue;
public:
	MONSTER(SceneManager *a_SceneMgr,std::queue< Ogre::Vector3 > a_goalQueue );
	~MONSTER();
	virtual void update(const Ogre::FrameEvent& evt);
	void setGoalPos(Vector3 a);
	bool isReachGoalPos();
	bool isAlive();
	Real minusHP(Real damage);
	void setHP(Real hp);
	Vector3 getPos();

	void r(Real angle);

	MonsterData* getData();
	void setData(MonsterData* mData);
};

#endif
