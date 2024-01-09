#include "signReceive.h"
#include <QDebug>
sRec::sRec(QObject *parent) : QObject(parent){

                              };
sRec::~sRec(){};
// 槽函数实现
void sRec::cold()
{
    qDebug() << "信号函数已接收,clod!";
}
void sRec::cold(quint8 c)
{
    qDebug() << "信号函数已接收,clod!" << c;
}