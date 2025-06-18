/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:30:58 by amweyer           #+#    #+#             */
/*   Updated: 2025/04/22 14:35:26 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

// #include <ctype.h>
// #include <stdio.h>
// int main()
// {
//     printf("%d\n", ft_isalpha('R'));
//     printf("%d\n", isalpha('R'));

// }
