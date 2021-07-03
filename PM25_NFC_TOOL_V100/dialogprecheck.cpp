#include "dialogprecheck.h"
#include "ui_dialogprecheck.h"

#include <QDebug>
DialogPrecheck::DialogPrecheck(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPrecheck)
{
    ui->setupUi(this);
    ui->lineEdit->setReadOnly(true);
    ui->textEdit->setReadOnly(true);

    QPixmap *pixmap = new QPixmap(":/image/dialogprecheck/1.png");
    pixmap->scaled(ui->label->size(),Qt::KeepAspectRatio);//把图片自适应label大小
    ui->label->setScaledContents(true);
//    ui->label->setPixmap(*pixmap); //将图片放入label，使用setPixmap,注意指针*img
//    ui->label->setAlignment(Qt::AlignCenter); //将图片放在label中心，用缩放了就不需要了

    //信号与槽连接
//    connect(this->ui->lineEdit,&QLineEdit::textEdited,this->ui->textEdit,&QTextEdit::append);
}

DialogPrecheck::~DialogPrecheck()
{
    delete ui;
}

//自定义成员函数
void DialogPrecheck::preCheckNFCCard()
{
    static int i = 80000000;
    i++;
    this->ui->lineEdit->setText(QString::number(i));

}
//自定义槽函数

//系统默认槽函数
void DialogPrecheck::on_pushButton_2_clicked()
{
    this->hide();
    emit signalDP_MWbtnShowDM("signalDP_MWbtnShowDM");
}

void DialogPrecheck::on_pushButton_3_clicked()
{
    this->hide();
    emit signalDP_MWbtnShowDC("signalDP_MWbtnShowDC");
}

void DialogPrecheck::on_pushButton_8_clicked()
{
    this->preCheckNFCCard();
}


void DialogPrecheck::on_lineEdit_textEdited(const QString &arg1)
{
    qDebug()<<"textEdited"<<arg1<<endl;
    ui->textEdit->append(arg1);
    ui->textBrowser->append(arg1);
}

void DialogPrecheck::on_lineEdit_textChanged(const QString &arg1)
{
    qDebug()<<"DialogPrecheck::on_lineEdit_textChanged"<<arg1<<endl;
    ui->textEdit->append(arg1);
    ui->textBrowser->append(arg1);
}
