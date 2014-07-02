#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "excel.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_fixName_clicked();

    void on_openFile_clicked();
    
private:
    Ui::MainWindow *ui;
    
private:
    Excel *excel;
};

#endif // MAINWINDOW_H
