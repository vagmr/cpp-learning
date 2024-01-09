#include "mydialog.h"
#include "ui_mydialog.h"

myDialog::myDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::myDialog)
{
    ui->setupUi(this);
}

myDialog::~myDialog()
{
    delete ui;
}

void myDialog::on_acceptBtn_clicked()
{
    this->accept();
}


void myDialog::on_doneBtn_clicked()
{
    this->done(10);
}


void myDialog::on_rejectBtn_clicked()
{
    this->reject();
}

