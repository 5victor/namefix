#ifndef MDBDICT_H
#define MDBDICT_H

class MDBDict
{
public:
    MDBDict();
    // a Dict map to a Table in the mdb file
    bool openDict(QString dictName);

    bool isWordInDict(QString word);
    bool insertWordToDict(QString word);
};

#endif // MDBDICT_H
