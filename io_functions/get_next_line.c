/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 15:16:11 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/24 11:13:53 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line_private.h"

static t_list			*get_correct_link(t_list **head, const int fd)
{
	t_data		*data;
	t_list		*list;
	t_list		*newlink;

	list = *head;
	while (list && LIST_CONTENT->fd != fd)
		list = list->next;
	if (!list)
	{
		PROTECT(data = (t_data *)malloc(sizeof(t_data)), NULL);
		PROTECT(data->str = ft_strnew(0), NULL);
		data->begin = data->str;
		data->fd = fd;
		PROTECT(newlink = ft_lstnew(data, sizeof(t_data)), NULL);
		free(data);
		ft_lstadd(head, newlink);
		list = *head;
	}
	return (list);
}

static void				*copy_until_newline(t_list *list, char **line)
{
	size_t		len;

	len = 0;
	while (LIST_CONTENT->str[len] && LIST_CONTENT->str[len] != '\n')
		++len;
	PROTECT(*line = ft_strnew(len), NULL);
	ft_memccpy(*line, LIST_CONTENT->str, '\n', len);
	LIST_CONTENT->str += len + 1;
	return (*line);
}

int						get_next_line(const int fd, char **line)
{
	char				buff[BUFF_SIZE + 1];
	ssize_t				bytes;
	t_list				*list;
	static t_list		*head = NULL;

	if (fd < 0 || !line)
		return (-1);
	PROTECT(list = get_correct_link(&head, fd), -1);
	while ((bytes = read(fd, buff, BUFF_SIZE)))
	{
		if (bytes == -1)
			return (-1);
		buff[bytes] = '\0';
		PROTECT(LIST_CONTENT->str = ft_strjoin(LIST_CONTENT->str, buff,\
			E_NO_FREE), -1);
		free(LIST_CONTENT->begin);
		LIST_CONTENT->begin = LIST_CONTENT->str;
		if (ft_strchr(LIST_CONTENT->str, '\n'))
			break ;
	}
	if (!bytes && LIST_CONTENT->str[0] == '\0')
		return (0);
	PROTECT(copy_until_newline(list, line), -1);
	return (1);
}
