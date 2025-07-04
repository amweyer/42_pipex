/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:36:30 by amweyer           #+#    #+#             */
/*   Updated: 2025/07/04 12:14:14 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void parse(int ac, char **av)
{
	//check_ac(ac);
	(void) ac;
	check_infile(av);
}

void check_ac(int ac)
{
	if (ac != 5)
	{
		perror("Incorrect number of arguments");
		exit(EXIT_FAILURE);
	}
}

void	check_infile(char **av)
{
	if (access(av[1], R_OK) != 0)
	{
		perror("no such file or directory: ");
		ft_putendl_fd(av[1], 2);
		exit(EXIT_FAILURE);
	}
}



void	print_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}