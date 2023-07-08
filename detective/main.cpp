#include "detective.h"
#include <QString>
#include<QFont>
#include<fstream>
#include <QtWidgets/QApplication>
#include <QDebug>
#include <cstring>
#include <Windows.h>
#include <WinUser.h>
#include <wingdi.h>
#include "nlohmann/json.hpp"


int main(int argc, char *argv[])
{
    int nScreenWidth = ::GetSystemMetrics(SM_CXSCREEN);
	int nScreenHeight = ::GetSystemMetrics(SM_CYSCREEN);
    HWND hwd = ::GetDesktopWindow();
    HDC hdc = ::GetDC(hwd);
    int dwidth = GetDeviceCaps(hdc, DESKTOPHORZRES);
	int dheight = GetDeviceCaps(hdc, DESKTOPVERTRES);
    qDebug() << dwidth << nScreenWidth;
	
	qreal scale = (qreal)nScreenWidth / 1920;
    qputenv("QT_SCALE_FACTOR", QString::number(scale).toLatin1());
	
    QFont f = QApplication::font();
    f.setStyleStrategy(QFont::PreferAntialias);
    QApplication::setFont(f);
	
    QApplication a(argc, argv);
    detective w;
	
    w.move((nScreenWidth/scale - 1600) / 2, (nScreenHeight/scale - 900)*0.9 / 2);
	
	
    w.show();
    return a.exec();
}
