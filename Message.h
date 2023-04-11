#pragma once
#include <string>
using namespace std;

class Message
{
	const string sender_;
	const string receiver_;
	const string message_;
public:
	Message(const string&, const string&, const string&);
	const string& getSender() const;
	const string& getReceiver() const;
	const string& getMessage() const;
};