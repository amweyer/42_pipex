/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:14:27 by amweyer           #+#    #+#             */
/*   Updated: 2025/06/30 19:48:24 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_cmd	*cmd1;
	t_cmd	*cmd2;

	if (ac != 5)
		print_error("Incorrect number of arguments");
		
	cmd1 = init_cmd(av[2], envp);
	cmd2 = init_cmd(av[3], envp);

	if (parse(av, cmd1, cmd2))
	{
		free_struct(cmd1);
		free_struct(cmd2);    
		return (1);
	}
		
	printf("%s\n", cmd1->path);
	printf("%s\n", cmd2->path);

    free_struct(cmd1);
	free_struct(cmd2);    
	return (0);
}

// char **path;

// path = envp[19];
// parse(ac,av,envp);

// int main(int argc, char **argv, char **envp) {
//     (void)argc;
//     printf("%s\n",argv[0]);
//     for (int i = 0; envp[i] != NULL; i++) {
//         printf("envp[%d] = %s\n", i, envp[i]);
//     }
//     return (0);
// }
