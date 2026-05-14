/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:36:30 by amweyer           #+#    #+#             */
/*   Updated: 2025/09/01 13:23:51 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse(int ac, char **av, t_pipeline *pipeline)
{
	if (ac < 5)
	{
		ft_printf("Error: Not enought arguments\n");
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp("here_doc", av[1], 10) == 0)
	{
		if (ac < 6)
		{
			ft_printf("Error: Not enought arguments\n");
			exit(EXIT_FAILURE);
		}
		pipeline->pipe_hd = check_here_doc(av);
		if (pipeline->pipe_hd == -1)
			free_error(pipeline, NULL, NULL);
		pipeline->here_doc = 1;
	}
	else
		pipeline->here_doc = 0;
	return ;
}

int	check_here_doc(char **av)
{
	char	*new_line;
	int		pipe_hd[2];

	if (av[2][0] == '\0' || !ft_strlen(av[2]))
	{
		ft_printf("Error: limiter empty\n");
		exit(EXIT_FAILURE);
	}
	if (create_pipe(pipe_hd))
		return (-1);
	ft_printf("here_doc > ");
	new_line = get_next_line(STDIN_FILENO);
	while (new_line && !(ft_strncmp(new_line, av[2], ft_strlen(av[2])) == 0
			&& new_line[ft_strlen(av[2])] == '\n'))
	{
		ft_printf("here_doc > ");
		write(pipe_hd[WRITE], new_line, ft_strlen(new_line));
		free(new_line);
		new_line = get_next_line(STDIN_FILENO);
	}
	free(new_line);
	free_gnl();
	close(pipe_hd[WRITE]);
	return (pipe_hd[READ]);
}
