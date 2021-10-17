/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 05:25:52 by bbrassar          #+#    #+#             */
/*   Updated: 2021/08/02 17:01:21 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "libft.h"

t_gnl_fd_list	*gnl_find_or_create_fd(t_gnl_fd_list **head, int fd)
{
	t_gnl_fd_list	*list;

	list = *head;
	while (list)
	{
		if (fd == list->fd)
			return (list);
		list = list->next;
	}
	list = malloc(sizeof (*list));
	if (list)
	{
		list->fd = fd;
		list->rest = FT_NULL;
		list->next = *head;
		*head = list;
	}
	return (list);
}

int	gnl_remove_fd(t_gnl_fd_list **head, int fd, int rv)
{
	t_gnl_fd_list	*prev;
	t_gnl_fd_list	*list;

	prev = FT_NULL;
	list = *head;
	while (list)
	{
		if (list->fd == fd)
		{
			if (prev)
				prev->next = list->next;
			else
				*head = list->next;
			free(list->rest);
			free(list);
			break ;
		}
		prev = list;
		list = list->next;
	}
	return (rv);
}

void	gnl_join(char **line, char *buffer, t_size n)
{
	t_size	i;
	char	*s;

	i = 0;
	while (*line && (*line)[i])
		++i;
	s = malloc(i + n + 1);
	if (s)
	{
		ft_memmove(s, *line, i);
		ft_memmove(s + i, buffer, n);
		s[i + n] = 0;
		free(*line);
		*line = s;
	}
}

int	gnl_copy_until_line_break(char **line, char *buffer, char **rest)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		++i;
	gnl_join(line, buffer, i);
	free(*rest);
	if (buffer[i])
		*rest = ft_strdup(buffer + i + 1);
	else
		*rest = FT_NULL;
	i = !!buffer[i];
	free(buffer);
	return (i);
}

int	get_next_line(int fd, char **line)
{
	static t_gnl_fd_list	*head = FT_NULL;
	t_gnl_fd_list			*list;
	char					*buffer;
	int						bytes;

	if (line == FT_NULL || BUFFER_SIZE < 1)
		return (-1);
	list = gnl_find_or_create_fd(&head, fd);
	bytes = 1;
	*line = FT_NULL;
	if (list && list->rest)
		if (gnl_copy_until_line_break(line, ft_strdup(list->rest), &list->rest))
			return (1);
	while (bytes > 0)
	{
		buffer = malloc(sizeof (char) * (BUFFER_SIZE + 1));
		bytes = read(fd, ft_memset(buffer, 0, BUFFER_SIZE + 1), BUFFER_SIZE);
		if (bytes == -1)
			free(buffer);
		else if (gnl_copy_until_line_break(line, buffer, &list->rest))
			return (1);
	}
	return (gnl_remove_fd(&head, fd, bytes));
}
