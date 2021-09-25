#include "mwin.hpp"

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

Mwin::Mwin(): QMainWindow(), btn_(nullptr)
{
	QWidget* wdgt = new QWidget();
	QVBoxLayout* vl = new QVBoxLayout();
	QLabel* lbl = new QLabel("¡Hola Qt!");
	vl->addWidget(lbl);
	btn_ = new QPushButton("Salir");
	vl->addWidget(btn_);
	wdgt->setLayout(vl);
	setCentralWidget(wdgt);
	connect(btn_, &QPushButton::clicked, [this](bool) {
		close();
	});
}

