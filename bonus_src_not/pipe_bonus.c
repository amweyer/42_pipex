/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:08:02 by amweyer           #+#    #+#             */
/*   Updated: 2025/07/04 19:40:37 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execute_pipeline(t_pipeline *pipeline)
{
	t_fd	*fd;
	int		res;

	// show(pipeline);
	fd = malloc(sizeof(t_fd));
	if (!fd)
	{
		free_pipeline(pipeline);
		exit(EXIT_FAILURE);
	}
	printf("Before res\n");

	res = launch_pipeline(fd, pipeline);
	printf("after res\n");

	if (res)
	{
		free(fd);
		free_pipeline(pipeline);
		exit(EXIT_FAILURE);
	}
	// printf("After\n");
	printf("After exit faiure\n");

	wait_pid(pipeline);
	printf("Before free\n");

	free(fd);
	printf("After free\n");

}

int	launch_pipeline(t_fd *fd, t_pipeline *pipeline)
{
	int		i;
	int		pipefd[2];
	pid_t	pid;

	i = 0;

	// printf("pipeline->nb_cmds: %d\n", pipeline->nb_cmds);
	while (i < pipeline->nb_cmds)
	{
		// printf("i: %d\n",i);

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
	return (0);
}

void	child_process(int i, int *pipefd, t_fd *fd, t_pipeline *pipeline)
{
	dup2(fd->in, STDIN_FILENO);
	dup2(fd->out, STDOUT_FILENO);
	close(pipefd[READ]);
	close(pipefd[WRITE]);
	close(fd->in);
	close(fd->out);
	execve(pipeline->cmds[i]->path, pipeline->cmds[i]->args, pipeline->envp);
}

void	parent_process(int i, int *pipefd, t_fd *fd, t_pipeline *pipeline)
{
	close(fd->in);
	close(fd->out);
	if (i < pipeline->nb_cmds - 1)
		fd->in = pipefd[READ];
}
