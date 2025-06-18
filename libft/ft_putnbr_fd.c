/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:30:45 by amweyer           #+#    #+#             */
/*   Updated: 2025/05/01 14:51:43 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	c;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	c = nb % 10 + '0';
	if (nb / 10 > 0)
		ft_putnbr_fd(nb / 10, fd);
	write(fd, &c, 1);
}

// int	main(void)
// {
// 	ft_putnbr_fd(-2147483648, 1);
// }