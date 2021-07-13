#include "SortCanvas.h"
#include <qpainter.h>
SortCanvas::SortCanvas(QWidget* parent) : QWidget(parent)
{
	ui.setupUi(this);
	QPainter painter(this);
}
SortCanvas::~SortCanvas()
{
}
void SortCanvas::InitializeCanvas( int number)
{
	double width = 530 / number;
	double height = 360 / number;
	for (int i = 1; i < number + 1; i++)
	{
		painter.fillRect(width * (double(i) - 1), 360 - height * i, width - 1, height * i, QColor(0, 160, 230));
	}
}
void SortCanvas::paintEvent(QPaintEvent* event)
{
	InitializeCanvas(10);
}