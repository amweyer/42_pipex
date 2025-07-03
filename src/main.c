/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:14:27 by amweyer           #+#    #+#             */
/*   Updated: 2025/07/03 15:13:18 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipeline *pipeline;

	// if (ac != 5)
	// 	return (print_error("Incorrect number of arguments"), 1);
	
	if(error_infile(av))
		return(1);	
	
	pipeline = init_pipeline(ac,av,envp);

	if(!pipeline)
	{
		ft_printf("Error in the pipeline creation\n");
		return(1);
	}
	// show(pipeline);
	/* ------------- PARSE ------------- */
	int a = execute_pipeline(pipeline);
	// ft_printf("%d\n",a);
	(void) a;
	
	
	free_pipeline(pipeline);
	
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
