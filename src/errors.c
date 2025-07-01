/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:36:30 by amweyer           #+#    #+#             */
/*   Updated: 2025/07/01 18:42:18 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(char *msg)
{
	//ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}
int	error_infile(char **av)
{
	if (access(av[1], R_OK) != 0)
	{
		print_error("no such file or directory");
		ft_putendl_fd(av[1], 2);
		return (1);
	}
	return (0);
}