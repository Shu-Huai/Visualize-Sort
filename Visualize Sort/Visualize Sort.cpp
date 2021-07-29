#include "Visualize Sort.h"
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
	connect(&sort_, SIGNAL(RepaintSignal(int, int, bool)), this, SLOT(RepaintSlot(int, int, bool)));
	connect(ui_->timeSpin, SIGNAL(valueChanged(int)), &sort_, SLOT(SetTime(int)));
	list_ = ElemList<int>(ui_->numberSpin->value(), maxLength_);
	sort_.SetTime(ui_->timeSpin->value());
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
	double unitWidth = (ui_->canvasPanel->width() - 20) / (ui_->numberSpin->value() + 1);
	double unitHeight = (ui_->canvasPanel->height() - 20) / (ui_->numberSpin->value() + 1);
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
	switch (ui_->meansCombo->currentIndex())
	{
	case 0:
		sort_.BubbleSort(list_);
		break;
	case 1:
		sort_.OptimizedBubbleSort(list_);
		break;
	case 2:
		sort_.CockTailSort(list_);
		break;
	case 3:
		sort_.QuickSort(list_);
		break;
	case 4:
		sort_.StraightInsertSort(list_);
		break;
	case 5:
		sort_.BinaryInsertSort(list_);
		break;
	case 6:
		sort_.ShellSort(list_);
		break;
	case 7:
		sort_.CountSort(list_);
		break;
	case 8:
		sort_.MonkeySort(list_);
		break;
	case 9:
		sort_.RadixSort(list_);
		break;
	case 10:
		sort_.MergeSort(list_);
		break;
	default:
		break;
	}
	isStarted_ = false;
	ui_->meansCombo->setEnabled(true);
	ui_->numberSpin->setEnabled(true);
	ui_->startButton->setEnabled(true);
	ui_->initializeButton->setEnabled(true);
	repaint();
}
void VisualizeSort::RepaintSlot(int firstIndex, int secondIndex, bool neededSwap)
{
	firstIndex_ = firstIndex;
	secondIndex_ = secondIndex;
	neededSwap_ = neededSwap;
	QCoreApplication::processEvents();
	repaint();
}