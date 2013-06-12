#ifndef __ScorePage_h__
#define __ScorePage_h__

#include "Ogre.h"
#include "../GameState.h"

class Game;

 class ScorePage : public GameState
{
public:

	ScorePage(Game *game);
	bool setLevel(int level);

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