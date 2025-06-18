/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:45:56 by amweyer           #+#    #+#             */
/*   Updated: 2025/05/01 14:51:21 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s1;

	s1 = (unsigned char *)s;
	while (n--)
		*s1++ = (unsigned char)c;
	return (s);
}

// int	main(void)
// {
// 	char str[] = "Hello";
// 	ft_memset(str, '5', 2);
// 	printf("%s", str);
// }