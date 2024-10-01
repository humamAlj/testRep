#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	
	
	
	int n = 0;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
