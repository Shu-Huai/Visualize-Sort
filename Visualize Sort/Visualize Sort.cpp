#include "Visualize Sort.h"
#include <Windows.h>
#include <QPainter>
VisualizeSort::VisualizeSort(int maxLength, QWidget* parent) : QMainWindow(parent), maxLength_(maxLength), isStarted_(false)
{
	ui_ = new Ui::VisualizeSortClass;
	ui_->setupUi(this);
	ui_->numberSpin->setMinimum(2);
	ui_->numberSpin->setMaximum(maxLength_);
	ui_->numberSpin->setKeyboardTracking(false);
	connect(ui_->numberSpin, SIGNAL(valueChanged(int)), this, SLOT(repaint()));
	connect(ui_->initializeButton, SIGNAL(clicked()), this, SLOT(RandomInitialize()));
	connect(ui_->startButton, SIGNAL(clicked()), this, SLOT(StartSort()));
	connect(&sort_, SIGNAL(BubbleSignal(int, int, bool)), this, SLOT(BubbleSlot(int, int, bool)));
	list_ = ElemList<int>(ui_->numberSpin->value(), maxLength_);
}
VisualizeSort::~VisualizeSort()
{
	delete ui_;
}
void VisualizeSort::paintEvent(QPaintEvent* event)
{
	list_.SetLength(ui_->numberSpin->value());
	QPainter painter(this);
	painter.begin(this);
	double unitWidth = (ui_->canvasPanel->width() - 20) / ui_->numberSpin->value();
	double unitHeight = (ui_->canvasPanel->height() - 20) / ui_->numberSpin->value();
	for (int i = 0; i < ui_->numberSpin->value(); i++)
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
		painter.fillRect(20 + unitWidth * i, ui_->canvasPanel->height() - unitHeight * value, unitWidth - 1, unitHeight * value, color);
	}
	if (isStarted_)
	{
		Sleep(ui_->timeSpin->value());
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
	ui_->meansCombo->setEnabled(false);
	ui_->numberSpin->setEnabled(false);
	ui_->startButton->setEnabled(false);
	ui_->initializeButton->setEnabled(false);
	if (ui_->meansCombo->currentText() == QString("冒泡排序"))
	{
		sort_.BubbleSort(list_);
	}
	else if (ui_->meansCombo->currentText() == QString("优化的冒泡排序"))
	{
		sort_.OptimizedBubbleSort(list_);
	}
	else if (ui_->meansCombo->currentText() == QString("鸡尾酒排序"))
	{
		sort_.CockTailSort(list_);
	}
	else if (ui_->meansCombo->currentText() == QString("快速排序"))
	{
		sort_.QuickSort(list_);
	}
	else if (ui_->meansCombo->currentText() == QString("直接插入排序"))
	{
		sort_.StraightInsertSort(list_);
	}
	isStarted_ = false;
	ui_->meansCombo->setEnabled(true);
	ui_->numberSpin->setEnabled(true);
	ui_->startButton->setEnabled(true);
	ui_->initializeButton->setEnabled(true);
	repaint();
}
void VisualizeSort::BubbleSlot(int firstIndex, int secondIndex, bool neededSwap)
{
	firstIndex_ = firstIndex;
	secondIndex_ = secondIndex;
	neededSwap_ = neededSwap;
	QCoreApplication::processEvents();
	repaint();
}