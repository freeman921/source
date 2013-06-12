#ifndef __MonsterData_h__
#define __MonsterData_h__

#include "Ogre.h"

class MONSTER;

class MonsterData
{
public:
	int monster_type;
	Ogre::String name;
	Ogre::String mesh_name;
	Ogre::String pic_name;
	Ogre::Real Max_HP;
	Ogre::Real DP;
	Ogre::Real speed;
	Ogre::String info;

	static bool setDataByType( MONSTER* monster ,int type);
};


#endif