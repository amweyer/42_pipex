/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayaweyer <amayaweyer@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:08:02 by amweyer           #+#    #+#             */
/*   Updated: 2025/07/11 10:20:03 by amayaweyer       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execute_pipeline(t_pipeline *pipeline)
{
	t_fd	*fd;
	int		i;
	int		pipefd[2];
	pid_t	pid;

	fd = malloc(sizeof(t_fd));
	if (!fd)
		free_error(pipeline, NULL, NULL);
	i = 0;
	while (i < pipeline->nb_cmds)
	{
		if (create_pipe(pipefd))
			free_error(pipeline, fd, NULL);
		fd = get_fd(fd, pipeline, pipefd, i);
		pid = fork();
		if (pid < 0)
			free_error(pipeline, fd, NULL);
		if (pid == 0)
			child_process(i, pipefd, fd, pipeline);
		parent_process(i, pipefd, fd, pipeline);
		i++;
	}
	wait_pid(pipeline);
	free(fd);
}

t_fd	*get_fd(t_fd *fd, t_pipeline *pipeline, int *pipefd, int i)
{
	if (i == 0)
	{
		fd->in = open(pipeline->infile, O_RDONLY);
		fd->out = pipefd[WRITE];
	}
	else if (i == pipeline->nb_cmds - 1)
	{
		fd->out = open(pipeline->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0664);
		close(pipefd[READ]);
		close(pipefd[WRITE]);
	}
	else
		fd->out = pipefd[WRITE];
	return (fd);
}

void	child_process(int i, int *pipefd, t_fd *fd, t_pipeline *pipeline)
{
	if (!pipeline->cmds[i])
		free_error(pipeline, fd, pipefd);
	if (fd->in < 0 || fd->out < 0)
		free_error(pipeline, fd, pipefd);
	if (dup2(fd->in, STDIN_FILENO) == -1 || dup2(fd->out, STDOUT_FILENO) == -1)
		free_error(pipeline, fd, pipefd);
	close_all_fds(fd, pipefd);
	execve(pipeline->cmds[i]->path, pipeline->cmds[i]->args, pipeline->envp);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	parent_process(int i, int *pipefd, t_fd *fd, t_pipeline *pipeline)
{
	close(fd->in);
	close(fd->out);
	if (i < pipeline->nb_cmds - 1)
		fd->in = pipefd[READ];
}
