#include "queryset.h"

#include <string>
#include <sstream>
using namespace std;

QuerySet::QuerySet()
{

}

string QuerySet::operator[](string key)
{
    return this->dict[key];
}

// 设置queryset
void QuerySet::setValue(string key, string value)
{
    this->dict[key] = value;
}

void QuerySet::setValue(string key, int value)
{
    stringstream ss;
    string s;
    ss << value;

    ss >> s;
    this->dict[key] = s;
}

// 查找queryset
string QuerySet::findValue(string key)
{
    return this->dict[key];
}

map<string, string> QuerySet::getDict() const
{
    return dict;
}

