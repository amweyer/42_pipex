/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:13:19 by amweyer           #+#    #+#             */
/*   Updated: 2025/04/22 15:18:11 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c <= 127 && c >= 0)
		return (1);
	return (0);
}

// #include <ctype.h>
// #include <stdio.h>
// int main(void)
// {
// 	printf("%d\n", ft_isascii('ώ'));
//     printf("%d", ft_isascii('ώ'));

// }
