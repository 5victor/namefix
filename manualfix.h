#ifndef MANUALFIX_H
#define MANUALFIX_H

#include <QDialog>

namespace Ui {
class ManualFix;
}

class ManualFix : public QDialog
{
    Q_OBJECT

public:
    explicit ManualFix(QWidget *parent = 0);
    ~ManualFix();

private:
    Ui::ManualFix *ui;
};

#endif // MANUALFIX_H
