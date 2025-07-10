/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:36:30 by amweyer           #+#    #+#             */
/*   Updated: 2025/07/08 15:17:07 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_ac(int ac)
{
	if (ac != 5)
	{
		ft_printf("Incorrect number of arguments\n");
		exit(EXIT_FAILURE);
	}
}
