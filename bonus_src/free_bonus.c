/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:28:20 by amweyer           #+#    #+#             */
/*   Updated: 2025/07/05 13:44:18 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
	while (pipeline->cmds[i])
	{
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

void	free_error(t_cmd *cmd1, t_cmd *cmd2)
{
	free_cmd(cmd1);
	free_cmd(cmd2);
	exit(1);
}
