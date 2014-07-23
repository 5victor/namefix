#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "excel.h"
#include "mmm.h"
#include <QCloseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void updateWorkSheetName();
    void updateColumnName();
    void closeEvent (QCloseEvent * event);
    void dumpColumn(QString fileName);
    void fix(QString fileName);

private slots:
    void on_fixName_clicked();

    void on_openFile_clicked();
    
    void on_sheetName_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    
private:
    Excel *excel;
    MMM *mmm;
};

#endif // MAINWINDOW_H
