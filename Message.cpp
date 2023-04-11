#include "Message.h"
#include <string>
using namespace std;

Message::Message(const string& sender, const string& receiver, const string& message) : sender_(sender), receiver_(receiver), message_(message) {}

const string& Message::getSender() const
{
	return sender_;
}

const string& Message::getReceiver() const
{
	return receiver_;
}

const string& Message::getMessage() const
{
	return message_;
}