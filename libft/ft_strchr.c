/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:49:12 by amweyer           #+#    #+#             */
/*   Updated: 2025/05/01 14:10:37 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s1;

	i = 0;
	s1 = (char *)s;
	while (s1[i] != '\0')
	{
		if (s1[i] == (unsigned char)c)
			return (&s1[i]);
		i++;
	}
	if (s1[i] == (unsigned char)c)
		return (&s1[i]);
	return (0);
}

// #include <bsd/string.h>
// #include <stdio.h>
// #include <unistd.h>

// int	main(void)
// {
// 	char	str[] = "Hello \0 13546";
// 	char	s[] = "tripouille";

// 	printf("%s\n", ft_strchr("teste", 'e'));
// 	printf("%s\n", strchr("teste", 'e'));
// 	printf("%s\n", ft_strchr("teste", '\0'));
// 	printf("%s\n", strchr("teste", '\0'));
// 	printf("%s\n", ft_strchr(s, 't' + 256));
// 	printf("%s\n", strchr(s, 't' + 256));
// 	printf("%s\n", ft_strchr("teste", 1024));
// 	printf("%s\n", strchr("teste", 1024));

// }
