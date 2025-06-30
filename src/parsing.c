/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:48:46 by amweyer           #+#    #+#             */
/*   Updated: 2025/06/30 19:53:44 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parse(char **av, t_cmd *cmd1, t_cmd *cmd2)
{
	if (access(av[1], R_OK) != 0)
	{
		print_error("no such file or directory:");
		return (1);
	}
	if (!cmd1)
	{
		print_error("Command 1 not found");
		return (1);
	}
	if (!cmd2)
	{
		print_error("Command 2 not found");
		return (1);
	}
	return (0);
}

t_cmd	*init_cmd(char *arg, char **envp)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->args = get_args(arg);
	if (!cmd->args)
		return (free(cmd), NULL);
	cmd->cmd = ft_strdup(cmd->args[0]);
	if (!cmd->cmd)
		return (free_tab(cmd->args), free(cmd), NULL);
	cmd->path = get_path(cmd->cmd, envp);
	if (!cmd->path)
		return (free_tab(cmd->args), free(cmd->cmd), free(cmd), NULL);
	return (cmd);
}

char	**get_args(char *args)
{
	int		i;
	char	**cmds;

	i = 0;
	cmds = ft_split(args, ' ');
	if (!cmds || !cmds[0])
		return (NULL);
	return (cmds);
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

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*full_path;
	char	*tmp;

	i = 0;
	paths = ft_split(extract_path(envp), ':');
	if (!paths)
		return (NULL);
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin((const char *)tmp, (const char *)cmd);
		if (access(full_path, X_OK) == 0)
			return (free(tmp), free_tab(paths), full_path);
		free(tmp);
		i++;
	}
	free_tab(paths);
	return (NULL);
}
