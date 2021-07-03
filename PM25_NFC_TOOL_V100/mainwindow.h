#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "dialoglogin.h"
#include "dialogprecheck.h"
#include "dialogmanufacture.h"
#include "dialogcheck.h"


#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    //SLOT DL
    void slotDLShow(QString x);
    void slotDLclose();

    //SLOT DP
    void slotDP_MWbtnShowDM(QString x);
    void slotDP_MWbtnShowDC(QString x);

    //SLOT DM
    void slotDM_MWbtnShowDP(QString x);
    void slotDM_MWbtnShowDC(QString x);

    //SLOT DC
    void slotDC_MWbtnShowDP(QString x);
    void slotDC_MWbtnShowDM(QString x);
private slots:
    void on_pushButton_clicked();

private:

    Ui::MainWindow *ui;
    //UI测试阶段
    DialogCheck dc;
//    dc.show();

    DialogManufacture dm;
//    dm.show();

    DialogPrecheck dp;
//    dp.show();

    DialogLogin dl;

signals:
    void signalMWclose();
    void signalMW_MWShow(QString x);
};
#endif // MAINWINDOW_H
