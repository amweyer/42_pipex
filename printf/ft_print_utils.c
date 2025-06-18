/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:47:32 by amweyer           #+#    #+#             */
/*   Updated: 2025/06/18 14:52:56 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen_printf(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

int	ft_putchar_printf(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr_printf(char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	else
	{
		len = 0;
		while (s[len])
			len++;
		if (write(1, s, len) == -1)
			return (-1);
		return (len);
	}
}

int	ft_putnbr_b_printf(int n, char *base)
{
	long	nb;
	char	c;
	int		len_base;
	int		len;

	nb = n;
	len = 0;
	len_base = ft_strlen_printf(base);
	if (nb < 0)
	{
		len += ft_putchar_printf('-');
		nb = -nb;
	}
	if (nb / len_base > 0)
		len += ft_putnbr_b_printf(nb / len_base, base);
	c = base[nb % len_base];
	len += ft_putchar_printf(c);
	return (len);
}

int	ft_putnbr_bu(unsigned long nb, char *base)
{
	char			c;
	unsigned long	len_base;
	int				len;

	len = 0;
	len_base = ft_strlen_printf(base);
	c = base[nb % len_base];
	if (nb / len_base > 0)
		len += ft_putnbr_bu(nb / len_base, base);
	len += ft_putchar_printf(c);
	return (len);
}
