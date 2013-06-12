#ifndef __MonsterManager_h_
#define __MonsterManager_h_

#include "Monster.h"
#include "Ogre.h"

#define MAX_NUM_MONSTER 512

class MonsterManager 
{
private:

	MONSTER *mMonstersArr[ MAX_NUM_MONSTER ];
	Ogre::SceneManager* mSceneMgr;

	bool deleteMonster( int monster_id );

public:

	MonsterManager(Ogre::SceneManager* mSceneMgr);
	~MonsterManager();

	int findNearestMonsterID( Ogre::Vector3 pos,Ogre::Real range);
	bool isMonsterExist(int monster_id);
	Ogre::Vector3 findMonsterPosByID(int id);
	bool damage(int id,Ogre::Real damage );
	
	bool create(  int monster_type, Ogre::Vector3 pos,std::queue< Ogre::Vector3 > a_goalQueue);
	void update(const Ogre::FrameEvent& evt);

	void s(int i);
};

#endif