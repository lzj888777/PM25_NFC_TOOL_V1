#include "dialogmanufacture.h"
#include "ui_dialogmanufacture.h"


#include <QDebug>
DialogManufacture::DialogManufacture(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogManufacture)
{
    ui->setupUi(this);
    ui->lineEdit_2->setReadOnly(true);
    ui->textEdit_2->setReadOnly(true);

//    QPixmap *pixmap = new QPixmap(":/image/dialogmanufacture/1.png");
//    pixmap->scaled(ui->label->size(),Qt::KeepAspectRatio);//把图片自适应label大小
//    ui->label->setScaledContents(true);
//    ui->label->setPixmap(*pixmap); //将图片放入label，使用setPixmap,注意指针*img
//    ui->label->setAlignment(Qt::AlignCenter); //将图片放在label中心，用缩放了就不需要了
}

DialogManufacture::~DialogManufacture()
{
    delete ui;
}

//自定义成员函数
void DialogManufacture::manufactureNFCCard()
{
    static int i = 80000000;
    i++;

    this->ui->lineEdit_3->setText("100");
    this->ui->lineEdit_4->setText("5");
    this->ui->lineEdit_2->setText(QString::number(i));

}
//系统槽函数
void DialogManufacture::on_pushButton_clicked()
{
    this->hide();
    emit signalDM_MWbtnShowDP("signalDM_MWbtnShowDP");
}

void DialogManufacture::on_pushButton_3_clicked()
{
    this->hide();
    emit signalDM_MWbtnShowDC("signalDM_MWbtnShowDC");
}

void DialogManufacture::on_pushButton_11_clicked()
{
    manufactureNFCCard();
}

void DialogManufacture::on_lineEdit_2_textChanged(const QString &arg1)
{
    QString num = this->ui->lineEdit_3->text();
    QString time = this->ui->lineEdit_4->text();
    QString textAll = arg1 + " " + num + " " + time;
    qDebug()<<"DialogManufacture::on_lineEdit_2_textChanged"<<textAll<<endl;
    ui->textEdit_2->append(textAll);
    ui->textBrowser_2->append(arg1);
}
