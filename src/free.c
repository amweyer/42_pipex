/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:28:20 by amweyer           #+#    #+#             */
/*   Updated: 2025/06/30 19:34:05 by amweyer          ###   ########.fr       */
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

void	free_struct(t_cmd *cmd)
{
	if (!cmd)
		return;
	if (cmd->args)
		free_tab(cmd->args);
	if (cmd->cmd)
		free(cmd->cmd);
	if (cmd->path)
		free(cmd->path);
	free(cmd);
}
