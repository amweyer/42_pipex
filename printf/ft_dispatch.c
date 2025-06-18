/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:45:54 by amweyer           #+#    #+#             */
/*   Updated: 2025/06/18 14:52:56 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_p_printf(unsigned long ptr)
{
	int	l;

	l = 0;
	if (ptr == 0)
		l += ft_putstr_printf("(nil)");
	else
	{
		l += ft_putstr_printf("0x");
		l += ft_putnbr_bu(ptr, "0123456789abcdef");
	}
	return (l);
}

int	ft_dispatch(char c, va_list *args)
{
	int	l;

	l = 0;
	if (c == '%')
		l += ft_putchar_printf('%');
	else if (c == 'c')
		l += ft_putchar_printf((char)va_arg(*args, int));
	else if (c == 's')
		l += ft_putstr_printf(va_arg(*args, char *));
	else if (c == 'u')
		l += ft_putnbr_bu(va_arg(*args, unsigned int), "0123456789");
	else if (c == 'x')
		l += ft_putnbr_bu((unsigned int)va_arg(*args, int), "0123456789abcdef");
	else if (c == 'X')
		l += ft_putnbr_bu((unsigned int)va_arg(*args, int), "0123456789ABCDEF");
	else if (c == 'd' || c == 'i')
		l += ft_putnbr_b_printf(va_arg(*args, int), "0123456789");
	else if (c == 'p')
		l += ft_putnbr_p_printf((unsigned long)va_arg(*args, void *));
	return (l);
}

int	ft_strchr_printf(const char *s, int c)
{
	int		i;
	char	*s1;

	i = 0;
	s1 = (char *)s;
	while (s1[i] != '\0')
	{
		if (s1[i] == (unsigned char)c)
			return (1);
		i++;
	}
	if (s1[i] == (unsigned char)c)
		return (1);
	return (0);
}
