
#include "DataReader.h"
using namespace std;

DataReader::DataReader() {}

void DataReader::create(const char* fname)
{
	fileName = string(fname);
	filePt = new ifstream( fname , ios::in | ios::binary);

	if (filePt == 0 || filePt->fail() ) 
	{
		string msg= "*** Cannot open file ("; 
		msg.append( fileName );
		msg.append( ") ***" ); 
		//Ogre::LogManager::getSingletonPtr()->stream() << "Cannot open file (" << fileName << ")";
		log(msg);
	}
	else
	{
		string msg= "FILE ("; 
		msg.append( fileName );
		msg.append( ") opened successful." );
			//Ogre::LogManager::getSingletonPtr()->logMessage( msg );
		log(msg);
	}

	readInDataFromFile();
}

void DataReader::log( const std::string &msg )
{
	cout << "==DataReader== " +msg << endl;
	//Ogre::LogManager::getSingletonPtr()->logMessage( msg );
	//Ogre::LogManager::getSingletonPtr()->logMessage( msg, Ogre::LML_CRITICAL );
}

void DataReader::logError( const std::string &msg )
{
	log(" !!Error!! "+msg);
}

void DataReader::readInDataFromFile()
{
	string line;
	curVarMap = new map< std::string , std::string>();
	mapMap[ DEFAULT_CATEGORY ] = curVarMap;

	while ( getline(*filePt,line) )
	{
		line = StringTokenizer::trim(line," \r\t");
		if ( line.empty() )
			continue; // scan next Line

		size_t leftBracePos = line.find('[',0);

		// '[' found = New Category.
		if ( leftBracePos != string::npos )
			switchToNewCategory(line);
		else
			saveVar(line);

	}
}

void DataReader::saveVar( const string& line)
{
	StringTokenizer st(line,"= ");

	if ( ! st.hasNext() )
		logError( "Error: "+line );
	string var = st.nextToken();

	if ( ! st.hasNext() )
		logError( "Error: "+line );
	string value = st.nextToken();
	
	(*curVarMap)[ var ] = value;
	log("Read "+var+'('+value+')');
}

void DataReader::switchToNewCategory( const string& line)
{
	StringTokenizer st(line," []");
	if ( !st.hasNext() )
		logError("DataReader : [Category] Error.");
	
	curVarMap = new map< std::string , std::string>();
	mapMap[ st.nextToken() ] = curVarMap;
}

string DataReader::getByString(const string& category, const string &name)
{
	map< std::string , std::string> *varMap = mapMap[category];

	if ( varMap->find(name)== varMap->end() )
		logError( "Var not found : [" + category + "] " + name );

	return (*varMap)[name];
}

int DataReader::getByInt(const string& category, const string &name)
{
	stringstream ss( getByString(category,name) );
	int result;
	ss >> result ;

	if ( ss.fail() )
	{
		logError( "Variable conversion Error (to int) : [" + category + "] " + name );
		return 0;
	}
	return result;
}

double DataReader::getByDouble(const string& category, const string &name)
{
	stringstream ss( getByString(category,name) );
	float result;
	ss >> result ;

	if ( ss.fail() )
	{
		logError( "Variable conversion Error (to double) : [" + category + "] " + name );
		return 0.0;
	}
	return result;
}



