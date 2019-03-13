#include "weather.h"
#include "ui_weather.h"

weather::weather(MainWindow *wea, QWidget *parent) :
    _wea(wea),
    QMainWindow(parent),
    ui(new Ui::weather)
{
    ui->setupUi(this);
    //隐藏状态栏
    QMainWindow::setStatusBar ( 0 );
    //设置图标。窗口文字
    this->setWindowTitle("weather");
    QIcon icon(":/image-3/主标志.png");
    this->setWindowIcon(icon);
    qDebug()<<"**"<<wea->today.city<<wea->today.wendu<<wea->today.shidu;
    ui->label->setText( wea->today.wendu + "℃");
    ui->label_2->setText(wea->today.city);
    ui->label_3->setText(QString("日期      ")+wea->forecast[0].date);
    ui->label_4->setText(QString("湿度      ")+wea->today.shidu);
    ui->label_5->setText(wea->forecast[0].fengxiang+ QString("      ") + wea->forecast[0].fengli.mid(9,4));
    ui->label_6->setText(QString("日出时间  ")+wea->today.sunrise);
    ui->label_7->setText(QString("日落时间  ")+wea->today.sunset);
    ui->label_8->setText(wea->forecast[0].date);
    ui->label_9->setText(wea->forecast[1].date);
    ui->label_10->setText(wea->forecast[2].date);
    ui->label_11->setText(wea->forecast[3].date);
    ui->label_12->setText(wea->forecast[4].date);
    /*
    ui->label_13->setText(wea->forecast[0].type);
    ui->label_14->setText(wea->forecast[0].type);
    ui->label_15->setText(wea->forecast[0].type);
    ui->label_16->setText(wea->forecast[0].type);
    ui->label_17->setText(wea->forecast[0].type);
    */

    ui->label_18->setText(wea->forecast[0].low );
    ui->label_19->setText(wea->forecast[1].low);
    ui->label_20->setText(wea->forecast[2].low );
    ui->label_21->setText(wea->forecast[3].low );
    ui->label_22->setText(wea->forecast[4].low );



    //设置天气（图片版）
   QPixmap pix1 = QPixmap(tr(":/images/%1").arg(wea->forecast[0].type));
   ui->label_13->setPixmap(pix1);
   QPixmap pix2 = QPixmap(tr(":/images/%1").arg(wea->forecast[1].type));
   ui->label_14->setPixmap(pix2);
   QPixmap pix3 = QPixmap(tr(":/images/%1").arg(wea->forecast[2].type));
   ui->label_15->setPixmap(pix3);
   QPixmap pix4 = QPixmap(tr(":/images/%1").arg(wea->forecast[3].type));
   ui->label_16->setPixmap(pix4);
   QPixmap pix5 = QPixmap(tr(":/images/%1").arg(wea->forecast[4].type));
   ui->label_17->setPixmap(pix5);



    ui->label_23->setText(wea->forecast[0].high );
    ui->label_24->setText(wea->forecast[1].high );
    ui->label_25->setText(wea->forecast[2].high );
    ui->label_26->setText(wea->forecast[3].high );
    ui->label_27->setText(wea->forecast[4].high );








    qDebug()<<"**"<<wea->forecast[0].type<<wea->forecast[0].low<<wea->forecast[0].high;
}

weather::~weather()
{
    delete ui;
}
