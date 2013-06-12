#include "GameStateManager.h"
#include "../Game.h"

GameStateManager::GameStateManager(Game *game)
{
	this->game = game;
	next_state_num =-1;
	now_state = NULL;
	level = -1;
}
bool  GameStateManager::_changeState(STATE new_state,int level,int difficulity)
{

	if(now_state!=NULL) delete(now_state);

	if(new_state == MAIN_MENU )
	{
		now_state = new MainMenu(game);
		return true;
	}
	if(new_state == LEVEL_SELECTION_MENU )
	{
		now_state = new LevelSelectionMenu(game);
		return true;
	}
	if(new_state == GAME_STORY )
	{
		now_state = new GameStory(game);
		now_state->setLevel(level);
		now_state->setDifficulity(difficulity);
		return true;
	}
	if(new_state == PLAY_FIELD )
	{
		now_state = new PlayField(game);
		now_state->setLevel(level);
		now_state->setDifficulity(difficulity);
		return true;
	}
	if(new_state == SCORE_PAGE )
	{
		now_state = new ScorePage(game);
		now_state->setLevel(level);
		now_state->setDifficulity(difficulity);
		return true;
	}

	return false;
}

bool  GameStateManager::changeState(STATE new_state,int level,int difficulity)
{
	next_state_num = (int)new_state;
	next_level = level;
	next_difficulity = difficulity;

	return true;
}

bool GameStateManager::setLevel(int level)
{
	if(	now_state==NULL	) return false;

	return now_state->setLevel(level);
/*
	if(state_num == MAIN_MENU )
	{
		return ((MainMenu*)now_state)->setLevel(level);
	}
	if(state_num == LEVEL_SELECTION_MENU )
	{
		return ((LevelSelectionMenu*)now_state)->setLevel(level);
	}
	if(state_num == GAME_STORY )
	{
		return ((GameStory*)now_state)->setLevel(level);
	}
	if(state_num == PLAY_FIELD )
	{
		return ((GameStory*)now_state)->setLevel(level);
	}
	if(state_num == SCORE_PAGE )
	{
		return ((ScorePage*)now_state)->setLevel(level);
	}
	return false;
*/
}
	

bool GameStateManager::frameStarted(const Ogre::FrameEvent& evt)
{

	if(next_state_num != -1)
	{
		_changeState( (STATE)next_state_num,next_level,next_difficulity);
		next_state_num=-1;
	}


	if(now_state==NULL) return false;

	return now_state->frameStarted(evt);
/*
	if(state_num == MAIN_MENU )
	{
		return ((MainMenu*)now_state)->frameStarted(evt);
	}
	if(state_num == LEVEL_SELECTION_MENU )
	{
		return ((LevelSelectionMenu*)now_state)->frameStarted(evt);
	}
	if(state_num == GAME_STORY )
	{
		return ((GameStory*)now_state)->frameStarted(evt);
	}
	if(state_num == PLAY_FIELD )
	{
		return ((GameStory*)now_state)->frameStarted(evt);
	}
	if(state_num == SCORE_PAGE )
	{
		return ((ScorePage*)now_state)->frameStarted(evt);
	}
	return false;
*/
}
// OIS::KeyListener
bool GameStateManager::keyPressed( const OIS::KeyEvent &arg )
{
	if(now_state==NULL) return false;

	return now_state->keyPressed(arg);
/*
	if(state_num == MAIN_MENU )
	{
		return ((MainMenu*)now_state)->keyPressed(arg);
	}
	if(state_num == LEVEL_SELECTION_MENU )
	{
		return ((LevelSelectionMenu*)now_state)->keyPressed(arg);
	}
	if(state_num == GAME_STORY )
	{
		return (((GameStory*)now_state))->keyPressed(arg);
	}
	if(state_num == PLAY_FIELD )
	{
		return ((GameStory*)now_state)->keyPressed(arg);
	}
	if(state_num == SCORE_PAGE )
	{
		return ((ScorePage*)now_state)->keyPressed(arg);
	}
	return false;
*/
}
bool GameStateManager::keyReleased( const OIS::KeyEvent &arg )
{
	if(now_state==NULL) return false;

	return now_state->keyReleased(arg);
/*
	if(state_num == MAIN_MENU )
	{
		return ((MainMenu*)now_state)->keyReleased(arg);
	}
	if(state_num == LEVEL_SELECTION_MENU )
	{
		return ((LevelSelectionMenu*)now_state)->keyReleased(arg);
	}
	if(state_num == GAME_STORY )
	{
		return ((GameStory*)now_state)->keyReleased(arg);
	}
	if(state_num == PLAY_FIELD )
	{
		return ((GameStory*)now_state)->keyReleased(arg);
	}
	if(state_num == SCORE_PAGE )
	{
		return ((ScorePage*)now_state)->keyReleased(arg);
	}
	return false;
*/
}
// OIS::MouseListener
bool GameStateManager::mouseMoved( const OIS::MouseEvent &arg )
{
	if(now_state==NULL) return false;

	return now_state->mouseMoved(arg);

/*	
	if(state_num == MAIN_MENU )
	{
		return ((MainMenu*)now_state)->mouseMoved(arg);
	}
	if(state_num == LEVEL_SELECTION_MENU )
	{
		return ((LevelSelectionMenu*)now_state)->mouseMoved(arg);
	}
	if(state_num == GAME_STORY )
	{
		return ((GameStory*)now_state)->mouseMoved(arg);
	}
	if(state_num == PLAY_FIELD )
	{
		return ((GameStory*)now_state)->mouseMoved(arg);
	}
	if(state_num == SCORE_PAGE )
	{
		return ((ScorePage*)now_state)->mouseMoved(arg);
	}
	return false;
*/	
}
bool GameStateManager::mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
	if(now_state==NULL) return false;

	return now_state->mousePressed(arg,id);

