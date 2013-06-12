#ifndef __ObstacleObject_h_
#define __ObstacleObject_h_
#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreLogManager.h>
#include <OgreRoot.h>
#include <OgreViewport.h>
#include <OgreSceneManager.h>

using namespace Ogre;

class ObstacleObject
{
protected:
	static int gs_NameIndex;
	SceneManager *mSceneMgr;
	SceneNode *mSceneNode;
	Entity *mEntity;

public:
	
	ObstacleObject(){} // for child class
	ObstacleObject(SceneManager *a_SceneMgr);
	~ObstacleObject();

	virtual void setMesh(const String &a_Name, const String &a_MeshName);
	void translate(const Vector3 &v);
	void setPosition(const Vector3 &pos);
	void scale(Real sx, Real sy, Real sz);

	void genNameUsingIndex(const String & prefix, int index, String &out_name);


};

#endif