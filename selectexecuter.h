#ifndef SELECTEXECUTER_H
#define SELECTEXECUTER_H

#include "executer.h"


// over test
class SelectExecuter : public Executer
{
public:
    SelectExecuter(string table);
    // 全部查询
    vector<QuerySet> doSelect();

};

#endif // SELECTEXECUTER_H
