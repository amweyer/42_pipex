/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:12:00 by amweyer           #+#    #+#             */
/*   Updated: 2025/05/01 14:52:37 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (siz > 0)
	{
		while (src[i] && i < (siz - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

// #include <stdio.h>
// #include <unistd.h>
// #include <bsd/string.h>

// int main()
// {
//     char dest[100] = " ";

// 	printf("%zu\n",(ft_strlcpy(dest, "lorem ipsum dolor sit amet", 0)));
//     write(1, "\n", 1);
//     write(1, dest, 15);
// 	printf("%zu\n",(strlcpy(dest, "lorem ipsum dolor sit amet", 0)));
//     write(1, "\n", 1);
//     write(1, dest, 15);

// }