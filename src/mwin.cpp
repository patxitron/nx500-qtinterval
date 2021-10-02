#include <QDebug>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QRect>
#include "mwin.hpp"

Mwin::Mwin()
		:QMainWindow()
		,xdo_(xdo_new(":0"))
		,camera_app_window_(CURRENTWINDOW)
		,btn_(nullptr)
{
	if (xdo_) {
		QRect geometry(0, 0, NX_WIDTH, NX_HEIGHT);
		xdo_get_focused_window(xdo_, &camera_app_window_);
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
		setGeometry(geometry);
		setMaximumSize(NX_WIDTH, NX_HEIGHT);
		setMinimumSize(NX_WIDTH, NX_HEIGHT);
		/* Take a test photo */
		QTimer::singleShot(2000, [this]() {
			xdo_send_keysequence_window_down(xdo_, camera_app_window_, "Super_L", 0);
			QTimer::singleShot(200, [this]() {
				xdo_send_keysequence_window_down(xdo_, camera_app_window_, "Super_R", 0);
				QTimer::singleShot(200, [this]() {
					xdo_send_keysequence_window_up(xdo_, camera_app_window_, "Super_R", 0);
					QTimer::singleShot(200, [this]() {
						xdo_send_keysequence_window_up(xdo_, camera_app_window_, "Super_L", 0);
					});
				});
			});
		});
	}
}
