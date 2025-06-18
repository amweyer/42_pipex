/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:45:56 by amweyer           #+#    #+#             */
/*   Updated: 2025/05/01 13:24:59 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_empty_string(void)
{
	char	*out;

	out = malloc(1);
	if (!out)
		return (NULL);
	out[0] = '\0';
	return (out);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*out;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_empty_string());
	if (len > s_len - start)
		len = s_len - start;
	i = 0;
	out = malloc((len + 1) * sizeof(char));
	if (!out)
		return (NULL);
	while (i < len)
	{
		out[i] = s[start + i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

// #include <stdio.h>
// #include <unistd.h>
// int	main(void)
// {

// 	printf("%s\n", ft_substr("", 0, 0));
// 	printf("-----------------------------");
// 	printf("%s\n", ft_substr("hola", 4, 0));
// 	printf("-----------------------------");

// 	printf("%s\n", ft_substr("hola", 4, 1));
// 	printf("-----------------------------");

// 	printf("%s\n", ft_substr("hola", 4, 20));
// 	printf("-----------------------------");

// 	printf("%s\n", ft_substr("hola", 5, 2));
// 	printf("-----------------------------");

// 	printf("%s\n", ft_substr("", 0, 0));
// 	printf("-----------------------------");

// }