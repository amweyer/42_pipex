/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:20:51 by amweyer           #+#    #+#             */
/*   Updated: 2025/04/30 11:20:21 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	nb;

	nb = 0;
	while (lst)
	{
		lst = lst->next;
		nb++;
	}
	return (nb);
}

//--------------------------------TEST ---------------------------

// #include <stdio.h>

// int	main(void)
// {
// 	int a = 3;
// 	int b = 5;
// 	int c = 8;

// 	t_list *head = ft_lstnew(&a);
// 	printf("lst size: %d\n", ft_lstsize(head)); // 1

// 	t_list *firts = ft_lstnew(&b);
// 	t_list *second = ft_lstnew(&c);

// 	ft_lstadd_front(&head, firts);
// 	printf("lst size: %d\n", ft_lstsize(head)); // 2

// 	ft_lstadd_front(&head, second);
// 	printf("lst size: %d\n", ft_lstsize(head)); // 3
// 	return (0);
// }