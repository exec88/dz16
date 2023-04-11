#include "Chat.h"

int main()
{
	Chat chat;
	chat.createChat();
	while (chat.isChatWorking())
	{
		chat.chatOptions();

		while (chat.getCurrUser())
		{
			chat.userOptions();
		}
	}

	return 0;
}