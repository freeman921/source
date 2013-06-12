#ifndef __MainMenu_h__
#define __MainMenu_h__

#include "Ogre.h"
#include "../GameState.h"
#include "MyGUI.h"	

class Game;

class MainMenu : public GameState
{
public:

	MainMenu(Game *game);
	~MainMenu();
	bool setLevel(int level);

	bool frameStarted(const Ogre::FrameEvent& evt);
	// OIS::KeyListener
    bool keyPressed( const OIS::KeyEvent &arg );
    bool keyReleased( const OIS::KeyEvent &arg );
	// OIS::MouseListener
    bool mouseMoved( const OIS::MouseEvent &arg );
    bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
    bool mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
private:
	void setLayout();
	void handleButton(MyGUI::WidgetPtr sender);
};


#endif