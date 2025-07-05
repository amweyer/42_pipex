/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:09:13 by amayaweyer        #+#    #+#             */
/*   Updated: 2025/07/05 15:26:53 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	**get_stack(void)
{
	static char	*stack = NULL;

	return (&stack);
}

void	free_gnl(void)
{
	char	**stack;

	stack = get_stack();
	if (*stack)
	{
		free(*stack);
		*stack = NULL;
	}
}

char	*ft_clean_stack(char *stack)
{
	char	*new_stack;
	int		i;
	int		j;

	if (!stack)
		return (NULL);
	i = 0;
	while (stack[i] && stack[i] != '\n')
		i++;
	if (!stack[i])
	{
		free(stack);
		return (NULL);
	}
	new_stack = malloc(ft_strlen(stack) - i);
	if (!new_stack)
		return (NULL);
	j = 0;
	i++;
	while (stack[i])
		new_stack[j++] = stack[i++];
	new_stack[j] = '\0';
	free(stack);
	return (new_stack);
}

char	*ft_fill_stack(int fd, char *stack)
{
	char	*buf;
	int		r;

	r = 1;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!ft_strchr(stack, '\n') && r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[r] = '\0';
		stack = ft_strjoin_gnl(stack, buf);
		if (!stack)
		{
			free(buf);
			return (NULL);
		}
	}
	free(buf);
	return (stack);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	**stack_ptr;

	stack_ptr = get_stack();
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(*stack_ptr), *stack_ptr = NULL, NULL);
	if (!*stack_ptr)
	{
		*stack_ptr = malloc(1);
		if (!*stack_ptr)
			return (NULL);
		(*stack_ptr)[0] = '\0';
	}
	*stack_ptr = ft_fill_stack(fd, *stack_ptr);
	if (!*stack_ptr || !**stack_ptr)
		return (free(*stack_ptr), *stack_ptr = NULL, NULL);
	line = ft_extract_line(*stack_ptr);
	*stack_ptr = ft_clean_stack(*stack_ptr);
	return (line);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int		fd = 0;
// 	char	*line;

// 	fd = open("empty.txt", O_RDONLY);
// 	if (fd < 0)
// 		return (1);
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
