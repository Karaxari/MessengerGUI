#include "DataController.h"

DataController::DataController() {
    std::cout << "Конструктор DataController \n";
    dataLoader();
}
DataController::DataController(std::string personLogin) {
    std::cout << "Конструктор DataController personLogin \n";
    setPersonLogin(personLogin);
    dataLoader();
}

DataController::DataController(bool loadFlag) {
    std::cout << "Конструктор DataController \n";
    if (loadFlag) {
        dataLoader();
    }
    else {
        std::list<MessangerUser> arrUsers = connectionDB.selectAllUsers();
        for (MessangerUser user : arrUsers) {
            setUser(user);
        }
    }
}

// Загрузка списка зарегистрированных пользователей и переписки в общем чате
void DataController::dataLoader()
{
    // Реализация с чтением из DB

    std::list<MessangerUser> arrUsers = connectionDB.selectAllUsers();
    for (MessangerUser user : arrUsers) {
        setUser(user);
    }

    std::list<std::string> arrMessage = connectionDB.selectMessageGeneralChat();
    for (std::string message : arrMessage) {
        setMessageGeneralChat(message);
    }

    std::list<PrivateChat> arrPrivateChat = connectionDB.selectPrivateChat();
    std::list<int> arrChatId;
    for (PrivateChat chat : arrPrivateChat) {
        arrChatId.push_back(chat.getChatID());
        setListOfPrivateChat(chat);
    }

    std::cout << "---------------------------------------\n";
    for (PrivateChat chat : arrPrivateChat) {
        std::cout << chat.getChatID() << ", " << chat.getlogin() << ", " << chat.getloginCompanion() << '\n';
    }
    std::cout << "---------------------------------------\n";

    std::map<int, std::list<std::string>> mapPrivateChatHistory = connectionDB.selectPrivateChatHistory(arrChatId);

    std::map <int, std::list<std::string>> ::iterator it = mapPrivateChatHistory.begin();
    for (int i = 0; it != mapPrivateChatHistory.end(); ++it, ++i) {
        for (std::string message : it->second) {
            setMapPrivateChatHistory(it->first, message);
            std::cout << it->first << ":\t " << message << "\n";
        }
        /*std::cout << it << ":\t " + it->second.() + "\t " + it->second.getLogin() + "\t " + it->second.getPassword() << std::endl;*/
    }

    // Реализация с чтением из файла
    /*MessangerUser* tmpUser = new MessangerUser();
    list<string> arrData = tmpUser->readingDataFromFile(pathUsersData);
    for (string line : arrData) {
        vector<string> arr = tmpUser->parsingStringWithSpaceDelimiter(line);

        if (arr.size() == 3) {
            MessangerUser user{ arr[0], arr[1], arr[2] };
            setUser(user);
        }
        else {
            cout << "\n Warning! Ошибка в структуре файла: " + pathUsersData << endl;
        }
    }

    arrData.clear(); //  Можно и не делать, и так инициализируется другим списком
    arrData = tmpUser->readingDataFromFile(pathGeneralChatData);

    for (string line : arrData) {
        setMessageGeneralChat(line);
    }*/
}

void DataController::setUser(MessangerUser user)
{
    _listOfUsers.insert_or_assign(user.getLogin(), user);
}

bool DataController::setMessage(std::string login, std::string dateMessage, std::string message) {
    if (connectionDB.insertGeneralChatMessage(login, dateMessage, message)) {
        std::string messageText = login + ":" + dateMessage + ":" + message;
        setMessageGeneralChat(messageText);
        return true;
    }
    return false;
}

void DataController::setMessageGeneralChat(std::string message)
{
    _generalСhat.push_back(message);
}

void DataController::setMapPrivateChatHistory(int chatID, std::string message)
{
    if (_mapPrivateChatHistory.find(chatID) != _mapPrivateChatHistory.end()) {
        _mapPrivateChatHistory[chatID].push_back(message);
    }
    else {
        std::list<std::string> arrMessage;
        arrMessage.push_back(message);
        _mapPrivateChatHistory.insert_or_assign(chatID, arrMessage);
    }
}

void DataController::setListOfPrivateChat(PrivateChat chat)
{
    _listOfPrivateChat.insert_or_assign(chat.getChatID(), chat);
}

