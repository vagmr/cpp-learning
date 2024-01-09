
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    // 应用程序对象
    QApplication a(argc, argv);
    MainWindow w;
    QApplication::setFont(QFont("楷书", 11, 600, false), "MainWindow");
    w.show();

    return a.exec();
}
