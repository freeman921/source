#include "GameStory.h"
#include "../../Game.h"

GameStory::GameStory(Game *game) : GameState( game )
{
	setLayout();
	level = 0;
	difficulity = 0;

	game->mTrayMgr->hideCursor();
}

void GameStory::setLayout()
{
	game->mGUI->loadlayout( "GameStory.layout" );
}

void GameStory::handleButton(MyGUI::WidgetPtr sender)
{

}

GameStory::~GameStory()
{
	game->mSoundManager->getSound("GameStoryMusic")->stop(true);
	game->mSoundManager->destroySound("GameStoryMusic");

	game->mGUI->unLoadlayout( "GameStory.layout" );

	game->mTrayMgr->showCursor();
}

bool GameStory::setLevel(int level)
{
	this->level = level;
	switch(level)
	{
		case 0:
			pic_queue.push( "Lv1_storyboard_0.png" );
			pic_queue.push( "Lv1_storyboard_1.png" );
			pic_queue.push( "Lv1_storyboard_2.png" );
			pic_queue.push( "Lv1_storyboard_3.png" );
			pic_queue.push( "Lv1_storyboard_4.png" );
			
			game->mSoundManager->createSound("GameStoryMusic", "Battle.ogg", false, true, true);
			game->mSoundManager->getSound("GameStoryMusic")->setVolume(0.25f);
			game->mSoundManager->getSound("GameStoryMusic")->setMaxVolume(0.4);
			game->mSoundManager->getSound("GameStoryMusic")->play();
			break;
		case 1:
			pic_queue.push( "Lv2_storyboard_0.png" );
			pic_queue.push( "Lv2_storyboard_1.png" );
			pic_queue.push( "Lv2_storyboard_2.png" );
			pic_queue.push( "Lv2_storyboard_3.png" );
			pic_queue.push( "Lv2_storyboard_4.png" );

			game->mSoundManager->createSound("GameStoryMusic", "Battle.ogg", false, true, true);
			game->mSoundManager->getSound("GameStoryMusic")->setVolume(0.25f);
			game->mSoundManager->getSound("GameStoryMusic")->setMaxVolume(0.4);
			game->mSoundManager->getSound("GameStoryMusic")->play();
			break;
	}

	Ogre::String name = pic_queue.front();
	pic_queue.pop();
	MyGUI::Gui* gui = game->mGUI->getGUI();
	MyGUI::ImageBox* img = gui->findWidget<MyGUI::ImageBox>("pic");
	img->setImageTexture( name );
	img->setVisible(true);

	return true;
}

bool GameStory::frameStarted(const Ogre::FrameEvent& evt)
{
	return true;
}

bool GameStory::keyPressed( const OIS::KeyEvent &arg )
{
	return true;
}
bool GameStory::keyReleased( const OIS::KeyEvent &arg )
{
	return true;
}

bool GameStory::mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
	if( pic_queue.empty() )
	{
		game->mGSm->changeState(PLAY_FIELD,level,difficulity);

		return true;
	}


	Ogre::String name = pic_queue.front();
	pic_queue.pop();
	MyGUI::Gui* gui = game->mGUI->getGUI();
	MyGUI::ImageBox* img = gui->findWidget<MyGUI::ImageBox>("pic");
	img->setImageTexture( name );
	img->setVisible(true);

	return true;
}