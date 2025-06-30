/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:12:05 by amweyer           #+#    #+#             */
/*   Updated: 2025/06/30 20:45:41 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf.h"
# include "libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_cmd
{
	char	*cmd;
	char	*path;
	char	**args;
}			t_cmd;

/* parsing.c */
int			parse(char **av, t_cmd *cmd1, t_cmd *cmd2);
char		*extract_path(char **envp);
char		*get_path(char *cmd, char **envp);
char		**get_args(char *args);
void		free_tab(char **tab);
t_cmd		*init_cmd(char *arg, char **envp);

/* free.c */

void		free_tab(char **tab);
void		free_struct(t_cmd *cmd);
void		free_error(t_cmd *cmd1, t_cmd *cmd2);

/* errors.c */
void		print_error(char *msg);

/* files.c */
int			get_fd(char *file, int in);

#endif