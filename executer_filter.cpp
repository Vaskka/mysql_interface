#include "executer_filter.h"

Executer_Filter::Executer_Filter()
{

}

void Executer_Filter::addFilter(string key, string value)
{
    this->indexs[key] = value;
}

bool Executer_Filter::isEmpty()
{
    if (this->indexs.size() == 0) {
           return true;
    }
    return false;
}

string Executer_Filter::toString() {
    if (this->indexs.size() == 0) {
        return "";
    }
    string result = "";

    map<string,string>::iterator iter;
    for(iter = indexs.begin(); iter != indexs.end(); iter++)
    {
        result += (iter->first + "=" + iter->second);
        result += (" " + this->STATUS + " ");
    }

    if (this->STATUS == "AND") {
        result += "1=1";
    }
    else {
        if (this->STATUS == "OR") {
            result += "1=0;";
        }
    }

    return result;


}
