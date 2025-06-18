/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:34:19 by amweyer           #+#    #+#             */
/*   Updated: 2025/04/28 09:46:51 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s1;

	s1 = (unsigned char *)s;
	while (n--)
		*s1++ = 0;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	array = (void *)malloc(nmemb * size);
	if (!array)
		return (NULL);
	ft_bzero(array, nmemb * size);
	return (array);
}

// int main()
// {
//     void *array =ft_calloc(5,1);
//     printf("%s\n", (char *)ft_calloc(5,1));
//     printf("%s\n", (char *)array);

// }
