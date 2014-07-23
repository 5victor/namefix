#ifndef MDB_H
#define MDB_H

#include <QSqlDatabase>
#include <QSqlTableModel>

class MDB
{
public:
    MDB();
    bool openDB(QString file);
    // connectName - useto open one db instance while multiple MDB object.
    bool openDB(QString file, QString connectionName);
    bool openTable(QString table);

private:

    QSqlDatabase db;
    QSqlTableModel table;
    QString connectionName;
};

#endif // MDB_H
