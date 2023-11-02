#include "ConnectionDB.h"

ConnectionDB::ConnectionDB() {
    //std::cout << "Constructor\n";
    innitConnect();

    //Для создание и заполнения данными тестовых таблиц!
    //creatingAndFillingTables();
}

ConnectionDB::~ConnectionDB() {
    //std::cout << "Destructor\n";
    disconnect();
}

void ConnectionDB::setStatus(bool status) {
    _status = status;
}

bool ConnectionDB::getStatus() {
    return _status;
}

bool ConnectionDB::deleteUsers(std::string userLogin) {

    std::string sql = "DELETE FROM allUsers WHERE login = '" + userLogin + "'";
    return creatingSQL_Query(sql);
}

void ConnectionDB::innitConnect() {
    // Выделяем дескриптор для базы данных
    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle)) {
        disconnect();
        return;
    }

    if (SQL_SUCCESS != SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0)) {
        disconnect();
        return;
    }

    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle)) {
        disconnect();
        return;
    }

    // Устанавливаем соединение с сервером  
    switch (SQLDriverConnect(sqlConnHandle,
        GetDesktopWindow(),
        (SQLWCHAR*)L"DRIVER={MySQL ODBC 8.1 ANSI Driver};SERVER=localhost;PORT=3306;DATABASE=testdb;UID=root;PWD=12345;",
        SQL_NTS,
        retconstring,
        1024,
        NULL,
        SQL_DRIVER_COMPLETE)) {


    case SQL_SUCCESS:
    case SQL_SUCCESS_WITH_INFO:
        //cout << "Successfully connected to SQL Server\n";
        break;

    case SQL_INVALID_HANDLE:
    case SQL_ERROR:
        //cout << "Could not connect to SQL Server\n";
        //goto COMPLETED;
        disconnect();
        return;

    default:
        break;
    }

    // Если соединение не установлено, то выходим из программы
    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle)) {
        disconnect();
        return;
    }

    //cout << "\nExecuting T-SQL query...\n";

    setStatus(true);
}

void ConnectionDB::disconnect() {
    // Закрываем соединение и выходим из программы
    setStatus(false);
    SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
    SQLDisconnect(sqlConnHandle);
    SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
    SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);
}

bool ConnectionDB::setSQL(const wchar_t* sql, int type = 0) {
    // Если выполнение запроса с ошибками, то выходим из программы
    if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)sql, SQL_NTS)) {
        //cout << "Error querying SQL Server \n";
        //goto COMPLETED;
        //disconect();
        return false;
    }
    else {

        //Объявление структуры данных для результата запроса версии SQL
        SQLCHAR sqlVersion[SQL_RESULT_LEN];
        SQLLEN sql_str_length;
        // Переменная для хранения числа столбцов
        SQLSMALLINT    V_OD_colanz, V_OD_rowcount;
        SQLINTEGER   V_OD_err, V_OD_id;
        SQLCHAR     V_OD_buffer[200];

        if (type == 1) {
            V_OD_err = SQLBindCol(sqlStmtHandle, 1, SQL_INTEGER, &V_OD_id, sizeof(V_OD_id), nullptr);
            V_OD_err = SQLBindCol(sqlStmtHandle, 2, SQL_CHAR, &V_OD_buffer, SQL_RESULT_LEN, &sql_str_length);

            // Получим значение числа столбцов
            V_OD_err = SQLNumResultCols(sqlStmtHandle, &V_OD_colanz);
            std::cout << "Col count: " << V_OD_colanz << std::endl;

            V_OD_err = SQLRowCount(sqlStmtHandle, &sql_str_length);
            std::cout << "Row count: " << sql_str_length << std::endl;


            while (SQLFetch(sqlStmtHandle) != SQL_NO_DATA) {
                //Выведем на экран версию SQL          
                std::cout << "Id: " << V_OD_id << ", name: " << V_OD_buffer << std::endl;
            }
        }
    }
    return true;
}

