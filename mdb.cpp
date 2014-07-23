#include "mdb.h"
#include <QTime>
#include <QSqlError>

MDB::MDB()
{
}

bool MDB::openDB(QString file)
{
    QString dsn;
    bool ret;
    QTime t;

    do {
    t = QTime::currentTime();
    qsrand(t.msec() + t.second()*1000);

    connectionName = QString::number(qrand());

    db = QSqlDatabase::database(connectName, false);

    if (!db.isValid())
        break;
    } while (1);

    db = QSqlDatabase::addDatabase("QODBC", connectionName);
    dsn.sprintf("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=%s", file);
    db.setDatabaseName(dsb);
    ret = db.open();

    return ret;
}

bool MDB::openTable(QString t)
{
    bool rc;
    QSqlError error;

    table = new QSqlTableModel(NULL, db);
    table.setTable(t);

    error = table.lastError();

    rc = error.type() == QSqlError::ErrorType::NoError;

    return rc;
}
