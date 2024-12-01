/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:31:39 by auplisas          #+#    #+#             */
/*   Updated: 2024/12/01 18:09:11 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CELL_H
# define CELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sysexits.h>
# include <sys/wait.h>
# include <errno.h>

# define Y "\033[1;33m"
# define G "\033[1;32m"
# define C "\033[1;36m"
# define RED "\033[1;31m"
# define RST "\033[0m"

typedef struct s_builtin
{
	const char	*builtin_name;
	int			(*foo)(char **);
}				t_builtin;

# define p(...) printf(__VA_ARGS__)
# define DEL "\t\n\v\f\r "
# define CELL_Jr 0

char			*Getcwd(char *buf, size_t size);
void			printbanner(void);
void			dbzSpinnerLoading(void);
void			*Malloc(size_t size);
void			*Realloc(void *ptr, size_t size);
int				cell_exit(char **args);
int				cell_env(char **args);
pid_t			Fork(void);
void			Execvp(const char *file, char *const argv[]);
pid_t			Wait(int *status);
#endif