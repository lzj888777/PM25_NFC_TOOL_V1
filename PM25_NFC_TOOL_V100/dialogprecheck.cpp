#include "dialogprecheck.h"
#include "ui_dialogprecheck.h"

DialogPrecheck::DialogPrecheck(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPrecheck)
{
    ui->setupUi(this);

    QPixmap *pixmap = new QPixmap(":/image/dialogprecheck/1.png");
    pixmap->scaled(ui->label->size(),Qt::KeepAspectRatio);//把图片自适应label大小
    ui->label->setScaledContents(true);
//    ui->label->setPixmap(*pixmap); //将图片放入label，使用setPixmap,注意指针*img
//    ui->label->setAlignment(Qt::AlignCenter); //将图片放在label中心，用缩放了就不需要了
}

DialogPrecheck::~DialogPrecheck()
{
    delete ui;
}
