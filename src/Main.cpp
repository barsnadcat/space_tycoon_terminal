#include <SpaceTycoonModel.h>


#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <readline/readline.h>
#include <readline/history.h>


const char *gCommandNames[] = 
{
	"run",
	nullptr
};

char* CommandNameGenerator(const char* text, int state)
{
	static int listIndex, len;
	const char* name;

	if (!state) {
		listIndex = 0;
		len = strlen(text);
	}

	while ((name = gCommandNames[listIndex++])) {
		if (strncmp(name, text, len) == 0) {
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


int main(int argc, char** argv)
{

	rl_attempted_completion_function = CommandNameCompletion;
	Do();


	char* buf;
	while ((buf = readline("> ")) != nullptr) 
	{
		if (strlen(buf) > 0)
		{
			add_history(buf);
			printf("executing %s\n", buf);
		}

		free(buf);
	}

	return 0;
}