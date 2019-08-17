#include <SpaceTycoonModel.h>


#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <readline/readline.h>
#include <readline/history.h>
#include <iostream>

const char* kRunCmd = "run";
const char* kCommands[] = 
{
	kRunCmd,
	nullptr
};

char* CommandNameGenerator(const char* text, int state)
{
	static int listIndex, len;
	const char* name;

	if (!state) 
	{
		listIndex = 0;
		len = strlen(text);
	}

	while ((name = kCommands[listIndex++]))
	{
		if (strncmp(name, text, len) == 0) 
		{
			return strdup(name);
		}
	}

	return nullptr;
}

char** CommandNameCompletion(const char* text, int start, int end)
{
	rl_attempted_completion_over = 1;
	return rl_completion_matches(text, CommandNameGenerator);
}

void ExecuteCommand(const char* buffer)
{
	if (strncmp(buffer, kRunCmd, strlen(kRunCmd)) == 0)
	{
		Do();
	}
	else
	{
		std::cout << "Unknown command " << buffer;
	}
}


int main(int argc, char** argv)
{

	rl_attempted_completion_function = CommandNameCompletion;

	char* buffer;
	while ((buffer = readline("> ")) != nullptr) 
	{
		if (strlen(buffer) > 0)
		{
			add_history(buffer);
			ExecuteCommand(buffer);
		}

		free(buffer);
	}

	return 0;
}