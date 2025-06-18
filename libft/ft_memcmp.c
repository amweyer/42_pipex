/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:39:39 by amweyer           #+#    #+#             */
/*   Updated: 2025/05/01 13:12:07 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*uc_s1;
	unsigned char	*uc_s2;
	size_t			i;

	uc_s1 = (unsigned char *)s1;
	uc_s2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	i = 0;
	while ((i < n))
	{
		if ((uc_s1[i] != uc_s2[i]))
			return (uc_s1[i] - uc_s2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// int	main(void)
// {
//     printf("%d\n", memcmp("Hello13546","Hello813546" , 6));
// 	printf("%d\n", ft_memcmp("Hello13546","Hello913546" , 6));

// 	printf("%d\n", ft_memcmp("abc", "abc", 7));
//     printf("%d\n", memcmp("abc", "abc", 7));

// }