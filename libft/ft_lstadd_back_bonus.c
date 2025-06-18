/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:07:50 by amweyer           #+#    #+#             */
/*   Updated: 2025/04/30 11:33:49 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return ;
}

//--------------------------------TEST ---------------------------

// 	t_list *second = ft_lstnew(&c);

// #include <stdio.h>

// int main()
// {

// 	int a =3;
// 	int b = 5;
// 	int c = 8;

// 	t_list *head  = ft_lstnew(&a);
// 	t_list *firts = ft_lstnew(&b);
// 	t_list *second = ft_lstnew(&c);

// 	ft_lstadd_back(&head, firts);
// 	ft_lstadd_back(&head, second);

// 	printf("1st node: %d\n", *(int *)head->content);       // 3
// 	printf("2nd node: %d\n", *(int *)head->next->content);  // 5
// 	printf("3nd node: %d\n", *(int *)head->next->next->content);  // 8

// 	return (0);
// }