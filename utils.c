#include "cell.h"

char	*Getcwd(char *buf, size_t size)
{
	char	*result;

	result = getcwd(buf, size);
	if (!result)
		perror(RED"Getcwd failed"RST);
	return (result);
}

void	*Malloc(size_t size)
{
	void	*ptr;

	if (size == 0)
		return (NULL);
	ptr = malloc(size);
	if (!ptr)
	{
		perror(RED"Malloc failed"RST);
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

void *Realloc(void *ptr, size_t size)
{
    void *new_ptr;
    
    new_ptr = realloc(ptr, size);
    if(!new_ptr && size != 0)
    {
        perror(RED"Realloc failed"RST);
        exit(EXIT_FAILURE);
    }
    return (new_ptr);
}

void printbanner(void)
{
    p(G"██████╗███████╗██╗     ██╗         ██╗   ██╗  ██╗\n"
      "██╔════╝██╔════╝██║     ██║         ██║   ██║ ███║\n"
      "██║     █████╗  ██║     ██║         ██║   ██║ ╚██║\n"
      "██║     ██╔══╝  ██║     ██║         ╚██╗ ██╔╝  ██║\n"
      "╚██████╗███████╗███████╗███████╗     ╚████╔╝██╗██║\n"
      " ╚═════╝╚══════╝╚══════╝╚══════╝      ╚═══╝ ╚═╝╚═╝\n"
      "                                                  \n"RST);
}