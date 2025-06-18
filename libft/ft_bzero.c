/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:26:13 by amweyer           #+#    #+#             */
/*   Updated: 2025/04/29 13:49:04 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s1;

	s1 = (unsigned char *)s;
	while (n--)
		*s1++ = 0;
}

// int	main(void)
// {
// 	char str[] = "Hello";
// 	ft_bzero(str, 2);
// 	printf("%c", str[1]);
// }