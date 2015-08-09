#ifndef __SELECT_VIEW_H__
#define __SELECT_VIEW_H__

#include "cocos2d.h"
#include "GameScenes\ChapterController.h"

/*----------------------------------------------------------------------------------
*CLASS NAME£ºSelectView
*DESC: table for player to choose which chapter he(she) would to play.
------------------------------------------------------------------------------------*/
class SelectView 
	: public cocos2d::Layer
	, public cocos2d::extension::TableViewDataSource
	, public cocos2d::extension::TableViewDelegate
{
public:

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	//
	//pure virtual functions that need to be overrided
	virtual void scrollViewDidScroll(cocos2d::extension::ScrollView* view) {};
	virtual void scrollViewDidZoom(cocos2d::extension::ScrollView* view) {}
	virtual void tableCellTouched(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell);
	virtual cocos2d::Size tableCellSizeForIndex(cocos2d::extension::TableView *table, ssize_t idx);
	virtual cocos2d::extension::TableViewCell* tableCellAtIndex(cocos2d::extension::TableView *table, ssize_t idx);
	virtual ssize_t numberOfCellsInTableView(cocos2d::extension::TableView *table);

	// implement the "static create()" method manually
	CREATE_FUNC(SelectView);

	//get tableView point
	cocos2d::extension::TableView*	getTableView(){ return m_chapterTable; }
private:
	//do not allowed to be accessed outside
	SelectView();
	~SelectView();

	//member variables
	int										m_gateNum;
	cocos2d::Size							m_cellSize;
	cocos2d::extension::TableView*			m_chapterTable;
};

#endif // __SELECT_VIEW_H__