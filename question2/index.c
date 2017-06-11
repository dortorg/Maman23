#include "wordHandler.h"
#include "utils.h"

int main(int argc, char* argv[])
{
	unsigned int read;
	char* line = NULL;
	size_t len = 0;
	validateInput(argc, argv);
	init(argv[1]);
	while((read = getLine(&line, &len, rf)) != -1)
	{
		if(strcmp(line, "\n") != 0)
		{
			handleLine(line);
		}
	}
	printWords();
	fclose(rf);
	deinit();
	return 0;
}

