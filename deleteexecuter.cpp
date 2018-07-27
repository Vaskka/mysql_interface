#include "base_database.h"
#include "deleteexecuter.h"

#include <iostream>

DeleteExecuter::DeleteExecuter(string table)
{
    this->table = table;

}

void DeleteExecuter::doDelete()
{
    if (this->filter.isEmpty()) {
        cerr << "error:未给删除器指定过滤器" << endl;
        return;
    }
    string result = "delete from " + table + " where " + this->filter.toString() + ";";
    cout << result;
    this->maker->doDeleteQuery(result);
}


