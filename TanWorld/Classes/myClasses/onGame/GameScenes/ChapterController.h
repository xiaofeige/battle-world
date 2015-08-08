#ifndef __CHAPTER_CONTROLLER_H__
#define __CHAPTER_CONTEOLLER_H__

#include <functional>
#include "chapter1.h"

using namespace std;
/*------------------------------------------------------------------------------
	NAME:章节控制器
	DESC:将所有章节集合到一个数组中，调用场景通过数组下标完成
	USAGE： chapters[idx].callBack()->runThisChapter()
--------------------------------------------------------------------------------*/
typedef struct controller
{
	const char*					chapterName;		//章节名称
	const char*					chapterLookPath;	//章节预览图地址
	function<BaseLayer*()>		callBack;			//章节调用器
}ChapterControoler;


static ChapterControoler chapters[] =
{
	{ "protect princess-apartment of CUG", "pic/chapterTest.png", [](){return Chapter1::create(); } }
};
#endif

