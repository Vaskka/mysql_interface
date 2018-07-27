#include "base_database.h"
#include <iostream>

#include <mysql/mysql.h>
using namespace std;

base_database::base_database()
{

}

base_database::base_database(string host, string password, int port, string user, string database)
{
    this->host = host;
this->password = password;
this->port =port;
this->user = user;
this->database =database;
}

string base_database::getDatabase() const
{
    return database;
}

void base_database::setDatabase(const string &value)
{
    database = value;
}

string base_database::getUser() const
{
    return user;
}

void base_database::setUser(const string &value)
{
    user = value;
}

int base_database::getPort() const
{
    return port;
}

void base_database::setPort(int value)
{
    port = value;
}

string base_database::getPassword() const
{
    return password;
}

void base_database::setPassword(const string &value)
{
    password = value;
}

string base_database::getHost() const
{
    return host;
}

void base_database::setHost(const string &value)
{
    host = value;
}

vector<QuerySet> base_database::doSelectQuery(string sql)
{
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_real_connect(&mysql, this->host.c_str(), this->user.c_str(), this->password.c_str(), this->database.c_str(), (unsigned int)this->port, NULL, 0);

    try
    {
        if (mysql_query(&mysql, sql.c_str()))
        {
            string err_string = mysql_error(&mysql);

            if(err_string.empty())
                throw string("MySQL query is error!");
            else
                throw err_string;
        }
        MYSQL_RES *result = mysql_store_result(&mysql);
        if (!result)
            throw string("MySQL not result!");

        //获取字段数量
        int num_fields = mysql_num_fields(result);
        if(0 == num_fields)
            throw string("MySQL fields number is 0!");

        //获取字段名
        MYSQL_FIELD *fields = mysql_fetch_fields(result);
        if (!fields)
            throw string("MySQL fields fetch is error!");
        // 得到结果集
        vector<QuerySet> allResult;
        while(MYSQL_ROW row = mysql_fetch_row(result))
        {

            QuerySet queryResult = QuerySet();

            for (int i = 0; i < num_fields; i++)
            {
                if (row[i])
                    queryResult.setValue(fields[i].name, row[i]);
                else
                    queryResult.setValue(fields[i].name, "NULL");
            }
            allResult.push_back(queryResult);
        }
        mysql_close(&mysql);
        return allResult;

    }
    catch (string &error_msg)
    {
        cout << error_msg << endl;
    }
    catch (...)
    {
        cout << "MySQL operation is error!" << endl;
    }

    mysql_close(&mysql);
}

void base_database::doUpdateQuery(string sql)
{
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_real_connect(&mysql, this->host.c_str(), this->user.c_str(), this->password.c_str(), this->database.c_str(), (unsigned int)this->port, NULL, 0);

try {
        if (mysql_query(&mysql, sql.c_str()))
        {
            string err_string = mysql_error(&mysql);

            if(err_string.empty())
                throw string("MySQL query is error!");
            else
                throw err_string;
        }
    }
    catch (string &error_msg)
    {
        cout << error_msg << endl;
    }
    catch (...)
    {
        cout << "MySQL operation is error!" << endl;
    }

    mysql_close(&mysql);
}

void base_database::doDeleteQuery(string sql)
{
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_real_connect(&mysql, this->host.c_str(), this->user.c_str(), this->password.c_str(), this->database.c_str(), (unsigned int)this->port, NULL, 0);

    try {
        if (mysql_query(&mysql, sql.c_str()))
        {
            string err_string = mysql_error(&mysql);

            if(err_string.empty())
                throw string("MySQL query is error!");
            else
                throw err_string;
        }
    }
    catch (string &error_msg)
    {
        cout << error_msg << endl;
    }
    catch (...)
    {
        cout << "MySQL operation is error!" << endl;
    }

    mysql_close(&mysql);
}

void base_database::doInsertQuery(string sql)
{
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_real_connect(&mysql, this->host.c_str(), this->user.c_str(), this->password.c_str(), this->database.c_str(), (unsigned int)this->port, NULL, 0);

try {
        if (mysql_query(&mysql, sql.c_str()))
        {
            string err_string = mysql_error(&mysql);

            if(err_string.empty())
                throw string("MySQL query is error!");
            else
                throw err_string;
        }
    }
    catch (string &error_msg)
    {
        cout << error_msg << endl;
    }
    catch (...)
    {
        cout << "MySQL operation is error!" << endl;
    }

    mysql_close(&mysql);
}

void base_database::init_mysql(MYSQL &mysql)
{
    mysql_init(&mysql);
    mysql_real_connect(&mysql, this->host.c_str(), this->user.c_str(), this->password.c_str(), this->database.c_str(), (unsigned int)this->port, NULL, 0);

}
