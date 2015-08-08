#include "SelectView.h"
#include "..\GameHandleLib.h"

USING_NS_CC_EXT;

SelectView::SelectView()
:m_gateNum(0)
,m_cellSize(Size(0,0))
{

}

SelectView::~SelectView()
{

}

bool SelectView::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = VisibleRect::getVisibleRect().size;

	//caculate table cell size
	m_cellSize = Size(visibleSize.width/5,visibleSize.height*3/5);

	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	//add table to this view	
	TableView* tableView = TableView::create(this, Size(m_cellSize.width*3, m_cellSize.height));
	tableView->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	tableView->setDirection(extension::ScrollView::Direction::HORIZONTAL);
	tableView->setPosition(VisibleRect::center());
	tableView->setDelegate(this);
	tableView->setZOrder(2);
	this->addChild(tableView);
	tableView->reloadData();


	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(SelectView::menuCloseCallback, this));

	closeItem->setPosition(Vec2(visibleSize.width/2,visibleSize.height/10));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	return true;
}


void SelectView::menuCloseCallback(cocos2d::Ref* pSender)
{
	this->removeFromParentAndCleanup(true); 
}



/*--------------------------------------------------------------------------*/
/*-------------------override methods of tableview--------------------------*/
/*--------------------------------------------------------------------------*/
void SelectView::tableCellTouched(TableView* table, TableViewCell* cell)
{
	auto idx = cell->getIdx();
	chapters[idx].callBack()->runThisChapter();
}

Size SelectView::tableCellSizeForIndex(TableView *table, ssize_t idx)
{
	return m_cellSize;
}

TableViewCell* SelectView::tableCellAtIndex(TableView *table, ssize_t idx)
{
	TableViewCell *cell = table->dequeueCell();
	if (!cell) {
		cell = new (std::nothrow) TableViewCell();
		cell->autorelease();
		auto sprite = Sprite::create(chapters[idx].chapterLookPath); //load background of each cell
		sprite->setScaleX(this->getContentSize().width*m_cellSize.width/this->getContentSize().width);
		sprite->setScaleY(this->getContentSize().height*m_cellSize.height/this->getContentSize().height);
		sprite->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
		sprite->setPosition(Vec2(0, 0));
		cell->addChild(sprite);

		auto label = Label::createWithSystemFont(chapters[idx].chapterName, "Helvetica", 20.0);
		label->setPosition(Vec2::ZERO);
		label->setAnchorPoint(Vec2::ZERO);
		label->setTag(123);
		cell->addChild(label);
	}
	else
	{
		auto label = (Label*)cell->getChildByTag(123);
		label->setString(chapters[idx].chapterName);
	}


	return cell;
}

ssize_t SelectView::numberOfCellsInTableView(TableView *table)
{
	//   here the number need to be changed later
	return getArrayLength(chapters);
}