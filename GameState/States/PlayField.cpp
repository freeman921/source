#include "PlayField.h"
#include "../../Game.h"

PlayField::PlayField(Game *game) : GameState(game)
{
	pause = false;
	god_menu = false;
	setLayout();
	level = 0;
	difficulity = 0;

	game->mSoundManager->createSound("PlayFieldMusic", "giant_go.ogg", false, true, true);
	game->mSoundManager->getSound("PlayFieldMusic")->setVolume(0.25f);
	game->mSoundManager->getSound("PlayFieldMusic")->setMaxVolume(0.4);
	game->mSoundManager->getSound("PlayFieldMusic")->play();

	creatScene();
}

PlayField::~PlayField()
{
	game->mSoundManager->getSound("PlayFieldMusic")->stop(true);
	game->mSoundManager->destroySound("PlayFieldMusic");

	game->mGUI->unLoadlayout( "PlayField.layout" );
}

void PlayField::setLayout()
{
	game->mGUI->loadlayout( "PlayField.layout" );
	MyGUI::Gui* gui = game->mGUI->getGUI();

	MyGUI::Window *window;

	window = gui->findWidget<MyGUI::Window>("god_menu");
	window->eventWindowButtonPressed += MyGUI::newDelegate(this, &PlayField::handleWindow);
	window->setVisible(false);

	window = gui->findWidget<MyGUI::Window>("menu");
	window->setVisible(false);

	MyGUI::ButtonPtr button;
	button = gui->findWidget<MyGUI::Button>("Resume");
	button->eventMouseButtonClick += MyGUI::newDelegate(this,&PlayField::handleButton);
	
	button = gui->findWidget<MyGUI::Button>("Option");
	button->eventMouseButtonClick += MyGUI::newDelegate(this,&PlayField::handleButton);
	
	button = gui->findWidget<MyGUI::Button>("Back to Menu");
	button->eventMouseButtonClick += MyGUI::newDelegate(this,&PlayField::handleButton);

	button = gui->findWidget<MyGUI::Button>("Exit");
	button->eventMouseButtonClick += MyGUI::newDelegate(this,&PlayField::handleButton);

	MyGUI::ImageBox *image;
	image =  gui->findWidget<MyGUI::ImageBox>("player_pic");
	image->eventMouseButtonClick += MyGUI::newDelegate(this,&PlayField::handleButton);
}

void PlayField::creatScene()
{
	game->createScene_GameRound();
}
void PlayField::handleWindow(MyGUI::WidgetPtr _widget, const std::string& _name)
{
	game->mSoundManager->getSound("click")->play();
	
	if(_name == "close")
	{
		MyGUI::Gui* gui = game->mGUI->getGUI();
		MyGUI::WindowPtr window = gui->findWidget<MyGUI::Window>( _widget->getName() );
		god_menu = false;
		window->setVisible(false);
	}
	
}

void PlayField::handleButton(MyGUI::WidgetPtr sender)
{
	if (sender->getName() == "Resume")
	{
		MyGUI::Gui* gui = game->mGUI->getGUI();
		MyGUI::Window *window;
		window = gui->findWidget<MyGUI::Window>("menu");
		window->setVisible( !window->isVisible() );

		game->mSoundManager->getSound("click")->play();
		setPause(false);
		return ;
	}
	if (sender->getName() == "Option")
	{
		game->mSoundManager->getSound("click")->play();
	}
	if (sender->getName() == "Back to Menu")
	{
		game->mSoundManager->getSound("click")->play();
		game->mGSm->changeState(MAIN_MENU);
		return ;
	}
	if (sender->getName() == "Exit")
	{
		game->mSoundManager->getSound("click")->play();
		game->mShutDown = true;
	}

	if(pause) return;

	if (sender->getName() == "player_pic")
	{
		game->mSoundManager->getSound("click")->play();	

		MyGUI::Gui* gui = game->mGUI->getGUI();
		MyGUI::Window *window;
		window = gui->findWidget<MyGUI::Window>("god_menu");
		window->setVisible( !window->isVisible() );
		god_menu = true;
	}
}

bool PlayField::setLevel(int level)
{
	return true;
}

bool PlayField::frameStarted(const Ogre::FrameEvent& evt)
{
	if(pause) return true;


	game->scrollScreenDetermine();
	game->mCameraArr[GAME_SCENE]->setPosition(game->mCameraX,game->mCameraY,game->mCameraZ);

	// game settings

	game->mMM->update(evt);
	game->mBM->update(evt);
	game->mTM->update(evt);
	game->mMap->update(evt.timeSinceLastFrame);

	return true;
}

bool PlayField::keyPressed( const OIS::KeyEvent &arg )
{
	game->mGUI->keyReleased(arg);

	if( arg.key == OIS::KC_ESCAPE )
	{
		MyGUI::Gui* gui = game->mGUI->getGUI();
		MyGUI::Window *window;
		if(god_menu)
		{
			
			window = gui->findWidget<MyGUI::Window>("god_menu");
			window->setVisible( !window->isVisible() );
			god_menu = false;
		}
		else
		{
			window = gui->findWidget<MyGUI::Window>("menu");
			window->setVisible( !window->isVisible() );
			setPause( !getPause() );
		}

	}

	if(pause) return true;

	return true;
	//return game->BaseApplication::keyReleased(arg);
}
bool PlayField::keyReleased( const OIS::KeyEvent &arg )
{
	game->mGUI->keyReleased(arg);

	if(pause) return true;

	return true;
	//return game->BaseApplication::keyReleased(arg);
}

bool PlayField::mouseMoved( const OIS::MouseEvent &arg )
{
	game->mGUI->mouseMoved(arg);

	if(pause) return game->BaseApplication::mouseMoved(arg);
	
	return game->BaseApplication::mouseMoved(arg);
}
bool PlayField::mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
	game->mGUI->mousePressed(arg,id);

	if(pause) return game->BaseApplication::mousePressed( arg, id );

	return game->BaseApplication::mousePressed( arg, id );
}
bool PlayField::mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
	game->mGUI->mouseReleased(arg,id);

	if(pause) return game->BaseApplication::mouseReleased( arg, id );

	return game->BaseApplication::mouseReleased( arg, id );
}

void PlayField::setPause(bool p){pause = p;}

bool PlayField::getPause(){return pause;}