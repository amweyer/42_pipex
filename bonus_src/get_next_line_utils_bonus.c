/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:09:18 by amayaweyer        #+#    #+#             */
/*   Updated: 2025/07/05 15:26:37 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*out;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	out = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!out)
		return (NULL);
	while (s1[i])
	{
		out[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		out[i] = s2[j];
		i++;
		j++;
	}
	out[i] = '\0';
	free(s1);
	return (out);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s1;

	i = 0;
	s1 = (char *)s;
	while (s1[i] != '\0')
	{
		if (s1[i] == (unsigned char)c)
			return (&s1[i]);
		i++;
	}
	if (s1[i] == (unsigned char)c)
		return (&s1[i]);
	return (0);
}

char	*ft_extract_line(char *stack)
{
	int		i;
	int		len;
	char	*line;

	if (!stack)
		return (NULL);
	i = 0;
	len = 0;
	while (stack[i] && stack[i] != '\n')
		i++;
	if (stack[i] == '\n')
		i++;
	len = i;
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = stack[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
