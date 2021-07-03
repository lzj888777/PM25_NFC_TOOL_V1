#include "dialoglogin.h"
#include "ui_dialoglogin.h"

#include <QDebug>
#include <QMessageBox>

DialogLogin::DialogLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLogin)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);

    //信号和槽
    //    connect();


}

DialogLogin::~DialogLogin()
{
    delete ui;
}

int DialogLogin::checkAccount(QString x)

{
    x = ui->lineEdit->text();
    if(x == "sayes"){
        return 1;
    }
    else{
        return 0;
    }

}

int DialogLogin::checkPassword(QString x)

{
    x = ui->lineEdit_2->text();
    if(x == "123456"){
        return 1;
    }
    else{
        return 0;
    }

}

void DialogLogin::on_pushButton_clicked()
{
    int i,k;
    QString x;
    i = this->checkAccount(x);
    if(i){
        qDebug()<<"Account is checked ok!"<<endl;

    }
    else {
        qDebug()<<"Account is checked faults!"<<endl;

    }
    k = this->checkPassword(x);
    if(k){
        qDebug()<<"Password is checked ok!"<<endl;
    }
    else {
        qDebug()<<"Password is checked faults!"<<endl;

    }
    if(i == 1 && k == 1){

        this->hide();
        emit toMainwindow("login success!");
        emit signalDLshow("login success!");


    }
    else if(i==0&&k==1){
        QMessageBox::warning(this,"Error Message","Account is checked faults!");
    }
    else if(i==1&&k==0){
        QMessageBox::warning(this,"Error Message","Password is checked faults!");
    }
    else{
        QMessageBox::warning(this,"Error Message","Account and Password is checked faults!");
    }
}

void DialogLogin::on_pushButton_2_clicked()
{
    this->close();
    qDebug()<<"close1"<<endl;
    emit signalDLclose("login close");
    qDebug()<<"close2"<<endl;


}
