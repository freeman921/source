#include "MonsterData.h"
#include "Monster.h"


bool MonsterData::setDataByType( MONSTER* monster ,int type)
{
	if( type<=0 || type>5) return false;

	
	if( type == 1 )
	{
		MonsterData* data = new MonsterData();
		data->monster_type	= 1;
		data->name			= "penguin";
		data->mesh_name		= "penguin.mesh";
		data->pic_name		= "penguin.jpg";
		data->Max_HP		= 100;
		data->DP			= 0;
		data->speed			= 80;
		data->info			= "test monster 1";

		monster->setData(data);
		monster->setMesh("m",data->mesh_name);
	}

	if( type == 2 )
	{
		MonsterData* data = new MonsterData();
		data->monster_type	= 2;
		data->name			= "speed up penguin";
		data->mesh_name		= "penguin.mesh";
		data->pic_name		= "penguin.jpg";
		data->Max_HP		= 50;
		data->DP			= 0;
		data->speed			= 160;
		data->info			= "test monster 2, i am fast~";

		monster->setData(data);
		monster->setMesh("m",data->mesh_name);
		monster->scale(0.6,0.6,0.6);
	}
			
	if( type == 3 )
	{
		MonsterData* data = new MonsterData();
		data->monster_type	= 3;
		data->name			= "Ogre head";
		data->mesh_name		= "ogrehead.mesh";
		data->pic_name		= "ogrehead.jpg";
		data->Max_HP		= 130;
		data->DP			= 0;
		data->speed			= 80;
		data->info			= "test monster 3";

		monster->setData(data);
		monster->setMesh("m",data->mesh_name);
	}
				
	if( type == 4 )
	{
		MonsterData* data = new MonsterData();
		data->monster_type	= 4;
		data->name			= "fish";
		data->mesh_name		= "fish.mesh";
		data->pic_name		= "fish.jpg";
		data->Max_HP		= 100;
		data->DP			= 0;
		data->speed			= 80;
		data->info			= "test monster 4";

		monster->setData(data);
		monster->setMesh("m",data->mesh_name);
	}

	if( type == 5 )
	{
		MonsterData* data = new MonsterData();
		data->monster_type	= 5;
		data->name			= "Big fish";
		data->mesh_name		= "fish.mesh";
		data->pic_name		= "fish.jpg";
		data->Max_HP		= 100;
		data->DP			= 0;
		data->speed			= 80;
		data->info			= "test monster 5";

		monster->setData(data);
		monster->setMesh("m",data->mesh_name);
		monster->scale(2.0,2.0,2.0);
	}

	return true;
}
