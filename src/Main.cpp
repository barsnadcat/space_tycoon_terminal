#include <Game.h>

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <linenoise.hpp>
#include <iostream>
#include <easylogging++.h>

INITIALIZE_EASYLOGGINGPP

const char* kRunCommand = "run";
const char* kResetCommand = "reset";
const char* kCommands[] =
{
	kRunCommand,
	kResetCommand,
	nullptr
};

void ExecuteRunCommand(Game& game, const char* buffer)
{
	int param = 0;
	if (sscanf(buffer, "%*s %d", &param) < 1)
	{
		LOG(WARNING) << "Failed to parse parameters of run command";
	}
	else
	{
		game.Run(param);
	}
}

void ExecuteResetCommand(Game& game, const char* buffer)
{
	int param = 0;
	if (sscanf(buffer, "%*s %d", &param) < 1)
	{
		LOG(WARNING) << "Failed to parse parameters of run command";
	}
	else
	{
		game.Reset(param);
	}
}

void ExecuteCommand(Game& game, const char* buffer)
{
	if (strncmp(buffer, kRunCommand, strlen(kRunCommand)) == 0)
	{
		ExecuteRunCommand(game, buffer);
		return;
	}
	if (strncmp(buffer, kResetCommand, strlen(kResetCommand)) == 0)
	{
		ExecuteResetCommand(game, buffer);
		return;
	}

	LOG(WARNING) << "Unknown command";
}

int main(int argc, char** argv)
{
	START_EASYLOGGINGPP(argc, argv);
	el::Configurations defaultConf;
	defaultConf.setToDefault();   // Values are always std::string
	defaultConf.set(el::Level::Global,
	                el::ConfigurationType::Format, "%msg");
	defaultConf.set(el::Level::Warning,
	                el::ConfigurationType::Format, "?: %msg");
	el::Loggers::reconfigureLogger("default", defaultConf);

	Game game;

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
		ExecuteCommand(game, line.c_str());
	}

	return 0;
}

#include <easylogging++.cc>
