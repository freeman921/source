#ifndef __Bullet_h__
#define __Bullet_h__
#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreLogManager.h>
#include <OgreRoot.h>
#include <OgreViewport.h>
#include <OgreSceneManager.h>

#include "../ObstacleObject/ObstacleObject.h"
#include "../ObstacleObject/Monster/MonsterManager.h"

class BULLET : public ObstacleObject {
protected:
	int TargetID;
	Real Speed;
	Real Damage;
	MonsterManager *mMonsterMgr;

	bool hit;

public:
	BULLET(SceneManager *a_SceneMgr,MonsterManager *a_MonsterMgr,int id,Real sp,Real d);
	virtual void update(const Ogre::FrameEvent& evt);

	void setTargetID(int id);
	void setSpeed(Real sp);
	void setDamage(Real d);

	int getTargetID();

	bool isHit();

};

#endif
