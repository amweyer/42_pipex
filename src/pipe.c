/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:08:02 by amweyer           #+#    #+#             */
/*   Updated: 2025/07/03 19:27:41 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execute_pipeline(const t_pipeline *pipeline)
{
	t_fd	*fd;
	int		res;

	fd = malloc(sizeof(t_fd));
	if (!fd)
		return (1);
	res = launch_pipeline(fd, pipeline);
	if (res)
	{
		free(fd);
		return (1);
	}
	wait_pid(pipeline);
	free(fd);
	return (0);
}

int	launch_pipeline(t_fd *fd, const t_pipeline *pipeline)
{
	int		i;
	int		pipefd[2];
	pid_t	pid;

	i = 0;
	while (i < pipeline->nb_cmds)
	{
		pipe(pipefd);
		fd = get_fd(fd, pipeline, pipefd, i);
		if (!fd)
			return (free(fd), 1);
		pid = fork();
		if (pid < 0)
		{
			perror("fork fail");
			return (1);
		}
		if (pid == 0)
			child_process(i, pipefd, fd, pipeline);
		else
			parent_process(i, pipefd, fd, pipeline);
		i++;
	}
	// close(fd->in);
	return (0);
}

void	child_process(int i, int *pipefd, t_fd *fd, const t_pipeline *pipeline)
{
	dup2(fd->in, STDIN_FILENO);
	dup2(fd->out, STDOUT_FILENO);
	if (i == 0)
		close(pipefd[READ]);
	close(fd->in);
	close(fd->out);
	execve(pipeline->cmds[i]->path, pipeline->cmds[i]->args, pipeline->envp);
}

void	parent_process(int i, int *pipefd, t_fd *fd, const t_pipeline *pipeline)
{
	close(fd->in);
	close(fd->out);
	if (i < pipeline->nb_cmds - 1)
		fd->in = pipefd[READ];
}
