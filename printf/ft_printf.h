/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:59:44 by amweyer           #+#    #+#             */
/*   Updated: 2025/06/18 14:52:56 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_dispatch(char c, va_list *args);
int	ft_strlen_printf(char *str);
int	ft_putchar_printf(char c);
int	ft_putstr_printf(char *s);
int	ft_putnbr_b_printf(int n, char *base);
int	ft_putnbr_bu(unsigned long nb, char *base);
int	ft_strchr_printf(const char *s, int c);
int	ft_printf_p_printf(unsigned long ptr);

#endif