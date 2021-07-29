#pragma once
#include <QThread>
class SleepThread : public QThread
{
public:
	static void Sleep(int time);
};