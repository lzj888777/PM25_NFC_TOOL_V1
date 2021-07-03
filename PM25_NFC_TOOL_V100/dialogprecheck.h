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

private:
    Ui::DialogPrecheck *ui;
};

#endif // DIALOGPRECHECK_H
