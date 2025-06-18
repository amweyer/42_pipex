/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:15:31 by amweyer           #+#    #+#             */
/*   Updated: 2025/04/30 11:33:36 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

//--------------------------------TEST ---------------------------

// 	t_list *second = ft_lstnew(&c);

// #include <stdio.h>

// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }					t_list;

// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*new;

// 	new = malloc(sizeof(t_list));
// 	if (!new)
// 		return (NULL);
// 	new->content = content;
// 	new->next = NULL;
// 	return (new);
// }

// int main()
// {

// 	int a =3;
// 	int b = 5;
// 	int c = 8;

// 	t_list *head  = ft_lstnew(&a);
// 	t_list *firts = ft_lstnew(&b);
// 	t_list *second = ft_lstnew(&c);

// 	ft_lstadd_front(&head, firts);
// 	ft_lstadd_front(&head, second);

// 	printf("1st node: %d\n", *(int *)head->content);       // 8
// 	printf("2nd node: %d\n", *(int *)head->next->content);  // 5
// 	printf("3nd node: %d\n", *(int *)head->next->next->content);  // 3

// 	return (0);
// }