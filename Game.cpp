#include "Game.h"

#define INIT_CAMERA_Y 500.0
#define MOUSEMOVE_BOARDER 0.05
#define MOUSESCROLL_CONST 0.4

using namespace Ogre;
Game::Game(void) {}

void Game::chooseSceneManager()
{
	mSceneMgrArr[ GAME_SCENE ] = mRoot->createSceneManager( ST_EXTERIOR_CLOSE, "primary");
}
void Game::createCamera(void) { createCamera_GameRound(); }
void Game::createViewports(void) { createViewport_GameRound(); }

void Game::createScene(void) 
{
	basicGameStartSet();
	mSceneMgr = mSceneMgrArr[GAME_SCENE];
	mCurrentSelectObject = NULL;
	createInitialSound();

	mGUI = new MyGUIController();
	mGUI->intitalMyGUIController(mWindow,mSceneMgr);

	mGSm = new GameStateManager(this);
	mGSm->changeState(MAIN_MENU);
	
	//createScene_GameRound(); 
	
}

void Game::basicGameStartSet(void)
{
	// Logger
	Log *mainLog = LogManager::getSingleton().createLog( MAIN_LOGGER );
	LogManager::getSingleton().setDefaultLog(mainLog);

	//DataReader
	mOgreDataReader = new OgreDataReader();
	mOgreDataReader->create( GAMEDATA_FILENAME );
		//double x = mOgreDataReader->getByDouble("Main","EyePos");
}

void Game::createManagers(SceneManager *mSceneMgr)
{
	mMM = new MonsterManager(mSceneMgr);
	mBM=new BulletManager(mSceneMgr,mMM);
	mTM=new TowerManager(mSceneMgr,mMM, mBM);
}

void Game::createCamera_GameRound(void)
{
	mSceneMgr = mSceneMgrArr[ GAME_SCENE ];
	mCameraArr[ GAME_SCENE ] =  mSceneMgr-> createCamera( "PlayerCam" ); // PLAYER_CAMERA
	mCamera = mCameraArr[ GAME_SCENE ];
	
	mCameraX = 0;
	mCameraZ = 400.0;
	mCameraY = INIT_CAMERA_Y; 
	//mCameraY = mOgreDataReader->getByDouble("Camera","Init_Camera_Y"); // has some bug.
	for (int i=0;i<4;i++)
		moveDirFlag[i]=false;


	mCamera->setPosition( Ogre::Vector3(mCameraX,mCameraY, mCameraZ) );
	mCamera->lookAt(Ogre::Vector3(0,0,0));
	
	mCamera->setNearClipDistance(5);
	mCameraManArr[ GAME_SCENE ] = new OgreBites::SdkCameraMan(mCamera);   // create a default camera controller
}

void Game::createViewport_GameRound(void)
{
	mCameraMan = mCameraManArr[ GAME_SCENE ];
	mCamera = mCameraArr[GAME_SCENE];
	Ogre::Viewport* vp = mWindow->addViewport(mCamera);
		
	vp->setBackgroundColour( Ogre::ColourValue(0,0.5,0.5) );
	mCamera->setAspectRatio( Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight()) );
	vp->setVisibilityMask(0x01);
	
}

// casually put something in scene for now.
void Game::createScene_GameRound(void)  
{

		//mSceneMgr->setWorldGeometry("terrain.cfg"); 
	mSceneMgr->setSkyBox( true, "Examples/TrippySkyBox");
	setLight();
	
	Plane plane(Vector3::UNIT_Y, 0); 
	MeshManager::getSingleton().createPlane(
		"ground", 						ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, 
		plane, 
		700,700, 	// width, height
		20,20, 		// x- and y-segments
		true, 		// normal
		1, 			// num texture sets
		5,5, 		// x- and y-tiles
		Vector3::UNIT_Z	// upward vector
		); 

	Entity *ent = mSceneMgr->createEntity(
		"GroundEntity", "ground");
	ent->setMaterialName("Examples/WaterStream");
	mSceneMgr->getRootSceneNode()->attachObject(ent);

	//Penguim
	//Ogre::Entity* entPenguin = mSceneMgr->createEntity("Penguin", "penguin.mesh");
    
	//SceneNode *snode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	//snode->setPosition(0, 0, 0);
	//snode->attachObject(entPenguin);

	createManagers(mSceneMgr);
	
	// Map
	mMap = new Map(mSceneMgr,mMM);
	mMap->createScene("test");

}


void Game::setLight(void)
{
	Light *light = mLight[MAIN_LIGHT] = mSceneMgr->createLight("MainLight"); 

	light->setType(Light::LT_POINT);
	light->setPosition( Vector3(100, 600, 100) ); 
	light->setDiffuseColour(0.7, 0.7, 0.7);		
	light->setSpecularColour(1.0, 1.0, 1.0);	
	light->setDirection(Vector3(1, 1, 1));
}

void Game::createInitialSound()
{
	mSoundManager = OgreOggSound::OgreOggSoundManager::getSingletonPtr();
	mSoundManager->init();

	ResourceGroupManager::getSingleton().addResourceLocation("../../media/music", "FileSystem",ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, false) ;

	mSoundManager->createSound("click", "click.wav", false, false, true);
	mSoundManager->getSound("click")->setVolume(0.5);
	mSoundManager->getSound("click")->setMaxVolume(0.55);
}

