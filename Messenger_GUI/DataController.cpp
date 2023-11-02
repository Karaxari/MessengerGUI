#include "DataController.h"

DataController::DataController() {
    std::cout << "����������� DataController \n";
    dataLoader();
}
DataController::DataController(std::string personLogin) {
    std::cout << "����������� DataController personLogin \n";
    setPersonLogin(personLogin);
    dataLoader();
}

DataController::DataController(bool loadFlag) {
    std::cout << "����������� DataController \n";
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

// �������� ������ ������������������ ������������� � ��������� � ����� ����
void DataController::dataLoader()
{
    // ���������� � ������� �� DB

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

    // ���������� � ������� �� �����
    /*MessangerUser* tmpUser = new MessangerUser();
    list<string> arrData = tmpUser->readingDataFromFile(pathUsersData);
    for (string line : arrData) {
        vector<string> arr = tmpUser->parsingStringWithSpaceDelimiter(line);

        if (arr.size() == 3) {
            MessangerUser user{ arr[0], arr[1], arr[2] };
            setUser(user);
        }
        else {
            cout << "\n Warning! ������ � ��������� �����: " + pathUsersData << endl;
        }
    }

    arrData.clear(); //  ����� � �� ������, � ��� ���������������� ������ �������
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
    _general�hat.push_back(message);
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
    //���������� ������ ������������ � DB
    if (loginVerification(user.getLogin())) {
        if (connectionDB.insertUser(user)) {
            setUser(user);
            return true;
        }
        std::cout << "������ �������� ������� ������, ��������� �������! \n";
        return false;
    }
    std::cout << "������ ����� ��� ������������, ���������� ������! \n";
    return false;


    //���������� ������ ������������ � �����
    //string data = user.getFullName();
    //user.writingDataToFile(pathUsersData, data);
}

std::list<MessangerUser> DataController::selectAllUsers() {
    return connectionDB.selectAllUsers();
}

// ������� ������ ������������� � �������, ������������� �������!
void DataController::outUsers()
{
    std::cout << "N: \t ��� \t ����� \t ������ \n";
    std::map <std::string, MessangerUser> ::iterator it = _listOfUsers.begin();
    for (int i = 0; it != _listOfUsers.end(); ++it, ++i) {
        std::cout << i + 1 << ":\t " + it->second.getName() + "\t " + it->second.getLogin() + "\t " + it->second.getPassword() << std::endl;
    }
}

// ����� ��������� �� ������ ����
void DataController::outMessagesGeneralChat()
{
    for (std::string message : _general�hat)
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

// �������� ������������ ������ � ������ ������������
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

//�������� �� ������������� ������������ � ������ �������
bool DataController::loginVerification(std::string login)
{
    if (_listOfUsers.count(login)) {
        return false; // ������������ � ����� ������� ��� ����������
    }
    return true; // ������ ����� �� ��������������� � �������
}

///����������� ������������ ����� ����� ������ � ������
//void DataController::authorization(std::string login, std::string password)
//{
//    if (authentication(login, password)) // �������������� �������� ������������ ������
//    {
//        personalAccount(login);
//    }
//    else {
//        std::cout << "\n �������� � �������! \n";
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

/// ��������� ���� � ������� ������ � ��������� �����
//void DataController::personalAccount(std::string login)
//{
//    char choice{ '0' };
//
//    for (;;) {
//        system("cls");
//        std::cout << " ����� ��������: \n 1 - ����� ��� \n 2 - ������ ���� \n 3 - ����� \n\n ������� ��������: ";
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

/// ��������� ������ ����, � ������� ��������� � ��������� ����� ���������
//void DataController::generalChat(std::string login)
//{
//    char choice{ '0' };
//
//    for (;;) {
//        system("cls");
//        outMessagesGeneralChat();
//
//        std::cout << "\n ����� ��������: \n 1 - �������� ��������� \n 2 - ����� \n\n ������� ��������: ";
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

/// �������� ��������� � ����� ���
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
//        std::cout << "\n Enther - ����� ��������� ���������, ��� ������ ������� �����: exit \n";
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
//        //������ ��������� ������ ���� � DB
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
//        //������ ��������� ������ ���� � ����
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

/// ��������� ��������� ����� ������������
//void DataController::privateChat(std::string login)
//{
//    char choice{ '0' };
//
//    for (;;) {
//        system("cls");
//
//        std::cout << " ����� ��������: \n 1 - ������� ������ ����� \n 2 - ������� ����� ��� \n 3 - ����� \n\n ������� ��������: ";
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

/// �������� ������ ���������� ����
//void DataController::createNewPrivateChat(std::string login)
//{
//    system("cls");
//    std::string loginCompanion = "";
//
//    for (;;) {
//
//        std::cout << "\n ������� ����� ������������� � ������� ������ ������� ���, ���� exit ��� ������: ";
//        std::cin >> loginCompanion;
//        std::cout << '\n';
//
//        if (loginCompanion == "exit") {
//            return;
//        }
//
//        if (loginCompanion == login) {
//            std::cout << " ������ ������� ��� � ����� � �����! \n";
//            continue;
//        }
//
//        if (!loginVerification(loginCompanion)) {
//            if (_listOfUsers[login].checkForChat(loginCompanion)) {
//                _listOfUsers[login].createNewChat(loginCompanion);
//                return;
//            }
//            else {
//                std::cout << " ��� � ������ �������������: " + loginCompanion + " ��� ����������!\n";
//            }
//        }
//        else {
//            std::cout << " ������������ � �������: " + loginCompanion + " �� ������ � �������!\n";
//        }
//    }
//}