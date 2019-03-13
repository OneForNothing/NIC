#include "newmainwindow.h"
#include "ui_newmainwindow.h"
#include<QPixmap>

newmainwindow::newmainwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::newmainwindow)
{
    ui->setupUi(this);

    this->setWindowTitle(" ");
    QIcon icon(":/image-3/主标志.png");
    this->setWindowIcon(icon);

    //隐藏最大化最小化
    this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint&~Qt::WindowMinimizeButtonHint);

    //设置二维码
    QMainWindow::setStatusBar ( 0 );
    QPixmap pix = QPixmap(":/image-3/活码.png");
    ui->label->setPixmap(pix.scaled(341,321));

    this->setFixedSize(400,350);

}

newmainwindow::~newmainwindow()
{
    delete ui;
}
