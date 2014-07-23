#include "manualfix.h"
#include "ui_manualfix.h"

ManualFix::ManualFix(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManualFix)
{
    ui->setupUi(this);
}

ManualFix::~ManualFix()
{
    delete ui;
}
