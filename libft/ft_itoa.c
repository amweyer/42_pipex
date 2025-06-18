/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:14:07 by amweyer           #+#    #+#             */
/*   Updated: 2025/05/01 14:50:50 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_nb(long nb)
{
	int	len;

	len = 1;
	while (nb / 10 != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len_nb;
	char	*out;

	nb = n;
	if (n < 0)
		nb = -nb;
	len_nb = ft_len_nb(nb) + (n < 0);
	out = malloc((len_nb + 1) * sizeof(char));
	if (!out)
		return (NULL);
	if (n < 0)
		out[0] = '-';
	out[len_nb] = '\0';
	while (len_nb-- > 0 && out[len_nb] != '-')
	{
		out[len_nb] = nb % 10 + '0';
		nb /= 10;
	}
	return (out);
}
