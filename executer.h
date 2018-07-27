#ifndef EXECUTER_H
#define EXECUTER_H

#include <map>
#include <string>
#include <vector>
#include "base_database.h"
#include "executer_filter.h"
#include "queryset.h"
using namespace std;

class Executer
{
public:
    Executer();
    Executer(string table);
    string table;

    base_database *maker = new base_database("127.0.0.1", "0000", 3306, "test", "new_blog");

    // 过滤器
    Executer_Filter filter;


//    // 插入
//    static void dealInsert();

//    // 更新
//    static void dealUpdate(QuerySet value);

//    // 删除
//    static void dealDelete();

};

#endif // EXECUTER_H
