#ifndef EXCEL_H
#define EXCEL_H

#include <QAxObject>

class Excel
{
public:
    Excel();

    //int setFile(QString file);
    int openExcel();
    void setDebug(bool dbg);
    int openFile(QString file);
    //int createFile();
    // open Active workbook

    int openWorkSheet(int index);
    QString getCellValue(int x, int y);

private:
    int openWorkBook();
    int openWorkSheets();

private:
    QString fileName;
    bool debug;
    
private:
    QAxObject *excelApp;
    QAxObject *workBooks;
    QAxObject *activeWorkBook;
    QAxObject *workSheets;
    QAxObject *workSheet;
};

#endif // EXCEL_H
