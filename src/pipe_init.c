/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayaweyer <amayaweyer@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:48:46 by amweyer           #+#    #+#             */
/*   Updated: 2025/07/11 10:21:52 by amayaweyer       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pipeline(int ac, char **av, char **envp, t_pipeline *pipeline)
{
	if (!pipeline)
		exit(EXIT_FAILURE);
	pipeline->nb_cmds = ac - 3;
	pipeline->infile = av[1];
	pipeline->outfile = av[ac - 1];
	pipeline->envp = envp;
	get_all_cmds(pipeline, av, envp);
}

void	get_all_cmds(t_pipeline *pipeline, char **av, char **envp)
{
	int	i;
	int	nb_arg;

	i = 0;
	nb_arg = pipeline->nb_cmds;
	pipeline->cmds = malloc((nb_arg + 1) * sizeof(t_cmd *));
	if (!pipeline->cmds)
		free_error(NULL, NULL, NULL);
	while (i < nb_arg)
	{
		pipeline->cmds[i] = get_cmd(av[i + 2], envp);
		i++;
	}
	pipeline->cmds[nb_arg] = NULL;
}

t_cmd	*get_cmd(char *arg, char **envp)
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
	char	**cmds;

	cmds = ft_split(args, ' ');
	if (!cmds || !cmds[0])
		return (NULL);
	return (cmds);
}

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*full_path;
	char	*tmp;

	i = 0;
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
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
		free(full_path);
		i++;
	}
	free_tab(paths);
	return (NULL);
}
