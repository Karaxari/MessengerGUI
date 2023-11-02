#include "MessangerUser.h"

// ����������� ��������� �������� ��������
std::string getCurrentTime()
{
    struct tm newtime;
    time_t now = time(0);
    localtime_s(&newtime, &now);
    std::string time = "[" + std::to_string(newtime.tm_year + 1900) + "-" + std::to_string(newtime.tm_mon + 1) + "-" + std::to_string(newtime.tm_mday) + " "
        + std::to_string(newtime.tm_hour) + ":" + std::to_string(newtime.tm_min) + ":" + std::to_string(newtime.tm_sec) + "]";
    return time;
}

std::string getCurrentTimeDB()
{
    struct tm newtime;
    time_t now = time(0);
    localtime_s(&newtime, &now);
    std::string time = std::to_string(newtime.tm_year + 1900) + "-" + std::to_string(newtime.tm_mon + 1) + "-" + std::to_string(newtime.tm_mday) + " "
        + std::to_string(newtime.tm_hour) + ":" + std::to_string(newtime.tm_min) + ":" + std::to_string(newtime.tm_sec);
    return time;
}

MessangerUser::~MessangerUser() {

}

/// �������� ���������� �� ������ �� ������ ��������� ����� ������������ � �� ���������!
//void MessangerUser::loadingUserChats()
//{
//    std::string pathFile = pathToUsersChats + getLogin() + ".txt";
//    std::list<std::string> arrData = readingDataFromFile(pathFile);
//
//    for (std::string line : arrData) {
//        std::vector<std::string> arr = parsingStringWithSpaceDelimiter(line);
//
//        if (arr.size() == 2) {
//            setUserChat(arr[0], arr[1]);
//        }
//        else {
//            std::cout << "\n Warning! ������ � ��������� �����: " + pathToUsersChats << std::endl;
//        }
//    }
//
//    std::map <std::string, PrivateChat> ::iterator it = _listOfChats.begin();
//    for (; it != _listOfChats.end(); ++it) {
//        pathFile = pathPrivateChats + it->second.getChatID() + ".txt";
//        arrData.clear(); //  ����� � �� ������, � ��� ���������������� ������ �������
//
//        arrData = readingDataFromFile(pathFile);
//
//        for (std::string line : arrData) {
//            it->second.setMesageChat(line);
//        }
//    }
//}

/// ������ ���������� � ���� � ���� � ������� �� ���������� ����
//void MessangerUser::addingUsersToChat(std::string chatID, std::string loginCompanion)
//{
//    std::string pathFile = pathToUsersChats + getLogin() + ".txt";
//    std::string data = chatID + " " + loginCompanion;
//    writingDataToFile(pathFile, data);
//
//    pathFile = pathToUsersChats + loginCompanion + ".txt";
//    data = chatID + " " + getLogin();
//    writingDataToFile(pathFile, data);
//}

// ����� ���� �� ������������ try cath, �� ��-�� �������� ��������� ������ � �� ��������� ��������  ����������� ����������� ���������
// ��������� ID ���� � ����� ����������� � ���� ������������
void MessangerUser::writingDataToFile(std::string file, std::string data)
{
    std::ofstream out(file, std::ios::app);
    if (out.is_open())
    {
        out << data << std::endl;
    }
    else {
        std::cout << "�� ������� ������� ����: " + file;
    }
    out.close();
}

// ������ ������ �� ����� �� ���������� ����
std::list<std::string> MessangerUser::readingDataFromFile(std::string pathFile)
{
    std::list<std::string> arrData;
    std::string line;

    std::ifstream inUsersData(pathFile); // �������� ���� ��� ������
    if (inUsersData.is_open())
    {
        while (getline(inUsersData, line))
        {
            arrData.push_back(line);
        }
    }
    else {
        std::cout << "���� " + pathFile + " �� ���������� \n";
    }
    inUsersData.close();     // ��������� ����

    return arrData;
}

// ��������� ������ �� ��������� � ������������ �� �������
std::vector<std::string> MessangerUser::parsingStringWithSpaceDelimiter(std::string line)
{
    std::vector<std::string> arr;
    std::string delim(" ");
    size_t prev = 0;
    size_t next;
    size_t delta = delim.length();

    while ((next = line.find(delim, prev)) != std::string::npos) {
        std::string tmp = line.substr(prev, next - prev); //�������-start
        arr.push_back(line.substr(prev, next - prev)); //�������-end
        prev = next + delta;
    }
    std::string tmp = line.substr(prev); //�������-start
    arr.push_back(line.substr(prev)); //�������-end

    return arr;
}

void MessangerUser::setStatus(int status)
{
    _status = status;
}

void MessangerUser::setRole(int role)
{
    _role = role;
}

