#ifndef DIALOGPRECHECK_H
#define DIALOGPRECHECK_H

#include <QDialog>

namespace Ui {
class DialogPrecheck;
}

class DialogPrecheck : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPrecheck(QWidget *parent = nullptr);
    ~DialogPrecheck();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_8_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::DialogPrecheck *ui;

    void preCheckNFCCard();
signals:
    void signalDP_MWbtnShowDM(QString x );
    void signalDP_MWbtnShowDC(QString x );
};

#endif // DIALOGPRECHECK_H
