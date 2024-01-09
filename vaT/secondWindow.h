#ifndef secondWindow_H
#define secondWindow_H
#include <QWidget>
class Sec : public QWidget
{
    Q_OBJECT
public:
    explicit Sec(QWidget *parent = nullptr);
    ~Sec();
    // 作为发送函数
    void emitHot();
    void getWinInfo();
    // 信号只需要声明，不需要实现
signals:
    void hot();
    void hot(quint8 c);
};
#endif