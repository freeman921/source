#include "LevelSelectionMenu.h"
#include "../../Game.h"

const int LevelSelectionMenu::MAX_LEVEL = 1;

LevelSelectionMenu::LevelSelectionMenu(Game *game) : GameState( game )
{
	setLayout();

	game->mSoundManager->createSound("LeveSelectMusic", "Battle.ogg", false, true, true);
	game->mSoundManager->getSound("LeveSelectMusic")->setVolume(0.25f);
	game->mSoundManager->getSound("LeveSelectMusic")->setMaxVolume(0.4);
	game->mSoundManager->getSound("LeveSelectMusic")->play();	

	setLevel( 0 );
}

void LevelSelectionMenu::setLayout()
{
	game->mGUI->loadlayout( "LevelSelect.layout" );
	MyGUI::Gui* gui = game->mGUI->getGUI();
	
	//put every button into listener 
	MyGUI::ButtonPtr button = gui->findWidget<MyGUI::Button>("start");
	button->eventMouseButtonClick += MyGUI::newDelegate(this,&LevelSelectionMenu::handleButton);

	button = gui->findWidget<MyGUI::Button>("last");
	button->eventMouseButtonClick += MyGUI::newDelegate(this,&LevelSelectionMenu::handleButton);

	button = gui->findWidget<MyGUI::Button>("next");
	button->eventMouseButtonClick += MyGUI::newDelegate(this,&LevelSelectionMenu::handleButton);

	button = gui->findWidget<MyGUI::Button>("back");
	button->eventMouseButtonClick += MyGUI::newDelegate(this,&LevelSelectionMenu::handleButton);


	MyGUI::ComboBoxPtr combobox = gui->findWidget<MyGUI::ComboBox>("difficulty");
	combobox->setIndexSelected( 0 );

}

void LevelSelectionMenu::handleButton(MyGUI::WidgetPtr sender)
{
	if (sender->getName() == "start")
	{
		MyGUI::Gui* gui = game->mGUI->getGUI();

		game->mSoundManager->getSound("click")->play();

		MyGUI::ComboBoxPtr combobox = gui->findWidget<MyGUI::ComboBox>("difficulty");
		unsigned int id = combobox->getItemIndexSelected();
		
		std::cout<<"defficulity:"<<(int)id<<std::endl;
		std::cout<<"level:"<<level<<std::endl;

		game->mGSm->changeState(GAME_STORY,level,(int)id);

		return ;
	}
	else if (sender->getName() == "last")
	{
		setLevel( level - 1 );
		game->mSoundManager->getSound("click")->play();
	}
	else if (sender->getName() == "next")
	{
		setLevel( level + 1 );
		game->mSoundManager->getSound("click")->play();
	}
	else if (sender->getName() == "back")
	{
		game->mSoundManager->getSound("click")->play();
		game->mGSm->changeState(MAIN_MENU);
	}

}

LevelSelectionMenu::~LevelSelectionMenu()
{
	game->mSoundManager->getSound("LeveSelectMusic")->stop(true);
	game->mSoundManager->destroySound("LeveSelectMusic");

	game->mGUI->unLoadlayout( "LevelSelect.layout" );
}

bool LevelSelectionMenu::setLevel(int lv)
{
	if( lv < 0 || lv > MAX_LEVEL ) return false;

	level = lv;
	MyGUI::Gui* gui = game->mGUI->getGUI();
	MyGUI::ImageBox* image = gui->findWidget<MyGUI::ImageBox>("pic_level");
	
	switch(level)
	{
	case 0:
		image->setImageTexture("pic_level_0.png");
		break;
	case 1:
		image->setImageTexture("pic_level_1.png");
		break;
	default:
		break;
	}
	
	return true;
}


bool LevelSelectionMenu::frameStarted(const Ogre::FrameEvent& evt)
{
	return true;
}

bool LevelSelectionMenu::keyPressed( const OIS::KeyEvent &arg )
{
	return true;
}
bool LevelSelectionMenu::keyReleased( const OIS::KeyEvent &arg )
{
	return true;
}

bool LevelSelectionMenu::mouseMoved( const OIS::MouseEvent &arg )
{
	game->mGUI->mouseMoved(arg);
	return game->BaseApplication::mouseMoved(arg);
}
bool LevelSelectionMenu::mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
	game->mGUI->mousePressed(arg,id);
	return game->BaseApplication::mousePressed( arg, id );
}
bool LevelSelectionMenu::mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
	game->mGUI->mouseReleased(arg,id);
	return game->BaseApplication::mouseReleased( arg, id );
}