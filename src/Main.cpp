#include <SpaceTycoonModel.h>


#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <linenoise.hpp>
#include <iostream>
#include <easylogging++.h>

INITIALIZE_EASYLOGGINGPP

const char* kRunCommand = "run";
const char* kCommands[] =
{
	kRunCommand,
	nullptr
};

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

	// Setup completion words every time when a user types
	auto completionCallBack = [](const char* editBuffer, std::vector<std::string>& completions)
	{
		int listIndex = 0;
		int len = strlen(editBuffer);
		const char* name;
		while ((name = kCommands[listIndex++]))
		{
			if (strncmp(name, editBuffer, len) == 0)
			{
				completions.push_back(name);
			}
		}
	};
	linenoise::SetCompletionCallback(completionCallBack);

	std::string line;
	while (!linenoise::Readline("> ", line))
	{
		linenoise::AddHistory(line.c_str());
		ExecuteCommand(line.c_str());
	}

	return 0;
}

#include <easylogging++.cc>