#ifndef __Map_h__
#define __Map_h__

#include "Ogre.h"

#define MAP_GRID 50

class MonsterManager;

class MonsterList
{
public:
	//Ogre::String monster_name;
	
	int	monster_type;
	float time;
	
	Ogre::Vector3 position;
	
	int a_goalQueueID;

};


class Map
{
protected:
	std::vector< MonsterList > monsters;

	std::vector< std::queue< Ogre::Vector3 > > pathlist;

	float timer;

	Ogre::SceneManager*		mSceneMgr;
	MonsterManager*			mMonsterMgr;
	
	bool *buildable;
	int map_hieght;
	int map_width;
	
	void setMapBuildable( int x, int y,bool t );
	Ogre::Vector2 getGridPos( Ogre::Vector3 pos );
	void createPlane();
public:
	
	Map(Ogre::SceneManager* mSceneMgr,MonsterManager* mMonsterMgr);
	~Map();
	
	void createScene(Ogre::String map_name);
	bool getMapBuildable( int x, int y);
	bool getMapBuildable( Ogre::Vector3 pos );
	void update( float time  );

	float getTime();

	void setTime(float time);
	
};








#endif