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

private:
    Ui::DialogCheck *ui;
};

#endif // DIALOGCHECK_H
