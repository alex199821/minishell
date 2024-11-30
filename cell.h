/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:31:39 by auplisas          #+#    #+#             */
/*   Updated: 2024/11/30 23:46:00 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CELL_H
# define CELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define Y "\033[1;33m"
# define G "\033[1;32m"
# define C "\033[1;36m"
# define RED "\033[1;31m"
# define RST "\033[0m"

# define p(...) printf(__VA_ARGS__)
# define DEL "\t\n\v\f\r "

char	*Getcwd(char *buf, size_t size);
void	printbanner(void);
void	*Malloc(size_t size);
void	*Realloc(void *ptr, size_t size);

#endif