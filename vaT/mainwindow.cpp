#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>
#include <QTime>
#include <QDate>
#include "mydialog.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFontDialog>
#include <QLabel>
#include <QInputDialog>
#include <QTimer>
#include <QProgressDialog>
#include "logindialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("vagmr");
    QPushButton *btn1 = new QPushButton(this);
    btn1->move(420, 130);
    btn1->setFixedSize(90, 50);
    btn1->setText("移动窗口");
    QPushButton *btn2 = new QPushButton(this);
    btn2->move(400, 20);
    btn2->setFixedSize(100, 100);
    btn2->setText("发送");
    QPushButton *closeBtn = new QPushButton(this);
    closeBtn->move(320, 20);
    closeBtn->setFixedSize(80, 50);
    closeBtn->setText("关闭窗口");
    connect(closeBtn, &QPushButton::clicked, this, &MainWindow::close);
    QString str = QString("vagmr learn %1 %2,分别是%3 和 %4 ")
                      .arg(2)
                      .arg("种语言")
                      .arg("c++")
                      .arg("python");
    str.toUtf8().toStdString();
    int value = dataAdd(10, 20).toInt();
    QString str2 = dataAdd("hello", "world").toString();
    qDebug() << "输出的字符串是" << str;
    qDebug() << "输出的数字是" << value;
    qDebug() << "输出的字符串是" << str2;
    Person p;
    p.age = 18;
    p.name = "饶师傅";
    p.id = 250;
    p.skill = "导管";
    sent = new Sec(this);
    receive = new sRec;
    // 随机位置宽度，高度和大小
    QPushButton *resizeBtn = new QPushButton("随机位置大小", this);
    resizeBtn->setFixedSize(100, 30);
    resizeBtn->move(500, 50);
    connect(sent, static_cast<void (Sec::*)()>(&Sec::hot), receive, static_cast<void (sRec::*)()>(&sRec::cold));
    // connect(sent, &Sec::hot, this, &MainWindow::hotSlot);
    void (Sec::*hotsign)(quint8) = &Sec::hot;
    connect(sent, static_cast<void (Sec::*)(quint8)>(&Sec::hot), receive, static_cast<void (sRec::*)(quint8)>(&sRec::cold));
    connect(btn2, &QPushButton::clicked, sent, hotsign);
#if 0
  //第一种方式 使用setvalue定义自定义类型的QVarant
    QVariant v;
    v.setValue(p);
#else
    // 第二种方式 使用fromValue
    QVariant v = QVariant::fromValue(p);

