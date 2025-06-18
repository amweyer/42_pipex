/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:16:21 by amweyer           #+#    #+#             */
/*   Updated: 2025/04/30 12:21:00 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp_current;
	t_list	*tmp_next;

	if (!lst || !*lst || !del)
		return ;
	tmp_current = *lst;
	while (tmp_current)
	{
		tmp_next = tmp_current->next;
		del(tmp_current->content);
		free(tmp_current);
		tmp_current = tmp_next;
	}
	*lst = NULL;
}

//--------------------------------TEST ---------------------------

// #include <stdio.h>

// void	del(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	int		*a;
// 	int		*b;
// 	int		*c;
// 	t_list	*node;
// 	t_list	*firts;
// 	t_list	*second;

// 	a = malloc(sizeof(int));
// 	b = malloc(sizeof(int));
// 	c = malloc(sizeof(int));
// 	if (!a || !b || !c)
// 		return (1);
// 	*a = 42;
// 	*b = 43;
// 	*c = 44;
// 	node = ft_lstnew(a);
// 	firts = ft_lstnew(b);
// 	second = ft_lstnew(c);
// 	ft_lstadd_front(&node, firts);
// 	ft_lstadd_front(&node, second);
// 	if (!node)
// 	{
// 		free(a);
// 		free(b);
// 		free(c);
// 		return (1);
// 	}
// 	printf("Avant suppression : %d\n", *(int *)node->content);
// 	ft_lstclear(&node, del);
// 	if (node == NULL)
// 		printf("La liste a bien été supprimée\n");
// 	else
// 		printf("Erreur : la liste n'est pas NULL\n");
// 	return (0);
// }
