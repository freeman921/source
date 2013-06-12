#include "MyGUIController.h"
#include "../Game.h"

MyGUIController::MyGUIController()
{

}

void MyGUIController::intitalMyGUIController( Ogre::RenderWindow *Window , Ogre::SceneManager *SceneMgr)
{
	MyGUI::OgrePlatform* mPlatform = new MyGUI::OgrePlatform();
	mPlatform->initialise(Window, SceneMgr);
	mGUI = new MyGUI::Gui();
	mGUI->initialise();
	mGUI->hidePointer();
}

bool MyGUIController::keyReleased( const OIS::KeyEvent &arg )
{
	return MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::Enum(arg.key));
}
bool MyGUIController::keyPressed( const OIS::KeyEvent &arg)
{
	return MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Enum(arg.key), arg.text);
}
bool MyGUIController::mouseMoved(const OIS::MouseEvent &arg)
{
	return MyGUI::InputManager::getInstance().injectMouseMove(arg.state.X.abs, arg.state.Y.abs, arg.state.Z.abs);
}
bool MyGUIController::mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	return MyGUI::InputManager::getInstance().injectMousePress(arg.state.X.abs, arg.state.Y.abs, MyGUI::MouseButton::Enum(id));
}
bool MyGUIController::mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	return MyGUI::InputManager::getInstance().injectMouseRelease(arg.state.X.abs, arg.state.Y.abs, MyGUI::MouseButton::Enum(id));
}

void MyGUIController::loadlayout(Ogre::String layout)
{

	MyGUI::VectorWidgetPtr new_layout = MyGUI::LayoutManager::getInstance().load( layout );
	
	std::pair<Ogre::String,MyGUI::VectorWidgetPtr> new_pair;
	new_pair.first = layout;
	new_pair.second = new_layout;

	layouts.push_back( new_pair );
}

void MyGUIController::unLoadlayout(Ogre::String layout)
{
	//MyGUI::VectorWidgetPtr ptr = findLayoutPtr(layout);
	//MyGUI::VectorWidgetPtr::iterator itr;
	//for(itr = ptr.begin() ; itr != ptr.end() ; itr++ ){ (*itr)->setVisible(false);  }

	MyGUI::LayoutManager::getInstance().unloadLayout( findLayoutPtr(layout) );
	deleteLayoutPtr(layout);
}

MyGUI::VectorWidgetPtr MyGUIController::findLayoutPtr(Ogre::String layout)
{
	std::vector< std::pair<Ogre::String,MyGUI::VectorWidgetPtr> >::iterator itr;
	for(itr=layouts.begin(); itr!=layouts.end(); itr++)
	{
		if( itr->first == layout )
		{
			return itr->second;
		} 
	}

	return layouts.begin()->second;

}

bool MyGUIController::deleteLayoutPtr(Ogre::String layout)
{
	std::vector< std::pair<Ogre::String,MyGUI::VectorWidgetPtr> >::iterator itr;
	for(itr=layouts.begin(); itr!=layouts.end(); itr++)
	{
		if( itr->first == layout )
		{
			layouts.erase(itr);
			return true;
		} 
	}
	return false;
}