#pragma once
#include <iostream>
#include <list>

//using namespace std;

class ChatMessages
{
public:
	ChatMessages() = default;
	ChatMessages(std::list<std::string> chatHistory) : _chatHistory(chatHistory) { }

	void setChatHistory(std::list<std::string> chatHistory);
	void setMesageChat(std::string mesage);

	void outChatHistory();

	std::list<std::string> getChatHistory();

private:
	std::list<std::string> _chatHistory;
};

