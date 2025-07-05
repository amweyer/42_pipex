/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:36:30 by amweyer           #+#    #+#             */
/*   Updated: 2025/07/05 15:28:06 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse(int ac, char **av)
{
	check_ac(ac);
	check_infile(av);
}

void	check_ac(int ac)
{
	if (ac != 5)
	{
		ft_printf("Incorrect number of arguments");
		exit(EXIT_FAILURE);
	}
}

void	check_infile(char **av)
{
	if (access(av[1], R_OK) != 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
}
