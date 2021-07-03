#ifndef DIALOGMANUFACTURE_H
#define DIALOGMANUFACTURE_H

#include <QDialog>

namespace Ui {
class DialogManufacture;
}

class DialogManufacture : public QDialog
{
    Q_OBJECT

public:
    explicit DialogManufacture(QWidget *parent = nullptr);
    ~DialogManufacture();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_11_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

private:
    Ui::DialogManufacture *ui;

    void manufactureNFCCard();
signals:
    void signalDM_MWbtnShowDP(QString x);
    void signalDM_MWbtnShowDC(QString x);
};

#endif // DIALOGMANUFACTURE_H
