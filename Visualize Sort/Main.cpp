#include <QtWidgets/QApplication>
#include <QTranslator>
#include "Visualize Sort.h"
int main(int argc, char* argv[])
{
	QApplication application(argc, argv);
	QTranslator translator;
	if (translator.load(":/VisualizeSort/qt_zh_CN.qm"))
	{
		application.installTranslator(&translator);
	}
	VisualizeSort mainWidget(265);
	mainWidget.setWindowIcon(QIcon(":/VisualizeSort/Visualize Sort Window Icon.ico"));
	mainWidget.setWindowTitle(QString("排序可视化"));
	mainWidget.setWindowState(Qt::WindowMaximized);
	mainWidget.show();
	return application.exec();
}