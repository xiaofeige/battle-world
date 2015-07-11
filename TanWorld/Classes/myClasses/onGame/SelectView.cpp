#include "SelectView.h"







/*--------------------------------------------------------------------------*/
/*-------------------override methods of tableview--------------------------*/
/*--------------------------------------------------------------------------*/
void SelectView::tableCellTouched(TableView* table, TableViewCell* cell)
{
	CCLOG("cell touched at index: %ld", cell->getIdx());
}

Size SelectView::tableCellSizeForIndex(TableView *table, ssize_t idx)
{
	/*--------------´ýÔö¼Ó-------------------------*/
	return Size(120, 60);
}

TableViewCell* SelectView::tableCellAtIndex(TableView *table, ssize_t idx)
{
	//auto string = String::createWithFormat("%ld", idx);
	TableViewCell *cell = table->dequeueCell();
	if (!cell) {
		cell = new (std::nothrow) TableViewCell();
		cell->autorelease();
		auto sprite = Sprite::create("pic/numView.png"); //load background of each cell
		sprite->setAnchorPoint(Vec2::ZERO);
		sprite->setPosition(Vec2(0, 0));
		cell->addChild(sprite);

		auto label = Label::createWithSystemFont("xiaofei", "Helvetica", 20.0);
		label->setPosition(Vec2::ZERO);
		label->setAnchorPoint(Vec2::ZERO);
		label->setTag(123);
		cell->addChild(label);
	}
	else
	{
		auto label = (Label*)cell->getChildByTag(123);
		label->setString("xiaofei");
	}


	return cell;
}

ssize_t SelectView::numberOfCellsInTableView(TableView *table)
{
	//   here the number need to be changed later
	return 20;
}