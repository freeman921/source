#ifndef __GameStateManager_h__
#define __GameStateManager_h__

#include "Ogre.h"
#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>

#include "AllStates.h"

class Game;

class GameStateManager
{
private:
	Game *game;
	GameState*	now_state;
	int			level;

	int next_state_num;
	int next_level;
	int next_difficulity;

	bool _changeState(STATE new_state,int level,int difficulity);
public:

	GameStateManager(Game *game);
	bool changeState(STATE new_state,int level=0,int difficulity=0);
	bool setLevel(int level);
	bool setDifficulity(int difficulity);

	bool frameStarted(const Ogre::FrameEvent& evt);
	// OIS::KeyListener
    bool keyPressed( const OIS::KeyEvent &arg );
    bool keyReleased( const OIS::KeyEvent &arg );
	// OIS::MouseListener
    bool mouseMoved( const OIS::MouseEvent &arg );
    bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
    bool mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id );

};

#endif