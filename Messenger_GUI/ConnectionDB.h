#pragma once
#include "MessangerUser.h"
//#include <iostream>
//#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

class ConnectionDB
{
private:

#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1000
    bool _status = false;
    SQLHANDLE sqlConnHandle{ nullptr }; // дескриптор для соединения с базой данных
    SQLHANDLE sqlEnvHandle{ nullptr }; // дескриптор окружения базы данных
    SQLHANDLE sqlStmtHandle{ nullptr };  // дескриптор для выполнения запросов к базе данных
    SQLWCHAR retconstring[SQL_RETURN_CODE_LEN]{}; // строка для кода возврата из функций API ODBC

    void setStatus(bool status);
    void innitConnect();
    void creatingAndFillingTables();
    bool setSQL(const wchar_t* sql, int type);
    bool creatingSQL_Query(std::string str);
    void disconnect();
    std::list<MessangerUser> selectThreeColumnTables(const wchar_t* sql);
    std::list<PrivateChat> selectPrivateChat(const wchar_t* sql);
    std::map<int, std::list<std::string>> selectPrivateChatHistorySQL(const wchar_t* sql);

public:
    ConnectionDB();
    ~ConnectionDB();
    //void selectAllUsers();
    std::list<MessangerUser> selectAllUsers();
    std::list<std::string> selectMessageGeneralChat();
    std::list<PrivateChat> selectPrivateChat();
    std::map<int, std::list<std::string>> selectPrivateChatHistory(std::list<int> arrChatId);
    bool insertUser(MessangerUser user);
    bool insertGeneralChatMessage(std::string login, std::string dateMessage, std::string message);

    bool setPrivateChatMessage(int chatID, std::string loginCompanion, std::string message);
    bool createPrivateChatMessage(std::string login, std::string loginCompanion, std::string message);
    bool setSQL_SELECT(const wchar_t* sql);
    bool setSQL_INSERT(const wchar_t* sql);
    bool getStatus();
};