bool ConnectionDB::creatingSQL_Query(std::string str) {
    wchar_t* sql = new wchar_t[str.length() + 1];
    std::copy(str.begin(), str.end(), sql);
    sql[str.length()] = 0;

    bool status = setSQL(sql);

    delete[] sql;
    return status;
}

std::list<MessangerUser> ConnectionDB::selectThreeColumnTables(const wchar_t* sql) {
    std::list<MessangerUser> arrUsers;
    // Если выполнение запроса с ошибками, то выходим из программы
    if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)sql, SQL_NTS)) {
        std::cout << "Error querying SQL Server \n";
        //disconect();
        //return;
    }
    else {

        //Объявление структуры данных для результата запроса версии SQL
        SQLCHAR sqlVersion[SQL_RESULT_LEN];
        SQLLEN sql_str_length;
        // Переменная для хранения числа столбцов
        SQLSMALLINT    V_OD_colanz, V_OD_rowcount;
        SQLINTEGER   V_OD_err, V_OD_id, V_OD_status, V_OD_role;
        SQLCHAR     V_name_buf[255], V_login_buf[255], V_passwoed_buf[255];


        V_OD_err = SQLBindCol(sqlStmtHandle, 1, SQL_INTEGER, &V_OD_id, sizeof(V_OD_id), nullptr);
        V_OD_err = SQLBindCol(sqlStmtHandle, 2, SQL_CHAR, &V_name_buf, SQL_RESULT_LEN, &sql_str_length);
        V_OD_err = SQLBindCol(sqlStmtHandle, 3, SQL_CHAR, &V_login_buf, SQL_RESULT_LEN, &sql_str_length);
        V_OD_err = SQLBindCol(sqlStmtHandle, 4, SQL_CHAR, &V_passwoed_buf, SQL_RESULT_LEN, &sql_str_length);
        V_OD_err = SQLBindCol(sqlStmtHandle, 5, SQL_INTEGER, &V_OD_status, sizeof(V_OD_status), nullptr);
        V_OD_err = SQLBindCol(sqlStmtHandle, 6, SQL_INTEGER, &V_OD_role, sizeof(V_OD_role), nullptr);

        // Получим значение числа столбцов
        V_OD_err = SQLNumResultCols(sqlStmtHandle, &V_OD_colanz);
        std::cout << "Col count: " << V_OD_colanz << std::endl;

        V_OD_err = SQLRowCount(sqlStmtHandle, &sql_str_length);
        std::cout << "Row count: " << sql_str_length << std::endl;


        std::cout << "ID \t name \t login \t password \n";
        while (SQLFetch(sqlStmtHandle) != SQL_NO_DATA) {
            //Выведем на экран версию SQL          
            //std::cout << V_OD_id << '\t' << V_name_buf << '\t' << V_login_buf << '\t' << V_passwoed_buf << std::endl;
            std::string s1((const char*)V_name_buf), s2((const char*)V_login_buf), s3((const char*)V_passwoed_buf);
            MessangerUser user{ s1, s2, s3, V_OD_status, V_OD_role };
            arrUsers.push_back(user);
        }

    }
    return arrUsers;
}

