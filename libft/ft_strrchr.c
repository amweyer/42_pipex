/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:03:45 by amweyer           #+#    #+#             */
/*   Updated: 2025/05/01 14:53:14 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len_s;

	len_s = ft_strlen(s);
	if (s[len_s] == (char)c)
		return ((char *)&s[len_s]);
	while (len_s--)
	{
		if (s[len_s] == (char)c)
			return ((char *)&s[len_s]);
	}
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char str[] = "Hello1354e6";
// 	printf("%s\n", ft_strrchr(str, '\0'));
// }
