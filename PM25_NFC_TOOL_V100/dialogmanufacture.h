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

private:
    Ui::DialogManufacture *ui;
};

#endif // DIALOGMANUFACTURE_H
