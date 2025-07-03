/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:32:40 by amweyer           #+#    #+#             */
/*   Updated: 2025/07/03 19:29:44 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	show(const t_pipeline *pipeline)
{
	t_cmd	*cmd;

	int i, j;
	if (!pipeline)
	{
		printf("Pipeline is NULL\n");
		return ;
	}
	printf("Pipeline:\n");
	printf("  infile: %s\n", pipeline->infile ? pipeline->infile : "NULL");
	printf("  outfile: %s\n", pipeline->outfile ? pipeline->outfile : "NULL");
	printf("  nb_cmds: %d\n", pipeline->nb_cmds);
	for (i = 0; i < pipeline->nb_cmds; i++)
	{
		cmd = pipeline->cmds[i];
		if (!cmd)
		{
			printf("  cmd[%d]: NULL\n", i);
			continue ;
		}
		printf("  cmd[%d]:\n", i);
		printf("    cmd: %s\n", cmd->cmd ? cmd->cmd : "NULL");
		printf("    path: %s\n", cmd->path ? cmd->path : "NULL");
		printf("    args:\n");
		if (cmd->args)
		{
			for (j = 0; cmd->args[j] != NULL; j++)
				printf("      args[%d]: %s\n", j, cmd->args[j]);
		}
		else
		{
			printf("      (null)\n");
		}
	}
}
