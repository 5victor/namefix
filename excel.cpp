#include "excel.h"
#include "errno.h"
#include <QDebug>
#include <QFile>

Excel::Excel()
{
    debug = true;

    excelApp = NULL;
    workBooks = NULL;
    activeWorkBook = NULL;
    workSheets = NULL;
    workSheet = NULL;
    usedRange = NULL;
}

void Excel::genObjDoc(QAxObject *obj)
{
    static int num = 0;
    QString name = "c://excel//";
    num++;
    name = name + QString::number(num) + ".html";
    QFile file1(name);
    qDebug() << "objectName:" << obj->property("objectName").toString();
    qDebug() << "Name:" << obj->property("Name").toString();
    file1.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file1);
    out << obj->generateDocumentation();
    file1.close();
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

    genObjDoc(excelApp);

    return 0;
}

void Excel::closeExcel()
{
    if (excelApp)
        excelApp->dynamicCall("Quit()");
}

int Excel::openFile(QString file)
{
    if (file.isEmpty())
        return -EINVAL;
    
    workBooks = excelApp->querySubObject("WorkBooks");
    workBooks->dynamicCall("Open(const QString&)", file);
    openWorkBook();
    openWorkSheets();

    genObjDoc(workBooks);

    return 0;
}

int Excel::openWorkBook()
{
    activeWorkBook = excelApp->querySubObject("ActiveWorkBook");
    genObjDoc(activeWorkBook);
    return 0;
}

int Excel::openWorkSheets()
{
    workSheets = activeWorkBook->querySubObject("WorkSheets");

    genObjDoc(workSheets);

    return 0;
}

int Excel::openUsedRange()
{
    usedRange = workSheet->querySubObject("UsedRange");
    genObjDoc(usedRange);
    return 0;
}

int Excel::getUsedRowCount()
{
    QAxObject *rows = usedRange->querySubObject("Rows");
    int count = rows->property("Count").toInt();
    qDebug() << "Used Row Count:" << count;
    return count;
}

int Excel::getUsedColumnCount()
{
    QAxObject *columns = usedRange->querySubObject("Columns");
    int count = columns->property("Count").toInt();
    qDebug() << "Used columns Count:" << count;
    return count;
}

int Excel::openWorkSheet(int index)
{
    workSheet = activeWorkBook->querySubObject("Worksheets(int)", index + 1);
    qDebug() << "openWorkSheet";
    genObjDoc(workSheet);
    openUsedRange();
    return 0;
}

QString Excel::getCellValue(int x, int y)
{
    QAxObject *cell = workSheet->querySubObject("Cells(int,int)", x + 1, y + 1);
    qDebug() << "getCellValue";
 //   genObjDoc(cell);
    return cell->property("Value").toString();
}

int Excel::getWorkSheetCount()
{
    if (!workSheets)
        return 0;

    return workSheets->property("Count").toInt();
}

QString Excel::getWorkSheetName(int index)
{
    QAxObject *sheet = activeWorkBook->querySubObject("Worksheets(int)", index + 1);
    return sheet->property("Name").toString();
}

QString Excel::getColumnNameByIndex(int index)
{
    QString result;

    int i;
    int m;
    char c;

    i = index;
    //result = "";
    do {
        m = i % 26;
        c = 'A' + m;
        result.prepend(c);
        i /= 26;
    } while (i > 0);
    return result;
}
