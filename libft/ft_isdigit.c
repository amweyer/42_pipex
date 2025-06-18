/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:36:46 by amweyer           #+#    #+#             */
/*   Updated: 2025/04/22 14:40:34 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

// #include <ctype.h>
// #include <stdio.h>
// int main(void)
// {
// 	printf("%d\n", ft_isdigit('9'));
//     printf("%d", isdigit('9'));

// }
