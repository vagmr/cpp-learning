#include "secondWindow.h"
#include <QPushButton>
#include <QLabel>
#include <QTimer>
#include <QTime>
#include <QPixmap>
#include <QPalette>

Sec::Sec(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *sentBtn = new QPushButton(this);
    this->resize(340, 340);
    this->move(0, 100);
    this->setStyleSheet("background-color:red;\
                        border:1px solid black;\
    ");
    sentBtn->setText("发送");
    sentBtn->setFixedSize(80, 30);
    sentBtn->move(100, 160);
    sentBtn->setStyleSheet("background-color:red;");
    connect(sentBtn, &QPushButton::clicked, this, &Sec::emitHot);
    QPushButton *startBtn = new QPushButton("开始", this);
    QPushButton *getBtn = new QPushButton("获取位置", this);
    getBtn->move(0, 40);
    getBtn->setFixedSize(80, 30);
    QLabel *label = new QLabel(this);
    label->move(50, 280);
    label->resize(120, 30);
    QTimer *timer = new QTimer(this);
    startBtn->setFixedSize(100, 30);
    connect(startBtn, &QPushButton::clicked, this, [=]()
            {  if(timer -> isActive()){
                timer->stop();
                startBtn->setText("开始");
            } else{
                startBtn->setText("停止");
                timer->start(1000); 
            } });
    connect(timer, &QTimer::timeout, this, [=]()
            { 
                QTime time = QTime::currentTime();
                QString tStr = time.toString("hh:mm:ss");
                label->setText(tStr); });
    connect(getBtn, &QPushButton::clicked, this, &Sec::getWinInfo);
    QPixmap backgroundImage(":/wbg"); // 使用绝对路径或资源文件前缀来指定图片路径
    QPalette palette;
    palette.setBrush(QPalette::Window, backgroundImage);
    this->setPalette(palette);

}

Sec::~Sec()
{
}
void Sec::emitHot()
{
    // 可以发送多条信号
    emit Sec::hot();
    emit Sec::hot(8);
}
// 获取当前窗口的位置信息
void Sec::getWinInfo()
{
    QRect rect = this->frameGeometry();
    qDebug() << "位置信息如下"
             << "左上角:" << rect.topLeft() << "右上角:" << rect.topRight() << "左下角:" << rect.bottomLeft() << "右下角:" << rect.bottomRight() << "宽度:" << rect.width() << "高度:" << rect.height();
}
