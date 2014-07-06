#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "excel.h"

#include <QFileDialog>
#include <QDebug>
#include <QFile>

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
    QString fileName = QFileDialog::getSaveFileName(this, "保存Excel", "", "Excel Files(*.txt)");
    dumpColumn(fileName);
}

void MainWindow::dumpColumn(QString fileName)
{
    int count;
    int i;
    int column;
    QFile file(fileName);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);

    count = excel->getUsedRowCount();
    column = ui->columnName->currentIndex();
    ui->progressBar->setMaximum(count - 1);
    for (i = 0; i < count; i++) {
        QString value = excel->getCellValue(i, column);
        out << value << endl;
        ui->progressBar->setValue(i);
    }
    file.close();
}

void MainWindow::on_openFile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "打开Excel", "", "Excel Files(*.xls *.xlsx)");
    ui->fileName->setText(fileName);
    excel->openExcel();
    excel->openFile(fileName);

    updateWorkSheetName();
    int sheetIndex = ui->sheetName->currentIndex();
    excel->openWorkSheet(sheetIndex);
    updateColumnName();

//    excel->openWorkSheet(1);

//    QString cell = excel->getCellValue(1, 1);
//    qDebug() << cell << endl;
}

void MainWindow::updateWorkSheetName()
{
    int count = excel->getWorkSheetCount();

    for (int i = 0; i < count; i++) {
        QString name = excel->getWorkSheetName(i);
        ui->sheetName->addItem(name);
    }
}

void MainWindow::updateColumnName()
{
    int count = excel->getUsedColumnCount();
    ui->columnName->clear();
    for (int i = 0; i < count; i++) {
        QString name;
        name = excel->getColumnNameByIndex(i);
        ui->columnName->addItem(name);
    }
}

void MainWindow::on_sheetName_currentIndexChanged(int index)
{
    excel->openWorkSheet(index);
    updateColumnName();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    excel->closeExcel();
    event->ignore();
    event->accept();
}
