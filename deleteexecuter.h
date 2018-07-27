#ifndef DELETEEXECUTER_H
#define DELETEEXECUTER_H

#include "executer.h"

// over test
class DeleteExecuter : public Executer
{
public:
    DeleteExecuter(string table);

    void doDelete();
};

#endif // DELETEEXECUTER_H
