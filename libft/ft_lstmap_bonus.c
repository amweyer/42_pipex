/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:19:29 by amweyer           #+#    #+#             */
/*   Updated: 2025/05/01 14:46:15 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_dup;
	t_list	*new;
	t_list	*f_lst;

	lst_dup = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		f_lst = f(lst->content);
		new = ft_lstnew(f_lst);
		if (!new)
		{
			del(f_lst);
			ft_lstclear(&lst_dup, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_dup, new);
		lst = lst->next;
	}
	return (lst_dup);
}

//--------------------------------TEST ---------------------------

// #include <stdio.h>

// void	del(void *content)
// {
// 	free(content);
// }

// void	*f(void *val)
// {
// 	int	*v;
// 	int	*tmp;

// 	v = (int *)val;
// 	tmp = malloc(sizeof(int));
// 	*tmp = *v + 1;
// 	return ((void *)tmp);
// }

// int	main(void)
// {
// 	int		*a;
// 	int		*b;
// 	int		*c;
// 	t_list	*node;
// 	t_list	*firts;
// 	t_list	*second;
// 	t_list	*dup;

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
// 	dup = ft_lstmap(node, f, del);
// 	printf("---------NODE---------\n");
// 	printf("1er element: %d\n", *(int *)node->content);
// 	printf("2er element: %d\n", *(int *)node->next->content);
// 	printf("3er element: %d\n", *(int *)node->next->next->content);
// 	printf("\n---------DUP---------\n");
// 	printf("1er element: %d\n", *(int *)dup->content);
// 	printf("2er element: %d\n", *(int *)dup->next->content);
// 	printf("3er element: %d\n", *(int *)dup->next->next->content);
// }
