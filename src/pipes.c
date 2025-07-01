/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:08:02 by amweyer           #+#    #+#             */
/*   Updated: 2025/07/01 18:45:11 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	start_fd(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd == -1)
	{
		perror("Erreur ouverture fichier");
		return (1);
	}
	return (fd);
}

int	end_fd(char *outfile)
{
	int	fd;

	fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
	{
		perror("Erreur fermeture fichier");
		return (1);
	}
	return (fd);
}


int execute_pipeline(t_pipeline pipeline)
{

	
	
}


int	*start_pipe(char *infile, t_cmd *cmd)
{
	int		fd;
	int		pipe_fd[2];
	pid_t	pid;

	fd = open(infile, O_RDONLY);
	if (fd == -1)
	{
		perror("Erreur ouverture fichier");
		return (1);
	}
	pipe(pipe_fd);
	pid = fork();
	if (pid < 0)
	{
		perror("fork fail");
		return (1);
	}
	if (pid == 0)
	{
		dup2(fd, STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
		execve(cmd->path, cmd->args, cmd->envp);
	}
	else
	{
		
	}
	return pipe_fd;
}

int	end_pipe(char *outfile, t_cmd *cmd, int *pipe_fd)
{
	int	fd;
	
	fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
	{
		perror("Erreur fermeture fichier");
		return (1);
	}
	
	


	
}

/* pid == 0 : child process - pid = -1 : Erreur */
