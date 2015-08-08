/****************************************************************************
Copyright (c) 2015 feihan inspiration.

http://www.flewawayblog.sinnapp.com

*descriptions:
this files contains functions that will be used in game,in other words,this is
a lib of functions

****************************************************************************/

#include "cocos2d.h"
#include <string>
USING_NS_CC;

/*---------------------------------------------------------------------------
*NAME:	toStr
*PARA:	T  any type will be okay
*DESC:	change any type of data to string
----------------------------------------------------------------------------*/
template <typename T> std::string tostr(const T& t)
{
	std::ostringstream os; os << t; return os.str();
}

/*---------------------------------------------------------------------------
*NAME:	getArrayLength
*PARA:	T  any type of array will be okay
*DESC:	get the length of array length (PS: will not work if the array is 
		created by "new")
----------------------------------------------------------------------------*/
template <typename T> int getArrayLength(const T& t)
{
	return sizeof(t) / sizeof(t[0]);
}

/*---------------------------------------------------------------------------
*NAME:	seekFromRootByName
*PARA:	Node*	_root:	search root of the csb file
		string&	name:	name of node,when you edit in cocostuio,you gave it a 
						name
*DESC:	select the very widget from csb file by name. In this way,you will no 
		longer be trouble to find the widget from csb file;
-----------------------------------------------------------------------------*/
Node* seekFromRootByName(Node* _root, std::string& name);