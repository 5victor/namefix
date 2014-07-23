#include "mmm.h"

MMM::MMM()
{
}

bool MMM::initDict(QString fileName)
{
    dict = new TextDict();

    return dict->setDictFile(fileName);
}

QString MMM::segment(QString sentence)
{

}
