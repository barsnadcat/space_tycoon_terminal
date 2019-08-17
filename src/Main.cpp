#include <SpaceTycoonModel.h>


#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <readline/readline.h>
#include <readline/history.h>
#include <iostream>
#include <easylogging++.h>

INITIALIZE_EASYLOGGINGPP

const char* kRunCommand = "run";
const char* kCommands[] = 
{
	kRunCommand,
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
	rl_attempted_completion_over = 1; // Disable fallback to file name auto complete
	return rl_completion_matches(text, CommandNameGenerator);
}

void ExecuteRunCommand(const char* buffer)
{
	int param = 0;
	if (sscanf(buffer, "%*s %d", &param) < 1)
	{
		LOG(ERROR) << "Failed to parse parameters of run command";
	}
	else
	{
		Do(param);
	}
}

void ExecuteCommand(const char* buffer)
{
	if (strncmp(buffer, kRunCommand, strlen(kRunCommand)) == 0)
	{
		ExecuteRunCommand(buffer);
	}
	else
	{
		LOG(ERROR) << "Unknown command";
	}
}


int main(int argc, char** argv)
{
	START_EASYLOGGINGPP(argc, argv);

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

#include <easylogging++.cc>