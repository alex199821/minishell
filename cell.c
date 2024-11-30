/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:30:58 by auplisas          #+#    #+#             */
/*   Updated: 2024/11/30 23:56:46 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cell.h"

char	**cell_split_line(char *line)
{
	char			**tokens;
	unsigned int	position;
	size_t			bufsize;

	bufsize = BUFSIZ;
	tokens = Malloc(bufsize * sizeof *tokens);
	position = 0;
	for (char *token = strtok(line, DEL); token; token = strtok(NULL, DEL))
	{
		tokens[position++] = token;
		if (position >= bufsize)
		{
			bufsize *= 2;
			tokens = Realloc(tokens, bufsize * sizeof *tokens);
		}
	}
	tokens[position] = NULL;
	return (tokens);
}

char	*cell_read_line(void)
{
	char	*buf;
	size_t	bufsize;
	char	cwd[BUFSIZ];

	buf = NULL;
	Getcwd(cwd, sizeof(cwd));
	p(C "%s" RST "$>", cwd);
	if (getline(&buf, &bufsize, stdin) == -1)
	{
        free(buf);
		buf = NULL;
		if (feof(stdin))
		{
			p(RED "[EOF]" RST);
		}
		else
		{
			p(RED "Getline failed" RST);
		}
		// p("%s\n", buf);
	}
	return (buf);
}

// int	main(int ac, char **av)
int	main(void)
{
	char *line;
	char **args;

	p("\n");
	printbanner();

	while ((line = cell_read_line()))
	{
		args = cell_split_line(line);
		for (int i = 0; args[i] != NULL; ++i)
		{
			p("%s\n", args[i]);
		}
        free(line);
        free(args);
		// while (args[i])
		// {
		// 	p("%s\n", args[i]);
		// 	i++;
		// }
	}
	return (EXIT_SUCCESS);
}