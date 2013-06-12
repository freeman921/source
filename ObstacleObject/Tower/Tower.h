#ifndef __Tower_h_
#define __Tower_h_

#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreLogManager.h>
#include <OgreRoot.h>
#include <OgreViewport.h>
#include <OgreSceneManager.h>

#include "../SelectableObject.h"
#include "../Monster/MonsterManager.h"
#include "../Bullet/BulletManager.h"

class TOWER : public SelectableObject {
protected:

	Real MaxCD;
	Real Range;

	Real CD;
	int TargetID;
	MonsterManager *mMonsterMgr;
	BulletManager  *mBulletMgr;
public:
	TOWER(SceneManager *a_SceneMgr,MonsterManager *a_MonsterMgr,BulletManager  *a_BulletMgr);
	void update(const Ogre::FrameEvent& evt);
	void setRange(Real r);
	void shoot(int TargetID);
};

#endif
