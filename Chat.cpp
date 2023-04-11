#include "Chat.h"
#include "Message.h"
#include "User.h"
#include <vector>
#include <iostream>
#include <map>
using namespace std;

void Chat::createChat()
{
	isChatWorking_ = true;
}

bool Chat::isChatWorking()
{
	return isChatWorking_;
}

void Chat::regIn()
{
	string login;
	string password;
	string name;

	cout << "Enter login: ";
	cin >> login;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (User user : users_)
	{
		while (login == user.getLogin())
		{
			cout << endl;
			cout << "Login is busy. Supported operations: 1 - try another login, 0 - exit" << endl;
			cout << "Your operation: ";

			const char TRY = '1';
			const char EXIT = '0';

			string op;
			while (op != "0" && op != "1")
			{
				cin >> op;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << endl;

				map <string, char> mapping;
				mapping["1"] = TRY;
				mapping["0"] = EXIT;

				switch (mapping[op])
				{
				case TRY:
					cout << "Enter login: ";
					cin >> login;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					break;
				case EXIT:
					isChatWorking_ = false;
					cout << "Bye, see you later =) " << endl;
					return;
				default:
					cout << "Wrong operation. Supported operations: 1 - try another login, 0 - exit" << endl;
					cout << "Your operation: ";
					break;
				}
			}
		}
	}

	cout << "Enter Password: ";
	cin >> password;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Enter Name: ";
	cin >> name;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (User user : users_)
	{
		while (name == user.getName())
		{
			cout << endl;
			cout << "Name is busy. Supported operations: 1 - try another name, 0 - exit" << endl;
			cout << "Your operation: ";

			string op;

			const char TRY = '1';
			const char EXIT = '0';

			while (op != "0" && op != "1")
			{
				cin >> op;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << endl;

				map <string, char> mapping;
				mapping["1"] = TRY;
				mapping["0"] = EXIT;

				switch (mapping[op])
				{
				case TRY:
					cout << "Enter Name: ";
					cin >> name;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					break;
				case EXIT:
					isChatWorking_ = false;
					cout << endl;
					cout << "Bye see you later =) " << endl;
					return;
				default:
					cout << "Wrong operation. Supported operations: 1 - try another name, 0 - exit" << endl;
					cout << "Your operation: ";
					break;
				}
			}
		}
	}
	User user = User(login, password, name);
	users_.push_back(user);
	currUser_ = make_shared<User>(user);
	cout << endl;
	cout << "Hey " << currUser_->getName() << " Welcome to the chat =) " << endl;
}

void Chat::logIn()
{
	string login;
	string password;
	string op;

	cout << "Enter login: ";
	cin >> login;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	currUser_ = getUserByLogin(login);

	if (!currUser_)
	{
		while (!currUser_)
		{
			const char TRY = '1';
			const char REGIN = '2';
			const char EXIT = '0';

			cout << endl;
			cout << "There is no user with this login. Supported operations: 1 - try another login, 2 - register to chat, 0 - exit" << endl;
			cout << "Your operation: ";

			while (op != "1" && op != "2" && op != "0")
			{
				cin >> op;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << endl;

				map <string, char> mapping;
				mapping["1"] = TRY;
				mapping["2"] = REGIN;
				mapping["0"] = EXIT;

				switch (mapping[op])
				{
				case TRY:
					logIn();
					break;
				case REGIN:
					regIn();
					break;
				case EXIT:
					isChatWorking_ = false;
					cout << endl;
					cout << "Bye see you later =) " << endl;
					return;
				default:
					cout << "Wrong operation. Supported operations: 1 - try another login, 2 - register to chat, 0 - exit" << endl;
					cout << "Your operation: ";
					break;
				}
			}
		}
	}
	else
	{
		cout << "Enter password: ";
		cin >> password;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl;

		while (password != currUser_->getPassword())
		{
			cout << "Wrong password. Supported operations: 1 - try another password, 0 - exit" << endl;
			cout << "Your operation: ";

			string op;

			const char TRY = '1';
			const char EXIT = '0';

			while (op != "1" && op != "0")
			{
				cin >> op;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << endl;

				map <string, char> mapping;
				mapping["1"] = TRY;
				mapping["0"] = EXIT;

				switch (mapping[op])
				{
				case TRY:
					cout << "Enter password: ";
					cin >> password;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << endl;
					break;
				case EXIT:
					isChatWorking_ = false;
					cout << endl;
					cout << "Bye see you later =) " << endl;
					return;
				default:
					cout << "Wrong operation. Supported operations: 1 - try another login, 0 - exit" << endl;
					cout << "Your operation: ";
					break;
				}
			}
		}
		cout << "Hey " << currUser_->getName() << "Welcome back to the chat =) " << endl;
	}
}

