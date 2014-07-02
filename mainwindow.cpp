#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "excel.h"

#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    excel = new Excel();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_fixName_clicked()
{

}

void MainWindow::on_openFile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "打开Excel", "", "Excel Files(*.xls *.xlsx)");
    excel->openExcel();
    excel->openFile(fileName);
    excel->openWorkSheet(1);

    QString cell = excel->getCellValue(1, 1);
    qDebug() << cell << endl;
}
