#include "selectexecuter.h"
#include <iostream>

SelectExecuter::SelectExecuter(string table)
{
    this->table = table;
}

vector<QuerySet> SelectExecuter::doSelect()
{
    string fil;
    if (this->filter.isEmpty()) {
        fil = "";
    }
    else {
        fil =" WHERE " + this->filter.toString();
    }

    string result = "SELECT * FROM " + this->table + fil + ";";
//    cout << result << endl;
    return this->maker->doSelectQuery(result);
}
