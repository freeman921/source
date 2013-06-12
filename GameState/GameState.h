#ifndef __GameState_h__
#define __GameState_h__

#include "Ogre.h"
#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>

class Game;

 class GameState
{
protected:
	Game *game;
	int difficulity;
	int level;
public:

	GameState(Game *game);
	virtual ~GameState();
	virtual bool setLevel(int level);
	virtual bool setDifficulity(int d);

	virtual bool frameStarted(const Ogre::FrameEvent& evt);
	// OIS::KeyListener
    virtual bool keyPressed( const OIS::KeyEvent &arg );
    virtual bool keyReleased( const OIS::KeyEvent &arg );
	// OIS::MouseListener
    virtual bool mouseMoved( const OIS::MouseEvent &arg );
    virtual bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
    virtual bool mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id );

};

#endif