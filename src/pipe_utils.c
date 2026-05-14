/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:25:09 by amweyer           #+#    #+#             */
/*   Updated: 2025/09/01 15:50:43 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_pid(t_pipeline *pipeline, pid_t last_pid)
{
	int		status;
	pid_t	wpid;

	pipeline->exit_code = 0;
	wpid = wait(&status);
	while ((wpid) > 0)
	{
		if (wpid == last_pid)
		{
			if (WIFEXITED(status))
				pipeline->exit_code = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				pipeline->exit_code = 128 + WTERMSIG(status);
		}
		wpid = wait(&status);
	}
}

char	*extract_path(char **envp)
{
	int		i;
	char	*path;

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

void	close_all_fds(t_fd *fd, int *pipefd)
{
	if (fd->in >= 0)
		close(fd->in);
	if (fd->out >= 0)
		close(fd->out);
	if (pipefd)
	{
		close(pipefd[READ]);
		close(pipefd[WRITE]);
	}
}

int	create_pipe(int pipefd[2])
{
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (1);
	}
	return (0);
}
