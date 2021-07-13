#include "Visualize Sort.h"
#include <Windows.h>
#include <qpainter.h>
VisualizeSort::VisualizeSort(int maxLength, QWidget* parent) : QMainWindow(parent), maxLength_(maxLength), isStarted_(false)
{
	ui_.setupUi(this);
	ui_.numberSpin->setMinimum(2);
	ui_.numberSpin->setMaximum(maxLength_);
	ui_.numberSpin->setKeyboardTracking(false);
	connect(ui_.numberSpin, SIGNAL(valueChanged(int)), this, SLOT(repaint()));
	connect(ui_.initializeButton, SIGNAL(clicked()), this, SLOT(RandomInitialize()));
	connect(ui_.startButton, SIGNAL(clicked()), this, SLOT(StartSort()));
	connect(&sort_, SIGNAL(BubbleSignal(int, int, bool)), this, SLOT(BubbleSlot(int, int, bool)));
	list_ = ElemList<int>(ui_.numberSpin->value(), maxLength_);
}
VisualizeSort::~VisualizeSort()
{
}
void VisualizeSort::paintEvent(QPaintEvent* event)
{
	list_.SetLength(ui_.numberSpin->value());
	QPainter painter(this);
	painter.begin(this);
	double unitWidth = (ui_.canvasPanel->width() - 20) / ui_.numberSpin->value();
	double unitHeight = (ui_.canvasPanel->height() - 20) / ui_.numberSpin->value();
	for (int i = 0; i < ui_.numberSpin->value(); i++)
	{
		int value = list_[i];
		QColor color(0, 0, 0);
		if (isStarted_ && (i == firstIndex_ || i == secondIndex_))
		{
			if (neededSwap_)
			{
				color.setRgb(250, 170, 0);
			}
			else
			{
				color.setRgb(0, 200, 0);
			}
		}
		else
		{
			color.setRgb(0, 160, 230);
		}
		painter.fillRect(20 + unitWidth * i, ui_.canvasPanel->height() - unitHeight * value, unitWidth - 1, unitHeight * value, color);
	}
	if (isStarted_)
	{
		Sleep(ui_.timeSpin->value());
	}
	painter.end();
}
void VisualizeSort::RandomInitialize()
{
	list_.RandomOrder();
	repaint();
}
void VisualizeSort::StartSort()
{
	isStarted_ = true;
	if (ui_.meansCombo->currentText() == QString("冒泡排序"))
	{
		sort_.BubbleSort(list_);
	}
	isStarted_ = false;
	repaint();
}
void VisualizeSort::BubbleSlot(int firstIndex, int secondIndex, bool neededSwap)
{
	firstIndex_ = firstIndex;
	secondIndex_ = secondIndex;
	neededSwap_ = neededSwap;
	repaint();
}