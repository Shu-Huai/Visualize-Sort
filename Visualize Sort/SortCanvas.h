#pragma once
#include <QWidget>
#include "ui_SortCanvas.h"
#include <qpainter.h>
class SortCanvas : public QWidget
{
	Q_OBJECT
public:
	SortCanvas(QWidget* parent = Q_NULLPTR);
	~SortCanvas();
	void Start();
	void InitializeCanvas(int number);
	void paintEvent(QPaintEvent* event);
protected:
	void Paint();
private:
	Ui::SortCanvas ui;
	QPalette backGroundColor;
	QPainter painter;
};