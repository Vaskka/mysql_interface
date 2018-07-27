/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   DatabaseProcessor.cpp
 * Author: vaskka
 *
 * Created on 2018年7月25日, 下午10:28
 */

#include "databaseprocessor.h"
#include "utils.h"
#include <QDebug>
#include <mysql/mysql.h>
#include <QString>
#include <iostream>
using namespace std;

DatabaseProcessor::DatabaseProcessor() {
}

/**
 * 初始化数据库接口
 * @param host ip
 * @param user 用户名
 * @param password 密码
 * @param port 端口号
 * @param databaseName 数据库名
 */
DatabaseProcessor::DatabaseProcessor(string host, string user, string password, string port, string databaseName) {
    this->host = host;
    this->user = user;
    this->password = password;
    this->port;
    this->databaseName = databaseName;

    this->address = (this->host + ":" + this->port);
}

DatabaseProcessor::~DatabaseProcessor() {
}

/**
错误处理
*/
void DatabaseProcessor::dealWithErrors() {
    fprintf(stderr, "%s\n", mysql_error(this->connection));
    mysql_close(this->connection);
    this->connection = NULL;
}

/**
 * 初始化mysql
 * @return
 */

bool DatabaseProcessor::initMysql() {

    this->connection = mysql_init(this->connection);

    if (!this->connection) {
        Utils::L("数据库初始化错误");
        return false;
    }

    return true;

}

/**
 * 执行数据库连接
 * @return  bool
 */
bool DatabaseProcessor::doConnectDatabase() {
    this->initMysql();

    this->connection = mysql_real_connect(this->connection, this->address.c_str(),
            this->user.c_str(), this->password.c_str(), this->databaseName.c_str(), 0, NULL, 0);
}

/**
 * 执行查询
 * @param query sql
 * @return bool
 */
bool DatabaseProcessor::doSelectQuery(string query) {


    this->doConnectDatabase();

    MYSQL_ROW row;

    if(mysql_query(connection, query.c_str()))
    {
        this->dealWithErrors();
        return false;
    }
    else
    {
            MYSQL_RES *result = mysql_use_result(connection); // 获取结果集
            // mysql_field_count()返回connection查询的列数
            int num_fields = mysql_num_fields(result);

            while ((row = mysql_fetch_row(result)))
            {
                for(int i = 0; i < num_fields; i++)
                {
                     QString str(row[i] ? row[i] : "NULL");
                     qDebug() << str;
                }

                printf("\n");
            }
            // 释放结果集的内存
            mysql_free_result(result);
    }
    return true;
}

/**
 * 执行插入
 * @param query sql
 * @return bool
 */
bool DatabaseProcessor::doInsertQuery(string query) {
    this->doConnectDatabase();
    if (mysql_query(this->connection, query.c_str()))
    {
        this->dealWithErrors();
        return false;
    }
    return true;
}

/**
 * 执行删除
 * @param query sql
 * @return bool
 */
bool DatabaseProcessor::doDeleteQuery(string query) {
    this->doConnectDatabase();
    if (mysql_query(this->connection, query.c_str()))
    {
        this->dealWithErrors();
        return false;
    }
    return true;
}

/**
 * 执行更新
 * @param query sql
 * @return bool
 */
bool DatabaseProcessor::doUpdateQuery(string query) {
    this->doConnectDatabase();
    if (mysql_query(this->connection, query.c_str()))
    {
        this->dealWithErrors();
        return false;
    }
    return true;
}

