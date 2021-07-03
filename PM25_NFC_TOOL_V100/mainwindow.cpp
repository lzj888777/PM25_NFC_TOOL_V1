#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dialoglogin.h"
#include "dialogprecheck.h"
#include "dialogmanufacture.h"
#include "dialogcheck.h"


#include <QDebug>
#include <QTime>

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




    //信号与槽链接 DialogLogin 与 MainWindow
    connect(&dl,&DialogLogin::signalDLshow,this,&MainWindow::slotDLShow);
    connect(&dl,&DialogLogin::signalDLclose,this,&MainWindow::slotDLclose);
    connect(this,&MainWindow::signalMWclose,this,&MainWindow::on_pushButton_clicked);
    connect(this,&MainWindow::signalMW_MWShow,this,&MainWindow::slotDLShow);


    //信号与槽链接 DialogPrecheck 与 MainWindow
    connect(&dp,&DialogPrecheck::signalDP_MWbtnShowDM,this,&MainWindow::slotDP_MWbtnShowDM);
    connect(&dp,&DialogPrecheck::signalDP_MWbtnShowDC,this,&MainWindow::slotDP_MWbtnShowDC);

    //信号与槽链接 DialogManufacture 与 MainWindow
    connect(&dm,&DialogManufacture::signalDM_MWbtnShowDP,this,&MainWindow::slotDM_MWbtnShowDP);
    connect(&dm,&DialogManufacture::signalDM_MWbtnShowDC,this,&MainWindow::slotDM_MWbtnShowDC);

    //信号与槽链接 DialogCheck 与 MainWindow
    connect(&dc,&DialogCheck::signalDC_MWbtnShowDP,this,&MainWindow::slotDC_MWbtnShowDP);
    connect(&dc,&DialogCheck::signalDC_MWbtnShowDM,this,&MainWindow::slotDC_MWbtnShowDM);

    dl.show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->show();
    this->close();
    qDebug()<<"close4"<<endl;
}

//MainWindow SLOT form DialogLogin
void MainWindow::slotDLShow(QString x)
{

    qDebug()<<x<<endl;
    this->show();

    //延时2秒进入界面
    QTime _Timer = QTime::currentTime().addMSecs(2000);

    while( QTime::currentTime() < _Timer ){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }

    this->hide();
    this->dp.show();

}
void MainWindow::slotDLclose()
{

//    this->close();
    qDebug()<<"close3"<<endl;
    emit signalMW_MWShow("signalMW_MWShow");
}


//MainWindow SLOT form DialogPrecheck
void MainWindow::slotDP_MWbtnShowDM(QString x)
{
    qDebug()<<x<<endl;
    this->dm.show();
}
void MainWindow::slotDP_MWbtnShowDC(QString x)
{
    qDebug()<<x<<endl;
    this->dc.show();
}

//MainWindow SLOT form DialogManufacture
void MainWindow::slotDM_MWbtnShowDP(QString x)
{
    qDebug()<<x<<endl;
    this->dp.show();
}
void MainWindow::slotDM_MWbtnShowDC(QString x)
{
    qDebug()<<x<<endl;
    this->dc.show();
}


//MainWindow SLOT form DialogCheck
void MainWindow::slotDC_MWbtnShowDP(QString x)
{
    qDebug()<<x<<endl;
    this->dp.show();
}
void MainWindow::slotDC_MWbtnShowDM(QString x)
{
    qDebug()<<x<<endl;
    this->dm.show();
}
