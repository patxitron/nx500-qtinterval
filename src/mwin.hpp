
#ifndef mwin_l_alOYQAAAAAXjX17OBOF_bw
#define mwin_l_alOYQAAAAAXjX17OBOF_bw

#include <QMainWindow>
extern "C" {
	/// TODO: Use XSendEvent directly to get rid of the xdotools dependency
#include <xdo.h>
}

#define NX_WIDTH 720
#define NX_HEIGHT 480

class QPushButton;

class Mwin: public QMainWindow
{
	Q_OBJECT

public:
	Mwin();

private:
	xdo_t* xdo_;
	Window camera_app_window_;
	QPushButton* btn_;
};

#endif /* mwin_l_alOYQAAAAAXjX17OBOF_bw */

