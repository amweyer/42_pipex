/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:14:27 by amweyer           #+#    #+#             */
/*   Updated: 2025/07/03 19:22:49 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipeline	*pipeline;
	int			a;

	// if (ac != 5)
	// 	return (print_error("Incorrect number of arguments"), 1);
	if (error_infile(av))
		return (1);
	pipeline = init_pipeline(ac, av, envp);
	if (!pipeline)
	{
		ft_printf("Error in the pipeline creation\n");
		return (1);
	}
	a = execute_pipeline(pipeline);
	(void)a;
	free_pipeline(pipeline);
	return (0);
}
