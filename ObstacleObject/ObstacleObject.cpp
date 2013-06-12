/*
#include "ObstacleObject.h"

ObstacleObject
*/
#include "ObstacleObject.h"

int ObstacleObject::gs_NameIndex =0;

void ObstacleObject::genNameUsingIndex(const String & prefix, int index, String &out_name)
{
	out_name= prefix + StringConverter::toString(static_cast<int>(index));
}

ObstacleObject::ObstacleObject(SceneManager *a_SceneMgr)
{
	mSceneMgr = a_SceneMgr;
	mSceneNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	gs_NameIndex++;
}

ObstacleObject::~ObstacleObject()
{
	LogManager::getSingleton().logMessage("[Delete] "+ mEntity->getMesh()->getName() );

	mSceneNode->detachObject(mEntity);
	mSceneMgr->destroySceneNode(mSceneNode);
	mSceneMgr->destroyEntity(mEntity);
}

void ObstacleObject::setMesh(const String &a_Name, const String &a_MeshName)
{
	String name;
	genNameUsingIndex(a_Name, gs_NameIndex, name);
	mEntity = mSceneMgr->createEntity(name, a_MeshName);
	mSceneNode->attachObject(mEntity);
}

void ObstacleObject::translate(const Vector3 &v)
{
	mSceneNode->translate(v);
}

void ObstacleObject::setPosition(const Vector3 &pos)
{
	mSceneNode->setPosition(pos);
}

void ObstacleObject::scale(Real sx, Real sy, Real sz)
{
	mSceneNode->scale(sx, sy, sz);
}