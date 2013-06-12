#include "Map.h"
#include "../ObstacleObject/Monster/MonsterManager.h"

Map::Map(Ogre::SceneManager* mSceneMgr,MonsterManager* mMonsterMgr)
{
	this->mSceneMgr = mSceneMgr;
	this->mMonsterMgr = mMonsterMgr;
	timer = 0;
}

void Map::createPlane()
{

	Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0); 
	Ogre::MeshManager::getSingleton().createPlane(
		"ground", 						Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, 
		plane, 
		700,700, 	// width, height
		20,20, 		// x- and y-segments
		true, 		// normal
		1, 			// num texture sets
		5,5, 		// x- and y-tiles
		Ogre::Vector3::UNIT_Z	// upward vector
		); 

	Ogre::Entity *ent = mSceneMgr->createEntity(
		"GroundEntity", "ground");
	ent->setMaterialName("Examples/WaterStream");
	mSceneMgr->getRootSceneNode()->attachObject(ent);

}

void Map::update( float time  )
{
	timer = timer + time;

	for(int i = 0 ; i < monsters.size() ; i++ )
	{
		MonsterList* m = &monsters.at(i);
		if( m->time < 0 || m->time > timer ) 
			continue;
		
		mMonsterMgr->create( m->monster_type , m->position , pathlist.at(m->a_goalQueueID) );
		m->time = -1;
	}

}

void Map::createScene( Ogre::String map_name)
{
	//here should read file but now it's for test~

	map_hieght = 2000;
	map_width  = 2000;

	buildable = new bool[map_hieght*map_width];

	std::queue< Ogre::Vector3 > goalQueue_1;
	goalQueue_1.push( Ogre::Vector3(250,0,0) );
	goalQueue_1.push( Ogre::Vector3(250,0,800) );

	std::queue< Ogre::Vector3 > goalQueue_2;
	goalQueue_2.push( Ogre::Vector3(250,0,0) );
	goalQueue_2.push( Ogre::Vector3(250,0,-800) );

	std::queue< Ogre::Vector3 > goalQueue_3;
	goalQueue_3.push( Ogre::Vector3(250,0,0) );
	goalQueue_3.push( Ogre::Vector3(250,0,-800) );
	goalQueue_3.push( Ogre::Vector3(500,0,-800) );

	pathlist.push_back(goalQueue_1);
	pathlist.push_back(goalQueue_2);
	pathlist.push_back(goalQueue_3);

	MonsterList monster;
	monster.a_goalQueueID = 0 ;
	monster.monster_type = 1;
	monster.time = 10.0;
	monster.position = Ogre::Vector3(0,0,0);
	monsters.push_back(monster);

	monster.a_goalQueueID = 1 ;
	monster.monster_type = 2;
	monster.time = 12.0;
	monster.position = Ogre::Vector3(0,0,0);
	monsters.push_back(monster);

	monster.a_goalQueueID = 2 ;
	monster.monster_type = 3;
	monster.time = 14.0;
	monster.position = Ogre::Vector3(0,0,0);
	monsters.push_back(monster);
}