/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:20:09 by amweyer           #+#    #+#             */
/*   Updated: 2025/04/30 12:07:09 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

//--------------------------------TEST ---------------------------

// #include <stdio.h>

// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }					t_list;

// int main()
// {
// 	t_list *head = NULL;

// 	head = ft_lstnew((void *)3);
// 	printf("%p head   : (%p, %p)\n", head, head->content, head->next);
// 	return (0);
// }