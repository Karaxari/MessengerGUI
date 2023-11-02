#include "MessangerUser.h"

// Логирование сообщений временем отправки
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

/// Загрузка информации из файлов об списке приватных чатов пользователя и их переписок!
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
//            std::cout << "\n Warning! Ошибка в структуре файла: " + pathToUsersChats << std::endl;
//        }
//    }
//
//    std::map <std::string, PrivateChat> ::iterator it = _listOfChats.begin();
//    for (; it != _listOfChats.end(); ++it) {
//        pathFile = pathPrivateChats + it->second.getChatID() + ".txt";
//        arrData.clear(); //  Можно и не делать, и так инициализируется другим списком
//
//        arrData = readingDataFromFile(pathFile);
//
//        for (std::string line : arrData) {
//            it->second.setMesageChat(line);
//        }
//    }
//}

/// Запись информации о чате в файл к каждому из участников чата
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

// Можно было бы использовать try cath, но из-за простоты структуры файлов и их ихерархии хранения  ограничился стандартной проверкой
// Добавляем ID чата и логин собеседника в файл пользователя
void MessangerUser::writingDataToFile(std::string file, std::string data)
{
    std::ofstream out(file, std::ios::app);
    if (out.is_open())
    {
        out << data << std::endl;
    }
    else {
        std::cout << "Не удалось создать файл: " + file;
    }
    out.close();
}

// Чтение данных из файла по указанному пути
std::list<std::string> MessangerUser::readingDataFromFile(std::string pathFile)
{
    std::list<std::string> arrData;
    std::string line;

    std::ifstream inUsersData(pathFile); // окрываем файл для чтения
    if (inUsersData.is_open())
    {
        while (getline(inUsersData, line))
        {
            arrData.push_back(line);
        }
    }
    else {
        std::cout << "Файл " + pathFile + " не существует \n";
    }
    inUsersData.close();     // закрываем файл

    return arrData;
}

// Разбиваем строку на подстроки с разделителем по пробелу
std::vector<std::string> MessangerUser::parsingStringWithSpaceDelimiter(std::string line)
{
    std::vector<std::string> arr;
    std::string delim(" ");
    size_t prev = 0;
    size_t next;
    size_t delta = delim.length();

    while ((next = line.find(delim, prev)) != std::string::npos) {
        std::string tmp = line.substr(prev, next - prev); //Отладка-start
        arr.push_back(line.substr(prev, next - prev)); //Отладка-end
        prev = next + delta;
    }
    std::string tmp = line.substr(prev); //Отладка-start
    arr.push_back(line.substr(prev)); //Отладка-end

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

/// Добавляем новый чат пользвателю в данные
//void MessangerUser::setUserChat(std::string chatID, std::string loginCompanion)
//{
//    if (chatIDVerification(chatID)) {
//        PrivateChat chat{ chatID, loginCompanion };
//        _listOfChats.insert_or_assign(chatID, chat);
//    }
//    else
//        std::cout << "\n Warning! Данный chatID: " + chatID + " уже используется! проверьте корректность данных!\n";
//}

/// Проверка на сущетсвование чата с данным ID
//bool MessangerUser::chatIDVerification(std::string chatID)
//{
//    if (_listOfChats.count(chatID)) {
//        return false; // Чат с с этим ID уже существует
//    }
//    return true; // Данный ID доступен для использования
//}

// Проверка существования чата с данным пользователем
bool MessangerUser::checkForChat(std::string loginCompanion)
{
    std::map <std::string, PrivateChat> ::iterator it = _listOfChats.begin();
    for (; it != _listOfChats.end(); ++it) {
        if (loginCompanion == it->second.getloginCompanion()) {
            return false; // Чат уже существует
        }
    }
    return true; // Чат с данным пользователем отсутствует
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

// Генерируем случайный ID чата
int MessangerUser::generateChatID()
{
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(10000, 99999);

    return distribution(generator);
}

/// Создаем новый чат с уникальным ID и записываем информациб о нем обим пользователям в файл
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

///Вывод списка чатов доступных данному пользователю!
//void MessangerUser::outUserChatList()
//{
//    std::cout << "N: \t ID чата \t Логин \n";
//    std::map <std::string, PrivateChat> ::iterator it = _listOfChats.begin();
//    for (int i = 0; it != _listOfChats.end(); ++it, ++i) {
//        std::cout << i + 1 << ":\t " + it->second.getChatID() + "\t " + it->second.getloginCompanion() << std::endl;
//    }
//}

/// Список чатов у пользователя, и возможность открыть нужный чат по вводу ID
//void MessangerUser::userChatList()
//{
//    std::string input = "";
//
//    for (;;) {
//        system("cls");
//        outUserChatList();
//
//        std::cout << "\n Набор действий: \n Введите ID чата из списка выше для перехода в чат с пользователем. \n Введите exit для выхода. \n : ";
//        std::cin >> input;
//        std::cout << '\n';
//
//        if (input == "exit") break;
//
//        if (!chatIDVerification(input)) {
//            privateChat(input);
//        }
//        else {
//            std::cout << "\n Чат с id: " + input + "не существует или нет доступа к нему! \n";
//        }
//    }
//
//}

/// Интерфейс приватного чата с отправкой сообщений
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
//        std::cout << "\n Enther - чтобы отправить сообщение, для выхода введите слово: exit \n";
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