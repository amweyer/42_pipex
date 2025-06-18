/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:18:04 by amweyer           #+#    #+#             */
/*   Updated: 2025/04/30 14:26:03 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

//--------------------------------TEST ---------------------------

// #include <stdio.h>

// void f(void *val)
// {
// 	int *v;

// 	v = (int*)val;
// 	*v += 1;

// }

// int main()
// {

// 	int a =2;
// 	int b = 4;
// 	int c = 8;

// 	t_list *head  = ft_lstnew(&a);
// 	t_list *firts = ft_lstnew(&b);
// 	t_list *second = ft_lstnew(&c);

// 	ft_lstadd_back(&head, firts);
// 	ft_lstadd_back(&head, second);

// 	printf("Before f()\n");
// 	printf("1st node: %d\n", *(int *)head->content);       // 2
// 	printf("2nd node: %d\n", *(int *)head->next->content);  // 4
// 	printf("3nd node: %d\n", *(int *)head->next->next->content);  // 8

// 	ft_lstiter(head,f);

// 	printf("After f()\n");
// 	printf("1st node: %d\n", *(int *)head->content);       // 2
// 	printf("2nd node: %d\n", *(int *)head->next->content);  // 4
// 	printf("3nd node: %d\n", *(int *)head->next->next->content);  // 8

// 	return (0);
// }
