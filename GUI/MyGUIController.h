#ifndef __MyGUIController_h__
#define __MyGUIController_h__

#include "Ogre.h"
#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>

// MyGUI  v 3.2
#include "MyGUI.h"									
#include "MyGUI_OgrePlatform.h"


class MyGUIController
{
public:
	MyGUIController();
	void intitalMyGUIController( Ogre::RenderWindow* Window , Ogre::SceneManager* SceneMgr);

	bool keyReleased( const OIS::KeyEvent &arg );
	bool keyPressed( const OIS::KeyEvent &arg);
	bool mouseMoved(const OIS::MouseEvent &arg);
	bool mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
	bool mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id);

	void loadlayout(Ogre::String layout);
	void unLoadlayout(Ogre::String layout);

	MyGUI::Gui* getGUI(){return mGUI;}
private:
	MyGUI::Gui* mGUI;
	MyGUI::VectorWidgetPtr mConsoleLayout;
	std::vector< std::pair<Ogre::String,MyGUI::VectorWidgetPtr> > layouts;
	
	MyGUI::VectorWidgetPtr findLayoutPtr(Ogre::String layout);
	bool deleteLayoutPtr(Ogre::String layout);
};


#endif