/*	
	if(state_num == MAIN_MENU )
	{
		return ((MainMenu*)now_state)->mousePressed(arg,id);
	}
	if(state_num == LEVEL_SELECTION_MENU )
	{
		return ((LevelSelectionMenu*)now_state)->mousePressed(arg,id);
	}
	if(state_num == GAME_STORY )
	{
		return ((GameStory*)now_state)->mousePressed(arg,id);
	}
	if(state_num == PLAY_FIELD )
	{
		return ((GameStory*)now_state)->mousePressed(arg,id);
	}
	if(state_num == SCORE_PAGE )
	{
		return ((ScorePage*)now_state)->mousePressed(arg,id);
	}
	return false;
*/	
}
bool GameStateManager::mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
	if(now_state==NULL) return false;

	return now_state->mouseReleased(arg,id);

/*	
	if(state_num == MAIN_MENU )
	{
		return ((MainMenu*)now_state)->mouseReleased(arg,id);
	}
	if(state_num == LEVEL_SELECTION_MENU )
	{
		return ((LevelSelectionMenu*)now_state)->mouseReleased(arg,id);
	}
	if(state_num == GAME_STORY )
	{
		return ((GameStory*)now_state)->mouseReleased(arg,id);
	}
	if(state_num == PLAY_FIELD )
	{
		return ((GameStory*)now_state)->mouseReleased(arg,id);
	}
	if(state_num == SCORE_PAGE )
	{
		return ((ScorePage*)now_state)->mouseReleased(arg,id);
	}
	return false;
*/	
}


bool GameStateManager::setDifficulity(int difficulity)
{
	if(now_state==NULL) return false;

	return now_state->setDifficulity(difficulity);

/*	
	if(state_num == MAIN_MENU )
	{
		return ((MainMenu*)now_state)->setDifficulity(difficulity);
	}
	if(state_num == LEVEL_SELECTION_MENU )
	{
		return ((LevelSelectionMenu*)now_state)->setDifficulity(difficulity);
	}
	if(state_num == GAME_STORY )
	{
		return ((GameStory*)now_state)->setDifficulity(difficulity);
	}
	if(state_num == PLAY_FIELD )
	{
		return ((GameStory*)now_state)->setDifficulity(difficulity);
	}
	if(state_num == SCORE_PAGE )
	{
		return ((ScorePage*)now_state)->setDifficulity(difficulity);
	}
	return false;
	*/
}