#include "ChatMessages.h"

void ChatMessages::setChatHistory(std::list<std::string> chatHistory) {
	_chatHistory = chatHistory;
}

void ChatMessages::setMesageChat(std::string message) {
	_chatHistory.push_back(message);
}

std::list<std::string> ChatMessages::getChatHistory() {
	return _chatHistory;
}

void ChatMessages::outChatHistory() {
	for (std::string message : _chatHistory)
	{
		std::cout << message << std::endl;
	}
}