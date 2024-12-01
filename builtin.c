#include "cell.h"

int	cell_exit(char **args)
{
	(void)args;
	dbzSpinnerLoading();
	exit(EXIT_SUCCESS);
}

int	cell_env(char **args)
{
	extern char **environ;

	(void)args;
	if (!environ)
		return (1);
	for (int i = 0; environ[i]; i++)
		p("%s\n", environ[i]);
	return (0);
}