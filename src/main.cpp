#include <QApplication>
#include "mwin.hpp"
#include <QtPlugin>

Q_IMPORT_PLUGIN(QXcbIntegrationPlugin)
//Q_IMPORT_PLUGIN(QMinimalIntegrationPlugin)


int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	Mwin mw;
	mw.show();
	return a.exec();
}
