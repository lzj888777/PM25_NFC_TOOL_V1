#include "dialogcheck.h"
#include "ui_dialogcheck.h"


#include <QDebug>
DialogCheck::DialogCheck(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCheck)
{
    ui->setupUi(this);
    ui->lineEdit_2->setReadOnly(true);
    ui->textEdit_2->setReadOnly(true);

    QPixmap *pixmap = new QPixmap(":/image/dialogcheck/1.png");
    pixmap->scaled(ui->label->size(),Qt::KeepAspectRatio);//把图片自适应label大小
    ui->label->setScaledContents(true);
//    ui->label->setPixmap(*pixmap); //将图片放入label，使用setPixmap,注意指针*img
//    ui->label->setAlignment(Qt::AlignCenter); //将图片放在label中心，用缩放了就不需要了
}

DialogCheck::~DialogCheck()
{
    delete ui;
}


//自定义成员函数
void DialogCheck::checkNFCCard()
{
    static int i = 80000000;
    i++;

    this->ui->lineEdit_3->setText("100");
    this->ui->lineEdit_4->setText("5");
    this->ui->lineEdit_2->setText(QString::number(i));

}
//系统槽函数
void DialogCheck::on_pushButton_clicked()
{
    this->hide();
    emit signalDC_MWbtnShowDP("signalDC_MWbtnShowDP");
}

void DialogCheck::on_pushButton_2_clicked()
{
    this->hide();
    emit signalDC_MWbtnShowDM("signalDC_MWbtnShowDM");
}

void DialogCheck::on_pushButton_11_clicked()
{
    checkNFCCard();
}

void DialogCheck::on_lineEdit_2_textChanged(const QString &arg1)
{
    QString num = this->ui->lineEdit_3->text();
    QString time = this->ui->lineEdit_4->text();
    QString textAll = arg1 + " " + num + " " + time;
    qDebug()<<"DialogCheck::on_lineEdit_2_textChanged"<<textAll<<endl;
    ui->textEdit_2->append(textAll);
    ui->textBrowser_2->append(arg1);
}
