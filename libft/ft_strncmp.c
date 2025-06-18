/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:11:14 by amweyer           #+#    #+#             */
/*   Updated: 2025/05/01 14:53:02 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((i < n))
	{
		if ((s1[i] != s2[i]) || s1[i] == '\0' || s2[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", ft_strncmp("test1", "test", 4));
// 	printf("%d\n", strncmp("test1", "test", 4));
// 	printf("----------------------------------------\n");
// 	printf("%d\n", ft_strncmp("zyxbcdefgh", "abcdwxyz", 0));
// 	printf("%d\n", strncmp("zyxbcdefgh", "abcdwxyz", 0));
// 	printf("----------------------------------------\n");
// 	printf("%d\n", ft_strncmp("zyxbcdefgh", "abcdwxyz", 0));
// 	printf("%d\n", strncmp("zyxbcdefgh", "abcdwxyz", 0));
// 	printf("----------------------------------------\n");
// 	printf("%d\n", ft_strncmp("", "test", 4));
// 	printf("%d\n", strncmp("", "test", 4));

// 	printf("----------------------------------------\n");
// 	printf("%d\n", ft_strncmp("", "test", 1));
// 	printf("%d\n", strncmp("", "test", 1));
// 	printf("----------------------------------------\n");
// 	printf("%d\n", ft_strncmp("", "test", 2));
// 	printf("%d\n", strncmp("", "test", 2));
// 	printf("----------------------------------------\n");
// 	printf("%d\n", ft_strncmp("teste", "testex", 6));
// 	printf("%d\n", strncmp("teste", "testex", 6));

// 	printf("----------------------------------------\n");
// 	printf("%d\n", ft_strncmp("test\200", "test\0", 6));
// 	printf("%d\n", strncmp("test\200", "test\0", 6));

// }