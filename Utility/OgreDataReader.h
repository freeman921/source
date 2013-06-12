#ifndef __OgreDataReader_h_
#define __OgreDataReader_h_

#include "DataReader.h"
#include <OgreLogManager.h>


class OgreDataReader : public DataReader
{
public:
	OgreDataReader() {}

	void log( const std::string &msg ) override
	{
		//std::cout << "==DataReader== " << msg << std::endl;
		Ogre::LogManager::getSingletonPtr()->logMessage( "==DataReader== "+msg );
	}

};

#endif