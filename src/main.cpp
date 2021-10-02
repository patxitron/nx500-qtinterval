#include <QDebug>
#include <QApplication>
#include <QtPlugin>
#include <QScreen>
#include "mwin.hpp"

Q_IMPORT_PLUGIN(QXcbIntegrationPlugin)

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	QScreen* sc = a.primaryScreen();
	QSize sz{sc->availableSize()};
	qDebug() << "Resolution: " << sz.width() << "x" << sz.height();
	qDebug() << "DPI: " << sc->logicalDotsPerInchX() << "x" << sc->logicalDotsPerInchY();
	Mwin mw;
	mw.show();
	return a.exec();
}
