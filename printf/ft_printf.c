/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:50:20 by amweyer           #+#    #+#             */
/*   Updated: 2025/06/09 12:19:33 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if ((str[i] == '%') && (ft_strchr_printf("cspdiuxX%%", str[i + 1])))
		{
			i++;
			len += ft_dispatch(str[i], &args);
		}
		else
			len += ft_putchar_printf(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

// #include <limits.h>
// #include <stdio.h>

// int	main(void)
// {
// 	printf("Test 2:\n");
// 	printf("%d\n",printf(0));
// 	printf("\n");
// 	printf("%d\n",ft_printf(0));
// 	printf("\n");
// 	return (0);
// }
