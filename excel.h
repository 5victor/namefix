#ifndef EXCEL_H
#define EXCEL_H

#include <QAxObject>

/* Notice all index in this class start by zero
 * But Excel start by one
 */

class Excel
{
public:
    Excel();

    //int setFile(QString file);
    int openExcel();
    void closeExcel();
    void setDebug(bool dbg);
    int openFile(QString file);
    //int createFile();
    // open Active workbook

    //index start by zero
    int openWorkSheet(int index);
    QString getCellValue(int rowIndex, int columnIndex);
    int getWorkSheetCount();
    //index start by zero
    QString getWorkSheetName(int index);
    int getUsedRowCount();
    int getUsedColumnCount();
    QString getColumnNameByIndex(int index);

private:
    int openWorkBook();
    int openWorkSheets();
    int openUsedRange();
    void genObjDoc(QAxObject *obj);

private:
    QString fileName;
    bool debug;
    
private:
    QAxObject *excelApp;
    QAxObject *workBooks;
    QAxObject *activeWorkBook;
    QAxObject *workSheets;
    QAxObject *workSheet;
    QAxObject *usedRange;
};

#endif // EXCEL_H
