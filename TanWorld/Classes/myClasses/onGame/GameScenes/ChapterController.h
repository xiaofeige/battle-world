#ifndef __CHAPTER_CONTROLLER_H__
#define __CHAPTER_CONTEOLLER_H__

#include <functional>
#include "chapter1.h"

using namespace std;
/*------------------------------------------------------------------------------
	NAME:�½ڿ�����
	DESC:�������½ڼ��ϵ�һ�������У����ó���ͨ�������±����
	USAGE�� chapters[idx].callBack()->runThisChapter()
--------------------------------------------------------------------------------*/
typedef struct controller
{
	const char*					chapterName;		//�½�����
	const char*					chapterLookPath;	//�½�Ԥ��ͼ��ַ
	function<BaseLayer*()>		callBack;			//�½ڵ�����
}ChapterControoler;


static ChapterControoler chapters[] =
{
	{ "protect princess-apartment of CUG", "pic/chapterTest.png", [](){return Chapter1::create(); } }
};
#endif

