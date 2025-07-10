/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:36:30 by amweyer           #+#    #+#             */
/*   Updated: 2025/07/09 19:10:28 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
		check_here_doc(av);
		pipeline->here_doc = 1;
	}
	else
		pipeline->here_doc = 0;
	return ;
}

void	check_here_doc(char **av)
{
	char	*new_line;
	int		fd_infile;

	if (av[2][0] == '\0' || !ft_strlen(av[2]))
	{
		ft_printf("Error: limiter empty\n");
		exit(EXIT_FAILURE);
	}
	fd_infile = open("infile", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_infile < 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	new_line = get_next_line(STDIN_FILENO);
	while (new_line && !(ft_strncmp(new_line, av[2], ft_strlen(av[2])) == 0
			&& new_line[ft_strlen(av[2])] == '\n'))
	{
		write(fd_infile, new_line, ft_strlen(new_line));
		free(new_line);
		new_line = get_next_line(STDIN_FILENO);
	}
	free(new_line);
	free_gnl();
	close(fd_infile);
}

void	delete_infile(t_pipeline *pipeline)
{
	if (pipeline->here_doc)
	{
		if (unlink("infile") != 0)
			perror("Error");
	}
}
