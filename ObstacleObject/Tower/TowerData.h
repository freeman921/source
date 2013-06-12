#ifndef __TowerData_h__
#define __TowerData_h__

#include "Ogre.h"

class TOWER;

class UpGradeInfo
{
public:
	// <resource type , num>
	std::queue< std::pair<int,int> > cost;
	
	int origin_tower;
	int upgrade_tower;
};

class TowerData
{
public:
	int tower_type;
	Ogre::String name;
	Ogre::String mesh_name;
	Ogre::String pic_name;

	int bullet_type;
	Ogre::Real AP;
	Ogre::Real MaxCD;

	Ogre::Real range;
	Ogre::String info;


	//static std::queue< UpGradeInfo > upgarde;
	static void init();
	static bool setDataByType( TOWER* tower ,int type);
};


#endif