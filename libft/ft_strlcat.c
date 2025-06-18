/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:43:51 by amweyer           #+#    #+#             */
/*   Updated: 2025/05/01 14:52:32 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	i = 0;
	src_len = 0;
	dst_len = 0;
	while (dst[dst_len] && dst_len < dstsize)
		dst_len++;
	while (src[src_len])
		src_len++;
	if (dst_len == dstsize)
		return (dstsize + src_len);
	while ((dst_len + i + 1) < dstsize && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len + i < dstsize)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
// #include <stdio.h>

// int main()
// {
//     char dst[]="abcdefg";
//     char src[]= "1234";
//     printf("%lu\n", ft_strlcat(dst, src, 3));
//     //printf("%lu\n", strlcat(dst, src, 3));

//     printf("%s\n", dst);

// }
