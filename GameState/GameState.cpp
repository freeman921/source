#include "GameState.h"

GameState::GameState(Game *game)
{
	this->game = game;
	difficulity = 0;
	level = 0;
}

GameState::~GameState()
{
}
bool GameState::setDifficulity(int d)
{
	difficulity =d;
	return true;
}

bool GameState::setLevel(int level)
{
	return true;
}


bool GameState::frameStarted(const Ogre::FrameEvent& evt)
{
	return true;
}

bool GameState::keyPressed( const OIS::KeyEvent &arg )
{
	return true;
}
bool GameState::keyReleased( const OIS::KeyEvent &arg )
{
	return true;
}

bool GameState::mouseMoved( const OIS::MouseEvent &arg )
{
	return true;
}
bool GameState::mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
	return true;
}
bool GameState::mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
	return true;
}