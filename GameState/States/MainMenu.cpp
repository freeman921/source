#include "MainMenu.h"
#include "../../Game.h"

MainMenu::MainMenu(Game *game) : GameState(game)
{
	setLayout();
	
	game->mSoundManager->createSound("mainMenuMusic", "Akkadian Empire.ogg", false, true, true);
	game->mSoundManager->getSound("mainMenuMusic")->setVolume(0.25f);
	game->mSoundManager->getSound("mainMenuMusic")->setMaxVolume(0.4);
	game->mSoundManager->getSound("mainMenuMusic")->play();
}
void MainMenu::setLayout()
{
	game->mGUI->loadlayout( "testMainMenu.layout" );
	MyGUI::Gui* gui = game->mGUI->getGUI();
	
	//put every button into listener 
	MyGUI::ButtonPtr button = gui->findWidget<MyGUI::Button>("start");
	button->eventMouseButtonClick += MyGUI::newDelegate(this,&MainMenu::handleButton);

	button = gui->findWidget<MyGUI::Button>("option");
	button->eventMouseButtonClick += MyGUI::newDelegate(this,&MainMenu::handleButton);

	button = gui->findWidget<MyGUI::Button>("about");
	button->eventMouseButtonClick += MyGUI::newDelegate(this,&MainMenu::handleButton);

	button = gui->findWidget<MyGUI::Button>("exit");
	button->eventMouseButtonClick += MyGUI::newDelegate(this,&MainMenu::handleButton);

}

void MainMenu::handleButton(MyGUI::WidgetPtr sender)
{
	if (sender->getName() == "start")
	{
		game->mSoundManager->getSound("click")->play();
		game->mGSm->changeState(LEVEL_SELECTION_MENU);
	}
	else if (sender->getName() == "option")
	{
		game->mSoundManager->getSound("click")->play();
	}
	else if (sender->getName() == "about")
	{
		game->mSoundManager->getSound("click")->play();
	}
	else if (sender->getName() == "exit")
	{
		game->mSoundManager->getSound("click")->play();
		game->mShutDown = true;
	}
}

MainMenu::~MainMenu()
{
	game->mSoundManager->getSound("mainMenuMusic")->stop(true);
	game->mSoundManager->destroySound("mainMenuMusic");

	game->mGUI->unLoadlayout( "testMainMenu.layout" );
}

bool MainMenu::setLevel(int level)
{
	return true;
}

bool MainMenu::frameStarted(const Ogre::FrameEvent& evt)
{
	return true;
}

bool MainMenu::keyPressed( const OIS::KeyEvent &arg )
{
	if(arg.key == OIS::KC_0)
    {
        
    }

	

	return true;
}
bool MainMenu::keyReleased( const OIS::KeyEvent &arg )
{
	return true;
}

bool MainMenu::mouseMoved( const OIS::MouseEvent &arg )
{
	game->mGUI->mouseMoved(arg);
	return game->BaseApplication::mouseMoved(arg);
}
bool MainMenu::mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
	game->mGUI->mousePressed(arg,id);
	return game->BaseApplication::mousePressed( arg, id );
}
bool MainMenu::mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
	game->mGUI->mouseReleased(arg,id);
	return game->BaseApplication::mouseReleased( arg, id );
}