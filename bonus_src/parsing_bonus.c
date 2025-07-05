/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:36:30 by amweyer           #+#    #+#             */
/*   Updated: 2025/07/05 13:54:37 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	parse(char **av)
{
	check_infile(av);
}

// void	check_ac(int ac)
// {
// 	if (ac != 5)
// 	{
// 		ft_printf("Incorrect number of arguments");
// 		exit(EXIT_FAILURE);
// 	}
// }

void	check_infile(char **av)
{
	if (access(av[1], R_OK) != 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
}

void	print_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}