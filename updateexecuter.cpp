#include "updateexecuter.h"
#include <cstring>
#include <iostream>

UpdateExecuter::UpdateExecuter(string table)
{
    this->table = table;
}

void UpdateExecuter::doUpdate(QuerySet dataToUpdate)
{
    string setValue = "";
    map<string ,string> dict = dataToUpdate.getDict();

    map<string ,string>::iterator ite;
    for (ite=dict.begin(); ite!=dict.end(); ite++) {
        setValue += (ite->first + "='" + ite->second + "',");
    }
    setValue = setValue.substr(0, setValue.length() - 1);

    string whereValue = "";
    whereValue += (" WHERE " + this->filter.toString());

    string result = "UPDATE " + this->table + " SET " + setValue + whereValue + ";";
    this->maker->doUpdateQuery(result);
}
