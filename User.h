#pragma once
#include <string>
using namespace std;

class User
{
	string name_;
	string login_;
	string password_;
public:
	User(const string&, const string&, const string&);
	User(const string&, const string&);


	void setName(const string&);
	const string& getName() const;

	void setLogin(const string&);
	const string& getLogin() const;

	void setPassword(const string&);
	const string& getPassword() const;
};