std::string DataController::createPrivateChatMessage(std::string loginCompanion, std::string message) {
    std::string _mess = _personLogin + " : " + getCurrentTimeDB() + " : " + message;
    if (connectionDB.createPrivateChatMessage(_personLogin, loginCompanion, _mess))
        return _mess;

    return "";
}
std::string DataController::setPrivateChatMessage(int chatID, std::string loginCompanion, std::string message) {
    std::string _mess = _personLogin + " : " + getCurrentTimeDB() + " : " + message;
    if (connectionDB.setPrivateChatMessage(chatID, loginCompanion, _mess))
        return _mess;

    return "";
}


bool DataController::loadUser(MessangerUser user)
{
    //Сохранение данных пользователя в DB
    if (loginVerification(user.getLogin())) {
        if (connectionDB.insertUser(user)) {
            setUser(user);
            return true;
        }
        std::cout << "Ошибка создания учетной записи, повторите попытук! \n";
        return false;
    }
    std::cout << "Данный логин уже используется, придумайте другой! \n";
    return false;


    //Сохранение данных пользователя в файле
    //string data = user.getFullName();
    //user.writingDataToFile(pathUsersData, data);
}

std::list<MessangerUser> DataController::selectAllUsers() {
    return connectionDB.selectAllUsers();
}

// Выводит список пользователей с данными, тестировачная функция!
void DataController::outUsers()
{
    std::cout << "N: \t Имя \t Логин \t Пароль \n";
    std::map <std::string, MessangerUser> ::iterator it = _listOfUsers.begin();
    for (int i = 0; it != _listOfUsers.end(); ++it, ++i) {
        std::cout << i + 1 << ":\t " + it->second.getName() + "\t " + it->second.getLogin() + "\t " + it->second.getPassword() << std::endl;
    }
}

// Вывод сообщений из общего чата
void DataController::outMessagesGeneralChat()
{
    for (std::string message : _generalСhat)
    {
        std::cout << message << std::endl;
    }
}

void DataController::setPersonLogin(std::string personLogin) {
    _personLogin = personLogin;
}

int DataController::getPrivateChatID(std::string login, std::string loginCompanion) {
    std::map<int, PrivateChat> ::iterator it = _listOfPrivateChat.begin();
    for (int i = 0; it != _listOfPrivateChat.end(); ++it, ++i) {
        if ((it->second.getlogin() == login && it->second.getloginCompanion() == loginCompanion) ||
            (it->second.getlogin() == loginCompanion && it->second.getloginCompanion() == login))
            return it->second.getChatID();
   }
    return 0;
}

std::string DataController::getPersonLogin() {
    return _personLogin;
}

// Проверка корректности логина и пароля пользователя
bool DataController::authentication(std::string login, std::string password)
{
    if (_listOfUsers.count(login)) {
        if (_listOfUsers[login].getStatus() == 0 && password == _listOfUsers[login].getPassword()) {
            return true;
        }
    }
    return false;
}

bool DataController::authenticationAdmin(std::string login, std::string password)
{
    if (_listOfUsers.count(login)) {
        if (_listOfUsers[login].getStatus() == 0 && _listOfUsers[login].getRole() == 1 && password == _listOfUsers[login].getPassword()) {
            return true;
        }
    }
    return false;
}

//Проверка на сущетсвование пользователя с данным логином
bool DataController::loginVerification(std::string login)
{
    if (_listOfUsers.count(login)) {
        return false; // Пользователь с таким логином уже существует
    }
    return true; // Данный логин не зарегистрирован в системе
}

///Авторизация пользователя после ввода логина и пароля
//void DataController::authorization(std::string login, std::string password)
//{
//    if (authentication(login, password)) // Дополнительная проверка корректности данных
//    {
//        personalAccount(login);
//    }
//    else {
//        std::cout << "\n Отказано в доступе! \n";
//    }
//}

std::list<std::string> DataController::getUsersList() {
    std::list<std::string> userList;
    for each (auto user in _listOfUsers)
    {
        userList.push_back(user.first.c_str());
    }
    return userList;
}

/// Интерфейс меню с выбором общего и приватных чатов
//void DataController::personalAccount(std::string login)
//{
//    char choice{ '0' };
//
//    for (;;) {
//        system("cls");
//        std::cout << " Набор действий: \n 1 - Общий чат \n 2 - Личные чаты \n 3 - Выход \n\n Введите действие: ";
//        std::cin >> choice;
//        std::cout << '\n';
//
//        switch (choice)
//        {
//        case '1': generalChat(login); break;
//        case '2': _listOfUsers[login].loadingUserChats(); privateChat(login); break;
//        case '3': return;
//        default:
//            system("cls");
//            std::cin.clear();
//            break;
//        }
//    }
//}

