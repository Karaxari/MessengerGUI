#pragma once
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <random>
#include <windows.h>;
#include "PrivateChat.h"

//using namespace std;

std::string getCurrentTime();
std::string getCurrentTimeDB();

const std::string pathToUsersChats = "DataController\\Users\\"; // ѕуть к директории с файлами пользователей, содержащих информацию об приватных чатах в кторых они участвуют
const std::string pathPrivateChats = "DataController\\PrivateChats\\"; // ѕуть к директории где хранитс€ переписки приватных чатов

class MessangerUser
{
public:
	MessangerUser() = default;
	MessangerUser(std::string name, std::string login, std::string password, int status, int role) : _name(name), _login(login), _password(password), _status(status), _role(role){}
	~MessangerUser();

	void writingDataToFile(std::string file, std::string data);
	std::list<std::string> readingDataFromFile(std::string pathFile);
	std::vector<std::string> parsingStringWithSpaceDelimiter(std::string line);

	//void loadingUserChats();
	//void addingUsersToChat(std::string charID, std::string loginCompanion);
	void setStatus(int status);
	void setRole(int role);
	void setName(std::string name);
	void setLogin(std::string login);
	void setPassword(std::string password);
	//void setUserChat(int chatID, std::string loginCompanion);

	//void userChatList();
	//void outUserChatList();
	//void createNewChat(std::string loginCompanion);
	//void privateChat(std::string charID);

	int generateChatID();
	//bool chatIDVerification(std::string chatID);
	bool checkForChat(std::string loginCompanion);

	int getStatus() const;
	int getRole() const;
	std::string getStatusStr() const;
	std::string getRoleStr() const;
	std::string getName() const;
	std::string getLogin() const;
	std::string getPassword() const;
	std::string getFullName() const;

private:
	std::string _name;
	std::string _login;
	std::string _password;
	int _status;
	int _role;

	std::map<std::string, PrivateChat> _listOfChats; // “оже закрытое наслеование, релизаци€ отнощени€ "содержит"
};
