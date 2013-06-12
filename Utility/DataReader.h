#ifndef __DataReader_h_
#define __DataReader_h_

#include <fstream>
#include <sstream> 
#include <iostream>
#include <string>
#include <map>
#include "StringTokenizer.h"

#define NAME_SIZE	100
#define	DEFAULT_CATEGORY	"Default"


class DataReader
{
private:
	std::ifstream *filePt;
	std::string fileName;
	std::map< std::string , std::string> *curVarMap;
	std::map< std::string , std::map< std::string , std::string>* > mapMap;
	
	void readInDataFromFile();
	void saveVar( const std::string& line);
	void switchToNewCategory( const std::string& line);

public:
	DataReader(); // no use

	//! Remember to init(create) !!!
	void create(const char*);

	//!!!!!!  OverWrite this function to give it the output stream !!!!!
	virtual void log( const std::string &msg );
	void logError( const std::string &msg );

	//! category=[xxx] , name=parameter name
	//! Will log Message if Var not Exist or Conversion Error occured.
	std::string getByString( const std::string& category, const std::string& name );
	int getByInt( const std::string& category, const std::string& name );
	double getByDouble( const std::string& category, const std::string& name );
};

#endif