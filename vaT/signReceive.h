#ifndef signReceive_H
#define signReceive_H
#include <QObject>
class sRec : public QObject
{
    Q_OBJECT
public:
    explicit sRec(QObject *parent = nullptr);
    ~sRec();
    // 槽函数声明
public slots:
    void cold();
    void cold(quint8 c);
};

#endif