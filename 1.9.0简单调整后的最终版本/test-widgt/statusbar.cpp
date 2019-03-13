#include "statusbar.h"
#include "ui_statusbar.h"
#include"toolbox.h"

statusbar::statusbar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::statusbar)
{
    ui->setupUi(this);
    QImage _image;
    _image.load(":/pic/界面背景555.jpg");
    setAutoFillBackground(true);
    QPalette pal(palette());
    pal.setBrush(QPalette::Window, QBrush(_image.scaled(size(), Qt::IgnoreAspectRatio,
                                                        Qt::SmoothTransformation)));
    setPalette(pal);


    this->setFixedWidth(213);
    ToolBox *tool = new ToolBox(this);
    tool->move(0,80);
    tool->show();
}

statusbar::~statusbar()
{
    delete ui;
}
