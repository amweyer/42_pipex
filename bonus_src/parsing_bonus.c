/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:36:30 by amweyer           #+#    #+#             */
/*   Updated: 2025/07/05 15:08:29 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	parse(char **av, t_pipeline *pipeline)
{
	if (check_here_doc(av) == 0)
		pipeline->here_doc = 1;
	else
	{
		check_infile(av);
		pipeline->here_doc = 0;
	}
	return ;
}

int	check_here_doc(char **av)
{
	char	*new_line;
	int		fd_infile;

	if (ft_strncmp("here_doc", av[1], 10) == 0)
	{
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
		return (0);
	}
	return (1);
}

void	check_infile(char **av)
{
	if (access(av[1], R_OK) != 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
}
