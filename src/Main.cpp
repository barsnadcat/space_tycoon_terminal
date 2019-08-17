#include <SpaceTycoonModel.h>


#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <readline/readline.h>
#include <readline/history.h>

int main(int argc, char** argv)
{
	Do();

	char* buf;
	while ((buf = readline(">> ")) != nullptr) 
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