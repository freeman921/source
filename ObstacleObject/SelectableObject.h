#ifndef __SelectableObject_h_
#define __SelectableObject_h_

#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreLogManager.h>
#include <OgreRoot.h>
#include <OgreViewport.h>
#include <OgreSceneManager.h>

#include "ObstacleObject.h"
#include "../Utility/Defines.h"
using namespace Ogre;


class SelectableObject : public ObstacleObject
{

public:
	int type; // T or M

	SelectableObject(SceneManager *a_SceneMgr);
	//~SelectableObject(); // will automatically calls ~ObstacleObject

	void setMesh(const String &a_Name, const String &a_MeshName);
		//void getSelectedInfo(); // to be done

};

#endif