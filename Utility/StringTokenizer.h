#ifndef __StringTokenizer_h_
#define __StringTokenizer_h_

//#include "stdafx.h"
#include <string>

class StringTokenizer
{
private:
	std::string src;
	std::string deli;
	std::string buffer;
	bool seperator;
	
	int nextStrState;
	int curPos;
	int srcLen;

	void construct( const std::string& src, const std::string& delimeter, bool seperator );
	void cutNextToken(void);
	bool isSeperator(char c);

public:

	StringTokenizer( const std::string& src, const std::string& delimeter );
	//! if seperator = true (default) : means using the delimeter as seperator
	//! if seperator = false, choose tokens which contains only seperators.
	StringTokenizer( const std::string& src, const std::string& delimeter, bool seperator );
	

	bool hasNext(void);
	std::string nextToken(void);

	static std::string trim( const std::string& src );
	static std::string trim( const std::string& src, const std::string& delimeters );

};

#endif