std::list<PrivateChat> ConnectionDB::selectPrivateChat(const wchar_t* sql) {
    std::list<PrivateChat> arrPrivateChat;
    // Если выполнение запроса с ошибками, то выходим из программы
    if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)sql, SQL_NTS)) {
        std::cout << "Error querying SQL Server \n";
        //disconect();
        //return;
    }
    else {

        //Объявление структуры данных для результата запроса версии SQL
        SQLCHAR sqlVersion[SQL_RESULT_LEN];
        SQLLEN sql_str_length;
        // Переменная для хранения числа столбцов
        SQLSMALLINT    V_OD_colanz, V_OD_rowcount;
        SQLINTEGER   V_OD_err, V_OD_id; 
        SQLCHAR     V_login[255], V_loginCompanion[255];


        V_OD_err = SQLBindCol(sqlStmtHandle, 1, SQL_INTEGER, &V_OD_id, sizeof(V_OD_id), nullptr);
        V_OD_err = SQLBindCol(sqlStmtHandle, 2, SQL_CHAR, &V_login, SQL_RESULT_LEN, &sql_str_length);
        V_OD_err = SQLBindCol(sqlStmtHandle, 3, SQL_CHAR, &V_loginCompanion, SQL_RESULT_LEN, &sql_str_length);

        // Получим значение числа столбцов
        V_OD_err = SQLNumResultCols(sqlStmtHandle, &V_OD_colanz);
        std::cout << "Col count: " << V_OD_colanz << std::endl;

        V_OD_err = SQLRowCount(sqlStmtHandle, &sql_str_length);
        std::cout << "Row count: " << sql_str_length << std::endl;


        std::cout << "ID \t name \t login \t password \n";
        while (SQLFetch(sqlStmtHandle) != SQL_NO_DATA) {
            //Выведем на экран версию SQL          
            //std::cout << V_OD_id << '\t' << V_name_buf << '\t' << V_login_buf << '\t' << V_passwoed_buf << std::endl;
            std::string s1((const char*)V_login), s2((const char*)V_loginCompanion);
            PrivateChat chat{ V_OD_id, s1, s2 };
            //chat->setLogin(s1);
            //std::cout << chat->getChatID() << '\t' << chat->getlogin() << '\t' << chat->getloginCompanion() << '\n';
            arrPrivateChat.push_back(chat);
        }

    }
    return arrPrivateChat;
}

std::map<int, std::list<std::string>> ConnectionDB::selectPrivateChatHistorySQL(const wchar_t* sql) {
    std::map<int, std::list<std::string>> mapChatHistory;
    // Если выполнение запроса с ошибками, то выходим из программы
    if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)sql, SQL_NTS)) {
        std::cout << "Error querying SQL Server \n";
        //disconect();
        //return;
    }
    else {

        //Объявление структуры данных для результата запроса версии SQL
        SQLCHAR sqlVersion[SQL_RESULT_LEN];
        SQLLEN sql_str_length;
        // Переменная для хранения числа столбцов
        SQLSMALLINT    V_OD_colanz, V_OD_rowcount;
        SQLINTEGER   V_OD_err, V_OD_id, V_OD_chatId;
        SQLCHAR     V_message[255];


        V_OD_err = SQLBindCol(sqlStmtHandle, 1, SQL_INTEGER, &V_OD_id, sizeof(V_OD_id), nullptr);
        V_OD_err = SQLBindCol(sqlStmtHandle, 2, SQL_INTEGER, &V_OD_chatId, sizeof(V_OD_chatId), nullptr);
        V_OD_err = SQLBindCol(sqlStmtHandle, 3, SQL_CHAR, &V_message, SQL_RESULT_LEN, &sql_str_length);

        // Получим значение числа столбцов
        V_OD_err = SQLNumResultCols(sqlStmtHandle, &V_OD_colanz);
        std::cout << "Col count: " << V_OD_colanz << std::endl;

        V_OD_err = SQLRowCount(sqlStmtHandle, &sql_str_length);
        std::cout << "Row count: " << sql_str_length << std::endl;


        std::cout << "ID \t name \t login \t password \n";
        while (SQLFetch(sqlStmtHandle) != SQL_NO_DATA) {
            //Выведем на экран версию SQL          
            //std::cout << V_OD_id << '\t' << V_name_buf << '\t' << V_login_buf << '\t' << V_passwoed_buf << std::endl;
            std::string message((const char*)V_message);
            if (mapChatHistory.find(V_OD_chatId) != mapChatHistory.end()) {
                std::cout << "Key found" << std::endl;
                mapChatHistory[V_OD_chatId].push_back(message);
            }
            else {
                std::list<std::string> arrMessage;
                arrMessage.push_back(message);
                mapChatHistory.insert_or_assign(V_OD_chatId, arrMessage);
            }
            /*PrivateChat chat{ V_OD_id, s1, s2 };
            arrPrivateChat.push_back(chat);*/
        }

    }
    return mapChatHistory;
}