/// Интерфейс общего чата, с выводом переписки и отправкой новых сообщений
//void DataController::generalChat(std::string login)
//{
//    char choice{ '0' };
//
//    for (;;) {
//        system("cls");
//        outMessagesGeneralChat();
//
//        std::cout << "\n Набор действий: \n 1 - Написать сообщение \n 2 - Выход \n\n Введите действие: ";
//        std::cin >> choice;
//        std::cout << '\n';
//
//        switch (choice)
//        {
//        case '1': sendingMessagesGeneralChat(login); break;
//        case '2': return;
//        default:
//            system("cls");
//            std::cin.clear();
//            break;
//        }
//    }
//}

/// Отправка сообщения в общий чат
//void DataController::sendingMessagesGeneralChat(std::string login)
//{
//    std::string message = "", tmp_message = "";
//    char temp = '0';
//
//    for (;;)
//    {
//        temp = '0';
//        system("cls");
//        outMessagesGeneralChat();
//        tmp_message = "";
//
//        std::cout << "\n Enther - чтобы отправить сообщение, для выхода введите слово: exit \n";
//        SetConsoleCP(1251);
//        while (temp != '\n') {
//            std::cin.get(temp);
//            tmp_message += temp;
//        }
//        SetConsoleCP(866);
//
//        if (tmp_message == "exit\n") {
//            break;
//        }
//
//        //Запись сообщения общего чата в DB
//        if (tmp_message.size() > 1) {
//            if (tmp_message.rfind("\n") != std::string::npos) {
//                tmp_message.erase(tmp_message.rfind("\n"));
//            }
//            connectionDB.insertGeneralChatMessage(login, getCurrentTimeDB(), tmp_message);
//            message = login + ":" + getCurrentTimeDB() + ":" + tmp_message;
//            setMessageGeneralChat(message);
//        }
//
//
//        //Запись сообщения общего чата в файл
//        /*if (tmp_message.size() > 1) {
//            message = login + ":" + getCurrentTime() + ": " + tmp_message;
//            if (message.rfind("\n") != string::npos) {
//                message.erase(message.rfind("\n"));
//            }
//
//            setMessageGeneralChat(message);
//            _listOfUsers[login].writingDataToFile(pathGeneralChatData, message);
//        }*/
//    }
//}

/// Интерфейс приватных чатов пользователя
//void DataController::privateChat(std::string login)
//{
//    char choice{ '0' };
//
//    for (;;) {
//        system("cls");
//
//        std::cout << " Набор действий: \n 1 - Открыть список чатов \n 2 - Создать новый чат \n 3 - Выход \n\n Введите действие: ";
//        std::cin >> choice;
//        std::cout << '\n';
//
//        switch (choice)
//        {
//        case '1': _listOfUsers[login].userChatList(); break;
//        case '2': createNewPrivateChat(login); break;
//        case '3': return;
//        default:
//            std::cin.clear();
//            break;
//        }
//    }
//}

/// Создание нового приватного чата
//void DataController::createNewPrivateChat(std::string login)
//{
//    system("cls");
//    std::string loginCompanion = "";
//
//    for (;;) {
//
//        std::cout << "\n Введите логин пользователся с которым хотите создать чат, либо exit для выхода: ";
//        std::cin >> loginCompanion;
//        std::cout << '\n';
//
//        if (loginCompanion == "exit") {
//            return;
//        }
//
//        if (loginCompanion == login) {
//            std::cout << " Нельзя создать чат с самим с собой! \n";
//            continue;
//        }
//
//        if (!loginVerification(loginCompanion)) {
//            if (_listOfUsers[login].checkForChat(loginCompanion)) {
//                _listOfUsers[login].createNewChat(loginCompanion);
//                return;
//            }
//            else {
//                std::cout << " Чат с данным пользователем: " + loginCompanion + " уже существует!\n";
//            }
//        }
//        else {
//            std::cout << " Пользователь с логином: " + loginCompanion + " не найден в системе!\n";
//        }
//    }
//}