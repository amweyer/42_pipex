/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:18:50 by amweyer           #+#    #+#             */
/*   Updated: 2025/05/01 13:10:18 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && (lst->next))
		lst = lst->next;
	return (lst);
}

//--------------------------------TEST ---------------------------

// #include <stdio.h>

// int main()
// {

// 	int a =3;
// 	int b = 5;
// 	int c = 8;
// 	t_list *last = NULL;

// 	t_list *head  = ft_lstnew(&a);
// 	t_list *firts = ft_lstnew(&b);

// 	ft_lstadd_back(&head, firts);
// 	last = ft_lstlast(head);
// 	printf("last node: %d\n", *(int *)last->content);  // 8
// 	ft_lstadd_back(&head, second);
// 	last = ft_lstlast(head);
// 	printf("last node: %d\n", *(int *)last->content);  // 8
// 	return (0);
// }