#include "PrivateChat.h"

PrivateChat::PrivateChat(const PrivateChat& ob)
{
	_chatID = ob._chatID;
	_login = ob._login;
	_loginCompanion = ob._loginCompanion;
}

void PrivateChat::setChatID(int chatID) {
	_chatID = chatID;
}

void PrivateChat::setLogin(std::string login) {
	_login = login;
}

void PrivateChat::setLoginCompanion(std::string loginCompanion) {
	_loginCompanion = loginCompanion;
}

int PrivateChat::getChatID() {
	return _chatID;
}

std::string PrivateChat::getlogin() {
	return _login;
}

std::string PrivateChat::getloginCompanion() {
	return _loginCompanion;
}