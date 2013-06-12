#include "ScorePage.h"


ScorePage::ScorePage(Game *game) : GameState(game)
{
	this->game = game;
}

bool ScorePage::setLevel(int level)
{
	return true;
}

bool ScorePage::frameStarted(const Ogre::FrameEvent& evt)
{
	return true;
}

bool ScorePage::keyPressed( const OIS::KeyEvent &arg )
{
	return true;
}
bool ScorePage::keyReleased( const OIS::KeyEvent &arg )
{
	return true;
}

bool ScorePage::mouseMoved( const OIS::MouseEvent &arg )
{
	return true;
}
bool ScorePage::mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
	return true;
}
bool ScorePage::mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
	return true;
}