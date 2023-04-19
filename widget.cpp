#include "widget.h"
#include "ui_widget.h"
#include <QtNetwork/QTcpSocket>
QString message="";
bool flag=false;
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

void widget::keyPressEvent(QKeyEvent *event){
    char text=event->key();
    if(flag){
        message=text;
        qDebug()<<text;
        ui->label->setText(message);
        socket->write(message.toUtf8());

    }
}
void widget::on_level_1_clicked()
{
    if(!flag){
        flag=true;
        message="1";
        socket->write(message.toUtf8());

    }
}


void widget::on_level_2_clicked()
{
    if(!flag){
        flag=true;
        message="2";
        socket->write(message.toUtf8());

    }
}
void widget::on_level_3_clicked()
{
    if(!flag){
        flag=true;
        message="3";

    }
}

