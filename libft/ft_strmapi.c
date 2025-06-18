/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:25:48 by amweyer           #+#    #+#             */
/*   Updated: 2025/05/01 14:52:56 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*out;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = 0;
	while (s[len])
		len++;
	out = malloc((len + 1) * sizeof(char));
	if (!out)
		return (NULL);
	while (i < len)
	{
		out[i] = f(i, s[i]);
		i++;
	}
	out[i] = '\0';
	return (out);
}

// int main()
// {
//     printf("%s\n",ft_strmapi("lalala", test));
// }