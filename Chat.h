#pragma once
#include "User.h"
#include "Message.h"
#include <vector>
#include <iostream>
using namespace std;

class Chat
{
	bool isChatWorking_ = false;
	vector<User> users_;
	vector<Message> messages_;
	shared_ptr<User> currUser_ = nullptr;
public:
	void createChat();
	bool isChatWorking();
	void regIn();
	void logIn();
	void chatOptions();
	void userOptions();
	void writeMessage();
	void showMessages();
	shared_ptr<User> getUserByName(const string&) const;
	shared_ptr<User> getUserByLogin(const string&) const;
	shared_ptr<User> getCurrUser() const;

};