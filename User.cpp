#include "User.h"
#include <string>
using namespace std;

User::User(const string& login, const string& password, const string& name) : login_(login), password_(password), name_(name) {}

void User::setName(const string& name)
{
	name_ = name;
}

const string& User::getName() const
{
	return name_;
}

void User::setLogin(const string& login)
{
	login_ = login;
}

const string& User::getLogin() const
{
	return login_;
}

void User::setPassword(const string& password)
{
	password_ = password;
}

const string& User::getPassword() const
{
	return password_;
}