#endif
    if (v.canConvert<Person>())
    {
        Person tem = v.value<Person>();
        qDebug() << "person对象的属性为" << tem.name << tem.age << tem.id << tem.skill;
    }
    QDate date = QDate::currentDate();
    date.toString("yyyy-mm-dd");
    QTime time = QTime::currentTime();
    time.toString("hh:mm:ss.zzz");
    qDebug() << "今天的时间是" << date.toString("yyyy-MM-dd") + " " + time.toString("hh:mm:ss.zzz");
    // 使用时间日期
    QDateTime dateTime = QDateTime::currentDateTime();
    QString str3 = dateTime.toString("yyyy/MM/dd HH:mm:ss.zzz");
    qDebug() << "使用日期时间类输出的格式为" << str3;
    this->setWindowIcon(QIcon("H:/qtApp/vaT/favicon.ico"));
    // 移动窗口
    connect(btn1, &QPushButton::clicked, this, &MainWindow::moveWin);
    connect(resizeBtn, &QPushButton::clicked, this, &MainWindow::reSizeWin);
    // 设置右键菜单
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &MainWindow::customContextMenuRequested, this, [](const QPoint &pos)
            {
        QMenu menu;
        menu.addAction("西红柿");
        menu.addAction("黄瓜");
        menu.addAction("番茄");
        menu.exec(QCursor::pos()); });
    // 创建显示模态对话框的按钮
    QPushButton *showDig = new QPushButton("显示模态对话框", this);
    showDig->resize(120, 40);
    showDig->move(350, 180);
    // 连接信号
    connect(showDig, &QPushButton::clicked, this, &MainWindow::showDiglog);
    QMenuBar *menuBar = new QMenuBar(this);
    this->setMenuBar(menuBar);
    QMenu *menu = new QMenu("关于", this);
    QMenu *menu1 = new QMenu("文件", this);
    QMenu *menu2 = new QMenu("登录", this);
    menuBar->addMenu(menu);
    menuBar->addMenu(menu1);
    menuBar->addMenu(menu2);

    QAction *action1 = new QAction("关于版本", menu);
    QAction *action2 = new QAction("关于本软件", menu);
    QAction *action3 = new QAction("打开文件", menu1);
    QAction *action4 = new QAction("更换字体", menu1);
    QAction *action5 = new QAction("输入内容", menu1);
    QAction *action6 = new QAction("迁移文件", menu1);
    QAction *action7 = new QAction("用户登录", menu2);

    menu->addAction(action1);
    menu->addAction(action2);
    menu1->addAction(action3);
    menu1->addAction(action4);
    menu1->addAction(action5);
    menu1->addAction(action6);
    menu2->addAction(action7);

    connect(action1, &QAction::triggered, this, &MainWindow::showAbout);
    connect(action2, &QAction::triggered, this, &MainWindow::showAuthor);
    connect(action3, &QAction::triggered, this, [=]()
            {
        QString args = QString("img(*.png *.jpg *.webp)");
        QString filePath = QFileDialog::getOpenFileName
        (this, "选择文件", "G:/图片/", tr(" img(*.png *.jpg *.webp);;txt(*.txt) "),&args);
        QMessageBox::information(this, "提示", "打开文件成功:" + filePath); });
    // 弹出选择字体对话框
    QLabel *textShow = new QLabel(this);
    textShow->move(10, 20);
    textShow->setText("我的目标是星辰大海");
    textShow->resize(200, 30);
    connect(action4, &QAction::triggered, this, [=]()
            {
        bool * status;
        QFont ft = QFontDialog::getFont(status,QFont("宋体",16,600,false),this,"选择字体");
        if(*status){
            QMessageBox::information(this, "提示", "选择字体成功"  );
            textShow->setFont(ft);
        } });
    // 多行文本输入对话框
    connect(action5, &QAction::triggered, this, [=]()
            {
        bool * ok;
        QString txt = QInputDialog::getMultiLineText(this,"输入","请输入你想说的话","陌猪是个大笨蛋",ok);
        if(*ok) QMessageBox::information(this,"输出内容",txt); });
    connect(action6, &QAction::triggered, this, [=]()
            {
                QTimer *timer = new QTimer;
                QProgressDialog *progress = new QProgressDialog("拷贝文件中.....", "取消", 0, 100,this);
                progress->setWindowTitle("拷贝文件");
                progress->setWindowModality(Qt::WindowModal);
                progress->show();
                static int value = 0;
                connect(timer, &QTimer::timeout, this, [=]()
                        {
            progress->setValue(value);
            value++;
            // 当value > 最大值的时候
            if (value > progress->maximum())
            {
                timer->stop();
                value = 0;
                delete progress;
                delete timer;
            } });

                connect(progress, &QProgressDialog::canceled, this, [=]()               
                {
                    timer->stop();
                    value = 0;
                    delete progress;
                    delete timer; 
                });
                timer->start(30); });
    connect(ui->closeAction, &QAction::triggered, this, &MainWindow::close);
    ui->toolBar->addWidget(new QPushButton("搜索"));
    ui->toolBar->addWidget(new QLineEdit);
    QPushButton *clickBtn = new QPushButton("点击按钮");
    ui->statusBar->addWidget(clickBtn);
    ui->statusBar->addWidget(new QLabel("hello world"));
    QLabel *lableright = new QLabel("vagmr", this);
    ui->statusBar->addPermanentWidget(lableright);
    connect(clickBtn, &QPushButton::clicked, ui->statusBar, [=]()
            { QMessageBox::information(this, "提示", "你点击了按钮"); });
    // 绑定用户登录界面
    connect(action7, &QAction::triggered, this, [=]()
            {
        loginDialog * dlg = new loginDialog(this);
        dlg->show(); });
}

MainWindow::~MainWindow()
{
    delete ui;
}
QVariant MainWindow::dataAdd(QVariant a, QVariant b)
{
    QVariant res;
    if (a.typeId() == QVariant::Int && b.typeId() == QVariant::Int)
    {
        res = QVariant(a.toInt() + b.toInt());
    }
    else if (a.typeId() == QVariant::String && b.typeId() == QVariant::String)
    {
        res.setValue(a.toString() + b.toString());
    }
    return res;
}
void MainWindow::hotSlot()
{
    qDebug() << "信号函数已接收,主窗口已打开，clod!";
}
void MainWindow::moveWin()
{
    QRect rect = this->frameGeometry();
    qDebug() << "执行";
    move(rect.bottomRight() + QPoint(10, 30));
}
// 随机位置大小的函数
void MainWindow::reSizeWin()
{
    int x = rand() % 400;
    int y = rand() % 400;
    int width = this->width() + 10;
    int height = this->height() + 10;
    setGeometry(x, y, width, height);
}
void MainWindow::showDiglog()
{
    myDialog diglog;
    int res = diglog.exec();
    if (res == QDialog::Accepted)
    {
        qDebug() << "点击了确定按钮";
    }
    else if (res == QDialog::Rejected)
    {
        qDebug() << "点击了取消按钮";
    }
    else
    {
        qDebug() << "点击了其他按钮";
    }
}
void MainWindow::showAbout()
{
    QMessageBox::aboutQt(this, "版本信息");
}
void MainWindow::showAuthor()
{
    QMessageBox::about(this, "作者信息", "作者：vagmr");
}
