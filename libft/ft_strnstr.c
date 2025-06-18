/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:52:00 by amweyer           #+#    #+#             */
/*   Updated: 2025/04/30 18:19:30 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;
	size_t	big_len;

	i = 0;
	little_len = ft_strlen(little);
	big_len = ft_strlen(big);
	if (!big_len && little_len)
		return (NULL);
	while (i + little_len <= len)
	{
		if (big[i] == little[0] || !little_len)
		{
			if ((ft_strncmp(&big[i], little, little_len)) == 0)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}

// #include <bsd/string.h>
// #include <stdio.h>
// #include <unistd.h>

// #include <string.h>

// static int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t	i;

// 	if (n == 0)
// 		return (0);
// 	i = 0;
// 	while ((i < n))
// 	{
// 		if ((s1[i] != s2[i]) || s1[i] == '\0' || s2[i] == '\0')
// 			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
// 		i++;
// 	}
// 	return (0);
// }

// static size_t	ft_strlen(const char *s)
// {
// 	size_t	l;

// 	l = 0;
// 	while (s[l])
// 		l++;
// 	return (l);
// }

// int	main(void)
// {
// 	printf("---------------------------------\n");
// 	printf("%s\n", ft_strnstr("lorem ipsum dolor sit amet", "ipsum", 15));
// 	printf("%s\n", strnstr("lorem ipsum dolor sit amet", "ipsum", 15));
// 	printf("---------------------------------\n");
// 	printf("%s\n", ft_strnstr("lorem ipsum dolor sit lorem ipsum dolor",
// 			"ipsum", 35));
// 	printf("%s\n", strnstr("lorem ipsum dolor sit lorem ipsum dolor", "ipsum",
// 			35));
// 	printf("---------------------------------\n");
// 	printf("%s\n", ft_strnstr("lorem ipsum dolor sit amet", "", 10));
// 	printf("%s\n", strnstr("lorem ipsum dolor sit amet", "", 10));
// 	printf("---------------------------------\n");
// 	printf("%s\n", ft_strnstr("lorem ipsum dolor sit amet", "dol", 30));
// 	printf("%s\n", strnstr("lorem ipsum dolor sit amet", "dol", 30));
// 	printf("---------------------------------\n");
// 	printf("%s\n", ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15));
// 	printf("%s\n", strnstr("lorem ipsum dolor sit amet", "dolor", 15));
// 	printf("---------------------------------\n");
// 	printf("%s\n", ft_strnstr("aaaa", "aaaa", 4));
// 	printf("%s\n", strnstr("aaaa", "aaaa", 4));
// 	printf("---------------------------------\n");
// 	printf("%s\n", ft_strnstr("", "xx", 4294967295));
// 	printf("%s\n", strnstr("", "xx", 4294967295));

// 	printf("---------------------------------\n");
// 	printf("%s\n", ft_strnstr("", "", 0));
// 	printf("%s\n", strnstr("", "", 0));

// 	printf("---------------------------------\n");
// 	printf("%s\n", ft_strnstr("", "", 1));
// 	printf("%s\n", strnstr("", "", 1));

// 	printf("---------------------------------\n");
// 	printf("%s\n", ft_strnstr("", "", 2));
// 	printf("%s\n", strnstr("", "", 2));

// }
