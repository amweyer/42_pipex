/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:59:51 by amweyer           #+#    #+#             */
/*   Updated: 2025/06/18 17:53:22 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	get_nb_strs(char const *s, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c) && (i == 0 || c == s[i - 1]))
			nb++;
		i++;
	}
	return (nb);
}

static int	get_len_str(char const *s, char c, int start)
{
	int	len;

	len = start;
	while ((s[len] != c) && (s[len] != '\0'))
		len++;
	return (len - start);
}

static void	free_array(char **array, int strs)
{
	int	k;

	k = 0;
	while (k < strs)
		free(array[k++]);
	free(array);
}

static int	fill_all_words(char const *s, char c, char **array, int nb_strs)
{
	int	i;
	int	strs;
	int	len_str;

	i = 0;
	strs = 0;
	while (s[i] && strs < nb_strs)
	{
		if (s[i] != c)
		{
			len_str = get_len_str(s, c, i);
			array[strs] = malloc((len_str + 1) * sizeof(char));
			if (!array[strs])
			{
				free_array(array, strs);
				return (0);
			}
			ft_strlcpy(array[strs], &s[i], len_str + 1);
			i += len_str;
			strs++;
		}
		while (s[i] == c && s[i])
			i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		nb_strs;

	if (!s)
		return (NULL);
	nb_strs = get_nb_strs(s, c);
	array = malloc((nb_strs + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	if (!fill_all_words(s, c, array, nb_strs))
		return (free(array), NULL);
	array[nb_strs] = NULL;
	return (array);
}

// void	visualize_split(char **split_result)
// {
// 	int	i;

// 	i = 0;
// 	if (split_result == NULL)
// 	{
// 		printf("Erreur: Split échoué\n");
// 		return ;
// 	}
// 	while (split_result[i] != NULL)
// 	{
// 		printf("%s\n", split_result[i]);
// 		i++;
// 	}
// }

// #include <stdio.h>

// int	main(void)
// {
// 	// printf("%d\n", get_nb_strs(" ceci   re     est     un test   ", ' '));
// 	// printf("%d\n", get_len_str("ceci re     est     un test   ", ' ', 6));
// 	visualize_split(ft_split("    ce  ci re     est     un test   ", ' '));
// 	// visualize_split(ft_split("1234b        ", 'b'));
// 	//visualize_split(ft_split(" hello! ",' '));
// 	//visualize_split(ft_split("cedfbfs", ' '));
// }
