#include "dialogcheck.h"
#include "ui_dialogcheck.h"

DialogCheck::DialogCheck(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCheck)
{
    ui->setupUi(this);

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