std::list<MessangerUser> ConnectionDB::selectAllUsers() {
    return selectThreeColumnTables(L"SELECT * from allUsers");
}

std::list<std::string> ConnectionDB::selectMessageGeneralChat() {
    //Костыль!!! здесь класс MessangerUser используется для получения данных из таблицы generalChat.
    std::list<MessangerUser> arrMessage = selectThreeColumnTables(L"SELECT * from generalChat");
    std::list<std::string> allMessage;
    for (MessangerUser message : arrMessage) {
        allMessage.push_back(message.getName() + ":" + message.getLogin() + ":" + message.getPassword());
    }
    return allMessage;
}

std::list<PrivateChat> ConnectionDB::selectPrivateChat() {
    //Костыль!!! здесь класс MessangerUser используется для получения данных из таблицы generalChat.
    std::list<PrivateChat> arrPrivateChat = selectPrivateChat(L"SELECT * from privateChat");
    //std::list<std::string> allMessage;
    //for (MessangerUser message : arrMessage) {
    //    allMessage.push_back(message.getName() + ":" + message.getLogin() + ":" + message.getPassword());
    //}
    return arrPrivateChat;
}

std::map<int, std::list<std::string>> ConnectionDB::selectPrivateChatHistory(std::list<int> arrChatId) {

    std::map<int, std::list<std::string>> mapChatHistory;
    if (arrChatId.size() <= 0)
        return mapChatHistory;
    
    std::string request = "SELECT * from privateChatHistory Where chat_id in (";
    for (int id : arrChatId) {
        request += std::to_string(id) + ",";
    }

    if (!request.empty()) {
        request.pop_back();
    }

    request += ")";

    //std::cout << request << '\n';

    wchar_t* sql = new wchar_t[request.length() + 1];
    std::copy(request.begin(), request.end(), sql);
    sql[request.length()] = 0;

    mapChatHistory = selectPrivateChatHistorySQL(sql);
    //std::list<std::string> allMessage;
    //for (MessangerUser message : arrMessage) {
    //    allMessage.push_back(message.getName() + ":" + message.getLogin() + ":" + message.getPassword());
    //}

    delete[] sql;
    return mapChatHistory;
}

bool ConnectionDB::insertUser(MessangerUser user) {
    std::string str = "INSERT INTO allUsers(id, name, login, password, status, role) values(default, '" + user.getName() + "', '" + user.getLogin() + "', '" + user.getPassword() + "', " + user.getStatusStr() + ", " + user.getRoleStr() + ");";
    std::cout << str << '\n';
    return creatingSQL_Query(str);
}

bool ConnectionDB::insertGeneralChatMessage(std::string login, std::string dateMessage, std::string message) {
    std::string str = "INSERT INTO generalChat(id, login, dateMessage, message) values(default, '" + login + "', '" + dateMessage + "', '" + message + "');";
    return creatingSQL_Query(str);
}

bool ConnectionDB::setPrivateChatMessage(int chatID, std::string loginCompanion, std::string message) {
    std::string sql = "INSERT INTO privateChatHistory(id, chat_id, message) values(default, " + std::to_string(chatID) + ", '" + message + "')";
    std::cout << sql << '\n';
    return creatingSQL_Query(sql);
}

bool ConnectionDB::createPrivateChatMessage(std::string login, std::string loginCompanion, std::string message) {
    std::string sql1 = "INSERT INTO privateChat(id, login1, login2) values(default, '" + login + "', '" + loginCompanion + "')";
    return creatingSQL_Query(sql1);

    std::list<PrivateChat> arrPrivateChat = selectPrivateChat();
    int chatID = 0;
    for (PrivateChat chat : arrPrivateChat) {
        if (chat.getlogin() == login && chat.getloginCompanion() == loginCompanion) {
            chatID = chat.getChatID();
        }
    }

    std::cout << "chatID: " << chatID << '\n';

    if (chatID != 0) {
        setPrivateChatMessage(chatID, login, loginCompanion);
    }
}

