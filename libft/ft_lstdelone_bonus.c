/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:17:23 by amweyer           #+#    #+#             */
/*   Updated: 2025/04/30 12:07:37 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}

//--------------------------------TEST ---------------------------

// #include <stdio.h>

// void del(void *content)
// {
//     free(content);
// }

// int	main(void)
// {

//     int *a = malloc(sizeof(int));
//     if (!a)
//         return (1);

//     *a = 42;
//     t_list *node = ft_lstnew(a);
//     if (!node)
//     {
//         free(a);
//         return (1);
//     }

//     printf("Avant suppression : %d\n", *(int *)node->content);
//     ft_lstdelone(node, del);  // Supprimer le nœud
//     printf("Apres suppression : %d\n", *(int *)node->content);

// 	return (0);
// }