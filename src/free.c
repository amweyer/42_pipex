/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:28:20 by amweyer           #+#    #+#             */
/*   Updated: 2025/07/09 15:30:42 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_pipeline(t_pipeline *pipeline)
{
	int	i;

	i = 0;
	while (i < pipeline->nb_cmds)
	{
		if (pipeline->cmds[i])
			free_cmd(pipeline->cmds[i]);
		i++;
	}
	free(pipeline->cmds);
}

void	free_cmd(t_cmd *cmd)
{
	if (!cmd)
		return ;
	if (cmd->args)
		free_tab(cmd->args);
	if (cmd->cmd)
		free(cmd->cmd);
	if (cmd->path)
		free(cmd->path);
	free(cmd);
}

void	free_error(t_pipeline *pipeline, t_fd *fd, int pipefd[2])
{
	perror("");
	close_all_fds(fd, pipefd);
	if (fd)
		free(fd);
	if (pipeline)
		free_pipeline(pipeline);
	exit(EXIT_FAILURE);
}
