#include "excel.h"
#include "errno.h"
#include <QDebug>

Excel::Excel()
{
    debug = true;
}

void Excel::setDebug(bool dbg)
{
    debug = dbg;
}

/*
int Excel::setFile(QString file)
{
    fileName = file;
}
*/

int Excel::openExcel()
{
    excelApp = new QAxObject("Excel.Application");

    if (debug) {
        excelApp->setProperty("Visible", true);
    }

    excelApp->setProperty("Caption", "RoRo.Lin");

    return 0;
}

int Excel::openFile(QString file)
{
    if (file.isEmpty())
        return -EINVAL;
    
    workBooks = excelApp->querySubObject("WorkBooks");
    workBooks->dynamicCall("Open(const QString&)", file);
    openWorkBook();
    openWorkSheets();

    return 0;
}

int Excel::openWorkBook()
{
    activeWorkBook = excelApp->querySubObject("ActiveWorkBook");

    return 0;
}

int Excel::openWorkSheets()
{
    workSheets = activeWorkBook->querySubObject("WorkSheets");

    return 0;
}

int Excel::openWorkSheet(int index)
{
    workSheet = activeWorkBook->querySubObject("Worksheets(int)", index);
    qDebug() << "openWorkSheet";

    return 0;
}

QString Excel::getCellValue(int x, int y)
{
    QAxObject *cell = workSheet->querySubObject("Cells(int,int)", x, y);
    qDebug() << "getCellValue";
    return cell->property("Value").toString();
}
