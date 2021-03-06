#ifndef MYTREEWIDGET_H
#define MYTREEWIDGET_H

#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QTreeWidget>

class MyTreeWidget : public QTreeWidget {
    Q_OBJECT
  public:
    explicit MyTreeWidget(QWidget *parent = Q_NULLPTR);

protected:
	void mousePressEvent(QMouseEvent *event) override;

	// QWidget interface
protected:
	void mouseDoubleClickEvent(QMouseEvent *event) override;
};

#endif // MYTREEWIDGET_H