void MessangerUser::setName(std::string name)
{
    _name = name;
}

void MessangerUser::setLogin(std::string login)
{
    _login = login;
}

void MessangerUser::setPassword(std::string password)
{
    _password = password;
}

/// ��������� ����� ��� ����������� � ������
//void MessangerUser::setUserChat(std::string chatID, std::string loginCompanion)
//{
//    if (chatIDVerification(chatID)) {
//        PrivateChat chat{ chatID, loginCompanion };
//        _listOfChats.insert_or_assign(chatID, chat);
//    }
//    else
//        std::cout << "\n Warning! ������ chatID: " + chatID + " ��� ������������! ��������� ������������ ������!\n";
//}

/// �������� �� ������������� ���� � ������ ID
//bool MessangerUser::chatIDVerification(std::string chatID)
//{
//    if (_listOfChats.count(chatID)) {
//        return false; // ��� � � ���� ID ��� ����������
//    }
//    return true; // ������ ID �������� ��� �������������
//}

// �������� ������������� ���� � ������ �������������
bool MessangerUser::checkForChat(std::string loginCompanion)
{
    std::map <std::string, PrivateChat> ::iterator it = _listOfChats.begin();
    for (; it != _listOfChats.end(); ++it) {
        if (loginCompanion == it->second.getloginCompanion()) {
            return false; // ��� ��� ����������
        }
    }
    return true; // ��� � ������ ������������� �����������
}

int MessangerUser::getStatus() const
{
    return _status;
}

int MessangerUser::getRole() const
{
    return _role;
}

std::string MessangerUser::getStatusStr() const
{
    return std::to_string(_status);
}

std::string MessangerUser::getRoleStr() const
{
    return std::to_string(_role);
}

std::string MessangerUser::getName() const
{
    return _name;
}

std::string MessangerUser::getLogin() const
{
    return _login;
}

std::string MessangerUser::getPassword() const
{
    return _password;
}

std::string MessangerUser::getFullName() const
{
    return _name + " " + _login + " " + _password;
}

// ���������� ��������� ID ����
int MessangerUser::generateChatID()
{
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(10000, 99999);

    return distribution(generator);
}

/// ������� ����� ��� � ���������� ID � ���������� ���������� � ��� ���� ������������� � ����
//void MessangerUser::createNewChat(std::string loginCompanion)
//{
//    int id{ 0 };
//
//    for (;;) {
//        id = generateChatID();
//
//        if (chatIDVerification(std::to_string(id))) {
//            setUserChat(std::to_string(id), loginCompanion);
//            addingUsersToChat(std::to_string(id), loginCompanion);
//            break;
//        }
//    }
//}

///����� ������ ����� ��������� ������� ������������!
//void MessangerUser::outUserChatList()
//{
//    std::cout << "N: \t ID ���� \t ����� \n";
//    std::map <std::string, PrivateChat> ::iterator it = _listOfChats.begin();
//    for (int i = 0; it != _listOfChats.end(); ++it, ++i) {
//        std::cout << i + 1 << ":\t " + it->second.getChatID() + "\t " + it->second.getloginCompanion() << std::endl;
//    }
//}

/// ������ ����� � ������������, � ����������� ������� ������ ��� �� ����� ID
//void MessangerUser::userChatList()
//{
//    std::string input = "";
//
//    for (;;) {
//        system("cls");
//        outUserChatList();
//
//        std::cout << "\n ����� ��������: \n ������� ID ���� �� ������ ���� ��� �������� � ��� � �������������. \n ������� exit ��� ������. \n : ";
//        std::cin >> input;
//        std::cout << '\n';
//
//        if (input == "exit") break;
//
//        if (!chatIDVerification(input)) {
//            privateChat(input);
//        }
//        else {
//            std::cout << "\n ��� � id: " + input + "�� ���������� ��� ��� ������� � ����! \n";
//        }
//    }
//
//}

/// ��������� ���������� ���� � ��������� ���������
//void MessangerUser::privateChat(std::string chatID)
//{
//    std::string message = "", tmp_message = "";
//
//    for (;;)
//    {
//        system("cls");
//        _listOfChats[chatID].outChatHistory();
//        tmp_message = "";
//
//        std::cout << "\n Enther - ����� ��������� ���������, ��� ������ ������� �����: exit \n";
//        char temp = '0';
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
//        if (tmp_message.size() > 1) {
//            message = getLogin() + ":" + getCurrentTime() + ": " + tmp_message;
//            if (message.rfind("\n") != std::string::npos) {
//                message.erase(message.rfind("\n"));
//            }
//
//            _listOfChats[chatID].setMesageChat(message);
//
//            std::string pathFile = pathPrivateChats + chatID + ".txt";
//            writingDataToFile(pathFile, message);
//        }
//    }
//}