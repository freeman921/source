#ifndef __GameStory_h__
#define __GameStory_h__

#include "Ogre.h"
#include "../GameState.h"
#include "MyGUI.h"	

class Game;

class GameStory : public GameState
{

public:

	GameStory(Game *game);
	~GameStory();
	bool setLevel(int level);

	bool frameStarted(const Ogre::FrameEvent& evt);
	// OIS::KeyListener
    bool keyPressed( const OIS::KeyEvent &arg );
    bool keyReleased( const OIS::KeyEvent &arg );
	bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
protected:
	void setLayout();
	void handleButton(MyGUI::WidgetPtr sender);
	std::queue< Ogre::String > pic_queue;	
};


#endif