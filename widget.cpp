#include "widget.h"
#include "ui_widget.h"
#include <QtNetwork/QTcpSocket>
 QString message;
widget::widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget)
{
    ui->setupUi(this);
    socket=new QTcpSocket;
    socket->connectToHost("localhost", 1400);


}
widget::~widget()
{
    delete ui;
}


void widget::on_level_1_clicked()
{
    message="1";
    socket->write(message.toUtf8());
}


void widget::on_level_2_clicked()
{
    message="2";
    socket->write(message.toUtf8());
}
void widget::on_level_3_clicked()
{
    message="3";
    socket->write(message.toUtf8());
}

