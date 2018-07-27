#ifndef EXECUTER_FILTER_H
#define EXECUTER_FILTER_H

#include <string>
#include <vector>
#include <map>
using namespace std;

class Executer_Filter
{
public:
    const string STATUS = "AND";
    Executer_Filter();
    map<string, string> indexs;

    void addFilter(string key, string value);

    bool isEmpty();

    string toString();

};

#endif // EXECUTER_FILTER_H
