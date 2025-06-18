/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:57:50 by amweyer           #+#    #+#             */
/*   Updated: 2025/05/01 13:53:54 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t size)
{
	char		*d;
	const char	*s;
	void		*origin_d;

	if (!destination && !source)
		return (NULL);
	origin_d = destination;
	d = (char *)destination;
	s = (const char *)source;
	if (d < s)
	{
		while (size--)
			*(d++) = *(s++);
	}
	else
	{
		d += size;
		s += size;
		while (size-- > 0)
			*(--d) = *(--s);
	}
	return (origin_d);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char str[] = "memmove can be very useful......";
// 	char str2[] = "memmove can be very useful......";

// 	printf("-----------------------------\n");
// 	printf("%s\n", memmove(str + 20, str + 15, 11));
// 	printf("%s\n", ft_memmove(str2 + 20, str2 + 15, 11));

// 	printf("-----------------------------\n");
// 	printf("%s\n", memmove(NULL ,NULL,0));
// 	printf("%s\n", ft_memmove(NULL ,NULL,0));

// 	printf("-----------------------------\n");
// 	printf("%s\n", memmove(((void*)0), ((void*)0), 5));
// 	printf("%s\n", ft_memmove(((void*)0), ((void*)0), 5));
// }
