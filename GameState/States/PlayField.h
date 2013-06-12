#ifndef __PlayField_h__
#define __PlayField_h__

#include "Ogre.h"
#include "../GameState.h"
#include "MyGUI.h"	

class Game;

 class PlayField : public GameState
{
public:

	PlayField(Game *game);
	~PlayField();
	bool setLevel(int level);
	void setPause(bool p);

	bool frameStarted(const Ogre::FrameEvent& evt);
	// OIS::KeyListener
    bool keyPressed( const OIS::KeyEvent &arg );
    bool keyReleased( const OIS::KeyEvent &arg );
	// OIS::MouseListener
    bool mouseMoved( const OIS::MouseEvent &arg );
    bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
    bool mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
	bool getPause();

protected:
	void setLayout();
	void handleButton(MyGUI::WidgetPtr sender);
	void handleWindow(MyGUI::WidgetPtr _widget, const std::string& _name);
	void creatScene();

	bool god_menu;
	bool pause;
};


#endif