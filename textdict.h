#ifndef TEXTDICT_H
#define TEXTDICT_H

#include <QTextStream>

class TextDict
{
public:
    TextDict();
    bool setDictFile(QString fileName);
    bool isWordInDict(QString word);

private:
    QTextStream *dict;
};

#endif // TEXTDICT_H
