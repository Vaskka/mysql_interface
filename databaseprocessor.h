/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   DatabaseProcessor.h
 * Author: vaskka
 * TODO:   接入数据库的统一接口
 * Created on 2018年7月25日, 下午10:28
 */

#ifndef DATABASEPROCESSOR_H
#define DATABASEPROCESSOR_H

using namespace std;
#include <string>
#include <mysql/mysql.h>

class DatabaseProcessor {
public:
    DatabaseProcessor();
    DatabaseProcessor(string host, string user, string password, string port, string databaseName);
    virtual ~DatabaseProcessor();

    // 创建数据库连接
    bool initMysql();
private:
    // 数据库类型（可扩展选择不同数据库）
    const string databaseType = "MySQL";

    // real address
    string address;

    // 地址
    string host;

    // 用户名
    string user;

    // 密码
    string password;

    // 端口
    string port;

    // 数据库名
    string databaseName;

    // 数据库连接
    MYSQL *connection;

public:
    // setter and getter
    void setHost(string host) {
        this->host = host;
    }
    string getHost() {
        return this->host;
    }

    void setUser(string user) {
        this->user = user;
    }
    string getUser() {
        return this->user;
    }

    void setPassword(string s) {
        this->password = s;
    }
    string getPassword() {
        return this->password;
    }

    void setPort(int port) {
        this->port = port;
    }
    string getPort() {
        return this->port;
    }

    void setDatabaseName(string name) {
        this->databaseName = name;
    }
    string getDatabase() {
        return this->databaseName;
    }


    // 连接数据库
    bool doConnectDatabase();

    // 执行查询
    bool doSelectQuery(string query);

    // 执行插入
    bool doInsertQuery(string query);

    // 执行删除
    bool doDeleteQuery(string query);

    // 执行修改
    bool doUpdateQuery(string query);

    // 错误处理
    void dealWithErrors();





};

#endif /* DATABASEPROCESSOR_H */

