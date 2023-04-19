#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>
namespace Ui {
class widget;
}
class QTcpSocket;

class widget : public QWidget
{
    Q_OBJECT

public:

    explicit widget(QWidget *parent = nullptr);
    ~widget();
    QTcpSocket *socket;

protected:
    void keyPressEvent(QKeyEvent *event);
private slots:

    void on_level_1_clicked();

    void on_level_2_clicked();

    void on_level_3_clicked();

    void serialCom();

private:
    Ui::widget *ui;
};

#endif // WIDGET_H