bool Game::frameStarted(const Ogre::FrameEvent& evt)
{
	return mGSm->frameStarted(evt);

	/*
	// Camera
	scrollScreenDetermine();
	mCameraArr[GAME_SCENE]->setPosition(mCameraX,mCameraY,mCameraZ);

	// game settings

	mMM->update(evt);
	mBM->update(evt);
	mTM->update(evt);
	mMap->update(evt.timeSinceLastFrame);

	return true;
	*/
}

void Game::scrollScreenDetermine(void)
{
	if (moveDirFlag[DIR_RIGHT]==true)
		mCameraX += 1;
	else if (moveDirFlag[DIR_LEFT]==true)
		mCameraX -= 1;

	if (moveDirFlag[DIR_DOWN]==true)
		mCameraZ += 1;
	else if (moveDirFlag[DIR_UP]==true)
		mCameraZ -= 1;
}

bool Game::mouseMoved( const OIS::MouseEvent &arg )
{
	return mGSm->mouseMoved(arg);

	/*
	mGUI->mouseMoved(arg);

	static int width = mWindow->getWidth(), height = mWindow->getHeight();
	
	if ( arg.state.X.abs > width*(1-MOUSEMOVE_BOARDER) )
		moveDirFlag[DIR_RIGHT] = true;
	else if ( arg.state.X.abs < width*MOUSEMOVE_BOARDER )
		moveDirFlag[DIR_LEFT] = true;
	else
	{
		moveDirFlag[DIR_RIGHT] = false;
		moveDirFlag[DIR_LEFT] = false;
	}

	if ( arg.state.Y.abs > height*(1-MOUSEMOVE_BOARDER) )
		moveDirFlag[DIR_DOWN] = true;
	else if ( arg.state.Y.abs < height*MOUSEMOVE_BOARDER )
		moveDirFlag[DIR_UP] = true;
	else
	{
		moveDirFlag[DIR_DOWN] = false;
		moveDirFlag[DIR_UP] = false;
	}
	
	// scroll middle button
	if ( arg.state.Z.rel != 0 )
		mCameraY += arg.state.Z.rel *-1 *MOUSESCROLL_CONST;

		//std::cout << mWindow->getWidth() << ' '<< mWindow->getHeight() << std::endl;
		//std::cout << arg.state.X.abs << ' ' << arg.state.Y.abs << std::endl;
		//std::cout << arg.state.Z.rel << std::endl;

	return BaseApplication::mouseMoved(arg);
	*/
}

bool Game::mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
	return mGSm->mousePressed(arg,id);
/*
	mGUI->mousePressed(arg,id);

	// cancel last bounding box.
	if ( mCurrentSelectObject!= NULL)
		mCurrentSelectObject->showBoundingBox(false);


	Ray mRay =mTrayMgr->getCursorRay(mCamera);
	RaySceneQuery *mRaySceneQuery = 
		mSceneMgr->createRayQuery ( Ray() ); 

	mRaySceneQuery->setSortByDistance(true); 

	mRaySceneQuery->setRay(mRay);
	// Perform the scene query
	RaySceneQueryResult &result = 
		mRaySceneQuery->execute();
	RaySceneQueryResult::iterator itr = result.begin();

	// Get the results, set the camera height
	// We are interested in the first intersection. It is ok to traverse all the results.
	for (itr = result.begin(); itr != result.end(); itr++)
    {
			// itr->movable && itr->movable->getName().substr(0, 5) != "tile["
		if (itr->movable && itr->movable->getName().find( SELECTABLE_MESH_HEADER ) != std::string::npos )
		{
			mCurrentSelectObject = itr->movable->getParentSceneNode();
			bool flgShow = mCurrentSelectObject->getShowBoundingBox();
			mCurrentSelectObject->showBoundingBox(!flgShow);
			
			// getSelectedInfo from Managers ?

			break;
		} // if
	}
	return BaseApplication::mousePressed( arg, id );

	*/
}

bool Game::mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
	return mGSm->mouseReleased(arg,id);

	/*
	mGUI->mouseReleased(arg,id);

	if ( id==OIS::MB_Right )
	{
		Ray mRay =mTrayMgr->getCursorRay(mCamera);
					
		// find the intersection of Ray and Plane y=0 (math)
		Vector3 org = mRay.getOrigin();
		Vector3 vec = mRay.getDirection();
		Real t = -1*( org.y / vec.y );

		Vector3 resultPlace = Vector3(org.x+t*vec.x, 0, org.z+t*vec.z);
		mTM->create("robot.mesh", resultPlace ,300 );
	}

	return BaseApplication::mouseReleased( arg, id );
	*/
}


bool Game::keyPressed( const OIS::KeyEvent &arg )
{
	return mGSm->keyPressed(arg);
}

bool Game::keyReleased( const OIS::KeyEvent &arg )
{
	return mGSm->keyReleased(arg);
}


int main(int argc, char *argv[]) {
	Game app;
	app.go();  
	return 0;
}



