#ifndef __Game_h__
#define __Game_h__

#include <string>
#include "BaseApplication.h"

#include "GUI/MyGUIController.h"
#include "Map/Map.h"
#include "GameState/GameStateManager.h"

#include "Utility/Defines.h"
#include "Utility/OgreDataReader.h"
#include "Bullet/BulletManager.h"
#include "ObstacleObject/Monster/MonsterManager.h"
#include "ObstacleObject/Tower/TowerManager.h"
#include "OgreOggSound.h"

class Game : public BaseApplication
{
private:


public:
	Game(void);
	
	// global vars
	Ogre::Camera* mCameraArr[8];
	Ogre::SceneManager* mSceneMgrArr[8];
	OgreBites::SdkCameraMan* mCameraManArr[8];
	Ogre::Light *mLight[8];

	OgreDataReader *mOgreDataReader;

	GameStateManager* mGSm;

	BulletManager *mBM;
	TowerManager *mTM;
	MonsterManager *mMM;
	SceneNode *mCurrentSelectObject;
	Map* mMap;

	//sound
	OgreOggSound::OgreOggSoundManager* mSoundManager;

	//GUI
	MyGUIController* mGUI;


	//Camera
	Ogre::Real mCameraX, mCameraZ, mCameraY; // Y=camera height
	bool moveDirFlag[4];

	void basicGameStartSet(void);
	void createManagers(SceneManager*);
	
	//! Basic Scene Create Functions
	virtual void createCamera(void);
	virtual void createViewports(void);
	virtual void createScene(void);
	virtual void chooseSceneManager(void);
	
	//! Sub-Scene Create Functions
	void createViewport_GameRound(void);
	void createCamera_GameRound(void);
	void createScene_GameRound(void);

	void setLight(void);
	
	virtual bool frameStarted(const Ogre::FrameEvent& evt);
	// OIS::MouseListener
	virtual bool mouseMoved( const OIS::MouseEvent &arg );
	virtual bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
	virtual bool mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
	void scrollScreenDetermine(void);

	void createInitialSound();

	
    // OIS::KeyListener
    virtual bool keyPressed( const OIS::KeyEvent &arg );
    virtual bool keyReleased( const OIS::KeyEvent &arg );
	
	
	// virtual void createFrameListener(void); // use baseApp's is ok?
	
	
	
	friend class MainMenu;
	friend class LevelSelectionMenu;
	friend class GameStory;
	friend class PlayField;
};
 
#endif 