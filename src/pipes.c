/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:08:02 by amweyer           #+#    #+#             */
/*   Updated: 2025/07/02 19:38:22 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



#include <stdio.h>


// int	start_fd(char *infile)
// {
// 	int	fd;

// 	fd = open(infile, O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Erreur ouverture fichier");
// 		return (1);
// 	}
// 	return (fd);
// }

// int	end_fd(char *outfile)
// {
// 	int	fd;

// 	fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
// 	if (fd == -1)
// 	{
// 		perror("Erreur fermeture fichier");
// 		return (1);
// 	}
// 	return (fd);
// }

t_fd	*get_fd(t_fd *fd, t_pipeline *pipeline, int *pipefd, int i)
{

	// printf(" ------------------ %d -------------------\n", i);
	// show(pipeline);
	// printf("[pipeline->outfile] %s\n", pipeline->outfile);
	// printf("[pipeline->nb_cmd] %d\n", pipeline->nb_cmds);

	// printf(" -------------------------------------\n");
	//show(pipeline);
	// printf("[pipeline->outfile] %s\n", pipeline->outfile);
	// printf("[pipeline->nb_cmd] %d\n", pipeline->nb_cmds);

	if (!fd)
	{
		fd = malloc(sizeof(t_fd));
		if (!fd)
			return (NULL);
	}
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

int	execute_pipeline(t_pipeline *pipeline)
{
	int		i;
	int		pipefd[2];
	pid_t	pid;
	t_fd	*fd;

	i = 0;
	// printf(" ------------------ %d -------------------\n", i);
	// show(pipeline);
	// show(pipeline);
	// show(pipeline);

	while (i < pipeline->nb_cmds)
	{

		// printf("[pipeline->outflie] %s\n", pipeline->outfile);
		pipe(pipefd);
		fd = get_fd(fd, pipeline, pipefd, i);
		printf(" ------------------ %d -------------------\n", i);
		show(pipeline);
		if (!fd)
			return (1);
		pid = fork();

		if (pid < 0)
		{
			perror("fork fail");
			return (1);
		}
		if (pid == 0)
		{
			dup2(fd->in, STDIN_FILENO);
			dup2(fd->out, STDOUT_FILENO);
			if (i == 0)
				close(pipefd[READ]);
			close(fd->in);
			close(fd->out);
			execve(pipeline->cmds[i]->path, pipeline->cmds[i]->args,
				pipeline->envp);
			//printf("Child: executed command: %d", i);
		}
		else
		{
			//printf("Child: executed command: %d", i);

			close(fd->in);
			close(fd->out);
			if (i < pipeline->nb_cmds - 1)
				fd->in = pipefd[READ];
		}
		i++;
	}
	close(fd->in);
	while (waitpid(0, NULL, 0) != -1)
		;
	return (0);
}
