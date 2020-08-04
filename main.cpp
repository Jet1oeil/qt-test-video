#include <QApplication>

#include "QAppWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString szDir = "./images";
    QString szIntervalMs = "30";

    if(argc > 1){
		szDir = argv[1];
    }
	if(argc > 2){
		szIntervalMs = argv[2];
	}

    QAppWindow w;
	w.init(szDir, szIntervalMs.toInt());

    //w.resize(1280, 800);
    w.show();

    return a.exec();
}