bool ConnectionDB::setSQL_SELECT(const wchar_t* sql) {
    return setSQL(sql, 1);
}

bool ConnectionDB::setSQL_INSERT(const wchar_t* sql) {
    return setSQL(sql);
}

void ConnectionDB::creatingAndFillingTables() {
    setSQL(L"CREATE TABLE allUsers(id INT AUTO_INCREMENT PRIMARY KEY, name VARCHAR(255), login VARCHAR(255), password VARCHAR(255), status INT, role INT)");
    //setSQL(L"INSERT INTO allUsers(id, name, login, password, status, role) values(default, 'kurt', 'kurt', '123qwe', 0, 0)");
    //setSQL(L"INSERT INTO allUsers(id, name, login, password, status, role) values(default, 'klark', 'klark', '123qwe', 0, 0)");
    //setSQL(L"INSERT INTO allUsers(id, name, login, password, status, role) values(default, 'кирил', 'kiril', '123qwe', 0, 0)");
    //setSQL(L"INSERT INTO allUsers(id, name, login, password, status, role) values(default, 'Олег', 'oleg', 'oleg', 0, 0)");
    //setSQL(L"INSERT INTO allUsers(id, name, login, password, status, role) values(default, 'kurt', '123qwe', 'exit', 0, 0)");
    //setSQL(L"INSERT INTO allUsers(id, name, login, password, status, role) values(default, 'df', 'sdf', 'sdfg', 0, 0)");

    setSQL(L"CREATE TABLE generalChat(id INT AUTO_INCREMENT PRIMARY KEY, login VARCHAR(255), dateMessage DATETIME, message VARCHAR(255))");
    //setSQL(L"INSERT INTO generalChat(id, login, dateMessage, message) values(default, 'klark', '2023-3-28 0:18:51', 'Добрый день! Как дела?')");
    //setSQL(L"INSERT INTO generalChat(id, login, dateMessage, message) values(default, 'klark', '2023-3-28 0:19:9', 'Что нового на HabraHabr?')");
    //setSQL(L"INSERT INTO generalChat(id, login, dateMessage, message) values(default, 'kurt', '2023-3-28 0:20:12', 'Добрый! Все как обычно')");
    //setSQL(L"INSERT INTO generalChat(id, login, dateMessage, message) values(default, 'kurt', '2023-3-28 0:20:21', 'Ничего интересного пока нет')");
    //setSQL(L"INSERT INTO generalChat(id, login, dateMessage, message) values(default, 'kurt', '2023-3-28 0:23:20', 'sd')");
    //setSQL(L"INSERT INTO generalChat(id, login, dateMessage, message) values(default, 'oleg', '2023-3-28 20:52:16', 'Привет, я Олег')");
    //setSQL(L"INSERT INTO generalChat(id, login, dateMessage, message) values(default, 'kurt', '2023-3-29 19:44:40', 'здарова народ')");
    //setSQL(L"INSERT INTO generalChat(id, login, dateMessage, message) values(default, 'kurt', '2023-3-29 19:44:43', 'че так')");
    //setSQL(L"INSERT INTO generalChat(id, login, dateMessage, message) values(default, 'kurt', '2023-3-29 19:44:46', 'тихо')");
    //setSQL(L"INSERT INTO generalChat(id, login, dateMessage, message) values(default, 'kiril', '2023-3-29 19:46:24', 'Олеееег')");

    setSQL(L"CREATE TABLE privateChat(id INT AUTO_INCREMENT PRIMARY KEY, login1 VARCHAR(255), login2 VARCHAR(255))");

    setSQL(L"CREATE TABLE privateChatHistory(id INT AUTO_INCREMENT PRIMARY KEY, chat_id INT, message VARCHAR(255))");
}