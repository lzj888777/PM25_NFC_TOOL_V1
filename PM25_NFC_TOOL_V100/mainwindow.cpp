#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dialoglogin.h"
#include "dialogprecheck.h"
#include "dialogmanufacture.h"
#include "dialogcheck.h"


#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //设置label3的背景图片
    QPixmap *pixmap = new QPixmap(":/image/mainwindow/1.png");
    pixmap = new QPixmap(":/image/mainwindow/4.png");
    pixmap->scaled(ui->label_3->size(),Qt::KeepAspectRatio);//把图片自适应label大小
    ui->label_3->setScaledContents(true);
    ui->label_3->setPixmap(*pixmap); //将图片放入label，使用setPixmap,注意指针*img

    //UI测试阶段
    DialogCheck dc;
//    dc.show();

    DialogManufacture dm;
//    dm.show();

    DialogPrecheck dp;
//    dp.show();

    DialogLogin dl;


    //信号与槽链接

    connect(&dl,&DialogLogin::signalDLshow,this,&MainWindow::slotDLShow);
    connect(&dl,&DialogLogin::signalDLclose,this,&MainWindow::slotDLclose);
    connect(this,&MainWindow::signalMWclose,this,&MainWindow::close);
    dl.exec();






}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotDLShow(QString x)
{

    qDebug()<<x<<endl;
    this->show();
}
void MainWindow::slotDLclose()
{
    qDebug()<<"close 3"<<endl;
    this->close();

    emit signalMWclose();
}

void MainWindow::on_pushButton_clicked()
{
    this->close();
}
