
#include "SelectableObject.h"


SelectableObject::SelectableObject(SceneManager *a_SceneMgr) : ObstacleObject(a_SceneMgr) {}

void SelectableObject::setMesh(const String &a_Name, const String &a_MeshName)
{
	ObstacleObject::setMesh( SELECTABLE_MESH_HEADER +a_Name, a_MeshName);
}

