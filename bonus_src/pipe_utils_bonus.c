/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:25:09 by amweyer           #+#    #+#             */
/*   Updated: 2025/07/04 16:49:21 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_fd	*get_fd(t_fd *fd, t_pipeline *pipeline, int *pipefd, int i)
{
	if (i == 0)
	{
		fd->in = open(pipeline->infile, O_RDONLY);
		fd->out = pipefd[WRITE];
	}
	else if (i == pipeline->nb_cmds - 1)
	{
		fd->out = open(pipeline->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		close(pipefd[READ]);
		close(pipefd[WRITE]);
	}
	else
		fd->out = pipefd[WRITE];
	return (fd);
}

void	wait_pid(t_pipeline *pipeline)
{
	int	i;
	int	status;

	i = 0;
	while (i < pipeline->nb_cmds)
	{
		wait(&status);
		i++;
	}
}

char	*extract_path(char **envp)
{
	int i;
	char *path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = envp[i] + 5;
			return (path);
		}
		i++;
	}
	return (NULL);
}