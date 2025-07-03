/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:12:05 by amweyer           #+#    #+#             */
/*   Updated: 2025/07/03 11:26:31 by amweyer          ###   ########.fr       */
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
#include <sys/wait.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define READ 0
# define WRITE 1

typedef struct s_cmd
{
	char	*cmd;
	char	*path;
	char	**args;
}			t_cmd;

typedef struct s_pipeline
{
	int		nb_cmds;
	char	*infile;
	char	*outfile;
	t_cmd	**cmds;
	char	**envp;
}			t_pipeline;

typedef struct s_fd
{
	int		in;
	int 	out;

}			t_fd;

/* parsing.c */
t_pipeline	*init_pipeline(int ac, char **av, char **envp);
char		*extract_path(char **envp);
char		*get_path(char *cmd, char **envp);
char		**get_args(char *args);
void		free_tab(char **tab);
t_cmd		*init_cmd(char *arg, char **envp);

/* free.c */

void		free_tab(char **tab);
void		free_cmd(t_cmd *cmd);
void		free_error(t_cmd *cmd1, t_cmd *cmd2);
void	free_pipeline(t_pipeline *pipeline);

/* errors.c */
void		print_error(char *msg);
int	error_infile(char **av);

/* utils.c */
void show(const t_pipeline *pipeline);

/* pipes.c */
int execute_pipeline(const t_pipeline *pipeline);
t_fd	*get_fd(t_fd *fd, const t_pipeline *pipeline, int *pipefd, int i);


#endif