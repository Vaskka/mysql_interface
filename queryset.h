#ifndef QUERYSET_H
#define QUERYSET_H

#include <string>
#include <map>
using namespace std;

class QuerySet
{
public:
    QuerySet();

    string operator[](string key);

    void setValue(string key, string value);

    void setValue(string key, int value);

    string findValue(string key);


    map<string, string> getDict() const;

private:
    map<string, string> dict;


};

#endif // QUERYSET_H
