#pragma once
#include "ChatMessages.h"

class PrivateChat : public ChatMessages // Публичное наследование, без него никак!
{
public:
	PrivateChat() = default;
	PrivateChat(int chatID, std::string loginCompanion) : _chatID(chatID), _loginCompanion(loginCompanion) { }
	PrivateChat(int chatID, std::string login, std::string loginCompanion) : _chatID(chatID), _login(login), _loginCompanion(loginCompanion) { }
	PrivateChat(int chatID, std::list<std::string> chatHistory, std::string loginCompanion) : ChatMessages(chatHistory) { _chatID = chatID; _loginCompanion = loginCompanion; }

	PrivateChat(const PrivateChat& ob); // Конструктор копирования. Добавил думаю что ошибка была в некорректной передаче объекта!
	//Но оказалось все проще: Рекурсивный вызов функции )). Спасибо дебагингу, а то обшика выводила отсутвует файла, вместо оверфлов

	void setChatID(int);
	void setLogin(std::string login);
	void setLoginCompanion(std::string loginCompanion);

	int getChatID();
	std::string getlogin();
	std::string getloginCompanion();
private:
	int _chatID;
	std::string _login;
	std::string _loginCompanion;
};