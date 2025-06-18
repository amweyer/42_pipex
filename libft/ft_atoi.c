/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:07:28 by amweyer           #+#    #+#             */
/*   Updated: 2025/06/17 12:09:29 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nb;
	int	neg;

	i = 0;
	nb = 0;
	neg = 1;
	while (nptr[i] == ' ' || (nptr[i] > 8 && nptr[i] < 14))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (nb * neg);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	printf("%d\n", ft_atoi(" \n   -123"));
// 	printf("%d\n", atoi(" \n  -123"));
// }
