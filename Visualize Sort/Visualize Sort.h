#pragma once
#include <QtWidgets/QMainWindow>
#include "Sort.h"
#include "ui_Visualize Sort.h"
class VisualizeSort : public QMainWindow
{
	Q_OBJECT
public:
	VisualizeSort(int maxLength, QWidget* parent = NULL);
	~VisualizeSort();
	void paintEvent(QPaintEvent* event);
public slots:
	void RandomInitialize();
	void StartSort();
	void BubbleSlot(int firstIndex, int secondIndex, bool neededSwap);
protected:
	Ui::VisualizeSortClass *ui_;
	ElemList<int> list_;
	Sort sort_;
	int maxLength_;
	bool isStarted_;
	int firstIndex_;
	int secondIndex_;
	bool neededSwap_;
};