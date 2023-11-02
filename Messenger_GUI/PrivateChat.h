#pragma once
#include "ChatMessages.h"

class PrivateChat : public ChatMessages // ��������� ������������, ��� ���� �����!
{
public:
	PrivateChat() = default;
	PrivateChat(int chatID, std::string loginCompanion) : _chatID(chatID), _loginCompanion(loginCompanion) { }
	PrivateChat(int chatID, std::string login, std::string loginCompanion) : _chatID(chatID), _login(login), _loginCompanion(loginCompanion) { }
	PrivateChat(int chatID, std::list<std::string> chatHistory, std::string loginCompanion) : ChatMessages(chatHistory) { _chatID = chatID; _loginCompanion = loginCompanion; }

	PrivateChat(const PrivateChat& ob); // ����������� �����������. ������� ����� ��� ������ ���� � ������������ �������� �������!
	//�� ��������� ��� �����: ����������� ����� ������� )). ������� ���������, � �� ������ �������� ��������� �����, ������ ��������

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