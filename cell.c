/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:30:58 by auplisas          #+#    #+#             */
/*   Updated: 2024/12/01 19:40:27 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cell.h"

t_builtin	g_builtin[] = {
	//{.builtin_name = "echo", .foo = cell_echo};
	{.builtin_name = "env", .foo = cell_env},
	{.builtin_name = "exit", .foo = cell_exit},
	{.builtin_name = NULL},
};

int			status = 0;

void	cell_launch(char **args)
{
	if (Fork() == CELL_Jr)
	{
		Execvp(args[0], args);
	}
	else
		Wait(&status);
}

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

void	cell_exec(char **args)
{
	int			i;
	const char	*curr;

	i = 0;
	while ((curr = g_builtin[i].builtin_name))
	{
		if (!strcmp(curr, args[0]))
		{
			status = g_builtin[i].foo(args);
			return ;
		}
		++i;
	}
	cell_launch(args);
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
		// while (args[i])
		// {
		// 	p("%s\n", args[i]);
		// 	i++;
		// }
		// for (int i = 0; args[i] != NULL; ++i)
		// {
		// 	p("%s\n", args[i]);
		// }
		cell_exec(args);
		free(line);
		free(args);
	}
	return (EXIT_SUCCESS);
}