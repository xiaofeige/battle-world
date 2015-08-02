#ifndef __CHAPTER_CONTROLLER_H__
#define __CHAPTER_CONTEOLLER_H__

#include <functional>
#include "..\BaseScene.h"
#include "chapter1.h"

using namespace std;

typedef struct controller
{
	const char*					chapterName;
	function<BaseLayer*()>		callBack;
}ChapterControoler;


static ChapterControoler chapters[] =
{
	"保护公主楼", [](){return new Chapter1();}
};
#endif