#include "StringTokenizer.h"
#include <iostream>
using namespace std;

#define	NOT_DECIDED	0
#define	OK			1
#define	FAIL		2


StringTokenizer::StringTokenizer( const string& src, const string& delimeter) { construct(src,delimeter,true); }
StringTokenizer::StringTokenizer( const string& src, const string& delimeter, bool seperator ) { construct(src,delimeter,seperator); }

void StringTokenizer::construct( const string& src, const string& delimeter, bool seperator )
{
	this->src = src;
	this->deli = delimeter;
	srcLen = src.length();
	buffer.reserve( srcLen );
	this->seperator = seperator;

	nextStrState = NOT_DECIDED;
	curPos = 0;
}

bool StringTokenizer::hasNext(void)
{
	if ( nextStrState==NOT_DECIDED )
		cutNextToken();

	if ( nextStrState==OK )
		return true;
	else if ( nextStrState==FAIL )
		return false;
	
	cerr << "hasNext() Wrong." << endl;
	return false;
}

string StringTokenizer::nextToken(void)
{
	if ( nextStrState==NOT_DECIDED )
		cutNextToken();

	if (nextStrState==OK)
	{
		nextStrState = NOT_DECIDED;
		return buffer;
	}
	else if ( nextStrState==FAIL )
		return "";
	else
		cerr << "nextToken() Wrong." << endl;
	return "";
}

void StringTokenizer::cutNextToken(void)
{
	buffer.clear();
	bool tokenAppeared = false;

	for (; curPos!=srcLen ;curPos++ ) // until source came to the end
	{
		if ( ! isSeperator(src[curPos]) )
		{
			tokenAppeared=true;
			buffer += src[curPos];
		}
		else if ( tokenAppeared==true ) // isSeperator & Token appeared
			break;
	}

	if ( buffer.empty() ) // haven't found the next token
		nextStrState = FAIL;
	else
		nextStrState = OK;

}

bool StringTokenizer::isSeperator(char c)
{
	unsigned int i;

	if (seperator==true)
	{
		for (i=0; i< deli.size();i++ )
			if ( c==deli[i] )
				return true;
		return false;
	}
	else
	{
		for (i=0; i< deli.size();i++ )
			if ( c==deli[i] )
				return false;
		return true;
	}

	
}

string StringTokenizer::trim( const std::string& src ) { return trim(src," "); }
string StringTokenizer::trim( const std::string& src, const string& delimeters )
{
	int i,k,start=0, end=0 ;
	int srcSize = (int)src.size();

	for (i=0; i<srcSize;i++ )
	{
		bool isDeli =false;
		for (k=0; k<delimeters.size();k++)
		{
			if ( src[i] == delimeters[k] )
			{
				isDeli = true;
				break;
			}
		}
		if (isDeli==false)
		{
			start = i;
			break;
		}
	}

	for ( i = srcSize-1 ; i>=0 ;i-- )
	{
		bool isDeli =false;
		for (k=0; k<delimeters.size();k++)
		{
			if ( src[i] == delimeters[k] )
			{
				isDeli = true;
				break;
			}
		}
		if (isDeli==false)
		{
			end = i;
			break;
		}
	}
	

	if (start==0 && end==0)
		return "";
	return src.substr(start,end-start+1);
}
