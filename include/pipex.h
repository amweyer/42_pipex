/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:12:05 by amweyer           #+#    #+#             */
/*   Updated: 2025/07/04 12:50:21 by amweyer          ###   ########.fr       */
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
# include <sys/wait.h>
# include <unistd.h>

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
	int		out;

}			t_fd;

/* parsing.c */
void		print_error(char *msg);
void		check_infile(char **av);
void		check_ac(int ac);
void		parse(int ac, char **av);

/* free.c */
void		free_tab(char **tab);
void		free_cmd(t_cmd *cmd);
void		free_error(t_cmd *cmd1, t_cmd *cmd2);
void		free_pipeline(t_pipeline *pipeline);

/* pipe_init.c */
void		init_pipeline(int ac, char **av, char **envp, t_pipeline *pipeline);
void		get_all_cmds(t_pipeline *pipeline, char **av, char **envp);
char		**get_args(char *args);
char		*get_path(char *cmd, char **envp);
t_cmd		*get_cmd(char *arg, char **envp);

/* pipes_utils.c */
void		wait_pid(t_pipeline *pipeline);
t_fd		*get_fd(t_fd *fd, t_pipeline *pipeline, int *pipefd, int i);
char		*extract_path(char **envp);

/* pipe.c */
void		execute_pipeline(t_pipeline *pipeline);
int			launch_pipeline(t_fd *fd, t_pipeline *pipeline);
void		child_process(int i, int *pipefd, t_fd *fd, t_pipeline *pipeline);
void		parent_process(int i, int *pipefd, t_fd *fd, t_pipeline *pipeline);

/* utils.c */
void		show(t_pipeline *pipeline);

#endif