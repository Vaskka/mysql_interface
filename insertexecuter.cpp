#include "insertexecuter.h"
#include <iostream>
using namespace std;


InsertExecuter::InsertExecuter(string table)
{

    this->table = table;
}

void InsertExecuter::doInsert(QuerySet row)
{
    // 得到格式化的列信息 数据信息
    string cols = "(";
    string data = "(";
    map<string, string> dict = row.getDict();

    map<string, string>::iterator iter;
    int count = dict.size();
    int i = 0;
    for (iter = dict.begin(); iter != dict.end(); iter++) {
        cols += iter->first;
        data += ("'" + iter->second + "'");
        if (i != count - 1) {
            cols += ",";
            data += ",";
        }
        i++;
    }

    cols += ")";
    data += ")";
    // 得到格式化的数据信息

    string result = "INSERT INTO " + this->table + " " + cols + " VALUES " + data + ";";
    cout << result;
    this->maker->doInsertQuery(result);
}
