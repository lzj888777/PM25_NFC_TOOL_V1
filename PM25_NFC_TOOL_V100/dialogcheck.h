#ifndef DIALOGCHECK_H
#define DIALOGCHECK_H

#include <QDialog>

namespace Ui {
class DialogCheck;
}

class DialogCheck : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCheck(QWidget *parent = nullptr);
    ~DialogCheck();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_11_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

private:
    Ui::DialogCheck *ui;

    void checkNFCCard();
signals:
    void signalDC_MWbtnShowDP(QString x);
    void signalDC_MWbtnShowDM(QString x);
};

#endif // DIALOGCHECK_H
