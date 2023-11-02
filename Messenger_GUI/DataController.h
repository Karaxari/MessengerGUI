#pragma once
//#include "MessangerUser.h"
#include "ConnectionDB.h"

const std::string pathUsersData = "DataController\\allUsers.txt"; // данные пользователей: Имя, логин и пароль
const std::string pathGeneralChatData = "DataController\\generalChat.txt"; // переписка общего чата

class DataController
{
public:
	DataController();
	DataController(bool loadFlag);
	DataController(std::string personLogin);
	~DataController() = default;

	void dataLoader();
	void setUser(MessangerUser user);
	void setMessageGeneralChat(std::string message);
	void setMapPrivateChatHistory(int chatID, std::string message);
	void setListOfPrivateChat(PrivateChat chat);
	bool setMessage(std::string login, std::string dateMessage, std::string message);
	bool loadUser(MessangerUser user);

	std::string createPrivateChatMessage(std::string loginCompanion, std::string message);
	std::string setPrivateChatMessage(int chatID, std::string loginCompanion, std::string message);

	void outUsers();
	void outMessagesGeneralChat();

	void setPersonLogin(std::string personLogin);
	std::string getPersonLogin();
	std::list <std::string> getUsersList();
	int getPrivateChatID(std::string login, std::string loginCompanion);
	std::list<MessangerUser> selectAllUsers();

	bool authentication(std::string login, std::string password);
	bool authenticationAdmin(std::string login, std::string password);
	bool loginVerification(std::string login);
	void authorization(std::string login, std::string password);

	std::list <std::string> _generalСhat; // Дедлайн!!! идем на костыли
	std::map<std::string, MessangerUser> _listOfUsers; // Закрытое наслеование, релизация отнощения "содержит"
	std::map<int, PrivateChat> _listOfPrivateChat;
	std::map<int, std::list<std::string>> _mapPrivateChatHistory;

private:
	ConnectionDB connectionDB; // Объект для взаимодействия с БД
	std::string _personLogin;

	//void personalAccount(std::string login);
	void generalChat(std::string login);
	//void privateChat(std::string login);
	//void createNewPrivateChat(std::string login);
	//void sendingMessagesGeneralChat(std::string login);
};