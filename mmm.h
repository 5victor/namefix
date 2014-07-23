#ifndef MMM_H
#define MMM_H

#include "textdict.h"

// MaximumMatchingMethod

class MMM
{
public:
    MMM();
    bool initDict(QString fileName);
    QString segment(QString sentence);

private:
    TextDict *dict;
};

#endif // MMM_H
