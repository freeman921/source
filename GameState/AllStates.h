
#ifndef __AllStates_h__
#define __AllStates_h__

#include "States/GameStory.h"
#include "States/LevelSelectionMenu.h"
#include "States/MainMenu.h"
#include "States/PlayField.h"
#include "States/ScorePage.h"
#include "GameState.h"

typedef enum{
	MAIN_MENU = 0,
	LEVEL_SELECTION_MENU = 1,
	GAME_STORY = 2,
	PLAY_FIELD = 3,
	SCORE_PAGE = 4
}STATE;

#endif //__AllStates_h__