#include <QCoreApplication>
#include <iostream>
#include <mysql/mysql.h>
#include <iostream>
#include "base_database.h"
#include "deleteexecuter.h"
#include "executer_filter.h"
#include "insertexecuter.h"
#include "selectexecuter.h"
#include "updateexecuter.h"
using namespace std;

void showQuerySetList(vector<QuerySet> result) {
    for (QuerySet q : result) {
        map<string,string> dict = q.getDict();
        map<string,string>::iterator ite;
        for (ite=dict.begin(); ite!=dict.end(); ite++) {
            cout << ite->first << " " << ite->second << endl;
        }
        cout << "=====================" << endl;
    }

}

int main(int argc, char *argv[])
{
//base_database *test = new  base_database("127.0.0.1", "0000", 3306, "test", "new_blog");
//QuerySet t = test->doSelectQuery("select * from blog_article;");

//cout << t.findValue("summary");
//    Executer_Filter a = Executer_Filter();
//    a.addFilter("id", "40");
//    a.addFilter("title", "4asd0");
//    a.addFilter("content", "asdasd");
//    a.addFilter("summary", "4fevrv0");
//    cout << a.toString();

    UpdateExecuter *test = new UpdateExecuter("blog_banner");

    test->filter.addFilter("id", "16");
    QuerySet dict = QuerySet();
    dict.setValue("title", "sad");
    dict.setValue("image", "asdas");
        dict.setValue("banner_date", "sadasdsadasdasdasdas");
    cout << dict["title"];
        //    test->doUpdate(dict);



}
