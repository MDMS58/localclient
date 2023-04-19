#include "widget.h"
#include "ui_widget.h"
#include "serial.h"
#include <QtNetwork/QTcpSocket>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <Qtimer>

QString message="";
bool flag=false;

char *port = "\\\\.\\COM6";
char inc[MAX_DATA_LENGTH];
char out[MAX_DATA_LENGTH];
SerialPort controller(port);

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
    char text = event->key();
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
void widget::serialCom() {
    QTimer *timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, [=]() {
        if (controller.isConnected()) {
            std::string in;
            std::cin>>in;
            char *charArray = new char[in.size() + 1];
            copy(in.begin(), in.end(), charArray);
            charArray[in.size()] = '\n';

            controller.writeSerialPort(charArray, MAX_DATA_LENGTH);
            qDebug()<<controller.readSerialPort(out, MAX_DATA_LENGTH);

        } else {
            std::cout<<"no conncection ";
        }
    });
    timer->start(100);
}

