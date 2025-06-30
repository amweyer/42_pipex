/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:14:27 by amweyer           #+#    #+#             */
/*   Updated: 2025/06/30 16:34:14 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
    if(parse(ac, av, envp))
    {
        ft_printf("Error\n");
        return(1);
    }
    return(0);


    
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
