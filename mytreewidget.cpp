#include "mytreewidget.h"

#include <QDebug>
#include <QHeaderView>
#include <QPushButton>

MyTreeWidget::MyTreeWidget(QWidget *parent) : QTreeWidget(parent) {
    header()->hide();
    viewport()->setAcceptDrops(true);
    setDropIndicatorShown(true);
    setDragDropMode(QAbstractItemView::InternalMove);
    setSelectionMode(QAbstractItemView::SingleSelection);
    setColumnCount(3);

    auto usRow = new QTreeWidgetItem(this, {"Hello", "world"});
    usRow->setFlags(usRow->flags() & ~Qt::ItemIsSelectable);

    auto laRow = new QTreeWidgetItem(usRow, {"LA"});
    auto sfRow = new QTreeWidgetItem(usRow, {"SF"});
    auto nyRow = new QTreeWidgetItem(usRow, {"NY"});

    laRow->setFlags(laRow->flags() & (~Qt::ItemIsDragEnabled) & (~Qt::ItemIsDropEnabled));
    sfRow->setFlags(sfRow->flags() & (~Qt::ItemIsDragEnabled) & (~Qt::ItemIsDropEnabled));
    nyRow->setFlags(nyRow->flags() & (~Qt::ItemIsDragEnabled) & (~Qt::ItemIsDropEnabled));

    usRow->addChild(laRow);
    usRow->addChild(sfRow);
    usRow->addChild(nyRow);
	usRow->setExpanded(true);

    addTopLevelItem(usRow);
}

void MyTreeWidget::mousePressEvent(QMouseEvent *event)
{
	QTreeWidgetItem *item = itemAt(event->pos());

	if (item->flags() & Qt::ItemIsSelectable)
		QTreeWidget::mousePressEvent(event);
}

void MyTreeWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
	QTreeWidget::mouseDoubleClickEvent(event);

	QTreeWidgetItem *item = itemAt(event->pos());

	if (item->childCount())
		item->setExpanded(!item->isExpanded());
}
