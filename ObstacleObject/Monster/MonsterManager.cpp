
#include "MonsterManager.h"
#include "MonsterData.h"


MonsterManager::MonsterManager(Ogre::SceneManager* mSceneMgr)
{
	this->mSceneMgr = mSceneMgr;
	for(int i=0;i<MAX_NUM_MONSTER;i++)
	{
		mMonstersArr[i] = NULL;
	}

}

MonsterManager::~MonsterManager()
{
	for(int i=0;i<MAX_NUM_MONSTER;i++)
	{
		if(mMonstersArr[i] != NULL)delete(mMonstersArr[i]);
	}

}

bool MonsterManager::create( int monster_type, Ogre::Vector3 pos,std::queue< Ogre::Vector3 > a_goalQueue)
{

	bool sucess =false;
	for(int i=0;i<MAX_NUM_MONSTER;i++)
	{
		if( mMonstersArr[i]!= NULL ) continue; 
		
		mMonstersArr[i] = new MONSTER( mSceneMgr,a_goalQueue );
		MonsterData::setDataByType( mMonstersArr[i] , monster_type );
		mMonstersArr[i]->setPosition( pos );
		//mMonstersArr[i]->setMesh("m",mesh_name);

		sucess=true;
		break;
	}
	
	return sucess;
}



void MonsterManager::update(const Ogre::FrameEvent& evt)
{


	for(int i=0;i<MAX_NUM_MONSTER;i++)
	{
		if( mMonstersArr[i] == NULL ) continue; 
		
		if( !mMonstersArr[i]->isAlive() ) deleteMonster( i );
		else
		{
			mMonstersArr[i]->update(evt);
			if( mMonstersArr[i]->isReachGoalPos() )
			{
				//minus Gamer's Life

				deleteMonster( i );
			}
		}
	}

}


bool MonsterManager::deleteMonster( int monster_id )
{
	if( mMonstersArr[monster_id]== NULL ) return false;

	delete( mMonstersArr[monster_id] );
	mMonstersArr[monster_id] = NULL;

	return true;
}

int MonsterManager::findNearestMonsterID(Ogre::Vector3 pos,Ogre::Real range)
{

	int monster_id =-1;
	Ogre::Real min_distence = range+1 ;
	for(int i=0;i<MAX_NUM_MONSTER;i++)
	{
		if( mMonstersArr[i] == NULL ) continue; 
		
		Ogre::Vector3 distence = mMonstersArr[i]->getPos() - pos;
		if( distence.length() > range && distence.length() >min_distence )continue;
		monster_id=i;
		min_distence = distence.length();
		break;
	}
	
	return monster_id;

}

Ogre::Vector3 MonsterManager::findMonsterPosByID(int id)
{
	
	if( mMonstersArr[id] == NULL ) return Ogre::Vector3(0,0,0);
	return mMonstersArr[id]->getPos();

}
bool MonsterManager::damage(int id,Ogre::Real damage )
{
	if( mMonstersArr[id] == NULL ) return false;
	mMonstersArr[id]->minusHP(damage);
	return true;
}

void MonsterManager::s(int i)
{
	mMonstersArr[i]->r(30);
}


bool MonsterManager::isMonsterExist(int monster_id)
{
	if( mMonstersArr[monster_id] == NULL ) return false;
	else return true;  
}