void Chat::chatOptions()
{
	string op;
	cout << "Supported operations: 1 - register in chat, 2 - login, 0 - exit" << endl;
	cout << "Your operation: ";

	const char REGIN = '1';
	const char LOGIN = '2';
	const char EXIT = '0';

	while (op != "1" && op != "2" && op != "0" && isChatWorking_)
	{
		cin >> op;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl;

		map <string, char> mapping;
		mapping["1"] = REGIN;
		mapping["2"] = LOGIN;
		mapping["0"] = EXIT;

		switch (mapping[op])
		{
		case REGIN:
			regIn();
			break;
		case LOGIN:
			logIn();
			break;
		case EXIT:
			cout << "Bye see you later =) " << endl;
			isChatWorking_ = false;
			return;
		default:
			cout << "Wrong operation. Supported operations: 1 - register in chat, 2 - login, 0 - exit" << endl;
			cout << "Your operation: ";
			break;
		}
	}
}

void Chat::userOptions()
{
	const char WRITE = '1';
	const char SHOW = '2';
	const char LOGOUT = '0';

	while (currUser_)
	{
		cout << "Supported operations: 1 - write message, 2 - show messages, 0 - logout" << endl;
		cout << "Your operation: ";

		string op;
		while (op != "1" && op != "2" && op != "0")
		{
			cin >> op;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl;

			map <string, char> mapping;
			mapping["1"] = WRITE;
			mapping["2"] = SHOW;
			mapping["0"] = LOGOUT;

			switch (mapping[op])
			{
			case WRITE:
				writeMessage();
				break;
			case SHOW:
				showMessages();
				break;
			case LOGOUT:
				cout << currUser_->getName() << " is logged out! " << endl;
				currUser_ = nullptr;
				break;
			default:
				cout << "Wrong operation. Supported operations: 1 - write message, 2 - show messages, 0 - logout" << endl;
				cout << "Your operation: ";
				break;
			}
		}
	}
}

void Chat::writeMessage()
{
	string text;
	unsigned short i = 1, userNum = 1;

	cout << "Message body: ";
	getline(cin, text);
	cout << endl;

	for (User& user : users_)
	{
		cout << user.getName() << " - " << i << endl;
		i++;
	}

	cout << "Everyone in the chat - " << i << endl;
	cout << "Enter number : ";

	cout << endl;

	while (!(cin >> userNum))
	{
		cout << endl;

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Input is incorrect. Try again!" << endl;
		cout << "User number: ";
	}
	cout << endl;

	while (!userNum || userNum > i)
	{
		cout << "There is no user with this number. Try again!" << endl;
		cout << "User number: ";
		cin >> userNum;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl;
	}

	if (userNum == i)
	{
		for (User& user : users_)
		{
			Message message = Message(currUser_->getName(), user.getName(), text);
			messages_.push_back(message);
		}
		cout << "The message is sent from " << currUser_->getName() << " to everyone in the chat..." << endl;
	}
	else if (userNum > 0 && userNum < i)
	{
		Message message = Message(currUser_->getName(), users_.at(userNum - 1).getName(), text);
		messages_.push_back(message);
		cout << "The message is sent from " << currUser_->getName() << " to " << users_.at(userNum - 1).getName() << "..." << endl;
	}
}

void Chat::showMessages()
{
	int count = 0;

	for (Message& message : messages_)
	{
		if (currUser_->getName() == message.getReceiver())
		{
			count++;
			cout << "You've got message from " << message.getSender() << ": " << message.getMessage() << endl;
		}
	}

	if (count != 0)
	{
		cout <<endl;
	}

	if (count == 0)
	{
		cout << "You got no messages yet" << endl;
	}
}

shared_ptr<User> Chat::getUserByName(const string& name) const
{
	for (User user : users_)
	{
		if (name == user.getName())
		{
			return make_shared<User>(user);
		}
	}
	return nullptr;
}

shared_ptr<User> Chat::getUserByLogin(const string& login) const
{
	for (User user : users_)
	{
		if (login == user.getLogin())
		{
			return make_shared<User>(user);
		}
	}
	return nullptr;
}

shared_ptr<User> Chat::getCurrUser() const
{
	return currUser_;
}