#include "Sleep Thread.h"
void SleepThread::Sleep(int time)
{
	QThread::msleep(time);
}