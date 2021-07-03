#ifndef DIALOGLOGIN_H
#define DIALOGLOGIN_H

#include <QDialog>

namespace Ui {
class DialogLogin;
}

class DialogLogin : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLogin(QWidget *parent = nullptr);
    ~DialogLogin();

protected:
    int checkPassword(QString x);
    int checkAccount(QString x);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::DialogLogin *ui;

signals:
    void toMainwindow(QString x);
    void signalDLshow(QString x );
    void signalDLclose(QString x );
};

#endif // DIALOGLOGIN_H
