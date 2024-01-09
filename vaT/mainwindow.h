
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
// 导入信号和槽的头函数
#include "secondWindow.h"
#include "signReceive.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

struct Person
{
    QString name;
    quint16 age;
    quint8 id;
    QString skill;
};
Q_DECLARE_METATYPE(Person);

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QVariant dataAdd(QVariant a, QVariant b);
    void hotSlot();
    void moveWin();
    void reSizeWin();
    void showDiglog();
    void showAbout();
    void showAuthor();

private:
    Ui::MainWindow *ui;
    // 分别声明信号和槽的指向对象
    Sec *sent;
    sRec *receive;
};

#endif // MAINWINDOW_H
