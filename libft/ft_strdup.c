/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:39:22 by amweyer           #+#    #+#             */
/*   Updated: 2025/05/01 14:52:09 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	s_len;
	size_t	i;

	i = 0;
	s_len = ft_strlen(s);
	dup = (char *)malloc(s_len + 1);
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s\n", ft_strdup(""));
// 	printf("%s\n", strdup(""));
// }
