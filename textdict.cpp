#include "textdict.h"
#include <QFile>
#include <QTextStream>

TextDict::TextDict()
{
}

bool TextDict::setDictFile(QString fileName)
{
    QFile file(fileName);

    file.open(QIODevice::WriteOnly | QIODevice::Text);
    if (!file.isOpen())
        return false;

    dict = new QTextStream(&file);
    return true;
}

bool TextDict::isWordInDict(QString word)
{
    dict->seek(0);

    do {
        QString line = dict->readLine();
        if (!word.compare(line))
            return true;
    } while (!dict->atEnd());

    return false;
}
