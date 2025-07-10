/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:14:27 by amweyer           #+#    #+#             */
/*   Updated: 2025/07/08 15:13:22 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char **av, char **envp)
{
	t_pipeline	pipeline;

	parse(ac, av, &pipeline);
	init_pipeline(ac, av, envp, &pipeline);
	execute_pipeline(&pipeline);
	delete_infile(&pipeline);
	free_pipeline(&pipeline);
	return (0);
}
