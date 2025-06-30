/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:48:46 by amweyer           #+#    #+#             */
/*   Updated: 2025/06/30 16:32:10 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parse(int ac, char **av, char **envp)
{
	char	*path;

	if (ac != 5)
		return (1);
	if (access(av[1], R_OK) != 0)
		return (1);
	if (access(av[4], W_OK) != 0)
		return (1);
	path = extract_path(envp);
	if (!path)
		return (1);
	if(!check_cmd(av[2], path))
		return(1);
	if(!check_cmd(av[3], path))
		return(1);
	return(0);
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

char *get_path(char *cmd, char *path)
{
	int		i;
	char	**paths;
	char	*full_path;
	char	*tmp;

	i = 0;
	paths = ft_split(path, ':');
	if(!paths)
		return(NULL);
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin((const char *)tmp, (const char *)cmd);
		if (access(full_path, X_OK) == 0)
			return(free(tmp), free_tab(paths), full_path);
		free(tmp);
		i++;
	}
	free_tab(paths);
	return (NULL);
}


int	check_cmd(char *args, char *path)
{
	int		i;
	char	**cmds;

	i = 0;
	cmds = ft_split(args, ' ');
	if(!cmds)
		return(0);
	if(!get_path(cmds[0], path))
		return(free_tab(cmds), 0);
	return(free_tab(cmds), 1);
}

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}